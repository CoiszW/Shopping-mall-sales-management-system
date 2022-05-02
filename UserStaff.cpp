#include"UserStaff.h"

string UserStaff::getName()
{
	return UserName;
}

string UserStaff::getId()
{
	return UserId;
}

string UserStaff::getCode()
{
	return UserCode;
}

string UserStaff::getLevel()
{
	return UserLevel;
}

string UserStaff::GetTime()
{
	time_t timep;
	time(&timep);
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", localtime(&timep));
	return tmp;
}


//���캯��������Ա����Ϣ����Ʒ����
UserStaff::UserStaff(string n, string id, string code, string level)
{
	UserName = n;
	UserId = id;
	UserCode = code;
	UserLevel = level;

	ifstream f;
	f.open("Goods.txt");
	if (!f)
	{
		cout << "Goods.txt ERROR!" << endl;
		abort();
	}
	else
	{
		string Id, Name, Producer, Brand, Type;
		float iPrice, oPrice, Rep;

		while (!f.eof())
		{
			Goods* temp;
			f >> Id >> Name >> iPrice >> oPrice >> Rep >> Producer >> Brand >> Type;
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
			//��ӳ�Ա������
			goods_vector.push_back(temp);
		}
		goods_vector.pop_back();
		f.close();
	}
}

//�������������޸Ĺ�����Ʒд��Goods.txt��
UserStaff::~UserStaff()
{
	fstream f;
	f.open("Goods.txt", ios::out);
	if (!f)
	{
		cout << "Goods.txt ERROR!" << endl;
		abort();
	}
	else
	{
		int n = goods_vector.size();
		for (int i = 0; i < n; i++)
		{
			f << goods_vector[i]->getGid() << "\t"
				<< goods_vector[i]->getGname() << "\t"
				<< goods_vector[i]->getGip() << "\t"
				<< goods_vector[i]->getGop() << "\t"
				<< goods_vector[i]->getRepertory() << "\t"
				<< goods_vector[i]->getProducer() << "\t"
				<< goods_vector[i]->getBrand() << "\t"
				<< goods_vector[i]->getType() << "\n";
		}
		f.close();
	}

	//�ͷ�����
	goods_vector.clear();
	shopping_Cart.clear();
	Cart_sum.clear();
}

