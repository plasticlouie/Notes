#include <iostream>
#include "insert_sort.h"    // 1
#include "shell_sort.h"     // 2
#include "select_sort.h"    // 3
#include "bubble_sort.h"    // 4
#include "merge_sort.h"     // 5
#include "quick_sort.h"     // 6
#include "heap_sort.h"      // 7
#include "radix_sort.h"     // 8

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
