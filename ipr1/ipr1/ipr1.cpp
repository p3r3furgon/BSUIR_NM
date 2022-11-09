#include <iostream>
#include <cmath>
#include <conio.h>
#include <iomanip>


using namespace std;



 double factorial(int x) 
{
     double fact = 1;
    for (; x >= 1; x--)
    {
        fact = x * fact;
    }
    return fact;
}

 template <typename T>
 void taylor_sin(T x, int n, double eps)
 {
     x = static_cast<T>(x);
     eps = static_cast<T>(eps);
     int k = 0;
     T sum = 0, cp_x = x;
     T err;

     cout.precision(10);
     
     while (fabs(x) >= eps && k < n)
     {
         cout << setiosflags(ios::left);
         x = pow(-1, k) * pow(cp_x, 2 * k + 1) / factorial(2 * k + 1);
         sum += x;
         k++;
         cout << "k = " << setw(7) << k << " x = " << setw(30) << x << "sum = " << setw(30) << sum << "sin = " << sin(cp_x) << "\n";
     }
     err = abs((sin(cp_x)-sum)/sum);
     cout << " Error is " << err;
     cout << "\n\n\n\n\n";
 }

 int main()
 {
     setlocale(LC_ALL, "ru");
     do {
         int n, ch, h =1;
         double x, sum = 0, eps = 1e-15, b = 25.0;
         
         cout << "Enter number of task" << endl
             << "1. sin of chosen number(double)" << endl
             << "2. sin of chosen number(float)" << endl
             << "3. sin of period [0,25]" << endl
             << "4. precision(n) dependens" << endl;
         cin >> ch;
         switch (ch)
         {
         case 1:
             cout << "enter the value\t";  cin >> x;
             cout << "enter a number of operations(n)" << '\n';  cin >> n;
             taylor_sin<double>(x, n, eps);
             break;
         case 2:
             cout << "enter the value\t";  cin >> x;
             cout << "enter a number of operations(n)" << '\n';  cin >> n;
             taylor_sin<float>(x, n, eps);
             break;
         case 3:
             for (int i = 0; i <= b; i += h)
             {
                 taylor_sin<double>(i, 100, eps);
             }
             break;
         case 4: 
             cout << "enter the value\t";  cin >> x;
             cout << "enter max n\t"; cin >> n;
             for (int i = 0; i <= n; i ++)
             {
                 taylor_sin<double>(x, i, eps);
             }
             break;
         default:
             break;
         }
     } while (_getch());
         return 0;
 }

