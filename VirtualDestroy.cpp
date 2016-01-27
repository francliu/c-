/*************************************************************************
    > File Name: template.cpp
    > Author: 刘建飞
    > Mail: liujianfei526@163.com 
    > Created Time: 2016年01月22日 星期五 19时52分44秒
 ************************************************************************/

#include<iostream>
using namespace std;
struct Test{
	int a;
	int b;
	Test(){}
	Test(int i){
		a=i;
	}
	virtual void f(){
		cout<<"基类"<<endl;
	}
	virtual ~Test()
	{
		cout<<"基类"<<endl;
	}
};
class mumble:public Test
{

	public:
		mumble(){

		}
	    operator int() // 问题在此只能是非静态成员函数
		{
			cout << "mumble::operator int() is called." << endl;
			return 0;
		}
		virtual void f(){
			cout<<"派生类"<<endl;
		}
		~mumble(){
			cout<<"mumble"<<endl;
		}
		int c,d;
};
//基类如果不加virtual,就执行基类虚析构函数
//基类如果加virtual,就执行自身的析构函数
int main(){
	Test *t = new mumble();
	cout<<sizeof(t)<<sizeof(*t)<<endl;
	t->f();
	delete t;//如果不主动删除指针，之后程序完全退出之后才收会内存
	return 0;
}
