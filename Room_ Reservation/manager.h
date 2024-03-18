#pragma once
#include <iostream>
using namespace std;
#include "Identity.h"
#include <string>
#include <fstream>
#include "globalFile.h"
#include <vector>
#include "student.h"
#include "teacher.h"
#include <algorithm>
#include "computerRoom.h"

class Manager :public Identity
{
public:
	Manager();
	Manager(string name, string pwd);	//有参构造(账号密码）
	virtual void operMenu();	//菜单界面
	void addPerson();			//添加账号
	void showPerson();			//查看账号
	void showComputer();		//查看机房信息
	void cleanFile();			//清空预约记录
	void initVector();			//初始化容器
	bool checkRepeat(int id, int type);	//检测重复 参数1 检测学号/职工号  参数2  检测类型
	vector<Student>vStu;		//学生容器
	vector<Teacher>vTea;		//教师容器
	vector<ComputerRoom>vCom;	//机房信息容器
};