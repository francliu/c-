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
//当项目中引入多个同一文件时，必须使用预处理命令处理，否则会发生因多次声明，引起的编译错误
class mumble
{

	public:
		mumble(){

		}
		~mumble(){
			cout<<"mumble"<<endl;
		}
		int c,d;
}test;
int main(){
	return 0;
}
