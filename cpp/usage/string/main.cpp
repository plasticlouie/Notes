#include<iostream>
#include<string>

using namespace std;

int main()
{
  // ----- 构造函数 -----
  {
    int pos, n;
    string str = "0123456789";   //
    string s2(str); //生成字符串为str的复制品

    // string s(str, pos) 将字符串str中始于pos的部分，复位构造函数的初值
    string s3(str, 3); // s3: "3456789"
    string s4("abcdefgh",3); // s4: "abc"

    // string s(str, strbegin, strlen)：将字符串str中始于strbegin、长度为strlen的部分作为字符串初值
    string s5("01234567", 3, 4); // s5: "3456"

    //string s(cstr)：以C_string类型cstr作为字符串s的初值
    //string s(cstr, char_len)：以C_string类型cstr的前char_len个字符串作为字符串s的初值
    //string s(num ,c)：生成num个c字符的字符串。
  }
  // ----- 字符串切片 -----
  {
    string str = "0123456789";
    // str.substr(index)
    string s2 = str.substr(3); // s2: "3456789"
    // str.substr(index, n)
    string s3 = str.substr(3,2); // s3: "34"
  }

  // ----- 大小和容量 -----
  {
    string str = "12345";
    int len = str.size(); // len: 5 返回string对象的字符个数，和str.length()效果相同。
    long unsigned int max_size = str.max_size(); //返回string对象最多包含的字符数，超出会抛出length_error异常
    int capacity = str.capacity(); //重新分配内存之前，string对象能包含的最大字符数
  }

  // ----- 字符串比较 -----
  {
    // 比较运算符：<, >, ==, <=, >=
    // str.compare() !!!还未弄清
  }

  // ----- name -----
  {

  }



  return 0;
}



/*
字符串内容修改
str1.assign(str2): 直接给字符串赋值(string str2 or char *s)
str1.assign(str2, pos, n): 将str2的内容从位置pos起的n个字符作为原字串的新内容赋给原字串(int pos, int n)
str1.assign(s, n): 将字符数组或字符串的首n个字符替换原字符串内容(string s or char *s)
str1.assign(n, c): 将原字串替换为n个字符c(int n, char c)

erase():函数用于删除字符串中的内容
str = "1234567";
str.erase(1, 2);
cout << str << endl; //out:14567
str.erase(1);
cout << str << endl;//out:1

sawp()函数：相互交换字符串

insert()函数：在字符串中某个位置插入其他字符串
str = "01234567";
str.insert(1, "abc");
cout << str << endl;//out:0abc1234567
str.insert(1, "edfg", 3);
cout << str << endl;//out:0edfabc123467
str = "01234";
str.insert(1, "abcde", 2, 3);
cout << str << endl << endl;//out:0cde1234

append()函数：在字符串最后面追加其他字符串。
replace()函数：用其他字符串替换字符串中的某个子串。

字符串查找：
find()函数：从首部开始查找字符串，返回查找到的子串在字符串中的第一个字符的位置
rind()函数：从首部开始查找字符串，返回查找到的子串在字符串中的第一个字符的位置
find_first_of()函数：在源字符串搜索某字符串，返回被搜索字符串中第一个字符第一次出现的下标。
find_last_of()函数：功能同上，返回被搜索字符串中最后一个字符的下标。


数值转换：
在io的部分有过数值和字符串相互转换的例子，使用的是stringstream函数，在c++11当中有定义好的现成的函数取调用
to_string(val)	把val转换成string
stoi(s,p,b)	把字符串s从p开始转换成b进制的int
stol(s,p,b)	long
stoul(s,p,b)	unsigned long
stoll(s,p,b)	long long
stoull(s,p,b)	unsigned long long
stof(s,p)	float
stod(s,p)	double
stold(s,p)	long double

*/
