#pragma once
#include"UserStaff.h"


//����Ա�࣬Ա���������
class UserAdm :public UserStaff
{
private:

public:
	UserAdm(string n, string id, string code, string level);
	~UserAdm();

	//��ӳ�Ա
	void addUser();
	//����
	void Stock_menu();
	//�鿴�˵�
	void LookBills();
	//�鿴��Ʒ
	void LookGoods();
	//�޸���Ʒ��Ϣ
	void Modify();


	//�̳л����麯������ʾ����Ա����
	bool Menu();
};