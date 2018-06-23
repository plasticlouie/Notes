/*
题目描述
请实现一个函数用来找出字符流中第一个只出现一次的字符。
例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
输出描述:
如果当前字符流没有存在出现一次的字符，返回#字符。
*/

class Solution
{
private:
  int count[256];
  int order[256];

public:
  Solution()
  {
    for(int i=0; i<256 ; i++)
    {
      count[i] = 0;
      order[i] = 0;
    }
  }
  //Insert one char from stringstream
    void Insert(char ch)
    {
      if(count[ch]==0)
      {
        for(int i=0; i<256 ; i++)
        {
          if(order[i]>0)
          {
            order[i]++;
          }
        }
        order[ch] = 1;
      }
      else if(count[ch]==1)
      {
        order[ch] = 0;
      }
      count[ch]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
      int max_index = 0;
      for(int i=1 ; i<256 ; i++)
      {
        if(order[i]>order[max_index])
        {
          max_index = i;
        }
      }
      if(order[max_index]==0)
      {
        return '#';
      }
      else
      {
        char y = max_index;
        return y;
      }

    }
};
