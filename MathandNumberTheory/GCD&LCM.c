#include <iostream>

using namespace std;
typedef long long ll;

// complexity: O(log(min(a,b)))
ll gcd(ll a, ll b)
{
    if(b==0)
    {
        return a;
    }
    else
        return gcd(b,a%b);
}
ll lcm(ll a , ll b)
{
    return (  (  a/(gcd(a,b))  )*b  )
}
int main()
{
    
    cout<<gcd(20,15)<<endl;
    return 0;
}
