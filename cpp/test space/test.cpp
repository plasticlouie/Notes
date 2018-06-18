#include <iostream>
#include <stdlib.h>
//#include <sys/time>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
#define nullptr NULL

using namespace std;

template <class T>
int get_length(T &data)
{
  return sizeof(data) / sizeof(data[0]);
}


template <class T>
void print(T &data)
{
  int len = get_length(data);
  for(int i=0 ; i<len ; i++)
    cout << data[i] << " ";
  cout << endl;
  return;
}


// ------------------------------------------------------------------
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {

    }
};
// ------------------------------------------------------------------
//vector<vector<int> > permutation(vector<int> data)
//{}

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
  char matrix[] = {'d','e','f','a','b','g','i','c','h','\0'};
  int rows=3, cols=3;
  //char str[] = {'a','b','c','\0'};
  char str[] = {'b','b','c','\0'};
  Solution s;

  /*
  int row, col;
  row = 1; col = 0;
  cout << matrix[row*cols + col] << endl;
  row = 1; col = 1;
  cout << matrix[row*cols + col] << endl;
  row = 0; col = 2;
  cout << matrix[row*cols + col] << endl;
  */
  cout << s.hasPath(matrix, rows, cols, str) << endl;

  return 0;
}
