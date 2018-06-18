#include <iostream>
#include <algorithm>

void bubble_sort(int data[], int len);
void bubble_sort(int data[], int len)
{
  int i,j;
  for(i=0 ; i<len-1 ; i++)
  {
    for(j=len ; j>i ; j--)
    {
      if(data[j]<data[j-1])
        swap(data[j], data[j-1]);
    }
  }
  return;
}
