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
		//B(){}
		
		B(const char i):h(i){
		    //b=9;
		 	//h='d';
		}
		
	int b;
	const char h;
};//常量类成员只能使用初始化列表实现，不能在实现体内复制。
//且常量必须被初始化。
class A{
	public:
		//A(){a=0,str="c";}
		A& operator=(A &f){
			//str = c;
			return f;
		}
	
		int a;
		char* str;
		B t;
};
int main()
{
	B *hhh=new B('c');
	//cout<<hhh->b<<hhh->h<<endl;
	cout<<hhh->b<<hhh->h<<endl;
	//const int val;
	/**
	A c;//编译器不会声明且调用默认构造函数。
	c.a=9;
	cout<<c.a<<endl;
	//默认构造函数只有在编译器需要的时候才会生成，
	//故未对ｃ进行初始化操作，因为不满足编译器合成构造函数的四个条件
	//1.构造函数必须含有类对象，且该该对象也含有默认构造函数
	//c.t.c=2;
	//c.t.b=9;
	//可是为什么声明顺序不一样结果也不一样了？
	cout<<c.t.b<<c.t.b<<endl;
	A d=c;
	cout<<d.a<<d.str<<endl;
	cout<<c.a<<c.str<<endl;
	*/
}
