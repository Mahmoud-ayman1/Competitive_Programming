// dsu with roll back
struct dsu
{
    int parent[N],group[N];stack<array<int,4>>st;
    dsu()
    {
        for(int i=0;i<N;i++)
        {
            parent[i]=i;
            group[i]=1;
        }
    }
    int find(int i)
    {
        if(parent[i]==i)
        {
            return i;
        }
        return find(parent[i]);
    }
    bool samegroup(int x,int y)
    {
        return find(x)==find(y);
    }
    void merge(int x,int y)
    {
        int leader1=find(x);
        int leader2=find(y);
        if(group[leader1]>group[leader2])
        {
            swap(leader1,leader2);
        }
        array<int,4>p={0,0,0,0};
        p[0]=leader2,p[1]=group[leader2];
        p[2]=leader1,p[3]=parent[leader1];
        st.push(p);
        if(leader1==leader2)
        {
            return;
        }
        group[leader2]+=group[leader1];
        parent[leader1]=leader2;
    }
    int getsize(int x)
    {
        return group[find(x)];
    }
    void rollBack()
    {
        if(st.empty())return;
        auto &[a,b,c,d]=st.top();
        st.pop();
        group[a]=b;
        parent[c]=d;
    }
};
