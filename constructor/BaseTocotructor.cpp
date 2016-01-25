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
			b=9;
			//h='d';
		}
	int b;
	char h;
};
class A:public B{
	public:
		//A(){a=0,str="c";}
		A& operator=(A &f){
			//str = c;
			return f;
		}
	
		int a;
		char* str;
};
int main()
{
	A c;
	c.a=9;
	cout<<c.a<<endl;
	//默认构造函数只有在编译器需要的时候才会生成，
	//故未对ｃ进行初始化操作，因为不满足编译器合成构造函数的四个条件
	//2.构造函数继承的基类，且该基类也含有默认构造函数
	//c.t.c=2;
	//c.t.b=9;
	//可是为什么声明顺序不一样结果也不一样了？
	cout<<c.b<<c.h<<endl;
	//A d=c;
	//cout<<d.a<<d.str<<endl;
	cout<<c.a<<c.str<<endl;
}
