std::mt19937_64 rnd(std::chrono::system_clock::now().time_since_epoch().count());
struct Treap{
    struct Node{
        char key=0;
        int rev=0,pri=rnd(),sz=1;
        array<Node*,2>c={0,0};
        Node(){}
        Node(char k){
            key=k;
        }
    };
    Node*root=0;
    int getSize(Node*t)
    {
        return t?t->sz:0;
    }
    Treap(string&s)
    {
        for(int i=0;i<s.size();i++)
        {
            root=merge(root,new Node(s[i]));
        }
    }
    Node*fix(Node*t)
    {
        t->sz=getSize(t->c[0])+getSize(t->c[1])+1;
        return t;
    }
    void propegate(Node*t)
    {
        if(!t||!t->rev) return;
        swap(t->c[0],t->c[1]);
        if(t->c[0]) t->c[0]->rev^=1;
        if(t->c[1]) t->c[1]->rev^=1;
        t->rev=0;
    }
    array<Node*,2>split(Node*t,int k)
    {
        if(!t) return {0,0};
        propegate(t);
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
        propegate(u);
        propegate(v);
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
    void reverse(int l,int r)
    {
        auto a=split(root,l-1);
        auto b=split(a[1],r-l+1);
        b[0]->rev^=1;
        root=merge(a[0],merge(b[0],b[1]));
    }
    char getChar(int idx)
    {
        auto a=split(root,idx-1);
        auto b=split(a[1],1);
        propegate(b[0]);
        char ret=b[0]->key;
        merge(a[0],merge(b[0],b[1]));
        return ret;
    }
    void print(Node*t)
    {
        if(!t) return;
        print(t->c[0]);
        cout<<t->key<<' ';
        print(t->c[1]);
    }
};
