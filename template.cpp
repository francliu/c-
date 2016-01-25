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
	 int a=2;
	 void f()
	 {
		 cout<<"我是testchild"<<endl;
	 }
	};
	Test operator=(const Test &p)
	{
		this.a=p.a;
		return this;
	}
};
/**
Test<int> operator==(const Test<int> &p2)
{
	return p2;
}
*/
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
int main(){
	//类里面可以定义类，调用方法可调用静态一样使用::,
	//operator int()实际上就是强制转换类型,并且只能是类成员函数
	Test<int> t(1);
	mumble mum;
	Test<int>::testchild ch;
	ch.a=9;
	ch.f();
	cout<<ch.a<<endl;
	int a=mum;
	int b=mum.operator int();
	//int temp = cin.operator int();
	//temp<<a;
	//cin<<a;
	Test<int> *m=&t;
	Test<int> n(t);
	//int *in=&t;
	bool *f;
	int e=0;
	int &g=e;
	cout<<sizeof(m)<<sizeof(n)<<sizeof(f)<<sizeof(g);
	Test<int> p=t;
	cout<<p.a<<n.a<<endl;
	return 0;
}
