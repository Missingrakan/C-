#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

//class CGoods
//{
//public:
//	void RegisterGoods(char *name, int count, float price)
//	{
//		strcpy(this->name, name);
//		this->count = count;
//		this->price = price;
//	}
//	void SetName(char *name)
//	{
//		strcpy(this->name, name);
//	}
//	void SetCount(int count)
//	{
//		this->count = count;
//	}
//	void setPrice(float price)
//	{
//		this->price = price;
//	}
//public:
//	char* GetName()
//	{
//		return this->name;
//	}
//	int GetCount()
//	{
//		return this->count;
//	}
//	float GetPrice()
//	{
//		return this->price;
//	}
//	float GetTotalPrice()
//	{
//		return this->count * this->price;
//	}
//private:
//	char name[10];
//	int count;
//	float price;
//	float tatal_price;
//};
//
//
//void main()
//{
//	CGoods good;
//	good.RegisterGoods("窝窝头", 4, 1.0);
//	char *str = good.GetName();
//	int count = good.GetCount();
//	float price = good.GetPrice();
//	float total_price = good.GetTotalPrice();
//}

//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//
//int main()
//{
//	int& ret = Add(1, 2);
//	Add(3, 4); //可能会影响后续ret的值
//	cout << "Add(1,2) is :" << ret << endl;
//	return 0;
//}

//int& fun(const int &a, const int &b)
//{
//	int v = a + b;
//	return v;
//}
//
//void main()
//{
//	int a = 10;
//	int b = 20;
//
//	int &value = fun(a, b);
//	fun(100, 200);
//	cout << value << endl;
//}

//void main()
//{
//	int arr[5] = { 1, 2, 3, 4, 5 };
//	int(&brr)[5] = arr;
//
//	int(*par)[5] = &arr;
//
//	cout << sizeof(brr) << endl;
//	cout << sizeof(par) << endl;
//}

//内联方法  建议  效率
//inline int fun(int a, int b)
//{
//	return a + b;
//}
//
//void main()
//{
//	int value = fun(10, 20);
//	fun(10, 20);
//	fun(10, 20);
//	fun(10, 20);
//	fun(10, 20);
//	fun(10, 20);
//	fun(10, 20);
//	fun(10, 20);
//	fun(10, 20);
//	fun(10, 20);
//
//}
//struct Test
//{};
//
//void main()
//{
//	int a = 10;
//	auto b = 20;
//
//	int arr[5] = { 0 };
//	int *pa = &a;
//	Test t;
//
//	cout << typeid(b).name() << endl;
//	cout << typeid(arr).name() << endl;
//	cout << typeid(pa).name() << endl;
//	cout << typeid(t).name() << endl;
//}

//void main()
//{
//	int a = 10;
//	auto b = 20;
//	int ar[5] = { 0 };
//
//	auto par = &ar;
//	//auto x;  //
//	cout << typeid(b).name() << endl;
//	cout << typeid(par).name() << endl;
//}
//void fun(auto x) //error
//{
//	cout << x << endl;
//}
//void main()
//{
//	fun(10);
//}

//void main()
//{
//	auto a = 12.34;
//	//typeid(a).name() b; //error typeid(a).name()打印都是类型的字符串
//	decltype(a) b;
//	cout << typeid(b).name() << endl;
//}

//void main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int n = sizeof(arr) / sizeof(int);
//	for (int i = 0; i < n; ++i)
//		cout << arr[i] << " ";
//	cout << endl;
//
//	for (auto ele : arr)
//	{
//		ele = 11;
//		cout << ele << " ";
//	}
//	cout << endl;
//}

// 1 常方法的const 怎么了
// 1.不能修改数据成员
//GetData(Test * const this)  ==  GetData()；
//GetData()const == GetData(const Test * const this)；
// 2 GetData() 与 GetData()const 能否共存
//可以共存
//构成函数重载
//const Test t（100）；不能调动GetData() //Test * const this与const Test * const this不兼容
//常对象只能调动方法
//const int getData()
//函数的返回值被const修饰，不能作为左值。
//对于内置类型，返回值，这么使用好像没什么意义。
//因为返回的是临时变量，临时变量已经是const
//如果返回一个类对象的引用，加const可以确保，返回值不会被直接操作。
//
//int getData() const
//该函数是类的const成员函数
//即该函数不会修改类的数据成员
//当定义一个const对象时，只能调用const成员函数，
//以保证类的数据成员不会改变。
// 3 拷贝构造函数的const 
//Test（const Test &t）
//const ： 不允许更改t所引用对象的数据成员，保护数据
// 4 赋值语句 
//	 operator= ：运算符重载（. ？ ： ：： 不能重载）
//   Test& operator=(const Test &t)  返回类型Test& : 可以连等 const ： 不允许修改t所引用对象的数据成员，保护数据 ； & ：引用 提升效率
//   void  operator=(Test t)  不能连等 ：t1=t2=t3 ：即 t1.operator=(t2.operator=(t3operator=()))


void main()
{
	int arr[10][10];
	printf("%d", sizeof(arr));
}