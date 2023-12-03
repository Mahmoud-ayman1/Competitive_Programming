#include<bits/stdc++.h>
using namespace std;
#define ll long long
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    set<int>st;
    for(int i=1;i<=n;i++) st.insert(i);
    while(--n)
    {
        int x;cin>>x;
        st.erase(x);
    }
    cout<<*st.begin();
    return 0;
}
