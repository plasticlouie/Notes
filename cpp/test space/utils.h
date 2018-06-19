#include <iostream>

using namespace std;
/*
get array length
*/
template <class T>
int get_length(T &data)
{
  return sizeof(data) / sizeof(data[0]);
}

/*
print_array
*/
template <class T>
void print_array(T &data)
{
  int len = get_length(data);
  for(int i=0 ; i<len ; i++)
    cout << data[i] << " ";
  cout << endl;
  return;
}
