#include<iostream>
using namespace std;
int main()
{
    int marks;
    cout<<"enter marks:";
    cin >>marks;
    if(marks>=90)
    {
        cout<<"A\n";
    } else if(marks>80 && marks<90)

   {cout<<"B\n";
   } else 
   {
    cout<<"c\n";
   }
   return 0;
}