#include<bits/stdc++.h>
using namespace std;
#define ll long long
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    {
        ll n;cin>>n;
        ll x=9,num=0,c=0,sum=0;
        while(sum<n)
        {
            num=num*10+9;
            c++;
            if(sum+x*c<n) sum+=x*c;
            else
            {
                num=(num-9)/10;
                break;
            }
            x=x*10;
        }
        n-=sum;
        ll w=n/c;
        num+=w;
        n-=w*c;
        if(n==0)
        {
            string s=to_string(num);
            reverse(s.begin(),s.end());
            cout<<s[n]<<'\n';
        }
        else
        {
            string s=to_string(num+1);
            cout<<s[n-1]<<'\n';
        }
    }
    return 0;
}
