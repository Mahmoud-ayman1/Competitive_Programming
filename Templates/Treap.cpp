std::mt19937_64 rnd(std::chrono::system_clock::now().time_since_epoch().count());
struct Treap{
    struct Node{
        int key=0,val=0,pri=rnd(),sz=1;
        array<Node*,2>c={0,0};
        Node(){}
        Node(int k,int x=0){
            key=k;
            val=x;
        }
    };
    Node*root=0;
    int getSize(Node*t)
    {
        return t?t->sz:0;
    }
    Treap(int n)
    {
        for(int i=1;i<=n;i++)
        {
            root=merge(root,new Node(i));
        }
    }
    Node*fix(Node*t)
    {
        t->sz=getSize(t->c[0])+getSize(t->c[1])+1;
        return t;
    }
    array<Node*,2>split(Node*t,int k)
    {
        if(!t) return {0,0};
        if(getSize(t->c[0])>=k)
        {
            auto ret=split(t->c[0],k);
            t->c[0]=ret[1];
            return {ret[0],fix(t)};
        }
        else
        {
            auto ret=split(t->c[1],k-getSize(t->c[0])-1);
            t->c[1]=ret[0];
            return {fix(t),ret[1]};
        }
    }
    Node*merge(Node*u,Node*v)
    {
        if(!u||!v) return u?u:v;
        if(u->pri>v->pri)
        {
            u->c[1]=merge(u->c[1],v);
            return fix(u);
        }
        else
        {
            v->c[0]=merge(u,v->c[0]);
            return fix(v);
        }
    }
    void print(Node*t)
    {
        if(!t) return;
        print(t->c[0]);
        cout<<t->key<<' ';
        print(t->c[1]);
    }
};
