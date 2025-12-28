#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
string d="RLDU";
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    int sx,sy,ex,ey;
    char s[n][m];
    for(int i=0;i<n;i++)
    {
        for(int o=0;o<m;o++)
        {
            cin>>s[i][o];
            if(s[i][o]=='A') sx=i,sy=o;
            if(s[i][o]=='B') ex=i,ey=o;
        }
    }
    char vis[n][m];int dis[n][m]={};
    memset(vis,'?',sizeof vis);
    memset(dis,-1,sizeof dis);
    queue<pair<array<int,3>,char>>q;
    q.push({{sx,sy,0},'#'});
    while(q.size())
    {
        auto[i,o,c]=q.front().first;
        auto dir=q.front().second;
        q.pop();
        if(~dis[i][o]) continue;
        dis[i][o]=c;
        vis[i][o]=dir;
        for(int p=0;p<4;p++)
        {
            int X=i+dx[p],Y=o+dy[p];
            if(X>=0&&X<n&&Y>=0&&Y<m&&s[X][Y]!='#')
            {
                q.push({{X,Y,c+1},d[p]});
            }
        }
    }
    if(dis[ex][ey]==-1)
    {
        cout<<"NO";
    }
    else
    {
        cout<<"YES\n"<<dis[ex][ey]<<'\n';
        string ans="";
        while(s[ex][ey]!='A')
        {
            ans.push_back(vis[ex][ey]);
            if(vis[ex][ey]=='U') ex++;
            else if(vis[ex][ey]=='D') ex--;
            else if(vis[ex][ey]=='R') ey--;
            else if(vis[ex][ey]=='L') ey++;
        }
        reverse(ans.begin(),ans.end());
        cout<<ans;
    }
    return 0;
}
