#pragma once
#include<string>
#include<iostream>
#include<iomanip>
using namespace std;


//商品类
class Goods
{
protected:
	//商品编号
	string gId;
	//商品名称
	string gName;
	//进价
	float iPrice;
	//售价
	float oPrice;
	//库存
	float gRepertory;
	//生产商
	string gProducer;
	//品牌
	string gBrand;
	//类型
	string gType;
public:
	Goods(string id, string n, float ip, float op, float gp, string gpr, string b, string t);
	virtual void Introduce();

	string getGid();
	string getGname();
	float getGip();
	float getGop();
	float getRepertory();
	string getProducer();
	string getBrand();
	string getType();

	//设定库存
	void setRepertory(double x);
	//修改名称
	void setName(string n);
	// 修改进价
	void setIP(float p);
	// 修改售价
	void setOP(float p);
	// 修改生产商
	void setProducer(string p);
	// 修改品牌
	void setBrand(string p);
};