#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"
#include <string>
#include <vector>
#include "computerRoom.h"
#include <fstream>
#include "globalFile.h"
#include "orderFile.h"

class Student : public Identity
{
public:
	Student();
	Student(int id, string name, string pwd);		//有参构造  参数：学号、用户名、密码
	virtual void operMenu();	//菜单界面  虚函数   继承的Identity的纯虚函数
	void applyOrder();			//申请预约
	void showMyOrder();			//查看自身预约
	void showAllOrder();		//查看所有预约
	void cancelOrder();			//取消预约
	int m_Id;					//学生学号
	vector<ComputerRoom> vCom;	//机房容器
};