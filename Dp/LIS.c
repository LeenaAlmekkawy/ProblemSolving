#include <bits/stdc++.h>

using namespace std;
string s1,s2;
const int N=1e6;
int memo[3000][3000];
int n;
vector<int>nums;
int rec(int ind,int pre)
{
  //  cout<<s<<" "<<ind<<" "<<pre<<endl;
  if(ind==n)
    return 0;
  if(memo[ind][pre]!=-1)
    return memo[ind][pre];

    int c1=0;
    int c2=0;

  if(nums[pre]<nums[ind])
   c1=rec(ind+1,ind)+1;

   c2=rec(ind+1,pre);

   memo[ind][pre]=max(c1,c2);


  return max(c1,c2);

}
vector<int>ans;
void BT(int ind,int pre)
{
    if(ind==n)
        return ;


     if(memo[ind][pre]==rec(ind+1,pre))
    {

        BT(ind+1,pre);

    }
    else  if(nums[pre]<nums[ind]&&memo[ind][pre]==rec(ind+1,ind)+1)
    {
        ans.push_back(nums[ind]);
        BT(ind+1,ind);
    }

}
int main()
{
    int t;
    cin>>t;
    int cnt=0;
    while(t--)
    {  memset(memo,-1,sizeof memo);
        string s;
        nums.clear();
        ans.clear();
        string st;
        if(cnt==0)
        cin.ignore();

        getline(cin,s);
         st+=s;
            st+=" ";



        while(getline(cin,s))
        {
            if(s.empty())
                break;
            st+=s;
            st+=" ";

        }

        stringstream ss(st);
        int num;
        nums.push_back(-1);

          while (ss >> num) {
        nums.push_back(num);
    }
    n=nums.size();




    cout<<"Max hits: "<<rec(1,0)<<endl;

    /*for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            cout<<memo[i][j]<<" ";
        }
        cout<<endl;
    }
*/

    BT(1,0);

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
    if(t>0)
        cout<<endl;
        cnt++;

    }
    return 0;
}
