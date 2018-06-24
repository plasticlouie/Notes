#include <iostream>
#include <stdlib.h>
//#include <sys/time>
#include <cstring>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <algorithm>
#include "utils.h"
#define nullptr NULL

using namespace std;




// ------------------------------------------------------------------
class TreeNode
{
public:
  int val;
  TreeNode *left;
  TreeNode *right;
  friend class BinaryTree;
  TreeNode(int val=0)
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

class BinaryTree
{
  TreeNode *root;
public:
  BinaryTree()
  {
    this->root = nullptr;
  }
};

/*
void pre_order(TreeNode *root)
{
  stack<TreeNode*> s;
  while(!s.empty() || root!=nullptr)
  {
    while(root!=nullptr)
    {
      cout << root->val << " ";
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
  return;
}
*/
void pre_order(TreeNode *root)
{
  stack<TreeNode*> s;
  while(!s.empty() || root!=nullptr)
  {
    while(root!=nullptr)
    {
      cout << root->val << " ";
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
  return;
}


void post_order_recurrent(TreeNode *root)
{
  if(root==nullptr){return;}
  post_order_recurrent(root->left);
  post_order_recurrent(root->right);
  cout << root->val << " ";
}

void post_order(TreeNode *root)
{
  stack<TreeNode*> s;
  TreeNode *child;
  int i=0;
  while(root!=nullptr || !s.empty())
  {
    //cout << i << endl;
    //i++;
    while(root!=nullptr)
    {
      s.push(root);
      root = root->left;
    }

    child = nullptr;
    while(!s.empty())
    {
      root = s.top();
      if(root->right==child)
      {
        //cout << "here" << endl;
        s.pop();
        cout << root->val << endl;
        child = root;
      }
      else
      {
        root = root->right;
        //cout << (root==nullptr) << endl;
        break;
      }
      if(s.empty())
      {
        return;
      }
    }

  }
}
// ------------------------------------------------------------------



void permutation(vector<int> &data, int begin)
{
  if(begin==data.size()-1)
  {
    for(int j=0; j<data.size() ; j++)
    {
      cout << data[j] << " ";
    }
    cout << endl;
    return;
  }

  int temp;
  for(int i=begin ; i<data.size() ; i++)
  {
    if(i!=begin)
    {
      temp = data[begin];
      data[begin] = data[i];
      data[i] = temp;
    }
    permutation(data, begin+1);
    if(i!=begin)
    {
      temp = data[begin];
      data[begin] = data[i];
      data[i] = temp;
    }

  }
}



int main(){
  srand((unsigned int)time(NULL));
  int data[] = {4,2,1,4,2,4};
  vector<int> vector_data(data,data+get_length(data));

  TreeNode *t47 = new TreeNode(47);
  TreeNode *t35 = new TreeNode(35);
  TreeNode *t26 = new TreeNode(26);
  TreeNode *t24 = new TreeNode(24);
  TreeNode *t18 = new TreeNode(18);
  TreeNode *t7 = new TreeNode(7);
  TreeNode *t13 = new TreeNode(13);
  TreeNode *t19 = new TreeNode(19);
  t47->left = t35;
  t47->right = t26;

  t35->left = t24;
  t35->right = t18;

  t26->left = t7;
  t26->right = t13;

  t24->left = t19;
  pre_order(t47);
  //post_order(t47);
  //post_order_recurrent(t47);


  return 0;
}
