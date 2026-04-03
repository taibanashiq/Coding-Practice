// #include<iostream>
// using namespace std;
// int sum(int a,int b){
//     int sum=a+b;
//     return 0;
// }
// int main(){
//     cout<<sum(10,5)<<endl;
//     return 0;
// }
#include<iostream>
using namespace std;
// double sum(double a,double b){
//     double  s=a+b;
 
//    return s;
   int minOfTwo(int a,int b){
    if(a<b){
        return a;
    }else {
    return b;
   }
}
int main()
{
    cout << "min="<< minOfTwo(5,2)<<endl;
    return 0;
}
