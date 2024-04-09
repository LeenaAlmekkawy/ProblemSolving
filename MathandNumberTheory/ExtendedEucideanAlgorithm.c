#include <iostream>

using namespace std;


/// ax+by = gcd(a,b)                      (1)
/// gcd(a,b)= gcd(b,a%b)                  (2)
/// bx1+(a%b)y1= gcd(a,b)                 (3)
/// a%b =a-b*floor(a/b)                   (4)
/// bx1 + ( a-b*floor(a/b) )y1 = gcd(a,b) (5)
/// ay1 + b(x1-floor(a/b)*y1)  = gcd(a,b) (6)

///so i have a and b and i want to know x and y -->use extended Euclidean Algorithm(see equation one)
int extendedEuclid_recursive(int a, int b, int&x, int&y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int x1,y1;
    int d=extendedEuclid_recursive(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return d;
}
int main()
{
    int x;
    int y;
    /// it return gcd of the two numbers
    cout<<extendedEuclid_recursive(16,10,x,y)<<endl;
    cout<<x<<" "<<y<<endl;
    return 0;
}
