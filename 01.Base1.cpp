//理解顶层const与底层const
#include<iostream>
/*
参考文献：c++primer P58
当执行对象拷贝的时候，常量的顶层const不受影响
而底层const必须保持一致

一般来说，顶层const限制的是该变量的属性，即该变量
不能修改，而底层const通常出现在指针的身上，它一般
限制的是指针指向的那段空间的属性，表示被指向的那段空间不能
被修改
*/
/*
规则：
1.引用不是对象进行拷贝，不满足上述规则
2.常量引用如果在左侧，右侧可以接任何的东西
3.非常量引用=常量   报错
4.引用如果在等号右侧，请忽略&
5.非常量=常量引用   不报错
*/

int main()
{
	
	const int a = 10;  //该const为顶层const
	//a = 20;      //error ,不可被修改
	int b = a; //进行拷贝的时候顶层const被忽略
	const int* const p = &b; //第一个const是底层const,第二个const是顶层const
	//int*p1=&a error ,当顶层const的变量被取地址后该const会变成底层const
	const int* p2 = &a;
	const int& t = a;//底层const,这句可以这么理解：t是a的别名，a是一个常量，不能被修改，所以t必须加上const
	const int& t1 = 5;
	/*
	const int temp=5;
	const int &t1=temp;
	*/
	int c = t1;  //忽略&,即该表达式等价于 int c=const int t1
	return 0;
}