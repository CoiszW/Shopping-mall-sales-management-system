#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<iostream>
#include<fstream>
#include<Windows.h>
#include<vector>
#include<iomanip>
#include<ctime>
#include"gForm.h"
using namespace std;


//员工类
class UserStaff
{
private:
	//存储购物车信息
	vector<Goods*> shopping_Cart;
	//存储购物车中商品的出售数量
	vector<float> Cart_sum;
	//售卖商品
	void SellGoods();
	//存储商品临时库存
	vector<double> tempRep;

protected:
	string UserName;
	string UserId;
	string UserCode;
	string UserLevel;
	//存储商品信息
	vector<Goods*> goods_vector;

public:
	//含参构造函数
	UserStaff(string n, string id, string code, string level);
	//析构函数
	~UserStaff();

	string getName();
	string getId();
	string getCode();
	string getLevel();

	//获取系统当前时间
	string GetTime();
	//虚函数，员工菜单界面
	virtual bool Menu();
};