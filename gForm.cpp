#include"gForm.h"

Food::Food(string id, string n, float ip, float op, float gp, string gpr, string b, string t)
	:Goods(id, n, ip, op, gp, gpr, b, t)
{

}

void Food::Introduce()
{
	cout << "ʳƷ��" << endl;
}


Clothes::Clothes(string id, string n, float ip, float op, float gp, string gpr, string b, string t)
	:Goods(id, n, ip, op, gp, gpr, b, t)
{

}

void Clothes::Introduce()
{
	cout << "��װ��" << endl;
}


Daily::Daily(string id, string n, float ip, float op, float gp, string gpr, string b, string t)
	:Goods(id, n, ip, op, gp, gpr, b, t)
{

}

void Daily::Introduce()
{
	cout << "����Ʒ��" << endl;
}


Tools::Tools(string id, string n, float ip, float op, float gp, string gpr, string b, string t)
	:Goods(id, n, ip, op, gp, gpr, b, t)
{

}

void Tools::Introduce()
{
	cout << "������" << endl;
}


Others::Others(string id, string n, float ip, float op, float gp, string gpr, string b, string t)
	:Goods(id, n, ip, op, gp, gpr, b, t)
{

}

void Others::Introduce()
{
	cout << "������" << endl;
}