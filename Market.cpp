#include "Market.h"


//���캯������ʼ������ָ��
Market::Market()
{
	user1 = NULL;
	user2 = NULL;
}
//��������
Market::~Market()
{

}

//���˵�����
void Market::Menu()
{
	while (true)
	{
		//��պڴ���
		system("cls");
		cout << "���������������������" << endl;
		cout << "��                                    ��" << endl;
		cout << "��     ��ӭ�����̳����۹���ϵͳ��     ��" << endl;
		cout << "��                                    ��" << endl;
		cout << "���������������������" << endl;

		//flag1�����жϵ�¼�Ƿ�ɹ�
		bool flag1 = false;
		//flag2�����ж��Ƿ��˳�ϵͳ
		bool flag2 = false;
		//�ж��˳�ϵͳ���Ƿ��ص�¼����
		bool flag3 = false;

		//��¼����ʵ��
		ifstream in;
		in.open("Users.txt");
		string LogId, LogCode;
		string Name, Id, Code, Level;

		if (!in)
		{
			cout << "User.txt ERROR!" << endl;
			//abort()----��ֹ����ִ�У�ֱ�Ӵӵ��õĵط�����
			abort();
		}
		else
		{
			while (1)
			{
				cout << endl << "���¼" << endl << endl;
				cout << "�˺ţ�����Null�˳�ϵͳ����";
				cin >> LogId;

				//��¼���棬�����˺�ΪNull���˳�ϵͳ
				if (LogId == "Null")
				{
					break;
				}
				else
				{
					flag2 = true;
				}
				cout << "���룺";
				cin >> LogCode;

				//�ļ���ָ��ָ���ļ�ͷ
				in.seekg(0L, ios::beg);

				//ƥ���ļ����˺ź�����
				while (!in.eof())
				{
					in >> Name >> Id >> Code >> Level;
					if (Id == LogId && Code == LogCode)
					{
						//�˺�����ƥ��ɹ���flag1������
						flag1 = true;
						break;
					}
				}

				if (flag1 == true)
				{
					cout << endl;
					cout << "��¼�ɹ�" << endl;
					cout << "��ӭ����" << Name;
					cout << "\t" << "����Ȩ�޵ȼ�Ϊ��" << Level << endl;
					cout << endl << "���ڽ���ϵͳ����" << endl;
					//�ȴ�������ӦȨ�޵ȼ��Ľ���
					for (int i = 0; i < 6; i++)
					{
						cout << ".";
						Sleep(250);
					}
					break;
				}
				else
				{
					cout << "��¼ʧ�ܣ�" << endl;
					break;
				}
			}
			in.close();
		}
		
		//����Ȩ�޵ȼ�Ϊָ�뿪�ٿռ�
		if (flag1 == true)
		{
			if (Level == "Ա��")
			{
				user1 = new UserStaff(Name, Id, Code, Level);
				cout << "emem" << endl;
				flag3 = user1->Menu();
				delete user1;
				user1 = NULL;
			}
			else if (Level == "����Ա")
			{
				user2 = new UserAdm(Name, Id, Code, Level);
				flag3 = user2->Menu();
				delete user2;
				user2 = NULL;
			}
			else
			{
				flag3 = true;
				cout << "Ȩ�޴���!" << endl;
				cout << endl << "���ڷ��ص�¼���桭��" << endl;
				for (int i = 0; i < 6; i++)
				{
					cout << ".";
					Sleep(250);
				}
				break;
			}
			
			if (flag3 == false)
			{
				flag2 = false;
			}
		}

		//�˳�ϵͳ
		if (flag2 == false)
		{
			cout << endl << "��ӭ�´�ʹ�ã�" << endl;
			break;
		}
	}
}