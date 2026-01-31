#include<bits/stdc++.h>
using namespace std;
#define ll long long
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string a,b;cin>>a>>b;
    for(auto&it:a) it=tolower(it);
    for(auto&it:b) it=tolower(it);
    cout<<a[0]<<b<<"@noon.com";
    return 0;
}
