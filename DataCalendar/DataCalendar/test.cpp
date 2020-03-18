#define _CRT_SECURE_NO_WARNINGS 1

#include "datetime.h"

void main()
{
	//Date dt(2019,12,1);
	//cout << dt << endl;

	Date dt1(2019, 12, 9);
	cout << dt1 << endl;
	Date dt = dt1 - 20;
	cout << dt << endl;

	//Date dt1(2019, 12, 9);
	//cout << dt1 << endl;
	//Date dt = dt1 + 35;		//23  -->  1
	//++dt1;  //dt1.operator++()
	//dt1++;  //dt1.operator++(0)
	////dt = dt1 + dt2;  //dt1.operator+(dt2) //==> operator+(&dt1, dt2);
	//cout << dt << endl;
	//cout << dt1 << endl;

	//Date dt1(2011, 12, 29);
	//Date dt2(2019, 12, 19);
	////dt1.operator!=(dt2);
	//if (dt1 == dt2)
	//	cout << "dt1 == dt2" << endl;
	//if (dt1 != dt2)
	//	cout << "dt1 != dt2" << endl;
	//if (dt1 > dt2)
	//	cout << "dt1 > dt2" << endl;
	//if (dt1 <= dt2)
	//	cout << "dt1 <= dt2" << endl;
	//Date dt3 = dt2;
	//Date dt1(2020, 4, 16);
	//cout << dt1.GetWeek() << endl;
}