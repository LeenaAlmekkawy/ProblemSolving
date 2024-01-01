#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{  ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
set<int> s = {11, 12, 13, 14, 15, 16, 17, 18};

    // Print the elements of the set
    for (auto it : s) {
        cout << it << " ";
    }
    cout << endl;

    // find element 15 in the set
    auto it = s.find(15);

    if (it != s.end()) {
        int relativePosition = distance(s.begin(), it);
        cout<<relativePosition<<endl;
    }

    // delete element 15 from the set if it exists

    if (it != s.end()) {
        s.erase(it);
    }

    // Print the remaining elements of the set

    for (auto it : s) {
        cout << it << " ";
    }
    cout << endl;
    int t;
    cin>>t;
    while(t--)
    {
       int n;
       cin>>n;
       vector<pair<ll,char>>vec;
       for(int i=0;i<n;i++)
       {
           ll a,b;
           cin>>a>>b;
           vec.push_back({a,'s'});
           vec.push_back({b,'e'});

       }
       sort(vec.begin(),vec.end());
       ll cnt=0;
       ll ans=0;
       cout<<endl;
       for(int i=0;i<vec.size();i++)
       {
           cout<<vec[i].first<<" "<<vec[i].second<<endl;
           if(vec[i].second=='s')
            cnt++;
           else if(vec[i].second=='e')
           {
               cnt--;
               ans+=cnt;
           }


       }
       cout<<ans<<"\n";
       cout<<endl;
    }
    return 0;
}
