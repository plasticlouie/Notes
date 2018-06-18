#include <iostream>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#define nullptr NULL
#define middleorder 0
#define preorder 1

using namespace std;

template<typename T>
int get_len(T &array)
{
   return (sizeof(array) / sizeof(array[0]));
};

class TreeNode;
class AVLTree;

class TreeNode
{
public:
  int val;
  int balance;
  TreeNode *left;
  TreeNode *right;
  friend class AVLTree;
  TreeNode(int val)
  {
    this->val = val;
    this->balance = 0;
    this->left = nullptr;
    this->right = nullptr;
  }
  int get_val()
  {
    return this->val;
  }
  void set_val(int val)
  {
    this->val = val;
  }
};

int get_depth(TreeNode *root)
{
  if(root==nullptr){return 0;}
  int left_depth = 0;
  int right_depth = 0;
  left_depth = get_depth(root->left);
  right_depth = get_depth(root->right);
  int depth = left_depth>right_depth?left_depth:right_depth;
  depth++;
  return depth;
}


void print_tree_by_layer(TreeNode *root)
{
  int depth = get_depth(root);
  int count = 1;
  int nullptr_count = 0;
  queue<TreeNode*> q1, q2;
  queue<TreeNode*> *q1p, *q2p;
  q1.push(root);
  while(count<=depth)
  {
    nullptr_count = 0;
    if(!q1.empty())
    {
      q1p = &q1;
      q2p = &q2;
    }
    else
    {
      q1p = &q2;
      q2p = &q1;
    }
    queue<TreeNode*> &q_current = *q1p;
    queue<TreeNode*> &q_next = *q2p;
    while(!q_current.empty())
    {
      root = q_current.front();
      q_current.pop();
      if(root!=nullptr)
      {
        q_next.push(root->left);
        q_next.push(root->right);
        cout << root->val << " ";
      }
      else
      {
        cout << "n" << nullptr_count << " ";
        nullptr_count++;
      }
    }
    cout << endl;
    count ++;
  }
  return;
}


void left_rotation(TreeNode* root)
{
  TreeNode *right = root->right;
  TreeNode *temp_node = root->left;
  root->left = right;
  root->right = right->right;
  right->right = right->left;
  right->left = temp_node;
  swap(root->val, right->val);
  root->balance = 0;
  right->balance = 0;
  return;
}

void right_rotation(TreeNode* root)
{
  TreeNode *left = root->left;
  TreeNode *temp_node = root->right;
  root->right = left;
  root->left = left->left;
  left->left = left->right;
  left->right = temp_node;
  swap(root->val, left->val);
  root->balance = 0;
  left->balance = 0;
  return;
}

void left_right_rotation(TreeNode* root)
{
  TreeNode *left = root->left;
  TreeNode *left_right = left->right;
  TreeNode *temp = root->right;
  root->right = left_right;
  left->right = left_right->left;
  left_right->left = left_right->right;
  left_right->right = temp;
  swap(root->val, left_right->val);
  root->balance = 0;
  if(left_right->balance==1)
  {
    left->balance = 0;
    left_right->balance = -1;
  }
  else if(left_right->balance == -1)
  {
    left->balance = 1;
    left_right->balance = 0;
  }
  else
  {
    left->balance = 0;
    left_right->balance = 0;
    //cout << "left right rotation error: node " << root->val <<endl;
  }
  return;
}

void right_left_rotation(TreeNode *root)
{
  TreeNode *right = root->right;
  TreeNode *right_left = right->left;
  TreeNode *temp = root->left;
  root->left = right_left;
  right->left = right_left->right;
  right_left->right = right_left->left;
  right_left->left = temp;
  swap(root->val, right_left->val);
  root->balance = 0;
  if(right_left->balance==-1)
  {
    right->balance = 0;
    right_left->balance = 1;
  }
  else if(right_left->balance == 1)
  {
    right->balance = -1;
    right_left->balance = 0;
  }
  else
  {
    right->balance = 0;
    right_left->balance = 0;
    //cout << "right left rotation error: node " << root->val << endl;
  }
  return;
}

void rebalance(TreeNode *root)
{
  if(root->balance==-2)
  {
    if(root->right->balance==-1)
    {
      left_rotation(root);
      return;
    }
    if(root->right->balance==1)
    {
      right_left_rotation(root);
      return;
    }
  }
  if(root->balance==2)
  {
    if(root->left->balance==1)
    {
      right_rotation(root);
      return;
    }
    if(root->left->balance==-1)
    {
      left_right_rotation(root);
      return;
    }
  }
  cout << "rebalance error" << endl;
}


class AVLTree
{
  TreeNode *root;
public:
  AVLTree();
  bool insert_node(int val);
  //bool delete_node(int val);
  //TreeNode *search(int val);
  void preorder_print();
  void middleorder_print();
  TreeNode *get_root();
};

AVLTree::AVLTree()
{
  this->root = nullptr;
}

TreeNode *AVLTree::get_root()
{
  return this->root;
}

