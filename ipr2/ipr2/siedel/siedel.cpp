#include<iostream>
#include<iomanip>
#include<math.h>

#define f1(x1,x2,x3,x4,x5,x6,x7,x8,x9,x10)  (306-x2-x3-x4-x5-x6-x7-x8-x9-x10)/20
#define f2(x1,x2,x3,x4,x5,x6,x7,x8,x9,x10)  (325-x1-x3-x4-x5-x6-x7-x8-x9-x10)/20		
#define f3(x1,x2,x3,x4,x5,x6,x7,x8,x9,x10)  (344-x2-x1-x4-x5-x6-x7-x8-x9-x10)/20
#define f4(x1,x2,x3,x4,x5,x6,x7,x8,x9,x10)  (363-x2-x3-x1-x5-x6-x7-x8-x9-x10)/20
#define f5(x1,x2,x3,x4,x5,x6,x7,x8,x9,x10)  (382-x2-x3-x4-x1-x6-x7-x8-x9-x10)/20	
#define f6(x1,x2,x3,x4,x5,x6,x7,x8,x9,x10)  (401-x2-x3-x4-x5-x1-x7-x8-x9-x10)/20
#define f7(x1,x2,x3,x4,x5,x6,x7,x8,x9,x10)  (420-x2-x3-x4-x5-x6-x1-x8-x9-x10)/20
#define f8(x1,x2,x3,x4,x5,x6,x7,x8,x9,x10)  (439-x2-x3-x4-x5-x6-x7-x1-x9-x10)/20
#define f9(x1,x2,x3,x4,x5,x6,x7,x8,x9,x10)  (458-x2-x3-x4-x5-x6-x7-x8-x1-x10)/20
#define f10(x1,x2,x3,x4,x5,x6,x7,x8,x9,x10)  (477-x2-x3-x4-x5-x6-x7-x8-x9-x1)/20

using namespace std;

int main()
{
	float x10 = 0, x20 = 0, x30 = 0, x40 = 0, x50 = 0, x60 = 0, x70 = 0, x80 = 0, x90 = 0, x100 = 0,
		x11, x21, x31, x41, x51, x61, x71, x81, x91, x101, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, eps;
	//счетчик шагов
	int step = 1;

	cout << setprecision(6) << fixed;

	//ввод эпсилон
	cout << "Enter the epsilon value: ";
	cin >> eps;

	cout << endl << "Count\tx\t\ty\t\tz" << endl;
	do
	{
		x11 = f1(x10, x20, x30, x40, x50, x60, x70, x80, x90, x100);
		x21 = f2(x11, x20, x30, x40, x50, x60, x70, x80, x90, x100);
		x31 = f3(x11, x21, x30, x40, x50, x60, x70, x80, x90, x100);
		x41 = f4(x11, x21, x31, x40, x50, x60, x70, x80, x90, x100);
		x51 = f5(x11, x21, x31, x41, x50, x60, x70, x80, x90, x100);
		x61 = f6(x11, x21, x31, x41, x51, x60, x70, x80, x90, x100);
		x71 = f7(x11, x21, x31, x41, x51, x61, x70, x80, x90, x100);
		x81 = f8(x11, x21, x31, x41, x51, x61, x71, x80, x90, x100);
		x91 = f9(x11, x21, x31, x41, x51, x61, x71, x81, x90, x100);
		x101 = f10(x11, x21, x31, x41, x51, x61, x71, x81, x91, x100);

		cout << step << "\t" << x11 << "\t" << x21 << "\t" << x31 << "\t" << x41 << "\t" << x51 << "\t" << x61 << "\t" << x71 << "\t" << x81 << "\t" << x91 << "\t" << x101 << endl;

		//создание переменных для сравнения с эпсилон
		e1 = fabs(x10 - x11);
		e2 = fabs(x20 - x21);
		e3 = fabs(x30 - x31);
		e4 = fabs(x40 - x41);
		e5 = fabs(x50 - x51);
		e6 = fabs(x60 - x61);
		e7 = fabs(x70 - x71);
		e8 = fabs(x80 - x81);
		e9 = fabs(x90 - x91);
		e10 = fabs(x100 - x101);

		step++;

		x10 = x11;
		x20 = x21;
		x30 = x31;
		x40 = x41;
		x50 = x51;
		x60 = x61;
		x70 = x71;
		x80 = x81;
		x90 = x91;
		x100 = x101;

	} while (e1 > eps && e2 > eps && e3 > eps && e4 > eps && e5 > eps && e6 > eps && e7 > eps && e8 > eps && e9 > eps && e10 > eps);

	/*cout << endl << " x1 = " << x11 << ", x2 = " << x21 << " and x3 = " << x31;*/
	return 0;
}

