/*************************************************************************
    > File Name: extern.h
    > Author: 刘建飞
    > Mail: liujianfei526@163.com 
    > Created Time: 2016年01月24日 星期日 17时48分23秒
 ************************************************************************/

#include<iostream>
using namespace std;
extern int extern_temp;
int fun()
{
	cout<<extern_temp<<endl;
}
