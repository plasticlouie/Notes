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
  int data[] = {2,3,4,2,6,2,5,1};
  vector<int> vector_data(data,data+get_length(data));

  Solution s;
  vector<int> max_list = s.maxInWindows(vector_data, 3);
  string str = "abcXYZ";
  cout << str.substr(0,0) + str.substr(0,str.size()) << endl;
  cout << str.substr(0,0) << endl;
  cout << (-3%5) << endl;

  return 0;
}
