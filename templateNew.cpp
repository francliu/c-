/*************************************************************************
    > File Name: template.cpp
    > Author: 刘建飞
    > Mail: liujianfei526@163.com 
    > Created Time: 2016年01月22日 星期五 19时52分44秒
 ************************************************************************/

#include<iostream>
#include "haha.h"
#include "const.h"
using namespace std;
template<class type>
class mumble
{

	public:
		mumble(){

		}
	    type val(){
			if(i!=102992)
			{
				return i;
			}
		}
		void val(type v);
		~mumble(){
			cout<<"mumble"<<endl;
		}
		type i;
		int c,d;
};
/**
template<class type>
double mumble<type>::bogus_member(){
	return this->bdx;
}
*/
//基类如果不加virtual,就执行基类虚析构函数
//基类如果加virtual,就执行自身的析构函数
int main(){
	return 0;
}
