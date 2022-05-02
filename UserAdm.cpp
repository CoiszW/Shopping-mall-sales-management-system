#include"UserAdm.h"

UserAdm::UserAdm(string n, string id, string code, string level) :UserStaff(n, id, code, level)
{

}

UserAdm::~UserAdm()
{

}

void UserAdm::addUser()
{
	bool flag = false;

	ofstream f;
	f.open("Users.txt", ios::app);
	ifstream f1;
	f1.open("Users.txt");

	string n, id, code, level;
	string n1, id1, code1, level1;
	cout << "����������";
	cin >> n;
	cout << "�����˺ţ�";
	cin >> id;
	if (id == "Null")
	{
		cout << "�˺��������" << endl;
		flag = true;
		for (int i = 0; i < 6; i++)
		{
			cout << ".";
			Sleep(250);
		}
	}
	while (!f1.eof())
	{
		f1 >> n1 >> id1 >> code1 >> level1;
		if (id1 == id)
		{
			cout << "�˺��Ѵ��ڣ�" << endl;
			flag = true;
			for (int i = 0; i < 6; i++)
			{
				cout << ".";
				Sleep(250);
			}
		}
	}

	if (flag == false)
	{
		cout << "�������룺";
		cin >> code;
		cout << "����Ȩ�޵ȼ�������Ա\\Ա������";
		cin >> level;
	}

	f << n << "\t\t" << id << "\t\t" << code << "\t\t" << level << "\n";
}

void UserAdm::LookBills()
{
	system("cls");
	string time1, time2, name, id, gname;
	double price, num, money;
	ifstream f;
	f.open("Bills.txt");

	cout << "ʱ��\t\t\t\t" << "����\t\t" << "��Ʒ���\t"
		<< "��Ʒ����\t" << "�ۼ�\t" << "��������\t" << "���" << endl;
	while (!f.eof())
	{
		f >> time1 >> time2 >> name >> id >> gname >> price >> num >> money;
		cout << time1 << "  " << time2 << "\t\t" << name << "\t\t" << id << "\t\t"
			<< gname << "\t\t" << price << "\t" << num << "\t\t" << money << endl;
	}
	char c;
	cout << "�������������" << endl;
	cin.ignore();
	c = getchar();
}

