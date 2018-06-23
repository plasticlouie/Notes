/*
题目描述
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
输入描述:
输入一个字符串,包括数字字母符号,可以为空
输出描述:
如果是合法的数值表达则返回该数字，否则返回0

输入
+2147483647
输出
2147483647

输入
1a33
输出
0
*/

class Solution {
public:
    int StrToInt(string str) {
      if(str.size()==0){return 0;}
      if(str.size()==1 && (str[0]<'0'&&str[0]>'9')){return 0;}
      int sign = 1, i=0;
      if(str[0]=='+')
      {
        sign = 1;
        i = 1;
      }
      else if(str[0]=='-')
      {
        sign=-1;
        i = 1;
      }
      else if(str[0]>='0' && str[0]<='9')
      {
        i=0;
      }
      else{return 0;}

      int num=0;
      while(i<=str.size()-1)
      {
        if(str[i]>'9' || str[i]<'0'){return 0;}
        num = num*10 + (str[i]-'0');
        i++;
      }
      num *= sign;
      cout << num << endl;
      return num;
    }
};
