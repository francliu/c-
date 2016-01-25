/*************************************************************************
    > File Name: contructor.cpp
    > Author: 刘建飞
    > Mail: liujianfei526@163.com 
    > Created Time: 2016年01月23日 星期六 11时30分19秒
 ************************************************************************/

#include<iostream>
#include <assert.h>
using namespace std;
class A{
  
};
class B:public virtual A{

};
class C:public virtual A{

};
class D:public C,public B{

};
typedef int length;
//类型声名防御
//如果把typedef float length;放在类中间或后面，回引发类型声明使用冲突
//因为把同名类型在外部已经声明
extern length _val;
class P{
	public:
		void mumble(length val){
			_val=val;
		}
		//typedef float length;
		length mumble(){
			return _val;
		}
		//以下是错误行为应该放在使用该声明之前
		//typedef float length;
	private:
		length _val;
};
class Point{
	public:
		float x;
	public:
		float y;
	public:
		float z;
		/**
		bool operator<(Point *A)
		{
			if(this<A)return true;
			return false;
		}
		*/
};
template<class class_type,
		 class data_type1,
		 class data_type2>
char * access_order(data_type1 class_type::*mem1,data_type2 class_type::*mem2){
	assert(mem1!=mem2);
	return mem1 < mem2?"member 1":"member2";
}
class E{
  public:
		E(){}
		E(int i,char j)
		{
			this->a=i;
			this->m=j;
			cout<<a<<m<<endl;
		}
		void get()
		{
			cout<<this->a<<"---"<<this->m<<endl;
		}
	protected:
		int getA()
		{
			cout<<a<<endl;
			return a;
		}
  private:
	int a;
	char m;
};
class F:public E{
  public:
	F(){}
	F(int i,char j){
		E(i,j);
		get();
		getA();
	}
	char n;
	void f(){
		cout<<getA()<<endl;
	}
};
class G:private F{
	public:
   G(){}
   G(int i,char j){
	   F(i,j);
	   f();
   }
   public:
    	char j;
};
//复制构造函数一旦声明，就必须同时声明构造函数，以免没法实例化
//类的实例化只可以访问public成员
//private成员只能在当前类里面访问,即使是派生类都不能使用
//使用protected成员也不能被类实例化成员访问，只能在被派生类中使用
//默认情况下是私有继承,以及私有成员
int main()
{
	int aa;
	G gg;
	F ff(1,'c');
	//ff.getA();
	//ff.get();
	E ee;
	//ee.getA();
	cout<<ff.n<<endl;
	ff.f();
	cout<<sizeof(ee)<<sizeof(ff)<<sizeof(gg)<<endl;
	//access_order(&Point::z,&Point::y);
	cout<<sizeof(A)<<sizeof(B)<<sizeof(C)<<sizeof(D)<<endl;
}
