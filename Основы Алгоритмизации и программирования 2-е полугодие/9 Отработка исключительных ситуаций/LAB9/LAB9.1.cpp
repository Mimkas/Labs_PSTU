#include <iostream>
#include "Error.h"
#include "Vector.h"
using namespace std;

int main()
{
   try
   {
       int n[]{ 5,6,3 };
       Vector x(3,n);
       cout << x << "\n\n\n";
       x - 1;
       cout << x << "\n\n\n";
       x + 2;
       cout << x;
       cout << "\n\n\n" << x[2] <<"\n\n\n";
       cout << x.len() <<"\n\n\n";
       x[84];
       x - 60;
       x - -60;
       Vector y;
       y + 600;
       y + -600;
       Vector z(54);
   }
   catch (error e)
   {
       e.what();
   }
   return 0;
}