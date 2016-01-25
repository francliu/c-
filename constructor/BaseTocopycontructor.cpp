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
		//	b=9;
		//	h='d';
		}
		//B(B &t)
		//{
		//	b=3;
		//	h='c';
		//}
	int b;
	char h;
};
class A:public B{
	public:
		A(){a=0,str="c";}
		A(A &f){
			//str = c;
		//	return f;
		}
	
		int a;
		char* str;
};
int main()
{
	A c;
	c.a=9;
	c.str="stsssr";
	c.b=6;
	c.h='d';
	cout<<c.a<<c.str<<endl;
	cout<<c.b<<c.h<<endl;
	//默认复制构造函数只有在编译器需要的时候才会生成，
	//故未对ｃ进行初始化操作，因为不满足编译器合成构造函数的四个条件
	//2.复制构造函数继承基类，且该基类也含有复制构造函数
	//编译器就会合成复制构造函数，且调用基类的构造函数
	//可是为什么声明顺序不一样结果也不一样了？
	A d=c;
	cout<<d.a<<d.str<<endl;
	cout<<d.b<<d.h<<endl;
	/**
	c.b=7;
	c.h='h';
	cout<<c.b<<c.h<<endl;
	cout<<d.a<<d.str<<endl;
	cout<<d.b<<d.h<<endl;
	*/
}
