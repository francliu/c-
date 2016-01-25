/*************************************************************************
    > File Name: contructor.cpp
    > Author: 刘建飞
    > Mail: liujianfei526@163.com 
    > Created Time: 2016年01月23日 星期六 11时30分19秒
 ************************************************************************/

#include<iostream>
using namespace std;
class B{
	public:
		B(){
		 f();
		 B::f();
		}
		B(int i,char j):b(i),h(j){}
		/**
		B(int i,char j)
		{
			cout<<"ok"<<endl;
			b=i;
			cout<<"ok"<<endl;
			h=j;
			cout<<"ok"<<endl;
		}
		*/
		virtual void f(){
			cout<<"f()"<<endl;
		}
    private:
	int b;
	char h;
};
class A:public B{
	public:
		int a;
		char* str;
};
//私有继承
int main()
{
	//A c;
	//c.a=9;
	//cout<<c.a<<endl;
	//虚函数可以在构造函数是可以调用。
	B b;
	//A d=c;
	//cout<<d.a<<d.str<<endl;
	//cout<<c.a<<c.str<<endl;
}
