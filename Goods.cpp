#include "Goods.h"

Goods::Goods(string id, string n, float ip, float op, float gp, string gpr, string b, string t)
{
	gId = id;
	gName = n;
	iPrice = ip;
	oPrice = op;
	gRepertory = gp;
	gProducer = gpr;
	gBrand = b;
	gType = t;
}

void Goods::Introduce()
{
	cout << "商品基类" << endl;
}

string Goods::getGid()
{
	return gId;
}

string Goods::getGname()
{
	return gName;
}

float Goods::getGip()
{
	return iPrice;
}

float Goods::getGop()
{
	return oPrice;
}

float Goods::getRepertory()
{
	return gRepertory;
}

string Goods::getProducer()
{
	return gProducer;
}

string Goods::getBrand()
{
	return gBrand;
}

string Goods::getType()
{
	return gType;
}

void Goods::setRepertory(double x)
{
	gRepertory = x;
}

void Goods::setName(string n)
{
	gName = n;
}

void Goods::setIP(float p)
{
	iPrice = p;
}

void Goods::setOP(float p)
{
	oPrice = p;
}

void Goods::setProducer(string p)
{
	gProducer = p;
}

void Goods::setBrand(string p)
{
	gBrand = p;
}