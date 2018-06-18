#include <iostream>

void merge_sort(int data[], int len);
void merge(int data[], int temp[], int start, int middle, int end, int len);
void merge_sort_recurrent(int data[], int len);
void merge_sort_recurrent_core(int data[], int temp[], int start, int end, int len);
// ---

void merge_sort_recurrent(int data[], int len)
{
  int temp[len];
  for(int i=0 ; i<len ; i++)
    temp[i] = -1;
  merge_sort_recurrent_core(data, temp, 0, len-1, len);
  return;
}

void merge_sort_recurrent_core(int data[], int temp[], int start, int end, int len)
{
  if(start < end)
  {
    int middle = (start+end)/2;
    merge_sort_recurrent_core(data, temp, start, middle, len);
    merge_sort_recurrent_core(data, temp, middle+1, end, len);
    merge(data, temp, start, middle, end, len);
    for(int i=start ; i<=end ; i++)
      data[i] = temp[i];
  }
  return;
}

void merge_sort(int data[], int len)
{
  int temp[len], start, stride=1;
  while(stride<len)
  {
    for(start=0 ; start<len-1 ; start+=2*stride)
    {
      merge(data, temp, start, start+stride-1 , start+2*stride-1, len);
    }
    stride *= 2;
    for(start=0 ; start<len-1 ; start+=2*stride)
    {
      merge(temp, data, start, start+stride-1 , start+2*stride-1, len);
    }
    stride *= 2;
  }
  return;
}

void merge(int data[], int temp[], int start, int middle, int end, int len)
{
  if(start>len-1){return;}
  middle = middle < len-1 ? middle : len-1;
  end = end < len-1 ? end : len-1;
  int i=start, j=middle+1, k=start;
  while(i<=middle && j<=end)
  {
    if(data[i]<data[j])
      temp[k++] = data[i++];
    else
      temp[k++] = data[j++];
  }
  while(i<=middle)
    temp[k++] = data[i++];
  while(j<=end)
    temp[k++] = data[j++];
  return;
}

// ---

// ---
