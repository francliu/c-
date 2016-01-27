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
	int k;
	public:
	Test(){}
	Test(int i){
		cout<<"frined"<<endl;
		//t=i;
		cout<<m<<endl;
	}
	int m;
	class mumble;
	friend mumble;
	friend void fun();
};
//静态数据在未使用前不定义也可以编译通过，但一旦要使用，则必须首先定义。
//友员函数可以访问类里的函数以及静态数据，但不能访问非静态数据，因为不存在。
int Test::t=9;
void fun(){
	cout<<Test::t<<endl;
}
class mumble
{
	public:
		mumble(){
			Test(1);
			//cout<<m<<endl;
		}
	    operator int() // 问题在此只能是非静态成员函数
		{
			cout << "mumble::operator int() is called." << endl;
			return 0;
		}
};
int main(){
	Test m;
	mumble k;
	fun();
	//类里面可以定义类，调用方法可调用静态一样使用::,
	//operator int()实际上就是强制转换类型,并且只能是类成员函数
	return 0;
}
