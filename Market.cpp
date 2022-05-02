#include "Market.h"


//构造函数，初始化两个指针
Market::Market()
{
	user1 = NULL;
	user2 = NULL;
}
//析构函数
Market::~Market()
{

}

//主菜单界面
void Market::Menu()
{
	while (true)
	{
		//清空黑窗口
		system("cls");
		cout << "●●●●●●●●●●●●●●●●●●●●" << endl;
		cout << "●                                    ●" << endl;
		cout << "●     欢迎进入商场销售管理系统！     ●" << endl;
		cout << "●                                    ●" << endl;
		cout << "●●●●●●●●●●●●●●●●●●●●" << endl;

		//flag1用于判断登录是否成功
		bool flag1 = false;
		//flag2用于判断是否退出系统
		bool flag2 = false;
		//判断退出系统还是返回登录界面
		bool flag3 = false;

		//登录功能实现
		ifstream in;
		in.open("Users.txt");
		string LogId, LogCode;
		string Name, Id, Code, Level;

		if (!in)
		{
			cout << "User.txt ERROR!" << endl;
			//abort()----中止程序执行，直接从调用的地方跳出
			abort();
		}
		else
		{
			while (1)
			{
				cout << endl << "请登录" << endl << endl;
				cout << "账号（输入Null退出系统）：";
				cin >> LogId;

				//登录界面，输入账号为Null后退出系统
				if (LogId == "Null")
				{
					break;
				}
				else
				{
					flag2 = true;
				}
				cout << "密码：";
				cin >> LogCode;

				//文件读指针指向文件头
				in.seekg(0L, ios::beg);

				//匹配文件中账号和密码
				while (!in.eof())
				{
					in >> Name >> Id >> Code >> Level;
					if (Id == LogId && Code == LogCode)
					{
						//账号密码匹配成功，flag1返回真
						flag1 = true;
						break;
					}
				}

				if (flag1 == true)
				{
					cout << endl;
					cout << "登录成功" << endl;
					cout << "欢迎您！" << Name;
					cout << "\t" << "您的权限等级为：" << Level << endl;
					cout << endl << "正在进入系统……" << endl;
					//等待后加入对应权限等级的界面
					for (int i = 0; i < 6; i++)
					{
						cout << ".";
						Sleep(250);
					}
					break;
				}
				else
				{
					cout << "登录失败！" << endl;
					break;
				}
			}
			in.close();
		}
		
		//根据权限等级为指针开辟空间
		if (flag1 == true)
		{
			if (Level == "员工")
			{
				user1 = new UserStaff(Name, Id, Code, Level);
				cout << "emem" << endl;
				flag3 = user1->Menu();
				delete user1;
				user1 = NULL;
			}
			else if (Level == "管理员")
			{
				user2 = new UserAdm(Name, Id, Code, Level);
				flag3 = user2->Menu();
				delete user2;
				user2 = NULL;
			}
			else
			{
				flag3 = true;
				cout << "权限错误!" << endl;
				cout << endl << "正在返回登录界面……" << endl;
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

		//退出系统
		if (flag2 == false)
		{
			cout << endl << "欢迎下次使用！" << endl;
			break;
		}
	}
}