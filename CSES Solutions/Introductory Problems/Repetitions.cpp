#include<bits/stdc++.h>
using namespace std;
#define ll long long
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;cin>>s;
    int ans=0;
    for(int i=0;i<s.size();i++)
    {
        int o=i+1,c=1;
        while(o<s.size()&&s[o]==s[i]) o++,c++;
        ans=max(ans,c);
        i=o-1;
    }
    cout<<ans;
    return 0;
}
