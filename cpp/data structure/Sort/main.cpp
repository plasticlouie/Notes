#include <iostream>
#include "sort.h"

using namespace std;



int main()
{
  int data[] = {390, 58, 472, 343, 978, 420, 392, 106, 58, 674};
  //int data[] = {8,1,2,7,2,3,5,3,4,9,4,1,5,0,8,5,6,1,6,2,6,7,4,0,9,7,0,8,3,9};
  int len = get_length(data);
  cout << "original data" << endl;
  print(data);

  //quick_sort_recurrent(data, len);
  radix_sort(data, len);

  cout << "sorted data" << endl;
  print(data);


  return 0;
}