bool UserStaff::Menu()
{
	bool flag0 = 0;

	//�洢��Ʒ��ʱ�����Ϣ
	int n = goods_vector.size();
	for (int i = 0; i < n; i++)
	{
		tempRep.push_back(goods_vector[i]->getRepertory());
	}

	while (true)
	{
		system("cls");

		bool flag1 = false;

		int opt = -1;
		cout << "��ӭ����" << UserName << "\t" << "����Ȩ��Ϊ��" << UserLevel << endl;
		cout << "����������������" << endl;
		cout << "��                          ��" << endl;
		cout << "��        1.������Ʒ        ��" << endl;
		cout << "��        2.�˳���¼        ��" << endl;
		cout << "��        0.�˳�ϵͳ        ��" << endl;
		cout << "��                          ��" << endl;
		cout << "����������������" << endl;
		cout << "���������";
		cin >> opt;

		switch (opt)
		{
		case 1:
			SellGoods();
			break;
		case 2:
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

void UserStaff::SellGoods()
{
	while (true)
	{
		system("cls");
		
		//չʾ��Ʒ����
		cout << "���" << "\t"
			<< "����" << "\t\t\t"
			<< "�ۼ�" << "\t"
			<< "���" << "\t"
			<< "Ʒ��" << "\t\t\t"
			<< "����" << endl;

		int n = goods_vector.size();
		for (int i = 0; i < n; i++)
		{
			cout << goods_vector[i]->getGid() << "\t"
				<< setiosflags(ios::left) << setw(20) << goods_vector[i]->getGname() << "\t"
				<< goods_vector[i]->getGop() << "\t"
				//��ʱ���չʾ
				<< tempRep[i] << "\t"
				<< setiosflags(ios::left) << setw(8) << goods_vector[i]->getBrand()
				<< "\t\t" << goods_vector[i]->getType() << endl;
		}

		
		//���ﳵ������
		float sum = 0;
		cout << endl;
		cout << "���ﳵ��" << "\t\t\t\t" << "�ܽ�";
		

		//չʾ���ﳵ
		if (shopping_Cart.size() == 0)
		{
			cout << sum << endl << "����Ʒ" << endl;
		}
		else
		{
			int m = shopping_Cart.size();
			for (int i = 0; i < m; i++)
			{
				sum += shopping_Cart[i]->getGop() * Cart_sum[i];
			}

			cout << sum << endl;
			cout << "���\t" << "����\t\t\t\t" << "�ۼ�\t" << "��������\t" << "�ܼ�\t" << endl;
			for (int i = 0; i < m; i++)
			{
				cout << shopping_Cart[i]->getGid() << "\t"
					<< setiosflags(ios::left) << setw(20) << shopping_Cart[i]->getGname()
					<< "\t\t" << shopping_Cart[i]->getGop() << "\t"
					<< Cart_sum[i] << "\t\t"
					<< Cart_sum[i] * shopping_Cart[i]->getGop() << endl;
			}
			cout << endl;
		}

		string index;
		float amount = 0;
		int l;
		//�����жϱ���Ƿ�������ȷ
		bool flag = false;

		//�����Ʒ�����ﳵ
		cout << "����Ҫ�������Ʒ��ţ����� Null �˳�\\���� Clear ���㣩��";
		cin >> index;
		if (index == "Null")
		{
			break;
		}
		else if (index == "Clear")
		{
			int k = shopping_Cart.size();

			//���ﳵ����Ʒ���㣬���˳�
			if (k == 0)
			{
				cout << "���ﳵ������Ʒ" << endl;
				for (int i = 0; i < 6; i++)
				{
					cout << ".";
					Sleep(250);
				}
				break;
			}

			ofstream b;
			b.open("Bills.txt", ios::app);
			if (!b)
			{
				cout << "Bills.txt ERROR!" << endl;
				abort();
			}
			else
			{
				//�ѳ�����Ϣ¼���˵�Bills.txt�ļ���
				for (int x = 0; x < k; x++)
				{
					b << "\n" << GetTime() << "\t\t" << getName() << "\t\t"
						<< shopping_Cart[x]->getGname() << "\t\t"
						<< shopping_Cart[x]->getGid() << "\t"
						<< shopping_Cart[x]->getGop() << "\t"
						<< Cart_sum[x] << "\t"
						<< Cart_sum[x] * shopping_Cart[x]->getGop();
				}

				//���ۺ��޸���Ʒʵ�ʿ��
				for (int i = 0; i < n; i++)
				{
					goods_vector[i]->setRepertory(tempRep[i]);
				}

				//��չ��ﳵ��Ϣ
				shopping_Cart.clear();
				Cart_sum.clear();
				b.close();

				for (int i = 0; i < 6; i++)
				{
					cout << ".";
					Sleep(250);
				}
				break;
			}
		}
		else
		{
			for (l = 0; l < n; l++)
			{
				if (index == goods_vector[l]->getGid())
				{
					break;
				}
			}

			if (l == n)
			{
				cout << "����������" << endl;
				flag = false;
			}
			else
			{
				flag = true;
			}
		}

		if (flag == true)
		{
			cout << "���빺��������";
			cin >> amount;

			//�жϹ��������Ƿ������
			if (amount > tempRep[l])
			{
				cout << "��治��!��������ȷ��������" << endl;
				for (int j = 0; j < 6; j++)
				{
					cout << ".";
					Sleep(250);
				}
			}
			else
			{
				//�޸���ʱ��Ʒ���
				tempRep[l] -= amount;

				int m = shopping_Cart.size();
				if (m == 0)
				{
					//���ﳵ����Ʒ����������Ʒ��������ﳵ����
					shopping_Cart.push_back(goods_vector[l]);
					Cart_sum.push_back(amount);
				}
				else
				{
					int k;
					//�жϹ�����Ʒ�Ƿ����ڹ��ﳵ
					for (k = 0; k < m; k++)
					{
						if (shopping_Cart[k]->getGid() == goods_vector[l]->getGid())
						{
							break;
						}
					}
					//���������Ʒ�ڹ��ﳵ��
					if (k < m)
					{
						Cart_sum[k] += amount;
					}
					//���������Ʒ���ڹ��ﳵ��
					else if (k == m)
					{
						//�����Ʒ�����ﳵ
						shopping_Cart.push_back(goods_vector[l]);
						Cart_sum.push_back(amount);
					}
				}
			}
		}
	}
}