void UserAdm::Stock_menu()
{
	while (true)
	{
		system("cls");
		cout << "���\t" << "����\t" << "����\t" << "�ۼ�\t" << "���\t" << endl;
		int n = goods_vector.size();
		for (int i = 0; i < n; i++)
		{
			cout << goods_vector[i]->getGid() << "\t"
				<< goods_vector[i]->getGname() << "\t"
				<< goods_vector[i]->getGip() << "\t"
				<< goods_vector[i]->getGop() << "\t"
				<< goods_vector[i]->getRepertory() << endl;
		}

		int op;
		cout << endl;
		cout << "1.����������Ʒ" << endl;
		cout << "2.�������Ʒ" << endl;
		cout << "0.����������" << endl;
		cout << "�����룺";
		cin >> op;

		string id;
		int j;
		float increase;
		//flag0�жϱ���Ƿ�������ȷ
		bool flag0 = false;
		//flag1�ж��Ƿ��˳�����
		bool flag1 = false;
		//flag2�ж�������Ʒ��Ϣ�����Ƿ���ȷ
		bool flag2 = false;

		string Id, Name, Producer, Brand, Type;
		float iPrice, oPrice, Rep;
		Goods* temp;

		switch (op)
		{
		case 1:
			cout << "������Ʒ��ţ�";
			cin >> id;
			for (j = 0; j < n; j++)
			{
				if (id == goods_vector[j]->getGid())
				{
					flag0 = true;
					break;
				}
			}
			if (flag0 == true)
			{
				cout << "��Ʒ��" << goods_vector[j]->getGname() << "\t����������";
				cin >> increase;
				goods_vector[j]->setRepertory(goods_vector[j]->getRepertory() + increase);
			}
			else
			{
				cout << "����������" << endl;
				for (int i = 0; i < 3; i++)
				{
					cout << ".";
					Sleep(250);
				}
			}
			break;
		case 2:
			cout << "������Ʒ���ͣ�ʳƷ�ࡢ��װ�ࡢ����Ʒ�ࡢ�����ࡢ�����ࣩ��";
			cin >> Type;

			//�ж������Ƿ�������ȷ
			if (Type == "ʳƷ��" || Type == "��װ��" || Type == "����Ʒ��" || Type == "������" || Type == "������")
			{
				flag2 = true;
			}
			else
			{
				cout << "�����������" << endl;
				for (int i = 0; i < 3; i++)
				{
					cout << ".";
					Sleep(250);
				}
				break;
			}

			if (flag2 == true)
			{
				cout << "������Ʒ��ţ�";
				cin >> Id;

				//��Ų���ΪNull��Clear
				if (Id == "Null" || Id == "Clear")
				{
					cout << "����������" << endl;
					for (int i = 0; i < 3; i++)
					{
						cout << ".";
						Sleep(250);
					}
					flag2 = false;
					break;
				}

				//�жϱ���Ƿ��ظ�
				for (int i = 0; i < n; i++)
				{
					if (Id == goods_vector[i]->getGid())
					{
						cout << "����ظ���" << endl;
						for (int i = 0; i < 3; i++)
						{
							cout << ".";
							Sleep(250);
						}
						flag2 = false;
						break;
					}
				}

				if (flag2 == false)
				{
					break;
				}
			}

			if (flag2 == true)
			{
				cout << "������Ʒ���ƣ�";
				cin >> Name;
				cout << "������Ʒ���ۣ�";
				cin >> iPrice;
				cout << "������Ʒ�ۼۣ�";
				cin >> oPrice;
				cout << "�����������";
				cin >> Rep;
				cout << "���������̣�";
				cin >> Producer;
				cout << "����Ʒ�ƣ�";
				cin >> Brand;

				if (Type == "ʳƷ��")
				{
					temp = new Food(Id, Name, iPrice, oPrice, Rep, Producer, Brand, Type);
				}
				else if (Type == "��װ��")
				{
					temp = new Clothes(Id, Name, iPrice, oPrice, Rep, Producer, Brand, Type);
				}
				else if (Type == "����Ʒ��")
				{
					temp = new Daily(Id, Name, iPrice, oPrice, Rep, Producer, Brand, Type);
				}
				else if (Type == "������")
				{
					temp = new Tools(Id, Name, iPrice, oPrice, Rep, Producer, Brand, Type);
				}
				else if (Type == "������")
				{
					temp = new Others(Id, Name, iPrice, oPrice, Rep, Producer, Brand, Type);
				}
				goods_vector.push_back(temp);
			}
			break;
		default:
			flag1 = true;
			break;
		}

		//flag1Ϊtrue���˳�����
		if (flag1 == true)
		{
			break;
		}
	}
}

void UserAdm::LookGoods()
{
	while (true)
	{
		system("cls");
		cout << "���\t" << "����\t\t\t" << "����\t" << "�ۼ�\t" << "���\t" << endl;
		int n = goods_vector.size();
		for (int i = 0; i < n; i++)
		{
			cout << goods_vector[i]->getGid() << "\t"
				<< setiosflags(ios::left) << setw(20) << goods_vector[i]->getGname() << "\t"
				<< goods_vector[i]->getGip() << "\t"
				<< goods_vector[i]->getGop() << "\t"
				<< goods_vector[i]->getRepertory() << endl;
		}

		cout << endl << "�����Ų鿴��ϸ��Ϣ������Null���������棩��";
		string id;
		cin >> id;
		if (id == "Null")
		{
			break;
		}
		int i;
		for (i = 0; i < n; i++)
		{
			if (id == goods_vector[i]->getGid())
			{
				cout << endl << "��Ʒ���ƣ�" << goods_vector[i]->getGname() << "\t\t";
				goods_vector[i]->Introduce();
				cout << "�����۸�" << goods_vector[i]->getGip()
					<< "\t�ۼۣ�" << goods_vector[i]->getGop()
					<< "\t��棺" << goods_vector[i]->getRepertory() << endl
					<< "�����̣�" << goods_vector[i]->getProducer() << endl
					<< "Ʒ�ƣ�" << goods_vector[i]->getBrand() << endl << endl;
				break;
			}
		}
		if (i == n)
		{
			cout << endl << "����������" << endl;
			for (int i = 0; i < 3; i++)
			{
				cout << ".";
				Sleep(250);
			}
		}
		else
		{
			cout << "�������������������Null���������棩" << endl;
			string op;
			cin >> op;
			if (op == "Null")
			{
				break;
			}
		}
	}
}

