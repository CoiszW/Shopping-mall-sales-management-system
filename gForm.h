#pragma once
#include"Goods.h"

class Food :public Goods
{
public:
	Food(string id, string n, float ip, float op, float gp, string gpr, string b, string t);
	void Introduce();
};


class Clothes :public Goods
{
public:
	Clothes(string id, string n, float ip, float op, float gp, string gpr, string b, string t);
	void Introduce();
};


class Daily :public Goods
{
public:
	Daily(string id, string n, float ip, float op, float gp, string gpr, string b, string t);
	void Introduce();
};


class Tools :public Goods
{
public:
	Tools(string id, string n, float ip, float op, float gp, string gpr, string b, string t);
	void Introduce();
};


class Others :public Goods
{
public:
	Others(string id, string n, float ip, float op, float gp, string gpr, string b, string t);
	void Introduce();
};