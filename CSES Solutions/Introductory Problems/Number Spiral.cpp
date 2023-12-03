#include<bits/stdc++.h>
using namespace std;
#define ll long long
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    {
        ll a,b;cin>>a>>b;
        if(a>=b)
        {
            if(a&1)
            {
                cout<<(a-1)*(a-1)+1+(b-1)<<'\n';
            }
            else
            {
                cout<<a*a-(b-1)<<'\n';
            }
        }
        else
        {
            if(b&1)
            {
                cout<<b*b-(a-1)<<'\n';
            }
            else
            {
                cout<<(b-1)*(b-1)+1+(a-1)<<'\n';
            }
        }
    }
    return 0;
}
