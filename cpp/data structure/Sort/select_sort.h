#include <iostream>
#include <algorithm>

void select_sort(int data[], int len);
void select_sort(int data[], int len)
{
  int i, j, min_index;
  for(i=0 ; i<len-1 ; i++)
  {
    min_index = i;
    for(j=i+1 ; j<len ; j++)
    {
      if(data[min_index]>data[j])
        min_index = j;
    }
    if(min_index != i)
      swap(data[i], data[min_index]);
  }
  return;
}
