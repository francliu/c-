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
			f();
		}
		B(B &t)
		{
			b=3;
			//h='c';
		}
		virtual void f(){
			cout<<"haha"<<endl;
		}
	int b;
	char h;
};
class A:public B{
	public:
		A(){}
		A(int i):b(i){
			a=b;
		}
		A(char *c){
			str = c;
		//	return f;
		}
	    
		int a;
		int b;
		char* str;
		B t;
};
class D{

};
class C:public virtual D{

};
int main()
{
	A c(0);
	int aa;
	cout<<sizeof(aa)<<sizeof(C)<<sizeof(D)<<endl;
	C CCC;
	cout<<sizeof(CCC)<<endl;
	//B *BBB=&c;//同一指针只能指向其自身类型或派生类
	//B BBB;
	//A *AAA=BBB;//同一指针派生类不能指向基类
	//c.a=9;
	c.str="stsssr";
	c.t.b=6;
	c.t.h='d';
	cout<<c.a<<c.str<<endl;
	cout<<c.t.b<<c.t.h<<endl;
	//默认复制构造函数只有在编译器需要的时候才会生成，
	//故未对ｃ进行初始化操作，因为不满足编译器合成构造函数的四个条件
	//1.复制构造函数必须含有类对象，且该该对象也含有默认复制构造函数
	//可是为什么声明顺序不一样结果也不一样了？
	
	A d=c;//调用的是复制构造函数，不是赋值构造函数
	//下面的是赋值构造函数，两者不同
	A fffff;
	fffff=c;
	//d.A::A();
	cout<<d.a<<d.str<<endl;
	cout<<d.t.b<<d.t.h<<endl;
	/**
	c.t.b=7;
	c.t.h='h';
	cout<<c.t.b<<c.t.h<<endl;
	cout<<d.a<<d.str<<endl;
	cout<<d.t.b<<d.t.h<<endl;
	*/
}
