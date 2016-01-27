/*************************************************************************
    > File Name: template.cpp
    > Author: 刘建飞
    > Mail: liujianfei526@163.com 
    > Created Time: 2016年01月22日 星期五 19时52分44秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Test{
	static int t;
	public:
	Test(int i){
		t=i;
	}
	//class testchild;
	//friend testchild;
	class testchild{
		public:
	 static int a;
	 void f();
	 static int ch;
	};
	Test operator=(const Test &p)
	{
		this->t=p.t;
		//只要是函数中就不可以包含静态数据
		//但可以有静态函数，因为静态函数的目的就是为了给函数加一个限制
		//比如只可以访问静态数据，
		class local{
			static void f(){

			}//还是和普通函数一样只是对函数有了修饰
			//static int loc;//局部中不可以
		};
		int i;
		return *this;
	}
};
//静态数据在未使用前不定义也可以编译通过，但一旦要使用，则必须首先定义。
int Test::t=9;
int Test::testchild::a=7;
void Test::testchild::f()
{
		 cout<<t<<endl;
		 cout<<a<<endl;
		 cout<<"我是testchild"<<endl;
}
class mumble
{

	public:
		mumble(){

		}
	    operator int() // 问题在此只能是非静态成员函数
		{
			cout << "mumble::operator int() is called." << endl;
			return 0;
		}
		//Test<int> m;
};
void ttt()
{

		class local{
			static void f(){

			}//还是和普通函数一样只是对函数有了修饰
			//static int loc;//局部中不可以
		};
		int i;
		
		void f();//在函数中可以声明，但不可以有实现体,在任何地方的函数都一样
		//但不可以声明一个静态函数
		//static void ddd();

}
int main(){
	Test::testchild m;
	m.f();
	//类里面可以定义类，调用方法可调用静态一样使用::,
	//operator int()实际上就是强制转换类型,并且只能是类成员函数
	return 0;
}
