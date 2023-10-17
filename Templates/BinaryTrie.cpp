struct BinaryTrie{
    struct Node{
        Node *child[2];
        int frq[2];
        Node(){
            child[0]=child[1]=0;
            frq[0]=frq[1]=0;
        }
    };
    Node *root=new Node();
    void insert(int n)
    {
        Node *cur=root;
        for(int i=29;i>=0;i--)
        {
            bool idx=(n>>i)&1;
            if(cur->child[idx]==0) cur->child[idx]=new Node();
            cur->frq[idx]++;
            cur=cur->child[idx];
        }
    }
    void del(int n,int i,Node *cur)
    {
        if(i==-1)return;
        bool idx=(n>>i)&1;
        del(n,i-1,cur->child[idx]);
        cur->frq[idx]--;
        if(cur->frq[idx]==0)
        {
            delete cur->child[idx];
            cur->child[idx]=0;
        }
    }
    int query(int n)
    {
        int ret=0;Node *cur=root;
        for(int i=29;i>=0;i--)
        {
            bool idx=(n>>i)&1;
            if(cur->child[idx^1]==0) cur=cur->child[idx];
            else cur=cur->child[idx^1],ret|=(1<<i);
        }
        return ret;
    }
};
