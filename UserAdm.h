#pragma once
#include"UserStaff.h"


//管理员类，员工类的子类
class UserAdm :public UserStaff
{
private:

public:
	UserAdm(string n, string id, string code, string level);
	~UserAdm();

	//添加成员
	void addUser();
	//进货
	void Stock_menu();
	//查看账单
	void LookBills();
	//查看商品
	void LookGoods();
	//修改商品信息
	void Modify();


	//继承基类虚函数，显示管理员界面
	bool Menu();
};