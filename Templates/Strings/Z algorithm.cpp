#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int>Z;
void build(string&s)
{
    Z=vector<int>(s.size());
    int l=0,r=0;
    for(int i=1;i<s.size();i++)
    {
        if(i>=r||i+Z[i-l]>=r)
        {
            l=i;
            r=max(r,i);
            while(r<s.size()&&s[r]==s[r-l])
            {
                r++;
            }
            Z[i]=r-l;
        }
        else
        {
            Z[i]=Z[i-l];
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;cin>>s;
    build(s);
    // your sol here
    return 0;
}
