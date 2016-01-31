/*************************************************************************
    > File Name: union.cpp
    > Author: 刘建飞
    > Mail: liujianfei526@163.com 
    > Created Time: 2016年01月30日 星期六 23时07分41秒
 ************************************************************************/

#include<iostream>
using namespace std;
union temp{
	int a;
	char c;
	double d;
};
int main()
{
	temp t; 
	cout<<sizeof(t)<<endl;
	t.a= 1;
	cout<<sizeof(t)<<endl;
	cout<<t.a<<endl;
	t.c= 'f';
	cout<<sizeof(t)<<endl;
	cout<<t.c<<endl;
	t.d = 2.98;
	cout<<sizeof(t)<<endl;
	cout<<t.d<<endl;
}
