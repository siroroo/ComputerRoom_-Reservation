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
	Manager(string name, string pwd);	//�вι���(�˺����룩
	virtual void operMenu();	//�˵�����
	void addPerson();			//����˺�
	void showPerson();			//�鿴�˺�
	void showComputer();		//�鿴������Ϣ
	void cleanFile();			//���ԤԼ��¼
	void initVector();			//��ʼ������
	bool checkRepeat(int id, int type);	//����ظ� ����1 ���ѧ��/ְ����  ����2  �������
	vector<Student>vStu;		//ѧ������
	vector<Teacher>vTea;		//��ʦ����
	vector<ComputerRoom>vCom;	//������Ϣ����
};