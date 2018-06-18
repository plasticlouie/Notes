#include <iostream>

using namespace std;

void insert_sort(int data[], int len);
void insert_sort(int data[], int len)
{
  int i, j, temp;
  for(i=1 ; i<len ; i++)
  {
    temp = data[i];
    for(j=i ; j>0 && temp<data[j-1] ; j--)
    {
      data[j] = data[j-1];
    }
    data[j] = temp;
  }
}
