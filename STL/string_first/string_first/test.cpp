#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>

using namespace std;

////string对象的构造
//int main()
//{
//	//string();
//	string str1;
//	cout << "str1 = " << str1 << endl;
//	const char *s = "Hello world";
//
//	//string(const char *s)
//	string str2(s);
//	cout << "str2 = " << str2 << endl;
//
//	//string(const char *s)
//	string str3("Hello C++");
//	cout << "str3 = " << str3 << endl;
//
//	//string(size_t n,char c)
//	string str4(10, 'm');
//	cout << "str4 = " << str4 << endl;
//
//	//string(const string &s)
//	string str5(str3);
//	cout << "str5 = " << str5 << endl;
//
//	//string(const string &s)
//	string str6 = str5;
//	cout << "str6 = " << str6 << endl;
//
//	return 0;
//}

//int main()
//{
//	string str("hello bit!");
//	cout << "size = " << str.size() << endl;
//	cout << "length = " << str.length() << endl;
//	cout << "capacity = " << str.capacity() << endl;
//
//	string str1;
//	cout << "empty = " << str1.empty() << endl;
//	cout << "str1 = "<< str1 << endl;
//	str1.clear();
//	cout << "str1 = " << str1 << endl;
//
//	string str2 = "Hello";
//	cout << "str2 size = " << str2.size() << endl;
//	cout << "str2 cpacity = " << str2.capacity() << endl;
//	str2 += "string";
//	cout << "str2 size - " << str2.size() << endl;
//	cout << "str2 capaciity = " << str2.capacity() << endl;
//	str2 += "linux";
//	cout << "str2 size = " << str2.size() << endl;
//	cout << "str2 capacity = " << str2.capacity() << endl;
//
//	string str3 = "hello";
//	cout << "str3 size = " << str3.size() << endl;
//	cout << "str3 capacity = " << str3.capacity() << endl;
//	str3.reserve(100);
//	cout << "str3 size = " << str3.size() << endl;
//	cout << "str3 capacity = " << str3.capacity() << endl;
//
//	string str4 = "Hello";
//	cout << "str4 size = " << str4.size() << endl;
//	cout << "str4 capacity = " << str4.capacity() << endl;
//	cout << "str4 = " << str4 << endl;
//	str4.resize(20,'#');
//	cout << "str4 size = " << str4.size() << endl;
//	cout << "str4 capacity = " << str4.capacity() << endl;
//	cout << "str4 = " << str4 << endl;
//
//	string str5 = "hello";
//	cout << "str5 size = " << str5.size() << endl;
//	cout << "str5 capacity = " << str5.capacity() << endl;
//	cout << "str5 = " << str5 << endl;
//	str5.resize(50, '@');
//	cout << "str5 size = " << str5.size() << endl;
//	cout << "str5 capacity = " << str5.capacity() << endl;
//	cout << "str5 = " << str5 << endl;
//	str5.resize(2);
//	cout << "str5 size = " << str5.size() << endl;
//	cout << "str5 capacity = " << str5.capacity() << endl;
//	cout << "str5 = " << str5 << endl;
//
//	return 0;
//}

//
//int main()
//{
//	string str("hello bit");
//	cout << "size = " << str.size() << endl;//字字符串的有效大小，不包含'\'
//	cout << "length = "<< str.length() << endl;
//	cout << "capacity = " << str.capacity() << endl;
//
//	str.reserve(100);
//	cout << "size = " << str.size() << endl; //字符串的有效大小，不包含\0
//	cout << "length = " << str.length() << endl;
//	cout << "capacity = " << str.capacity() << endl;  //111
//
//	str.reserve(20);
//	cout << "size = " << str.size() << endl; //字符串的有效大小，不包含\0
//	cout << "length = " << str.length() << endl;
//	cout << "capacity = " << str.capacity() << endl; 
//
//	return 0;
//}

//int main()
//{
//	string str("Hello Bit.");
//	cout << "size = " << str.size() << endl; //字符串的有效大小，不包含\0
//	cout << "capacity = " << str.capacity() << endl;
//	cout << "str = " << str << endl;
//
//	str.clear();
//	cout << "size = " << str.size() << endl; //字符串的有效大小，不包含\0
//	cout << "capacity = " << str.capacity() << endl;
//	cout << "str = " << str << endl;
//
//	return 0;
//}


