/*************************************************************************
    > File Name: template.cpp
    > Author: 刘建飞
    > Mail: liujianfei526@163.com 
    > Created Time: 2016年01月22日 星期五 19时52分44秒
 ************************************************************************/

#include<iostream>
using namespace std;
namespace A
{
int j;
class mumble
{

	public:
		mumble(){

			cout<<"mumble"<<endl;
		}
		~mumble(){
			cout<<"mumble"<<endl;
		}
		int c,d;
};
}
namespace B
{
int j;
class mumble
{

	public:
		mumble(){
			cout<<"mumble"<<endl;

		}
		~mumble(){
			cout<<"mumble"<<endl;
		}
		int c,d;
};
}
/**
using namespace A;
using namespace B;
*/
//命名空间实际上就是为了解决命名冲突而引入的
//以下就会发生二义性,一般在使用时发生冲突
using A::mumble;
//但使用using声明，就可以避免二义性，因为声明只可以发生一次，当再一次发生时，编译不能通过
//不要随意的在头文件中引入using namespace XXX
//可能最终会引起二义性的情况发生.
int main(){
	mumble *t = new mumble();
	return 0;
}
