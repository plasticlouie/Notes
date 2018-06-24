#include<iostream>
#include<stack>

using namespace std;

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
    while(root!=nullptr)
    {
      s.push(root);
      root = root->left;
    }

    child = nullptr;
    while(!s.empty())
    {
      // root的左子树一定已经被访问过，只需要判断root的右子树是否被访问过或者是否为空
      root = s.top();
      // stack中的节点是按照路径顺序的，所以用child记录每次访问之后的root
      // 若root的右子树和child(上次的root)相等，说明该右子树已经访问过了，可输出当前节点值
      // 若root的右子树为空，则直接输出当前节点值
      if(root->right==child)
      {
        s.pop();
        cout << root->val << endl;
        child = root;
      }
      // 若不满足上述条件，说明root有右子树并且右子树没有访问过，则访问右子树
      else
      {
        root = root->right;
        break;
      }
      // 因为root的左子树已经访问过了，若stack为空说明在上面的if语句中执行了s.pop()
      // 即root的右子树为空或者右子树也被访问过了，此时完成了遍历，可以结束函数
      if(s.empty())
      {
        return;
      }
    }
  }
}

int main()
{
  return 0;
}