bool UserAdm::Menu()
{
	bool flag0 = 0;
	while (true)
	{
		system("cls");

		bool flag1 = false;

		int opt = -1;
		cout << "��ӭ����" << UserName << "\t" << "����Ȩ��Ϊ��" << UserLevel << endl;
		cout << "������������������" << endl;
		cout << "��                              ��" << endl;
		cout << "��        1.��ӳ�Ա            ��" << endl;
		cout << "��        2.����                ��" << endl;
		cout << "��        3.�鿴�˵�            ��" << endl;
		cout << "��        4.�鿴��Ʒ            ��" << endl;
		cout << "��        5.�޸���Ʒ��Ϣ        ��" << endl;
		cout << "��        6.�˳���¼            ��" << endl;
		cout << "��        0.�˳�ϵͳ            ��" << endl;
		cout << "��                              ��" << endl;
		cout << "������������������" << endl;
		cout << "���������";
		cin >> opt;

		switch (opt)
		{
		case 1:
			addUser();
			break;
		case 2:
			Stock_menu();
			break;
		case 3:
			LookBills();
			break;
		case 4:
			LookGoods();
			break;
		case 5:
			Modify();
			break;
		case 6:
			flag0 = true;
			flag1 = true;
			break;
		default:
			flag0 = false;
			flag1 = true;
			break;
		}

		if (flag1 == true)
		{
			break;
		}
	}
	return flag0;
}

void UserAdm::Modify()
{
	while (true)
	{
		system("cls");
		cout << "���\t" << "����\t\t\t" << "����\t" << "�ۼ�\t" << "���\t" << endl;
		int n = goods_vector.size();
		for (int i = 0; i < n; i++)
		{
			cout << goods_vector[i]->getGid() << "\t"
				<< setiosflags(ios::left) << setw(20) << goods_vector[i]->getGname() << "\t"
				<< goods_vector[i]->getGip() << "\t"
				<< goods_vector[i]->getGop() << "\t"
				<< goods_vector[i]->getRepertory() << endl;
		}

		cout << "������Null����������\\������Ʒ��ϸ��Ϣ�����޸ģ�" << endl;
		cout << endl << "�����Ų鿴��ϸ��Ϣ��";
		string id;
		cin >> id;
		if (id == "Null")
		{
			break;
		}

		int i;
		for (i = 0; i < n; i++)
		{
			if (id == goods_vector[i]->getGid())
			{
				cout << endl << "��Ʒ���ƣ�" << goods_vector[i]->getGname() << "\t\t";
				goods_vector[i]->Introduce();
				cout << "�����۸�" << goods_vector[i]->getGip()
					<< "\t�ۼۣ�" << goods_vector[i]->getGop()
					<< "\t��棺" << goods_vector[i]->getRepertory() << endl
					<< "�����̣�" << goods_vector[i]->getProducer() << endl
					<< "Ʒ�ƣ�" << goods_vector[i]->getBrand() << endl << endl;
				break;
			}
		}
		if (i == n)
		{
			cout << endl << "����������" << endl;
			for (int i = 0; i < 3; i++)
			{
				cout << ".";
				Sleep(250);
			}
		}
		else
		{
			cout << "�������������������Null����������\\����Yes�����޸ģ�" << endl;
			string op;
			cin >> op;
			if (op == "Null")
			{
				break;
			}
			else if (op == "Yes")
			{
				float rep, ip, op;
				string n, pro, bra;
				cout << "���������޸���" << endl;

				cout << "��Ʒ���ƣ�";
				cin >> n;
				goods_vector[i]->setName(n);

				cout << "��棺";
				cin >> rep;
				goods_vector[i]->setRepertory(rep);

				cout << "���ۣ�";
				cin >> ip;
				goods_vector[i]->setIP(ip);

				cout << "�ۼۣ�";
				cin >> op;
				goods_vector[i]->setOP(op);

				cout << "�����̣�";
				cin >> pro;
				goods_vector[i]->setProducer(pro);

				cout << "Ʒ�ƣ�";
				cin >> bra;
				goods_vector[i]->setBrand(bra);

				cout << endl << "�޸���ɣ�" << endl;
				for (int o = 0; o < 3; o++)
				{
					cout << ".";
					Sleep(250);
				}
			}
		}
	}
}