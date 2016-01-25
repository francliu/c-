/*************************************************************************
    > File Name: template.cpp
    > Author: 刘建飞
    > Mail: liujianfei526@163.com 
    > Created Time: 2016年01月22日 星期五 19时52分44秒
 ************************************************************************/
#include"extern.h"
#include<iostream>
using namespace std;
int extern_temp=9;
template<class Type>
struct Test{
	Type a;
	Test(int i){
		a=i;
	}
	class testchild{
		public:
	 static int a;
	 void f()
	 {
		 cout<<"我是testchild"<<endl;
	 }
	 static int ch;
	};
	Test operator=(const Test &p)
	{
		this.a=p.a;
		//只要是局部类中就不可以包含静态数据
		//但可以有静态函数，因为静态函数的目的就是为了给函数加一个限制
		//比如只可以访问静态数据，
		class local{
			static void f(){

			}//还是和普通函数一样只是对函数有了修饰
			//static int loc;//局部中不可以
			virtual void fs(){}
			const int a;
		};
		int i;
		/**
		void f(){

		}
		*/
		return this;
	}
	const int mm;//只能被构造函数初始化，不能外部初始化。
};
//类里面可以定义类，调用方法可调用静态一样使用::,
//operator int()实际上就是强制转换类型,并且只能是类成员函数
//static voif f();//但不可以静态函数声明。错误。
//在函数里不可以定义函数，但是当使用到一个还没有声明的函数时，
//需要先声明在使用。比如f(int i);
//------------内嵌类与局部类得总结--------------
//内嵌类实际上和外部类一样，只要外部类有，内嵌类就可以有。
//但是局部类中就不可以包含静态数据，其他都一样
//但可以有静态函数，因为静态函数的目的就是为了给函数加一个限制
//比如只可以访问静态数据，
template<class Type>
int	Test<Type>::testchild::a=1;
static void f(int i)
{
	cout<<i<<endl;
}
void ttt()
{

	class local{
		static void f(){
		}//还是和普通函数一样只是对函数有了修饰
			//static int loc;//局部中不可以
	};
	int i;	
	void f(int i);//在函数中可以声明，但不可以有实现体,在任何地方的函数都一样
	f(2);
}
//在全局变量以及全局函数之前添加static,限制可见性。
//在ｍａｉｎ函数里面加上static表明只是把局部数据改变为静态数据。
int main(){
	void f();
	static int extern_temp=8;
	fun();
	ttt();
	return 0;
}
