#include <iostream>

void shell_sort(int data[], int len);

void shell_sort(int data[], int len)
{
  int gap = len / 2, i, j, temp;

  while(gap>0)
  {
    for(i=gap ; i<len ; i++)
    {
      temp = data[i];
      for(j=i ; j>=gap && temp<data[j-gap] ; j--)
      {
        data[j] = data[j-gap];
      }
      data[j] = temp;
    }
    gap /= 2;
  }

  return;
}
