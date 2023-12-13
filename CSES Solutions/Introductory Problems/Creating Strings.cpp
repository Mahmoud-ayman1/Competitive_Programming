#include <bits/stdc++.h>
using namespace std;
#define ll long long
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;cin>>s;
    sort(s.begin(),s.end());
    set<string>st;
    do{
        st.insert(s);
    }while(next_permutation(s.begin(),s.end()));
    cout<<st.size()<<'\n';
    for(auto it:st) cout<<it<<'\n';
    return 0;
}
