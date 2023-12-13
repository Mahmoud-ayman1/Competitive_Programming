#include<bits/stdc++.h>
using namespace std;
#define ll long long
char s[8][8];bool col[8],digL[16],digR[16];
ll solve(int row=0)
{
    if(row==8) return 1;
    int ans=0;
    for(int i=0;i<8;i++)
    {
        if(s[row][i]=='.'&&!col[i]&&!digL[row+i]&&!digR[row-i+7])
        {
            col[i]=digL[row+i]=digR[row-i+7]=1;
            ans+=solve(row+1);
            col[i]=digL[row+i]=digR[row-i+7]=0;
        }
    }
    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i=0;i<8;i++) for(int o=0;o<8;o++) cin>>s[i][o];
    cout<<solve();
    return 0;
}
