#include"gForm.h"

Food::Food(string id, string n, float ip, float op, float gp, string gpr, string b, string t)
	:Goods(id, n, ip, op, gp, gpr, b, t)
{

}

void Food::Introduce()
{
	cout << "食品类" << endl;
}


Clothes::Clothes(string id, string n, float ip, float op, float gp, string gpr, string b, string t)
	:Goods(id, n, ip, op, gp, gpr, b, t)
{

}

void Clothes::Introduce()
{
	cout << "服装类" << endl;
}


Daily::Daily(string id, string n, float ip, float op, float gp, string gpr, string b, string t)
	:Goods(id, n, ip, op, gp, gpr, b, t)
{

}

void Daily::Introduce()
{
	cout << "日用品类" << endl;
}


Tools::Tools(string id, string n, float ip, float op, float gp, string gpr, string b, string t)
	:Goods(id, n, ip, op, gp, gpr, b, t)
{

}

void Tools::Introduce()
{
	cout << "工具类" << endl;
}


Others::Others(string id, string n, float ip, float op, float gp, string gpr, string b, string t)
	:Goods(id, n, ip, op, gp, gpr, b, t)
{

}

void Others::Introduce()
{
	cout << "其他类" << endl;
}