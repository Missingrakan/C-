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
//	good.RegisterGoods("����ͷ", 4, 1.0);
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
//	Add(3, 4); //���ܻ�Ӱ�����ret��ֵ
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

//��������  ����  Ч��
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
//	//typeid(a).name() b; //error typeid(a).name()��ӡ�������͵��ַ���
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

// 1 ��������const ��ô��
// 1.�����޸����ݳ�Ա
//GetData(Test * const this)  ==  GetData()��
//GetData()const == GetData(const Test * const this)��
// 2 GetData() �� GetData()const �ܷ񹲴�
//���Թ���
//���ɺ�������
//const Test t��100�������ܵ���GetData() //Test * const this��const Test * const this������
//������ֻ�ܵ�������
//const int getData()
//�����ķ���ֵ��const���Σ�������Ϊ��ֵ��
//�����������ͣ�����ֵ����ôʹ�ú���ûʲô���塣
//��Ϊ���ص�����ʱ��������ʱ�����Ѿ���const
//�������һ�����������ã���const����ȷ��������ֵ���ᱻֱ�Ӳ�����
//
//int getData() const
//�ú��������const��Ա����
//���ú��������޸�������ݳ�Ա
//������һ��const����ʱ��ֻ�ܵ���const��Ա������
//�Ա�֤������ݳ�Ա����ı䡣
// 3 �������캯����const 
//Test��const Test &t��
//const �� ���������t�����ö�������ݳ�Ա����������
// 4 ��ֵ��� 
//	 operator= ����������أ�. �� �� ���� �������أ�
//   Test& operator=(const Test &t)  ��������Test& : �������� const �� �������޸�t�����ö�������ݳ�Ա���������� �� & ������ ����Ч��
//   void  operator=(Test t)  �������� ��t1=t2=t3 ���� t1.operator=(t2.operator=(t3operator=()))


void main()
{
	int arr[10][10];
	printf("%d", sizeof(arr));
}