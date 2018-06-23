/*
题目描述
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
*/

/*
方法1：
数组中，数字n出现次数超过一半，则该数组的中位数为n
使用快速排序的思想，Partition函数把数组中第一个数作为基准，把比基准小的元素
排在左边，比基准大的元素排在右边，此时若该基准的下标小于（数组长度/2），说明
该数小于中位数，则对右边继续调用Partition函数，以此类推。
*/
class Solution {
public:
  int MoreThanHalfNum_Solution(vector<int> numbers)
  {
    if(numbers.size()==0){return 0;}
    int num_data = numbers.size();
    int middle=num_data/2, left=0, right=num_data-1, index=-1;

    while(left<=right && index!=middle)
    {
      index = Partition(numbers, left, right);
      if(index==-1)
        break;
      if(index==middle)
      {
        int count = 0;
        for(int i=0; i<numbers.size() ; i++)
        {
          if(numbers[i]==numbers[index])
            count++;
        }
        if(count>num_data/2)
          return numbers[index];
        else
          return 0;
      }
      else if(index<middle)
        left = index + 1;
      else
        right = index - 1;
    }
    return 0;
  }
  // Partition函数用于对数组进行调整，把数组中下标为left的值作为基准，对数组的left到right
  // 区间进行调整，使小于基准值的数都在左边，大于基准值的数都在右边，返回调整后的基准值下标，
  // 若输入的left<right则返回-1
  // 输入 {3,5,4,1,2}，数组被调整为{2,1,3,4,5}，并且输出2 (3的下标)
  int Partition(vector<int> &data, int left, int right)
  {
    if(left<=right)
    {
      int temp=data[left], i=left, j=right;
      while(i<j)
      {
        while(i<j && data[j]>temp)
          j--;
        if(i<j)
          data[i++] = data[j];
        while(i<j && data[i]<temp)
          i++;
        if(i<j)
          data[j--] = data[i];
      }
      data[i] = temp;
      return i;
    }
    return -1;
  }
};
