#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void main()
{
	stringstream sstream;  //空间中转站
	sstream << "first" << " " << "string,";
	sstream << " second string";
	//first string, second string
	cout << "strResult is: " << sstream.str() << endl;
	// 清空 sstream
	sstream.str("");
	sstream << "third string";
	cout << "After clear, strResult is: " << sstream.str() << endl;
}

//int main()
//{
//	int a = 1234567;
//	string str;
//	stringstream s;
//	s << a;
//	s >> str;
//	cout << "str = " << str << endl;
//	cout << s.str() << endl;
//	s.clear();
//	cout << s.str() << endl;		//s本质未将内容清空，1234567
//
//	double d = 12.345;
//	s << d;
//	s >> str;
//	cout << "str = " << str << endl;
//	string value = s.str();
//	cout << "value = " << value << endl;		// "value = 123456712.345"
//	return 0;
//}

//int main()
//{
//	int n = 3;
//	char s1[32];
//	_itoa(n, s1, 2);
//	char s2[32];
//	sprintf(s2, "%d", n);
//	char s3[32];
//	sprintf(s3, "%f", n);
//
//	return 0;
//}

//struct ServerInfo
//{
//	char _ip[32];
//	int _port;
//};
//
//class ConfigManager
//{
//public:
//	ConfigManager(const string cfgfile) : _configfile(cfgfile)
//	{}
//public:
//	void Write_ServerInfo_Text(const ServerInfo& info)
//	{
//		ofstream ofile(_configfile, ios::out);
//		if (!ofile)
//			return;
//		ofile << info._ip << " " << info._port;
//		ofile.close();
//	}
//
//	void Read_ServerInfo_Test(ServerInfo &info)
//	{
//		ifstream ifile(_configfile, ios::in);
//		if (!ifile)
//			return;
//		ifile >> info._ip >> info._port;
//		ifile.close();
//	}
//private:
//	string _configfile;
//};
//
//void main()
//{
//	ServerInfo serve_info = { "192.168.10.100", 8080};
//	ConfigManager cfgmgr("Server.config");
//	cfgmgr.Write_ServerInfo_Text(serve_info);
//	ServerInfo tmp_info;
//	cfgmgr.Read_ServerInfo_Test(tmp_info);
//	cout << tmp_info._ip << " : " << tmp_info._port << endl;
//}

////C++二进制读入
//void main()
//{
//	int ar[10];
//	int n = sizeof(ar) / sizeof(int);
//	//1
//	ifstream ifile;
//	//ifstream ifile("Test5.txt", ios::in | ios::binary); //rb
//	//2
//	ifile.open("Test5.txt", ios::in | ios::binary);		//fopen("test.txt", "rb")
//	ifile.read((char*)ar, sizeof(int)*n);
//
//	for (int i = 0; i<10; ++i)
//	{
//		cout << ar[i] << " ";
//	}
//
//	ifile.close();
//	return;
//}

//C++二进制写入
//void main()
//{
//	int ar[] = { 12, 23, 34, 45, 56, 67, 78, 89, 90, 100 };
//	int n = sizeof(ar) / sizeof(int);
//	//1
//	ofstream ofile;
//	//2
//	ofile.open("test5.txt", ios::out | ios::binary); //fopen("test.txt", "wb");
//	//3
//
//	ofile.write((const char*)ar, sizeof(int)*n);
//	ofile.close();
//	return;
//}

////C++读入
//void main()
//{
//	int ar[10];
//	int n = sizeof(ar) / sizeof(int);
//	
//	ifstream ifile;
//	
//	ifile.open("test4.txt", ios::in); //fopen("test.txt", "r");
//	
//	for (int i = 0; i<n; ++i)
//	{
//		ifile >> ar[i];   //cin>>ar[i];
//	}
//
//	for (int i = 0; i<10; ++i)
//	{
//		cout << ar[i] << " ";
//	}
//
//	ifile.close();
//	return;
//}


////C++写入
//int main()
//{
//	int ar[] = { 12, 23, 34, 45, 56, 67, 78, 89, 90, 100 };
//	int n = sizeof(ar) / sizeof(int);
//
//	ofstream ofile;
//
//	ofile.open("test4.txt", ios::out);	//fopen("test.txt", "r");
//
//	for (int i = 0; i<n; ++i)
//	{
//		ofile << ar[i] << " ";
//	}
//	ofile.close();
//	return 0;
//}

////二进制读入
//int main()
//{
//	int ar[10];
//	int n = 10;
//	FILE *fp = fopen("Test2.txt", "rb"); //write binary
//	if (NULL == fp)
//	{
//		cerr << "Open Test.txt file failed." << endl;
//		exit(1);
//	}
//	fread(ar, sizeof(int), n, fp);
//
//	for (int i = 0; i<10; ++i)
//	{
//		cout << ar[i] << " ";
//	}
//
//	fclose(fp);
//	return 0;
//}

////二进制写入
//int main()
//{
//	int ar[] = { 12, 23, 34, 45, 56, 67, 78, 89, 90, 100 };
//	int n = sizeof(ar) / sizeof(int);
//	FILE *fp = fopen("test2.txt", "wb"); //write binary
//	if (NULL == fp)
//	{
//		cerr << "Open Test.txt file failed." << endl;
//		exit(1);
//	}
//	fwrite(ar, sizeof(int), n, fp);
//	fclose(fp);
//	return 0;
//}

////文本读入
//int main()
//{
//	int ar[10];
//	FILE *fp = fopen("Test1.txt", "r");
//	if (NULL == fp)
//	{
//		cerr << "Open Test.txt file failed." << endl;
//		exit(1);
//	}
//	for (int i = 0; i<10; ++i)
//	{
//		//fprintf(fp, "%d ", ar[i]);
//		fscanf(fp, "%d", &ar[i]);
//	}
//	for (int i = 0; i<10; ++i)
//	{
//		cout << ar[i] << " ";
//	}
//	fclose(fp);
//	return 0;
//}

////文本写入
//int main()
//{
//	int ar[] = { 12, 23, 34, 45, 56, 67, 78, 89, 90, 100 };
//	int n = sizeof(ar) / sizeof(int);
//	FILE* fp = fopen("test1.txt", "w");
//	if (NULL == fp)
//	{
//		cerr << "open test1.txt failed." << endl;
//		exit(1);
//	}
//
//	for (int i = 0; i < n; ++i)
//	{
//		fprintf(fp, "%d ", ar[i]);
//	}
//	fclose(fp);
//
//	return 0;
//}


//class Test
//{
//	friend ostream& operator<<(ostream& out, const Test& t);
//public:
//	Test(int data = 0) : m_data(data)
//	{}
//private:
//	int m_data;
//};
//
//ostream& operator<<(ostream& out, const Test& t)
//{
//	out << t.m_data;
//	return out;
//}
//
//int main()
//{
//	Test t(100);
//	cout << t << endl;
//
//	char *str = "This is a test.";
//	//cout << str;
//	//cerr << str;
//	clog << str;
//	return 0;
//}