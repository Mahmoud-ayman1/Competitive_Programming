#include<bits/stdc++.h>
using namespace std;
#define ll long long
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int idx=0;
    for(int i=0;i<m;i++)
    {
        int x;cin>>x;
        while(idx<n&&a[idx]<x)
        {
            idx++;
        }
        cout<<idx<<' ';
    }
    return 0;
}
