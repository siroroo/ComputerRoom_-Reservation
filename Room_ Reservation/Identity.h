#pragma once 
#include <iostream>
using namespace std;

//��� ���� �� ��	����  ���麯��  ����Ϊ������
class Identity
{
public:

	virtual void operMenu() = 0;	//���麯�� ���������д
	string m_Name;		//�û���
	string m_Pwd;		//����
};