#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
const int N=1e3+5;
int n,m,ans;char s[N][N];bool vis[N][N];
bool valid(int x,int y)
{
    return x<n&&x>=0&&y<m&&y>=0&&!vis[x][y]&&s[x][y]!='#';
}
void dfs(int x,int y)
{
    vis[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int Nx=x+dx[i],Ny=y+dy[i];
        if(valid(Nx,Ny)) dfs(Nx,Ny);
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++) for(int o=0;o<m;o++) cin>>s[i][o];
    for(int i=0;i<n;i++) for(int o=0;o<m;o++) if(valid(i,o)) ans++,dfs(i,o);
    cout<<ans;
    return 0;
}
