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
	Test(){
	   cout<<"基类"<<endl;
	}
	Test(int i){
		a=i;
	}
	/**
	virtual void f(){
		cout<<"Test f(0)"<<endl;
	}*/
	virtual ~Test()
	{
		cout<<"~基类"<<endl;
	}
};
class mumble:public Test
{

	public:
		mumble(){
			cout<<"mumble"<<endl;
		}
		/**
	    operator int() // 问题在此只能是非静态成员函数
		{
			cout << "mumble::operator int() is called." << endl;
			return 0;
		}
		virtual void f(){
			cout<<"派生类"<<endl;
		}
		*/
		~mumble(){
			cout<<"~mumble"<<endl;
		}
		int c,d;
};
class T{
	public:
	int a;
	int b;
	T(){
	   cout<<"基类"<<endl;
	}
	~T(){
	   cout<<"~基类"<<endl;
	}
};
//基类如果不加virtual,就执行基类虚析构函数
//基类如果加virtual,就执行自身的析构函数
int main(){
	/**
	Test *t = new mumble();
	cout<<sizeof(t)<<sizeof(*t)<<endl;
	t->f();
	delete t;//如果不主动删除指针，之后程序完全退出之后才收会内存
	
	Test b;
	b.f();
	b.~Test();
	new (&b)mumble;
	b.f();
	
	Test *h = new Test;
	cout<<"ok"<<endl;
	h->f();
	cout<<"ok"<<endl;
	h->~Test();//当要再一次使用该地址时，必须首先调用上一个该地址所指对象的析构函数
	new (h)mumble;
	h->f();
	*/
	//可以看出只有指针才可以实现多态
	//Test g[10];
	/**
	Test *e=new Test[10];
	delete []e;
	*/
	Test *f=new mumble;
	cout<<"ok"<<endl;
	//delete []f;//错误
	delete f;
	/**
	for(int i=0;i<2;++i)
	{
		mumble *m=&((mumble*)f)[i];
		delete m;
	}
	*/
	T i;
	i.~T();//管你有没有我都能调用
	void *p = new T;
	delete p;
	//定义一个对象指针时，不管有没有构造函数，都不会调用该类的构造函数。
	/**
	Test *j;//没有调用构造函数
	cout<<"ok"<<endl;
	mumble l;
	cout<<"ok"<<endl;
	Test k=l;
	*/
	return 0;
}
