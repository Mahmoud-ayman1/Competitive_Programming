#include<bits/stdc++.h>
using namespace std;
#define ll long long
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,k;cin>>n>>m>>k;
    int dis[n+5][n+5];int home[k+5];
    for(int i=0;i<n+5;i++)
    {
        for(int o=0;o<n+5;o++)
        {
            dis[i][o]=INT_MAX/2;
        }
    }
    for(int i=0;i<m;i++)
    {
        int x,y,z;cin>>x>>y>>z;
        dis[x][y]=z;
        dis[y][x]=z;
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
    return 0;
}
