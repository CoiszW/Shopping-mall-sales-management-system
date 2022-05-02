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
	cout << "输入姓名：";
	cin >> n;
	cout << "输入账号：";
	cin >> id;
	if (id == "Null")
	{
		cout << "账号输入错误！" << endl;
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
			cout << "账号已存在！" << endl;
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
		cout << "输入密码：";
		cin >> code;
		cout << "输入权限等级（管理员\\员工）：";
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

	cout << "时间\t\t\t\t" << "姓名\t\t" << "商品编号\t"
		<< "商品名称\t" << "售价\t" << "出售数量\t" << "金额" << endl;
	while (!f.eof())
	{
		f >> time1 >> time2 >> name >> id >> gname >> price >> num >> money;
		cout << time1 << "  " << time2 << "\t\t" << name << "\t\t" << id << "\t\t"
			<< gname << "\t\t" << price << "\t" << num << "\t\t" << money << endl;
	}
	char c;
	cout << "输入任意键返回" << endl;
	cin.ignore();
	c = getchar();
}

void UserAdm::Stock_menu()
{
	while (true)
	{
		system("cls");
		cout << "编号\t" << "名称\t" << "进价\t" << "售价\t" << "库存\t" << endl;
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
		cout << "1.增加已有商品" << endl;
		cout << "2.添加新商品" << endl;
		cout << "0.返回主界面" << endl;
		cout << "请输入：";
		cin >> op;

		string id;
		int j;
		float increase;
		//flag0判断编号是否输入正确
		bool flag0 = false;
		//flag1判断是否退出功能
		bool flag1 = false;
		//flag2判断新增商品信息输入是否正确
		bool flag2 = false;

		string Id, Name, Producer, Brand, Type;
		float iPrice, oPrice, Rep;
		Goods* temp;

		switch (op)
		{
		case 1:
			cout << "输入商品编号：";
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
				cout << "商品：" << goods_vector[j]->getGname() << "\t增加数量：";
				cin >> increase;
				goods_vector[j]->setRepertory(goods_vector[j]->getRepertory() + increase);
			}
			else
			{
				cout << "编号输入错误！" << endl;
				for (int i = 0; i < 3; i++)
				{
					cout << ".";
					Sleep(250);
				}
			}
			break;
		case 2:
			cout << "输入商品类型（食品类、服装类、日用品类、工具类、其他类）：";
			cin >> Type;

			//判断类型是否输入正确
			if (Type == "食品类" || Type == "服装类" || Type == "日用品类" || Type == "工具类" || Type == "其他类")
			{
				flag2 = true;
			}
			else
			{
				cout << "类型输入错误！" << endl;
				for (int i = 0; i < 3; i++)
				{
					cout << ".";
					Sleep(250);
				}
				break;
			}

			if (flag2 == true)
			{
				cout << "输入商品编号：";
				cin >> Id;

				//编号不能为Null和Clear
				if (Id == "Null" || Id == "Clear")
				{
					cout << "编号输入错误！" << endl;
					for (int i = 0; i < 3; i++)
					{
						cout << ".";
						Sleep(250);
					}
					flag2 = false;
					break;
				}

				//判断编号是否重复
				for (int i = 0; i < n; i++)
				{
					if (Id == goods_vector[i]->getGid())
					{
						cout << "编号重复！" << endl;
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
				cout << "输入商品名称：";
				cin >> Name;
				cout << "输入商品进价：";
				cin >> iPrice;
				cout << "输入商品售价：";
				cin >> oPrice;
				cout << "输入进货量：";
				cin >> Rep;
				cout << "输入生产商：";
				cin >> Producer;
				cout << "输入品牌：";
				cin >> Brand;

				if (Type == "食品类")
				{
					temp = new Food(Id, Name, iPrice, oPrice, Rep, Producer, Brand, Type);
				}
				else if (Type == "服装类")
				{
					temp = new Clothes(Id, Name, iPrice, oPrice, Rep, Producer, Brand, Type);
				}
				else if (Type == "日用品类")
				{
					temp = new Daily(Id, Name, iPrice, oPrice, Rep, Producer, Brand, Type);
				}
				else if (Type == "工具类")
				{
					temp = new Tools(Id, Name, iPrice, oPrice, Rep, Producer, Brand, Type);
				}
				else if (Type == "其他类")
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

		//flag1为true，退出功能
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
		cout << "编号\t" << "名称\t\t\t" << "进价\t" << "售价\t" << "库存\t" << endl;
		int n = goods_vector.size();
		for (int i = 0; i < n; i++)
		{
			cout << goods_vector[i]->getGid() << "\t"
				<< setiosflags(ios::left) << setw(20) << goods_vector[i]->getGname() << "\t"
				<< goods_vector[i]->getGip() << "\t"
				<< goods_vector[i]->getGop() << "\t"
				<< goods_vector[i]->getRepertory() << endl;
		}

		cout << endl << "输入编号查看详细信息（输入Null返回主界面）：";
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
				cout << endl << "商品名称：" << goods_vector[i]->getGname() << "\t\t";
				goods_vector[i]->Introduce();
				cout << "进货价格：" << goods_vector[i]->getGip()
					<< "\t售价：" << goods_vector[i]->getGop()
					<< "\t库存：" << goods_vector[i]->getRepertory() << endl
					<< "生产商：" << goods_vector[i]->getProducer() << endl
					<< "品牌：" << goods_vector[i]->getBrand() << endl << endl;
				break;
			}
		}
		if (i == n)
		{
			cout << endl << "编号输入错误！" << endl;
			for (int i = 0; i < 3; i++)
			{
				cout << ".";
				Sleep(250);
			}
		}
		else
		{
			cout << "输入任意键继续（输入Null返回主界面）" << endl;
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
		cout << "欢迎您！" << UserName << "\t" << "您的权限为：" << UserLevel << endl;
		cout << "●●●●●●●●●●●●●●●●●" << endl;
		cout << "●                              ●" << endl;
		cout << "●        1.添加成员            ●" << endl;
		cout << "●        2.进货                ●" << endl;
		cout << "●        3.查看账单            ●" << endl;
		cout << "●        4.查看商品            ●" << endl;
		cout << "●        5.修改商品信息        ●" << endl;
		cout << "●        6.退出登录            ●" << endl;
		cout << "●        0.退出系统            ●" << endl;
		cout << "●                              ●" << endl;
		cout << "●●●●●●●●●●●●●●●●●" << endl;
		cout << "输入操作：";
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
		cout << "编号\t" << "名称\t\t\t" << "进价\t" << "售价\t" << "库存\t" << endl;
		int n = goods_vector.size();
		for (int i = 0; i < n; i++)
		{
			cout << goods_vector[i]->getGid() << "\t"
				<< setiosflags(ios::left) << setw(20) << goods_vector[i]->getGname() << "\t"
				<< goods_vector[i]->getGip() << "\t"
				<< goods_vector[i]->getGop() << "\t"
				<< goods_vector[i]->getRepertory() << endl;
		}

		cout << "（输入Null返回主界面\\进入商品详细信息进行修改）" << endl;
		cout << endl << "输入编号查看详细信息：";
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
				cout << endl << "商品名称：" << goods_vector[i]->getGname() << "\t\t";
				goods_vector[i]->Introduce();
				cout << "进货价格：" << goods_vector[i]->getGip()
					<< "\t售价：" << goods_vector[i]->getGop()
					<< "\t库存：" << goods_vector[i]->getRepertory() << endl
					<< "生产商：" << goods_vector[i]->getProducer() << endl
					<< "品牌：" << goods_vector[i]->getBrand() << endl << endl;
				break;
			}
		}
		if (i == n)
		{
			cout << endl << "编号输入错误！" << endl;
			for (int i = 0; i < 3; i++)
			{
				cout << ".";
				Sleep(250);
			}
		}
		else
		{
			cout << "输入任意键继续（输入Null返回主界面\\输入Yes进行修改）" << endl;
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
				cout << "以下输入修改项" << endl;

				cout << "商品名称：";
				cin >> n;
				goods_vector[i]->setName(n);

				cout << "库存：";
				cin >> rep;
				goods_vector[i]->setRepertory(rep);

				cout << "进价：";
				cin >> ip;
				goods_vector[i]->setIP(ip);

				cout << "售价：";
				cin >> op;
				goods_vector[i]->setOP(op);

				cout << "生产商：";
				cin >> pro;
				goods_vector[i]->setProducer(pro);

				cout << "品牌：";
				cin >> bra;
				goods_vector[i]->setBrand(bra);

				cout << endl << "修改完成！" << endl;
				for (int o = 0; o < 3; o++)
				{
					cout << ".";
					Sleep(250);
				}
			}
		}
	}
}