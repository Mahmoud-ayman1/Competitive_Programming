#include<bits/stdc++.h>
using namespace std;
#define ll long long
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;cin>>s;
    int f[26]={};
    for(auto it:s) f[it-'A']++;
    int odd=0;char od;
    for(int i=0;i<26;i++) if(f[i]&1) odd++,od=char(i+'A');
    if(odd>1)
    {
        cout<<"NO SOLUTION";
        return 0;
    }
    for(int i=0;i<26;i++)
    {
        int x=f[i]/2;
        while(x--) cout<<char(i+'A');
        f[i]/=2;
    }
    if(odd) cout<<od;
    for(int i=25;i>=0;i--)
    {
        int x=f[i];
        while(x--) cout<<char(i+'A');
    }
    return 0;
}
