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

ll extendedEuclid_recursive(ll a, ll b, ll*x, ll*y);
ll modInverse(ll a, ll m);
ll div(ll a,ll b,ll m );
///(a/b)%m
///it works only if gcd(b,m)=1
/// the output is an integer val


int main()
{
    ll a,b,m;
    cin>>a>>b>>m;
    ll ans=div(a,b,m);
    cout<<((a%m)*(ans%m))%m<<endl;

}
ll extendedEuclid_recursive(ll a, ll b, ll*x, ll*y)
{
    if(b==0)
    {
        *x=1;
        *y=0;
        return a;
    }
    ll x1,y1;
    ll d=extendedEuclid_recursive(b,a%b,&x1,&y1);
    *x=y1;
    *y=x1-y1*(a/b);
    return d;
}

ll modInverse(ll a, ll m)
{
    ll x, y;
    extendedEuclid_recursive(a,m,&x,&y);
    return (x%m+m)%m;//x may be negative

}
ll mul(ll a,ll b,ll m)
{
    return ((a%m)*(b%m))%m;
}
ll div(ll a,ll b,ll m )
{
    ll ans=modInverse(b,m);
    return (((a%m)*(ans%m))%m);
}
