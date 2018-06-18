#include <iostream>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <vector>
#include <stack>
#define nullptr NULL
#define middleorder 0
#define preorder 1

using namespace std;

template<typename T>
int get_len(T &array)
{
   return (sizeof(array) / sizeof(array[0]));
};

class TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  friend class BSTree;
public:
  TreeNode(int val)
  {
    this->val = val;
    this->left = nullptr;
    this->right = nullptr;
  }
  int get_val()
  {
    return this->val;
  }
};

class BSTree
{
  TreeNode *root;
public:
  BSTree();
  bool insert(int val);
  bool insert(TreeNode *root, int val);
  void print(int x=0);
  vector<int> pre_order();
  vector<int> middle_order();
  TreeNode *search(int val);
  bool delete_node(int val);
};

BSTree::BSTree()
{
  this->root = nullptr;
}

bool BSTree::insert(int val)
{
  if(this->root==nullptr)
  {
    this->root = new TreeNode(val);
    return true;
  }
  else
  {
    return BSTree::insert(this->root, val);
  }
}
bool BSTree::insert(TreeNode *root, int val)
{
  if(root != nullptr)
  {
    TreeNode *save_root = root;
    if(val==root->val){return false;}
    if(val < root->val)
    {
      if(root->left == nullptr)
      {
        root->left = new TreeNode(val);
        return true;
      }
      else
      {
        return BSTree::insert(root->left, val);
      }
    }
    if(val > root->val)
    {
      if(root->right == nullptr)
      {
        root->right = new TreeNode(val);
        return true;
      }
      else
      {
        return BSTree::insert(root->right, val);
      }
    }
  }
  return false;
}


void BSTree::print(int x)
{
  vector<int> data_vector;
  if(x==0)
    data_vector = this->middle_order();
  else
    data_vector = this->pre_order();

  cout << "---" << endl;
  for(int i=0 ; i<data_vector.size() ; i++)
  {
    cout << data_vector[i] << " ";
  }
  cout << "---" << endl;
  return;
}

vector<int> BSTree::pre_order()
{
  TreeNode *root = this->root;
  vector<int> y;
  if(root==nullptr){return y;}
  stack<TreeNode*> s;
  while(!s.empty() || root!=nullptr)
  {
    while(root != nullptr)
    {
      y.push_back(root->val);
      s.push(root);
      root = root->left;
    }
    if(!s.empty())
    {
      root = s.top();
      s.pop();
      root = root->right;
    }
  }
  return y;
}

vector<int> BSTree::middle_order()
{
  vector<int> y;
  if(this->root == nullptr){return y;}
  TreeNode *root = this->root;
  stack<TreeNode*> s;

  while(!s.empty() || root!=nullptr)
  {
    while(root != nullptr)
    {
      s.push(root);
      root = root->left;
    }
    if(!s.empty())
    {
      root = s.top();
      s.pop();
      y.push_back(root->val);
      root = root->right;
    }
  }
  return y;
}

TreeNode *BSTree::search(int val)
{
  TreeNode *root = this->root;
  while(root != nullptr)
  {
    if(val== root->val)
      return root;
    if(val > root->val)
      root = root->right;
    else
      root = root->left;
  }
  return nullptr;
};


bool BSTree::delete_node(int val)
{
  cout << "delete node: " << val << endl;
  TreeNode *root = this->root, *last, *temp, *temp_last;
  temp_last = nullptr;
  last = root;
  while(root != nullptr)
  {
    if(val== root->val)
      break;
    last = root;
    if(val > root->val)
      root = root->right;
    else
      root = root->left;
  }
  if(root==nullptr){return false;}

  if(root->right == nullptr)
  {
    cout << "right null" << endl;
    if(root==this->root)
    {
      this->root = root->left;
      delete root;
      return true;
    }
    else
    {
      if(last->left == root){last->left=root->left;}
      else last->right = root->left;
      delete root;
      return true;
    }
  }
  if(root->left == nullptr)
  {
    cout << "left null" << endl;
    if(root==this->root)
    {
      cout << "delete root" << endl;
      this->root = root->right;
      return true;
    }
    else
    {
      if(last->left == root){last->left=root->right;}
      else last->right = root->right;
      delete root;
      return true;
    }
  }

  temp = root->right;
  temp_last = temp;
  while(temp->left != nullptr)
  {
    temp_last = temp;
    temp = temp->left;
  }
  if(temp_last == temp)
  {
    root->val = temp->val;
    root->right = temp->right;
    delete temp;
    return true;
  }
  root->val = temp->val;
  temp_last->left = temp->right;
  delete temp;
  return true;
}


// --- main ---
int main()
{
  BSTree t;
  int data[] = {28,25,36,33,43,35,34};
  //int data[] = {28,25};
  for(int i=0 ; i<get_len(data) ; i++)
  {
    t.insert(data[i]);
  }
  t.print();

  t.delete_node(36);
  t.print();



  return 0;
}
