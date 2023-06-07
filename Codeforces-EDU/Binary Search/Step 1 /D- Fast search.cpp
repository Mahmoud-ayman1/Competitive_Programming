#include<bits/stdc++.h>
using namespace std;
#define ll long long
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;cin>>n;
    int s[n];
    for(auto &it:s)cin>>it;
    sort(s,s+n);
    cin>>k;while(k--)
    {
        int a,b;cin>>a>>b;;
        cout<<(upper_bound(s,s+n,b)-s)-(lower_bound(s,s+n,a)-s)<<' ';
    }
    return 0;
}
