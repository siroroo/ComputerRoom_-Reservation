#pragma once 
#include <iostream>
using namespace std;

//身份 抽象 基 类	包含  纯虚函数  的类为抽象类
class Identity
{
public:

	virtual void operMenu() = 0;	//纯虚函数 子类必须重写
	string m_Name;		//用户名
	string m_Pwd;		//密码
};