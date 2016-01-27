/*************************************************************************
    > File Name: const.cpp
    > Author: 刘建飞
    > Mail: liujianfei526@163.com 
    > Created Time: 2016年01月18日 星期一 16时46分48秒
 ************************************************************************/

#include<iostream>
#include<string>
#include "haha.h"
using namespace std;
const int tt=2;
static int st=3;
const class test{

public:
   test(){};
   test(int i):data(i){};
   test(int i,int j):data(i),A(j){};
   int data;
   int A;
   static long long F;
   int get()const
   {
	   return data;
   }
   int get()
   {
	   cout<<"&"<<endl;
	   return data;
   }
   int getA()const
   {
	   return A;
   }
   int &getA()
   {
	   cout<<"&"<<endl;
	   return A;
   }
}a(1,2);

long long test::F=3;
class quote{
public:
	//quote(){};
	quote(int i):b(i){};
	int a;
	const int b;
	class child{
		public:
		child(int b):a(b){};
		int a;
	};
	int const &get()const
	{
		//a=2;
		//int c = getA();
		return a;
	}
	int getA()
	{
		get();
		//return a;
	}
	int getB()const
	{
		//b=2;
		int c=b;
		return c;
	}
    static int F;
};
int quote::F=9;

int const haha()
{
	return 1;
}

/**
	static int jjj=8;
	int jj=8;
	int jssj;
	static int jjhhhj=8;
	//int *d = new int[10];
	//string s="a";
	//string *d = new string[10];
int main()
{
	const int sss=8;
	cout << "Size of A = " << sizeof(a) << endl;
	quote *q = new quote(1);
	cout << "Size of A = " << sizeof(q) << endl;
	test *t = new test(2,3);
	//cout<<a.get()<<a.getA()<<endl;
	int d = a.get();
	d = 5;
	//cout<<a.get()<<a.getA()<<endl;
	const test f = test(1,3);
	//cout<<f.get()<<f.getA()<<endl;
	cout<<t->get()<<endl;
	cout<<t->getA()<<endl;
	const int b=1;
	
	//cout<<t->F<<endl;
	
	quote *q = new quote(1);
	cout<<q->get()<<q->getB()<<endl;
	const int &C = q->get();
	cout<<C<<endl;
	//const quote *t = new quote(1);
	cout<<t->get()<<t->getA()<<endl;
	//C=8;
	//q->get()=9;
	//cout<<C<<endl;
	//C = q->getB();
	//cout<<C<<endl;
	//cout<<haha()<<endl;
	
}
*/
