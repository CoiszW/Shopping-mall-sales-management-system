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


//Ա����
class UserStaff
{
private:
	//�洢���ﳵ��Ϣ
	vector<Goods*> shopping_Cart;
	//�洢���ﳵ����Ʒ�ĳ�������
	vector<float> Cart_sum;
	//������Ʒ
	void SellGoods();
	//�洢��Ʒ��ʱ���
	vector<double> tempRep;

protected:
	string UserName;
	string UserId;
	string UserCode;
	string UserLevel;
	//�洢��Ʒ��Ϣ
	vector<Goods*> goods_vector;

public:
	//���ι��캯��
	UserStaff(string n, string id, string code, string level);
	//��������
	~UserStaff();

	string getName();
	string getId();
	string getCode();
	string getLevel();

	//��ȡϵͳ��ǰʱ��
	string GetTime();
	//�麯����Ա���˵�����
	virtual bool Menu();
};