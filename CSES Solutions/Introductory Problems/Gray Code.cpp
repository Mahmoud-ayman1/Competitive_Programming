#include<bits/stdc++.h>
using namespace std;
#define ll long long
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int sz=1<<n;
    vector<bitset<31>>s(sz,0);
    for(int idx=0;idx<n;idx++)
    {
        int cnt=sz/(1<<idx);bool flib=1;
        for(int i=0;i<sz;i+=cnt)
        {
            if(flib)
            {
                for(int o=0;o<cnt/2;o++) s[i+o][idx]=0;
                for(int o=cnt/2;o<cnt;o++) s[i+o][idx]=1;
            }
            else
            {
                for(int o=0;o<cnt/2;o++) s[i+o][idx]=1;
                for(int o=cnt/2;o<cnt;o++) s[i+o][idx]=0;
            }
            flib^=1;
        }
    }
    for(int i=0;i<sz;i++)
    {
        for(int o=n-1;o>=0;o--)
        {
            cout<<s[i][o];
        }
        cout<<'\n';
    }
    return 0;
}
