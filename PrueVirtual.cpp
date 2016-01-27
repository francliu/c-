/*************************************************************************
    > File Name: template.cpp
    > Author: 刘建飞
    > Mail: liujianfei526@163.com 
    > Created Time: 2016年01月22日 星期五 19时52分44秒
 ************************************************************************/

#include<iostream>
using namespace std;
class mumble
{

	public:
		mumble(){

		}
		//virtual void f()=0;
		//virtual void f()=0;
		virtual ~mumble()=0;

		//Test<int> m;
};
/**
//纯虚函数在类里面声明，在类外可以实现，在类里面不可以.
void mumble::f(){
	cout<<"f()"<<endl;
}
*/
//纯虚析构函数必须定义
mumble::~mumble(){
	cout<<"~mumble"<<endl;
}
class A:public mumble{
public:
	void f()
	{
		//mumble::f();
		cout<<333<<endl;
	}
	/**
	~A(){
		cout<<"~A"<<endl;
	}
	*/
	
};
//纯虚函数可以有函数体，
int main(){
	//mumble m;a
	//mumble m;
	A a;
	a.f();
	return 0;
}
