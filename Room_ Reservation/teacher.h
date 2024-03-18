#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"
#include <string>
#include "orderFile.h"
#include <vector>

class Teacher :public Identity
{
public:
	Teacher();
	Teacher(int empId, string name, string pwd);	//有参构造  职工号 用户名 密码
	virtual void operMenu();	//菜单界面
	void showAllOrder();		//查看学生的预约
	void validOrder();			//审核预约
	int m_EmpId;				//职工号
};