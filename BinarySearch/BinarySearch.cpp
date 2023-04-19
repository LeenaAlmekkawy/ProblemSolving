#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=2e5+10;
ll arr[N+5];
bool check(ll num);
ll n;
ll m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    reverse(arr,arr+n);

    ll be=1,en=n+5;
    ll ans=1e15;
    ///0 0 0 0 0 1 1 1 1
    while(be<=en)
    {
        int mid=be+(en-be)/2;
       // cout<<mid<<endl;
        if(check(mid))
        {
             ans=mid;
             en=mid-1;
        }
        else
        {
            be=mid+1;
        }
    }
    if(ans==1e15)
        ans=-1;
    cout<<ans<<endl;



}
bool check(ll num)
{
    ll a[num+1];
    ll sum=0;
   for(int i=0;i<n;i++)
   {
       ll dif=i/num;
       sum+=max((arr[i]-dif),(ll)0);
   }
   //cout<<" sum " <<sum<<endl;
   if(sum>=m)
    return 1;
   else
    return 0;
}
