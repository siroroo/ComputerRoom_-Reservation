#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include "Identity.h"
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"

//进入学生子菜单界面
void studentMenu(Identity*& student)
{
	while (true)
	{
		student->operMenu();		//调用学生子菜单
		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;				//接受用户选择
		if (select == 1)			//申请预约
		{
			stu->applyOrder();
		}
		else if (select == 2)		//查看自身预约
		{
			stu->showMyOrder();
		}
		else if (select == 3)		//查看所有人预约
		{
			stu->showAllOrder();
		}
		else if (select == 4) //取消预约
		{
			stu->cancelOrder();
		}
		else
		{
			//注销登录
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入教师子菜单界面
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->operMenu();
		Teacher* tea = (Teacher*)teacher;
		int select = 0;			//接受用户选择
		cin >> select;
		if (select == 1)		//查看所有预约
		{
			tea->showAllOrder();
		}
		else if (select == 2)	//审核预约
		{
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入管理员子菜单界面
void managerMenu(Identity*& manager)
{
	while (true)
	{
		manager->operMenu();				//调用管理员子菜单
		Manager* man = (Manager*)manager;	//将父类指针 转为子类指针，调用子类里其他接口
		int select = 0;
		cin >> select;						//接受用户选项
		if (select == 1)					//添加账号
		{
			//cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2)				//查看账号
		{
			//cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3)				//查看机房
		{
			//cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4)				//清空预约
		{
			//cout << "清空预约" << endl;
			man->cleanFile();
		}
		else
		{
			//注销
			delete manager;					//销毁掉堆区对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//封装的 学生/老师 登录函数
//登录功能          操作文件名    操作身份类型
void LoginIn(string fileName, int type)
{
	Identity* person = NULL;			//父类指针 ，用于指向子类对象
	ifstream ifs;						//读文件
	ifs.open(fileName, ios::in);
	if (!ifs.is_open())					//判断文件是否存在
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	int id = 0;
	string name;
	string pwd;
	//判断身份
	if (type == 1)							//学生身份
	{
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2)						//教师身份
	{
		cout << "请输入您的职工号： " << endl;
		cin >> id;
	}

	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//学生身份验证
		int fId;			//从文件中读取的id号
		string fName;		//获取姓名
		string fPwd;		//获取密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//cout << fId << endl << fName << endl << fPwd << endl;		//验证
			if (fId == id && fName == name && fPwd == pwd)				//信息对比
			{
				cout << "学生登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				studentMenu(person);	//进入学生子菜单
				return;
			}
		}
	}
	else if (type == 2)
	{
		//教师身份验证
		int fId;			//从文件中读取的id号
		string fName;		//获取姓名
		string fPwd;		//获取密码
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)				//信息对比
			{
				cout << "教师验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				teacherMenu(person);	//进入教师子菜单
				return;
			}
		}

	}
	else if (type == 3)
	{
		//管理员身份验证
		string fName;		//获取姓名
		string fPwd;		//获取密码
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "管理员验证登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				managerMenu(person);	//进入管理员子菜单界面
				return;
			}
		}

	}
	cout << "验证登录失败！" << endl;
	system("pause");
	system("cls");
	return;
}

int main()
{
	int select = 0; //用于接受用户的选择

	while (true)
	{
		cout << "======================  欢迎来到传智播客机房预约系统  ====================="
			<< endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";

		cin >> select; //接受用户选择

		switch (select) //根据用户选择 实现不同接口
		{
		case 1: //学生身份
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2: //老师身份
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:  //管理员身份
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:  //退出系统
			cout << "欢迎下一次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}




	system("pause");
	return 0;
}