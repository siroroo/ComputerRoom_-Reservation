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
	Student(int id, string name, string pwd);		//�вι���  ������ѧ�š��û���������
	virtual void operMenu();	//�˵�����  �麯��   �̳е�Identity�Ĵ��麯��
	void applyOrder();			//����ԤԼ
	void showMyOrder();			//�鿴����ԤԼ
	void showAllOrder();		//�鿴����ԤԼ
	void cancelOrder();			//ȡ��ԤԼ
	int m_Id;					//ѧ��ѧ��
	vector<ComputerRoom> vCom;	//��������
};