#include <iostream>
#include <algorithm>

void adjust_down(int heap[], int index, int len);
void adjust_up(int heap[], int index);
void heap_sort(int data[], int len);

void heap_sort(int data[], int len)
{
  for(int i=(len-2)/2 ; i>=0 ; i--)
  {
    adjust_down(data, i, len);
  }
  for(int i=len-1 ; i>0 ; i--)
  {
    swap(data[0], data[i]);
    adjust_down(data, 0, i-1);
  }
  return;
}


void adjust_down(int heap[], int index, int len)
{
  int child=(index*2)+1, temp=heap[index];
  while(child < len)
  {
    if(child<len-1 && heap[child+1]<heap[child]){child++;}
    if(temp<=heap[child]){break;}
    heap[(child-1)/2] = heap[child];
    child = child*2 + 1;
  }
  heap[(child-1)/2] = temp;
  return;
}

void adjust_up(int heap[], int index)
{
  int temp = heap[index];
  while(index>0 && heap[index]>heap[(index-1)/2])
  {
    heap[index] = heap[(index-1)/2];
    index = (index-1) / 2;
  }
  heap[index] = temp;
  return;
}
