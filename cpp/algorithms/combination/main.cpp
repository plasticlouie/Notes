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

vector<vector<int> > combination(vector<int> data, int k);
void combination_core(vector<int> data, vector<bool> &chosen, int index, int k, vector<vector<int> > &outputs);



//
// Combination
//
vector<vector<int> > combination(vector<int> data, int k)
{
  vector<vector<int> > outputs;

  if(data.size()==0)
    return outputs;

  vector<bool> chosen(data.size());
  combination_core(data, chosen, 0, k, outputs);
  return outputs;
}



//
// Combination core (recurrent)
//
void combination_core(vector<int> data, vector<bool> &chosen, int index, int k, vector<vector<int> > &outputs)
{
  if(k==0)
  {
    vector<int> temp;

    for(int i=0 ; i<index ; i++)
      if(chosen[i])
        temp.push_back(data[i]);

    outputs.push_back(temp);
    return;
  }
  for(int i=index ; i<data.size() ; i++)
  {
    chosen[i] = true;
    combination_core(data, chosen, i+1, k-1, outputs);
    chosen[i] = false;
  }
  return;
}

int main()
{
  int arr[] = {1,2,3,4};
  int len = get_length(arr);
  int k = 2;
  vector<int> data(len);
  vector<vector<int> > outputs;
  for(int i=0 ; i<len ; i++)
    data[i] = arr[i];

  //vector<vector<int> > outputs = permutation(data);
  outputs = combination(data, k);
  cout << "num combinations: " << outputs.size() << endl;
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
