#pragma once
#include"UserAdm.h"


//������
class Market
{
private:
	//��������ָ�룬�ֱ��ӦԱ���͹���Ա�Ĺ���
	UserStaff* user1;
	UserAdm* user2;
public:
	//���캯������ʼ������ָ��
	Market();
	//��������
	~Market();
	//���˵�����
	void Menu();
};