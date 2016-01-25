/*************************************************************************
    > File Name: empty_class.cpp
    > Author: 刘建飞
    > Mail: liujianfei526@163.com 
    > Created Time: 2016年01月18日 星期一 21时35分49秒
 ************************************************************************/

#include<iostream>
using namespace std;
class T
{
	int i;
	int j;
	virtual void fun0() {
		 cout << "A::fun0" << endl;
	}
	virtual void fun1() {
		 cout << "A::fun1" << endl;
	}
	virtual void fun2() {
		 cout << "A::fun2" << endl;
	}
};
int main()
{
	T a;
	cout << "Size of A = " << sizeof(a) << endl;
	return 0;
}
