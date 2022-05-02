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


//构造函数，定义员工信息和商品容器
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
			//添加成员至容器
			goods_vector.push_back(temp);
		}
		goods_vector.pop_back();
		f.close();
	}
}

//析构函数，将修改过的商品写入Goods.txt中
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

	//释放容器
	goods_vector.clear();
	shopping_Cart.clear();
	Cart_sum.clear();
}

bool UserStaff::Menu()
{
	bool flag0 = 0;

	//存储商品临时库存信息
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
		cout << "欢迎您！" << UserName << "\t" << "您的权限为：" << UserLevel << endl;
		cout << "●●●●●●●●●●●●●●●" << endl;
		cout << "●                          ●" << endl;
		cout << "●        1.出售商品        ●" << endl;
		cout << "●        2.退出登录        ●" << endl;
		cout << "●        0.退出系统        ●" << endl;
		cout << "●                          ●" << endl;
		cout << "●●●●●●●●●●●●●●●" << endl;
		cout << "输入操作：";
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
		
		//展示商品界面
		cout << "编号" << "\t"
			<< "名称" << "\t\t\t"
			<< "售价" << "\t"
			<< "库存" << "\t"
			<< "品牌" << "\t\t\t"
			<< "类型" << endl;

		int n = goods_vector.size();
		for (int i = 0; i < n; i++)
		{
			cout << goods_vector[i]->getGid() << "\t"
				<< setiosflags(ios::left) << setw(20) << goods_vector[i]->getGname() << "\t"
				<< goods_vector[i]->getGop() << "\t"
				//临时库存展示
				<< tempRep[i] << "\t"
				<< setiosflags(ios::left) << setw(8) << goods_vector[i]->getBrand()
				<< "\t\t" << goods_vector[i]->getType() << endl;
		}

		
		//购物车及购物
		float sum = 0;
		cout << endl;
		cout << "购物车：" << "\t\t\t\t" << "总金额：";
		

		//展示购物车
		if (shopping_Cart.size() == 0)
		{
			cout << sum << endl << "无商品" << endl;
		}
		else
		{
			int m = shopping_Cart.size();
			for (int i = 0; i < m; i++)
			{
				sum += shopping_Cart[i]->getGop() * Cart_sum[i];
			}

			cout << sum << endl;
			cout << "编号\t" << "名称\t\t\t\t" << "售价\t" << "购买数量\t" << "总价\t" << endl;
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
		//用于判断编号是否输入正确
		bool flag = false;

		//添加商品至购物车
		cout << "输入要购买的商品编号（输入 Null 退出\\输入 Clear 结算）：";
		cin >> index;
		if (index == "Null")
		{
			break;
		}
		else if (index == "Clear")
		{
			int k = shopping_Cart.size();

			//购物车无商品结算，则退出
			if (k == 0)
			{
				cout << "购物车中无商品" << endl;
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
				//把出售信息录入账单Bills.txt文件中
				for (int x = 0; x < k; x++)
				{
					b << "\n" << GetTime() << "\t\t" << getName() << "\t\t"
						<< shopping_Cart[x]->getGname() << "\t\t"
						<< shopping_Cart[x]->getGid() << "\t"
						<< shopping_Cart[x]->getGop() << "\t"
						<< Cart_sum[x] << "\t"
						<< Cart_sum[x] * shopping_Cart[x]->getGop();
				}

				//出售后，修改商品实际库存
				for (int i = 0; i < n; i++)
				{
					goods_vector[i]->setRepertory(tempRep[i]);
				}

				//清空购物车信息
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
				cout << "编号输入错误" << endl;
				flag = false;
			}
			else
			{
				flag = true;
			}
		}

		if (flag == true)
		{
			cout << "输入购买数量：";
			cin >> amount;

			//判断购买数量是否多与库存
			if (amount > tempRep[l])
			{
				cout << "库存不足!请输入正确数量……" << endl;
				for (int j = 0; j < 6; j++)
				{
					cout << ".";
					Sleep(250);
				}
			}
			else
			{
				//修改临时物品库存
				tempRep[l] -= amount;

				int m = shopping_Cart.size();
				if (m == 0)
				{
					//购物车无物品，将购买物品添加至购物车容器
					shopping_Cart.push_back(goods_vector[l]);
					Cart_sum.push_back(amount);
				}
				else
				{
					int k;
					//判断购买物品是否已在购物车
					for (k = 0; k < m; k++)
					{
						if (shopping_Cart[k]->getGid() == goods_vector[l]->getGid())
						{
							break;
						}
					}
					//如果购买物品在购物车中
					if (k < m)
					{
						Cart_sum[k] += amount;
					}
					//如果购买物品不在购物车中
					else if (k == m)
					{
						//添加商品至购物车
						shopping_Cart.push_back(goods_vector[l]);
						Cart_sum.push_back(amount);
					}
				}
			}
		}
	}
}