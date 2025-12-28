#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N=505;
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,q;cin>>n>>m>>q;
    int dis[n+5][n+5];
    for(int i=0;i<n+5;i++)
    {
        for(int o=0;o<n+5;o++)
        {
            dis[i][o]=(ll)1e18;
        }
    }
    for(int i=0;i<m;i++)
    {
        int x,y,z;cin>>x>>y>>z;
        dis[x][y]=min(dis[x][y],z);
        dis[y][x]=min(dis[x][y],z);
    }
    for(int i=1;i<=n;i++)
    {
        dis[i][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int o=1;o<=n;o++)
        {
            for(int j=1;j<=n;j++)
            {
                dis[o][j]=min(dis[o][j],dis[o][i]+dis[i][j]);
            }
        }
    }
    while(q--)
    {
        int a,b;cin>>a>>b;
        if(dis[a][b]==(ll)1e18)dis[a][b]=-1;
        cout<<dis[a][b]<<'\n';
    }
    return 0;
}
