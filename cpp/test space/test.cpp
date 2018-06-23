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
  int MoreThanHalfNum_Solution(vector<int> numbers)
  {
    if(numbers.size()==0){return 0;}
    int num_data = numbers.size();
    int middle = num_data / 2, left=0, right=num_data-1;
    int index=-1;
    while(left<=right && index!=middle)
    {
      index = Partition(numbers, left, right);
      if(index==-1)
        break;
      if(index==middle)
      {
        int count = 0;
        for(int i=0; i<numbers.size() ; i++)
        {
          if(numbers[i]==numbers[index])
            count++;
        }
        if(count>num_data/2)
          return numbers[index];
        else
          return 0;
      }

      else if(index<middle)
      {
        left = index + 1;
        // index = Partition(numbers, left, right);
      }
      else
      {
        right = index - 1;
        //index = Partition(numbers, left, right);
      }
    }
    return 0;
  }
  int Partition(vector<int> &data, int left, int right)
  {
    if(left<=right)
    {
      int temp = data[left];
      int i=left, j=right;
      while(i<j)
      {
        while(i<j && data[j]>temp)
          j--;
        if(i<j)
          data[i++] = data[j];
        while(i<j && data[i]<temp)
          i++;
        if(i<j)
          data[j--] = data[i];
      }
      data[i] = temp;
      for(int k=0 ; k<data.size() ; k++)
        cout << data[k] << " ";
      cout << endl;
      return i;

    }
    return -1;
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
  int data[] = {4,2,1,4,2,4};
  vector<int> vector_data(data,data+get_length(data));

  Solution s;
  cout << s.MoreThanHalfNum_Solution(vector_data) << endl;

  return 0;
}
