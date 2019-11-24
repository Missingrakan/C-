#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

class CGoods
{
public:
	void RegisterGoods(char *name, int count, float price)
	{
		strcpy(this->name, name);
		this->count = count;
		this->price = price;
	}
	void SetName(char *name)
	{
		strcpy(this->name, name);
	}
	void SetCount(int count)
	{
		this->count = count;
	}
	void setPrice(float price)
	{
		this->price = price;
	}
public:
	char* GetName()
	{
		return this->name;
	}
	int GetCount()
	{
		return this->count;
	}
	float GetPrice()
	{
		return this->price;
	}
	float GetTotalPrice()
	{
		return this->count * this->price;
	}
private:
	char name[10];
	int count;
	float price;
	float tatal_price;
};


void main()
{
	CGoods good;
	good.RegisterGoods("няням╥", 4, 1.0);
	char *str = good.GetName();
	int count = good.GetCount();
	float price = good.GetPrice();
	float total_price = good.GetTotalPrice();
}