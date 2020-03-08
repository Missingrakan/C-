#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

//c++二进制写入
int main()
{
	int ar[] = { 12, 23, 34, 45, 56, 67, 78, 89, 90, 100 };
	int n = sizeof(ar) / sizeof(int);
	//1
	ofstream ofile;
	//2
	ofile.open("Test5.txt", ios::out | ios::binary);		//fopen("test.txt","w");
	//3
	ofile.write((const char*)ar, sizeof(int)*n);
	ofile.close();
	return 0;
}

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