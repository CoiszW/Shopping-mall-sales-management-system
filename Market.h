#pragma once
#include"UserAdm.h"


//超市类
class Market
{
private:
	//两种类型指针，分别对应员工和管理员的功能
	UserStaff* user1;
	UserAdm* user2;
public:
	//构造函数，初始化两个指针
	Market();
	//析构函数
	~Market();
	//主菜单界面
	void Menu();
};