//int main()
//{
//	string str = "Hello world";
//	cout << str << endl;
//
//	//char *strt[] = "Hello world"
//	//strt[i] = *(strt + i)
//	//operator[]
//	for (int i = 0; i < str.size(); i++)
//		cout << str[i];
//	cout << endl;
//
//	//c++11
//	for (auto &ele : str)//引用
//		cout << ele;
//	cout << endl;
//
//	//迭代器 : iterator
//	string::iterator it = str.begin();
//	while (it != str.end())
//	{
//		cout << *it;
//		it++;
//	}
//	cout << endl;
//
//	return  0;
//}

//int main()
//{
//	char *s = "Hello C++";
//	string str;
//	while (*s != '\0')
//	{
//		str.push_back(*s);
//		s++;
//	}
//
//	cout << "str = " << str << endl;
//	str.append(" Linux");
//	cout << "str = " << str << endl;
//
//	return 0;
//}

//int main()
//{
//	string path = "C:";
//
//	path += "\\";
//	path += "C++";
//	path += "\\";
//	path += "STL.pdf";
//	cout << "path = " << path << endl;
//	return 0;
//}

//int main()
//{
//	string str = "Hello bit.";
//	int len = strlen(str.c_str());
//	cout << "len = " << len << endl;
//	//const char*  str.c_str();
//
//	return 0;
//}

//int main()
//{
//	char *s1 = "Hello bit.";
//	char *s2 = "Hello bit.";//s1和s2保存的“hello world”相同
//	string str1 = "Hello bit.";
//	string str2 = "Hello bit.";//str1和str2保存的不同，原因是str1hestr2是两个不同的对象
//
//	return 0;
//}

//int main()
//{
//	string email = "maoguoqianghesaobiwanmadeyouxiang2020@163.com";
//	size_t pos = email.find('@');
//	if (pos != string::npos)	//string::npos  -1
//	{
//		cout << "pos = " << pos << endl;
//	}
//	else
//		cout << "not find" << endl;
//	pos = email.find("saobi");//正向查找
//	if (pos != string::npos)
//	{
//		cout << "pos = " << pos << endl;
//	}
//	pos = email.rfind('@');//倒着查找
//	if (pos != string::npos)
//	{
//		cout << "pos = " << pos << endl;
//	}
//
//	return 0;
//}

//int main()
//{
//	string email = "maoguoqianghesaobiwanmadeyouxiang2020@163.com";
//	string email_type;
//	size_t start_pos = email.find('@');
//	size_t end_pos = email.rfind('.');
//	email_type = email.substr(start_pos + 1, end_pos - start_pos - 1);
//	cout << "Type = " << email_type << endl;
//
//	return 0;
//}

//int main()
//{
//	string s1 = "hello";
//	string s2 = "bit";
//	string s3 = s1 + s2;
//	cout << "s3 = " << s3 << endl;
//
//	string s4;
//	cout << "请输入字符串:>";
//	//cin >> s4;//以\n和space空格结束
//	getline(cin, s4);//读取一行字符以\n结束
//	cout << "s4 = " << s4 << endl;
//	return 0;
//}

//int main()
//{
//	string str = "Hello world";
//	//迭代器 iterator
//	string::iterator it = str.begin();
//	while (it != str.end())
//	{
//		cout << *it;
//		++it;
//	}
//	cout << endl;
//
//	string::reverse_iterator rit = str.rbegin();
//	while (rit != str.rend())
//	{
//		cout << *rit;
//		++rit;
//	}
//	cout << endl;
//
//
//	return 0;
//}


void main()
{
	string email = "kkkzkkbaosongshan2006@163.com";
	size_t pos = email.find('song'); //完全匹配

	string sub("abcxyz");
	pos = email.find_first_of(sub);
	cout << pos << endl;

	pos = email.find_first_not_of(sub);
	cout << pos << endl;

	pos = email.find_last_of(sub);
	cout << pos << endl;

	pos = email.find_last_not_of(sub);
	cout << pos << endl;
}