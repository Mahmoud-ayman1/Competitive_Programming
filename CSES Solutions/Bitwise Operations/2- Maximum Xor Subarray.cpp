#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct binaryTrie{
    struct Node{
        Node*child[2];
        Node(){
            child[0]=child[1]=0;
        }
    };
    binaryTrie(){
        insert(0);
    }
    Node*root=new Node();
    void insert(int n)
    {
        Node*cur=root;
        for(int i=30;i>=0;i--)
        {
            int idx=(n>>i)&1;
            if(cur->child[idx]==0) cur->child[idx]=new Node();
            cur=cur->child[idx];
        }
    }
    int maxXor(int n)
    {
        Node*cur=root;int ret=0;
        for(int i=30;i>=0;i--)
        {
            int idx=(n>>i)&1;
            if(cur->child[idx^1]!=0) cur=cur->child[idx^1],ret|=(1<<i);
            else cur=cur->child[idx];
        }
        return ret;
    }
};
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    binaryTrie trie;
    int ans=0,xr=0;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        xr^=x;
        trie.insert(xr);
        ans=max(ans,trie.maxXor(xr));
    }
    cout<<ans;
    return 0;
}
