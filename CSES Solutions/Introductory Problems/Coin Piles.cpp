#include<bits/stdc++.h>
using namespace std;
#define ll long long
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    {
        ll a,b;cin>>a>>b;
        if(a>b) swap(a,b);
        if((a+b)%3==0)
        {
            if(a*2>=b)
            {
                cout<<"YES\n";
                continue;
            }
        }
        cout<<"NO\n";
    }
    return 0;
}
