#include <iostream>

int get_max_bit(int data[], int len);
void radix_sort(int data[], int len);

int get_max_bit(int data[], int len)
{
  int d = 1;
  int p = 10;
  for(int i=0 ; i<len ; i++)
  {
    while(data[i] >= p)
    {
      p*=10;
      ++d;
    }
  }
  return d;
}

void radix_sort(int data[], int len)
{
  int num_bits = get_max_bit(data, len);
  int temp[len];
  int bins[10];
  int i, j, k, factor=1;
  cout << "radix sort num bits:" << num_bits << endl;
  for(i=1 ; i<=num_bits ; i++)
  {
    for(j=0 ; j<10 ; j++)
      bins[j] = 0;
    for(j=0 ; j<len ; j++)
    {
      k = (data[j]/factor) % 10;
      bins[k]++;
    }
    for(j=1 ; j<10 ; j++)
      bins[j] += bins[j-1];
    for(j=len-1 ; j>=0 ; j--)
    {
      k = (data[j]/factor) % 10;
      temp[ bins[k]-1 ] = data[j];
      bins[k]--;
    }
    for(j=0 ; j<len ; j++)
      data[j] = temp[j];
    factor *= 10;
  }
  return;
}