void AVLTree::preorder_print()
{
  TreeNode *root = this->root;
  if(root != nullptr)
  {
    cout << "val  balance" << endl;
  }
  stack<TreeNode*> s;

  while(root!=nullptr || !s.empty())
  {
    while(root!=nullptr)
    {
      cout << root->val << "\t" << root->balance << endl;
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
}

void AVLTree::middleorder_print()
{
  TreeNode *root = this->root;
  if(root != nullptr)
  {
    cout << "val  balance" << endl;
  }
  stack<TreeNode*> s;

  while(root!=nullptr || !s.empty())
  {
    while(root!=nullptr)
    {
      s.push(root);
      root = root->left;
    }
    if(!s.empty())
    {
      root = s.top();
      cout << root->val << "\t" << root->balance << endl;
      s.pop();
      root = root->right;
    }
  }
}

bool AVLTree::insert_node(int val)
{
  if(this->root == nullptr)
  {
    this->root = new TreeNode(val);
    return true;
  }
  int height_diff = 0;
  stack<TreeNode*> s;
  TreeNode *root = this->root, *last;
  while(root != nullptr)
  {
    s.push(root);
    last = root;
    if(val == root->val)
    {
      return false;
    }
    if(val > root->val)
    {
      root = root->right;
    }
    else
    {
      root = root->left;
    }
  }
  if(val < last->val)
  {
    last->left = new TreeNode(val);

    if(last->right == nullptr)
    {
      height_diff = 1;
      //last->left->balance = 1;
      last = last->left;
    }
    else
    {
      height_diff = 0;
      last->balance++;
      //last->left->balance = 0;
      return true;
    }
  }
  else if(val > last->val)
  {
    last->right = new TreeNode(val);
    if(last->left == nullptr)
    {
      height_diff = 1;
      last = last->right;
    }
    else
    {
      height_diff = 0;
      last->balance--;
      return true;
    }
  }
  while(!s.empty())
  {
    root = s.top();
    s.pop();
    if(root->left == last)
    {
      root->balance += height_diff;
    }
    else
    {
      root->balance -= height_diff;
    }
    if(root->balance == 0)
    {
      height_diff = 0;
      return true;
    }
    else
    {
      if(height_diff!=0)
      {
        height_diff = 1;
      }
    }
    if(root->balance>1 || root->balance<-1)
    {
      rebalance(root);
      return true;
    }
    last = root;
  }
  return true;
}


/*
bool AVLTree::insert_node(int val)
{
  if(this->root == nullptr)
  {
    this->root = new TreeNode(val);
    return true;
  }
  int height_diff = 0;
  stack<TreeNode*> s;
  TreeNode *root = this->root, *last;
  while(root != nullptr)
  {
    s.push(root);
    last = root;
    if(val == root->val)
    {
      return false;
    }
    if(val > root->val)
    {
      root = root->right;
    }
    else
    {
      root = root->left;
    }
  }
  if(val < last->val)
  {
    last->left = new TreeNode(val);

    if(last->right == nullptr)
    {
      height_diff = 1;
      //last->left->balance = 1;
      last = last->left;
    }
    else
    {
      height_diff = 0;
      last->balance++;
      //last->left->balance = 0;
      return true;
    }
    while(!s.empty())
    {
      root = s.top();
      s.pop();
      if(root->left==last)
      {
        root->balance += height_diff;
      }
      else
      {
        root->balance -= height_diff;
      }
      if(root->balance == 0)
      {
        height_diff = 0;
        return true;
      }
      else
      {
        if(height_diff!=0)
        {
          height_diff = 1;
        }
      }

      last = root;
    }

  }
  else if(val > last->val)
  {
    last->right = new TreeNode(val);
    if(last->left == nullptr)
    {
      height_diff = 1;
      //last->right->balance = -1;
      last = last->right;
    }
    else
    {
      height_diff = 0;
      last->balance--; // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
      //last->right->balance = 0;
      return true;
    }
    while(!s.empty())
    {
      root = s.top();
      s.pop();
      if(root->left == last)
      {
        root->balance += height_diff;
      }
      else
      {
        root->balance -= height_diff;
      }
      if(root->balance == 0)
      {
        height_diff = 0;
        return true;
      }
      else
      {
        if(height_diff!=0)
        {
          height_diff = 1;
        }
      }
      last = root;
    }
  }

  return true;
}
*/

/*
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
*/

// --- main ---
int main()
{
  AVLTree t;
  //int data[] = {11,7,3,9,18,15,26, 14, 16};
  //int data[] = {11,7,3,9,18};
  int data[] = {16,3,7,11,9,14,15,26,18};
  //int data[] = {16,3,7};
  //int data[] = {30,15,60,40,70,50,55,56};

  for(int i=0 ; i<get_len(data) ; i++)
  {
    t.insert_node(data[i]);
  }

  t.preorder_print();
  t.middleorder_print();
  print_tree_by_layer(t.get_root());
  //cout << get_depth(t.get_root()) << endl;

  return 0;
}
