#pragma once
#include <iostream>
using namespace std;
#include "globalFile.h"
#include <fstream>
#include <map>
#include <string>

class OrderFile
{
public:
	OrderFile();
	void updateOrder();	//����ԤԼ��¼
	int m_Size;			//��¼ԤԼ����
	map<int, map<string, string>> m_orderData;	//��¼����ԤԼ��Ϣ������  key��¼����   value �����¼��ֵ����Ϣ

};
