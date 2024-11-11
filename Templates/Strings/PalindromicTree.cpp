#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct PalindromicTree
{
    struct node {
        int nxt[26],len,st, en,link,cnt,oc;
    };
    string s;vector<node>t;
    int sz,last;
    PalindromicTree(){}
    PalindromicTree(string _s){
        s=_s;
        int n=s.size();
        t.clear();
        t.resize(n + 9);
        sz=2,last=2;
        t[1].len=-1,t[1].link=1;
        t[2].len=0,t[2].link=1;
    }
    int add(int pos)
    {
        int cur=last,curlen=0;
        int ch=s[pos]-'a';
        while(1)
        {
            curlen=t[cur].len;
            if(pos-1-curlen>=0&&s[pos-1-curlen]==s[pos])
            {
                break;
            }
            cur=t[cur].link;
        }
        if(t[cur].nxt[ch])
        {
            last=t[cur].nxt[ch];
            t[last].oc++;
            return 0;
        }
        sz++;
        last=sz;
        t[sz].oc=1;
        t[sz].len=t[cur].len+2;
        t[cur].nxt[ch]=sz;
        t[sz].en=pos;
        t[sz].st=pos-t[sz].len+1;
        if(t[sz].len==1)
        {
            t[sz].link=2;
            t[sz].cnt=1;
            return 1;
        }
        while(1)
        {
            cur=t[cur].link;
            curlen=t[cur].len;
            if(pos-1-curlen>=0&&s[pos-1-curlen]==s[pos])
            {
                t[sz].link=t[cur].nxt[ch];
                break;
            }
        }
        t[sz].cnt=1+t[t[sz].link].cnt;
        return 1;
    }
    void calc_occurrences()
    {
        for(int i=sz;i>=3;i--)
        {
            t[t[i].link].oc+=t[i].oc;
        }
    }
    string Max()
    {
        int len=0,a=0,b=0;
        for(int i=sz;i>=3;i--)
        {
            if(t[i].en-t[i].st+1>len)
            {
                len=t[i].en-t[i].st+1;
                a=t[i].st,b=t[i].en;
            }
        }
        return s.substr(a,len);
    }
};
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;cin>>s;
    PalindromicTree tree(s);
    for(int i=0;i<s.size();i++)
    {
        tree.add(i);
    }
    cout<<tree.Max();
    return 0;
}
