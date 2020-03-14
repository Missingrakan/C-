#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
	stringstream sstream;		//空间中转站
	sstream << "first" << " " << "string.";
	sstream << " second string";
	//first string second string
	cout << "strResult is: " << sstream.str() << endl;
	//清空 sstream
	sstream.str("");
	sstream << "third string";
	cout << "After clear,strResult is: " << sstream.str() << endl;
	return 0;
}

//int main()
//{
//	int a = 1234560;
//	string str;
//	stringstream s; //string 对象 扩容 内存不足
//	s << a;		//12345  -> str;
//	s >> str;
//	cout << "str = " << endl;
//	s.clear();
//	double d = 12.345;
//	s << d;
//	s >> str;
//	cout << "str = " << str << endl;
//	string value = s.str();
//	cout << "value = " << value << endl;
//	return 0;
//}

//int main()
//{
//	int n = -123;
//	char s1[32];
//	_itoa(n, s1, 10);
//	cout << s1 << endl;
//	char s2[32];
//	sprintf(s2, "%d", n);
//	cout << s2 << endl;
//	char s3[32];
//	sprintf(s3, "%f", n);
//	cout << s3 << endl;
//	return 0;
//}

//struct ServerInfo
//{
//	char _ip[30];	//ip		192.168.10.100
//	int _port;		//端口		8080
//};
//class ConfigManager
//{
//public:
//	ConfigManager(const string cfgfile) :_configFile(cfgfile)
//	{}
//public:
//	//文本
//	void Write_ServerInfo_Test(const ServerInfo &info)
//	{
//		ofstream ofile(_configFile, ios::out);
//		if (!ofile)
//			return;
//		ofile << info._ip << " " << info._port;
//		ofile.close();
//	}
//	void Read_ServerInfo_Test(ServerInfo &info)
//	{
//		ifstream ifile(_configFile, ios::in);
//		if (!ifile)
//			return;
//		ifile >> info._ip >> info._port;
//		ifile.close();
//	}
//private:
//	string _configFile;
//};
//
//int main()
//{
//	ServerInfo serve_info = { "192.168.10.100", 8080 };
//	ConfigManager cfgmgr("bitServer.config");
//	cfgmgr.Write_ServerInfo_Test(serve_info);
//	ServerInfo tmp_info;
//	cfgmgr.Read_ServerInfo_Test(tmp_info);
//	cout << tmp_info._ip << " : " << tmp_info._port << endl;
//	return 0;
//}

//int main()
//{
//	int ar[10];
//	int n = sizeof(ar) / sizeof(int);
//	//1
//	ifstream ifile("Test5.txt", ios::in || ios::binary); //rb
//	//2
//	ifile.read((char*)ar, sizeof(int)*n);
//	//3
//	ifile.close();
//	return 0;
//}

////c++二进制写入
//int main()
//{
//	int ar[] = { 12, 23, 34, 45, 56, 67, 78, 89, 90, 100 };
//	int n = sizeof(ar) / sizeof(int);
//	//1
//	ofstream ofile;
//	//2
//	ofile.open("Test5.txt", ios::out | ios::binary);		//fopen("test.txt","w");
//	//3
//	ofile.write((const char*)ar, sizeof(int)*n);
//	ofile.close();
//	return 0;
//}

//int main()
//{
//	int ar[10];
//	int n = sizeof(ar) / sizeof(int);
//	//1
//	ifstream ifile;
//	//2
//	ifile.open("Test5.txt", ios::in || ios::binary);
//	ifile.read((char *)ar, sizeof(int)*n);
//	ifile.close();
//
//
//	return 0;
//}

//c++文本读入
//int main()
//{
//	int ar[10];
//	int n = sizeof(ar) / sizeof(int);
//	//1
//	ifstream ifile;
//	//2
//	ifile.open("Test4", ios::in); //fopen("test.txt","w")
//	//3
//	for (int i = 0; i < n; ++i)
//	{
//		ifile >> ar[i];		//cin>>ar[i]
//	}
//	ifile.close();
//	return 0;
//}

////c++文本写入
//int main()
//{
//	int ar[] = { 12, 23, 34, 45, 56, 67, 78, 89, 90, 100 };
//	int n = sizeof(ar) / sizeof(int);
//	//1
//	ofstream ofile;
//	//2
//	ofile.open("Test4.txt", ios::out);	//fopen("test.txt", "w");
//	//3
//	for (int i = 0; i < n; ++i)
//	{
//		ofile << ar[i] << " ";
//	}
//	//4
//	ofile.close();
//	return 0;
//}

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
//	fclose(fp);
//	return 0;
//}

////二进制写入
//int main()
//{
//	int ar[] = { 12, 23, 34, 45, 56, 67, 78, 89, 90, 100 };
//	int n = sizeof(ar) / sizeof(int);
//	FILE *fp = fopen("Test2.txt", "wb");		//write binary
//	if (NULL == fp)
//	{
//		cerr << "Open Test.txt file failed." << endl;
//		exit(1);
//	}
//	fwrite(ar, sizeof(int), n, fp);
//	fclose(fp);
//
//	return 0;
//}

//int main()
//{
//	int ar[10];
//	FILE *fp = fopen("Test.txt", "r");
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
//	fclose(fp);
//
//
//	return 0;
//}

////c语言文本写入
//int main()
//{
//	int ar[] = { 12, 23, 34, 45, 56, 67, 78, 89, 90, 100 };
//	int n = sizeof(ar) / sizeof(int);
//	FILE *fp = fopen("Test.txt", "w");
//	if (NULL == fp)
//	{
//		cerr << "Open Test.txt file failed." << endl;
//		exit(1);
//	}
//	for (int i = 0; i < n; ++i)
//	{
//		fprintf(fp, "%d", ar[i]);
//	}
//	fclose(fp);
//
//	return 0;
//}