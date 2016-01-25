/*************************************************************************
    > File Name: template.cpp
    > Author: 刘建飞
    > Mail: liujianfei526@163.com 
    > Created Time: 2016年01月22日 星期五 19时52分44秒
 ************************************************************************/

#include<iostream>
using namespace std;
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
		/**;
		void f(){

		}
		*/
		return this;
	}
	const static void con_st()
	{
		cout<<"const,static"<<endl;
	}
	/**
	//virtual与static不可以一起使用
	virtual static void con_st(){
		cout<<"const,static"<<endl;
	}
	//const修饰函数时与static不可以一起使用，但修饰返回值是可以。
	static void con_st()const
	{
		cout<<"const,static"<<endl;
	}
	//volatile修饰函数时与static不可以一起使用，但修饰返回值是可以。
	static void vol_st()volatile{
		cout<<"const,static"<<endl;
	}
	*/
	/**
	void vol_st()volatile{
		cout<<"volatile,static"<<endl;
	}//为什么没法用，不知道
	volatile static void vol_st(){
		cout<<"const,static"<<endl;
	}
	*/
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
//静态函数没有隐含的内部指针this.
//
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
int main(){
	Test<int>::con_st();
	Test<int>::vol_st();
	ttt();
	return 0;
}
