#include<bits/stdc++.h>
using namespace std;
#define ll long long
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    string s[n];
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    sort(s[0].begin(),s[0].end());
    vector<string>ans={s[0]};
    for(int i=1;i<n;i++)
    {
        int f[26]={};
        for(auto it:s[i])
        {
            f[it-'a']++;
        }
        string cur="";
        for(int o=0;o<ans.back().size();o++)
        {
            char c=ans.back()[o];
            if(f[c-'a'])
            {
                cur.push_back(c);
                f[c-'a']--;
            }
            else
            {
                for(int p=c-'a'+1;p<26;p++)
                {
                    if(f[p])
                    {
                        cur.push_back(char(p+'a'));
                        f[p]--;
                        goto done;
                    }
                }
                while(cur.size())
                {
                    f[cur.back()-'a']++;
                    for(int p=cur.back()-'a'+1;p<26;p++)
                    {
                        if(f[p])
                        {
                            cur.pop_back();
                            cur.push_back(char(p+'a'));
                            f[p]--;
                            goto done;
                        }
                    }
                    cur.pop_back();
                }
            }
        }
        done:{};
        for(int o=0;o<26;o++)
        {
            while(f[o]--)
            {
                cur.push_back(char(o+'a'));
            }
        }
        ans.push_back(cur);
    }
    if(is_sorted(ans.begin(),ans.end()))
    {
        for(auto it:ans)
        {
            cout<<it<<'\n';
        }
    }
    else
    {
        cout<<-1;
    }
    return 0;
}
