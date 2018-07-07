#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//
// Get array length
//
template <class T>
int get_length(T &data)
{
  return sizeof(data) / sizeof(data[0]);
}

vector<vector<int> > permutation(vector<int> data, int k);
void permutation_core(vector<int> &data, int index, vector<vector<int> > &outputs, int k);



//
// Permutation
// Compute P(m,k) where m is the data length
//
vector<vector<int> > permutation(vector<int> data, int k)
{
  vector<vector<int> > outputs;

  if(data.size()==0)
    return outputs;

  permutation_core(data, 0, outputs, k);
  return outputs;
}



//
// Permutation core (recurrent)
//
void permutation_core(vector<int> &data, int index, vector<vector<int> > &outputs, int k)
{
  if(index == k)
  {
    vector<int> temp(&data[0], &data[k]);
    outputs.push_back(temp);
    return;
  }
  for(int i=index ; i<data.size() ; i++)
  {
    if(i!=index)
      swap(data[i], data[index]);

    permutation_core(data, index+1, outputs, k);

    if(i!=index)
      swap(data[i], data[index]);
  }
}

int main()
{
  int arr[] = {1,2,3,4};
  int len = get_length(arr);
  int k = 4;
  vector<int> data(len);
  vector<vector<int> > outputs;
  for(int i=0 ; i<len ; i++)
    data[i] = arr[i];

  //vector<vector<int> > outputs = permutation(data);
  outputs = permutation(data, k);
  cout << outputs.size() << endl;
  for(int i=0; i<outputs.size(); i++)
  {
    for(int j=0; j<outputs[i].size() ; j++)
    {
      cout << outputs[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
