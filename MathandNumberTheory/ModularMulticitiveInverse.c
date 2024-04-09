#include <iostream>

using namespace std;
typedef long long ll;
/***
link: https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/tutorial/

->Modular Multiplicative Inverse

->input A,M , find B such that it satisfies the equation (A*B)%m=1  ,b=(a^-1)%m
-> B is said to be modular multiplication inverse A under module M if it satisfies the following  equations

(A*B)%m=1 , B in range(1,m-1)

-> an inverse exists only when A and M are coprime , gcd(A,M)=1
-> time complexity( o(log(n)) )

****/

int extendedEuclid_recursive(int a, int b, int*x, int*y);
int modInverse(int a, int m);

int main()
{

    ll sec=modInverse(5,12);
    cout<<sec<<endl;

}
int extendedEuclid_recursive(int a, int b, int*x, int*y)
{
    if(b==0)
    {
        *x=1;
        *y=0;
        return a;
    }
    int x1,y1;
    int d=extendedEuclid_recursive(b,a%b,&x1,&y1);
    *x=y1;
    *y=x1-y1*(a/b);
    return d;
}

int modInverse(int a, int m)
{
    int x, y;
    extendedEuclid_recursive(a,m,&x,&y);
    return (x%m+m)%m;//x may be negative

}
