#include<bits/stdc++.h>
using namespace std;
#define ll long long
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,q;cin>>n>>m>>q;
    int s[n+5][m+5]={};
    while(q--)
    {
        int a,b,x,y,k;cin>>a>>b>>x>>y>>k;
        s[a][b]+=k;
        s[a][y+1]-=k;
        s[x+1][b]-=k;
        s[x+1][y+1]+=k;
    }
    for(int i=1;i<=n;i++)
    {
        for(int o=1;o<=m;o++)
        {
            s[i][o]=s[i-1][o]+s[i][o-1]-s[i-1][o-1]+s[i][o];
        }
    }
    return 0;
}
