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
	Teacher(int empId, string name, string pwd);	//�вι���  ְ���� �û��� ����
	virtual void operMenu();	//�˵�����
	void showAllOrder();		//�鿴ѧ����ԤԼ
	void validOrder();			//���ԤԼ
	int m_EmpId;				//ְ����
};