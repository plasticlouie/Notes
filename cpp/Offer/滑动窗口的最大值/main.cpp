/*
题目描述
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，
那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}；
针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个：
{[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}，
{2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。

解体思路：
使用双向队列，队列的头指向当前的最大值对应的下标。
当滑窗向后移动一格时候，进行如下操作：
1. 从队尾开始，根据队列中记录的下标得到对应的数组元素值，和新来的元素对比，若
  新元素大于队尾记录的元素，则把队尾元素出队，直到满足条件为止。
2. 新元素进入队尾
3. 检查队头元素（下标值）是否已经在窗口之外，若超过窗口范围则把队头元素去除
4. 此时的队头元素即当前最大值对应的数组下标
*/
#include <deque>
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
      if(num.size()==0 || size<1 || size>num.size())
      {
        vector<int> empty_list;
        return empty_list;
      }
      int num_data = num.size(), i, list_size;

      if(size>=num_data)
        list_size = 1;
      else
        list_size = num_data - size + 1;

      vector<int> max_list(list_size);
      deque<int> q;

      for(i=0 ; i<size ; i++)
      {
        while(!q.empty() && num[i]>=num[q.back()])
          q.pop_back();
        q.push_back(i);
      }
      max_list[0] = num[q.front()];

      for(i=size ; i<num_data ; i++)
      {
        while(!q.empty() && num[i]>num[q.back()])
          q.pop_back();
        q.push_back(i);
        if(q.front()<=i-size)
          q.pop_front();
        max_list[i-size+1] = num[q.front()];
      }

      return max_list;
    }
};
