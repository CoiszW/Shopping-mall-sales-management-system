#pragma once
#include<string>
#include<iostream>
#include<iomanip>
using namespace std;


//��Ʒ��
class Goods
{
protected:
	//��Ʒ���
	string gId;
	//��Ʒ����
	string gName;
	//����
	float iPrice;
	//�ۼ�
	float oPrice;
	//���
	float gRepertory;
	//������
	string gProducer;
	//Ʒ��
	string gBrand;
	//����
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

	//�趨���
	void setRepertory(double x);
	//�޸�����
	void setName(string n);
	// �޸Ľ���
	void setIP(float p);
	// �޸��ۼ�
	void setOP(float p);
	// �޸�������
	void setProducer(string p);
	// �޸�Ʒ��
	void setBrand(string p);
};