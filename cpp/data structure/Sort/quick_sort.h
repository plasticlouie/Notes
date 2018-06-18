#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

void quick_sort_recurrent(int data[], int len);
void quick_sort_recurrent_core(int data[], int left, int right);
void quick_sort(int data[], int len);

// ---
void quick_sort_recurrent(int data[], int len)
{
  if(len<=0){return;}
  quick_sort_recurrent_core(data, 0, len-1);
  return;
}

void quick_sort_recurrent_core(int data[], int left, int right)
{
  if(left<right)
  {
    int i = left, j = right, temp = data[left];
    while(i<j)
    {
      while(i<j && temp<data[j])
        j--;
      if(i<j)
        data[i++] = data[j];
      while(i<j && temp>data[i])
        i++;
      if(i<j)
        data[j--] = data[i];
    }
    data[i] = temp;
    quick_sort_recurrent_core(data, left, i-1);
    quick_sort_recurrent_core(data, i+1, right);
  }
  return;
}
// ---

void quick_sort(int data[], int len)
{
  stack<int> s;
  int left=0, right=len-1, i, j, temp;
  s.push(left);
  s.push(right);
  while(!s.empty())
  {
    j = right = s.top();
    s.pop();
    i = left = s.top();
    s.pop();
    if(i<j)
    {
      temp = data[i];
      while(i<j)
      {
        while(i<j && temp<data[j])
          j--;
        if(i<j)
          data[i++] = data[j];
        while(i<j && temp>data[i])
          i++;
        if(i<j)
          data[j--] = data[i];
      }
      data[i] = temp;
      s.push(left);
      s.push(i-1);
      s.push(i+1);
      s.push(right);
    }
  }
  return;
}
