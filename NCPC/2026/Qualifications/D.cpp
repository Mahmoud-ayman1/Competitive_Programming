#include<bits/stdc++.h>
using namespace std;
#define ll long long
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;cin>>s;
    int f[26]={};
    int n='n'-'a',o='o'-'a';
    for(auto it:s) f[it-'a']++;
    if(f[n]<2||f[o]<2)
    {
        cout<<0;
        return 0;
    }
    f[n]--;
    cout<<min(f[n],f[o]/2);
    return 0;
}
