/*************************************************************************
    > File Name: mysql_test.cpp
    > Author: 刘建飞
    > Mail: liujianfei526@163.com 
    > Created Time: 2016年01月12日 星期二 19时26分38秒
 ************************************************************************/

#include<iostream>
#include<mysql/mysql.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
char tmp[400];
int main()
{
	MYSQL* mysql;
	int rt;
	MYSQL_RES *res;
	MYSQL_ROW row;
	//mysql_init(&mysql);
	mysql = mysql_init((MYSQL*) 0);
	cout<<"mysql is running"<<endl;
    string str="asd";
	if(!mysql_real_connect(mysql, "localhost", "root", "ict", "ipv6_web", 3306, NULL, 0))
	{
		printf("error\n");
	}
	else
	{
		printf("sucess\n");
	}
	int id=0;
	 //"insert into t1 (id, name) values (1, 'java1');";
	sprintf(tmp,"insert into test_info (id,type) values (%d,\"%s\");",id,str.c_str()); 
	//mysql_query(mysql, tmp);
	printf("%s\n",tmp);
	//rt=mysql_real_query(mysql,tmp,strlen(tmp));
	//if(rt)
	{
	 //  printf("Error making query: %s !!!\n",mysql_error(mysql));
	} 
	sprintf(tmp,"select * from %s","test_info");
	rt=mysql_real_query(mysql,tmp,strlen(tmp));
	res = mysql_store_result(mysql);//将结果保存在res结构体中
	while(row = mysql_fetch_row(res)) 
	{
		for(int t=0;t<mysql_num_fields(res);t++)  
		{
			printf("%s  ",row[t]);
			//printf("sucess\n");
		}
		printf("\n");
	}
	mysql_free_result(res); 
	mysql_close(mysql);
	return 0;
}
