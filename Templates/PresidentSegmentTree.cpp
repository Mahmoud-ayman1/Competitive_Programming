struct PresidentSegmentTree{
public:
    PresidentSegmentTree(int n){
        sz = n;
        roots.push_back(new node(0));
    }
    void set(int idx , int val , int version = 1){
        version--;
        roots[version] = set(idx , val , roots[version] , 1 , sz);
    }
    void newVersion(int version){
        version--;
        roots.push_back(roots[version]);
    }
    ll query(int l , int r , int version){
        version--;
        return query(l , r , roots[version] , 1 , sz);
    }
private:
    struct node{
        ll val;
        node *l , *r;
        node(ll v){
            val = v;
            l = r = this;
        }
        node(node *_l , node *_r){
            val = 0;
            l = _l;
            r = _r;
            if(l) val+=l->val;
            if(r) val+=r->val;
        }
    };
    vector<node*> roots;
    int sz;
    node* set(int idx , int val , node *cur , int l , int r){
        if(l == r) return new node(val);
        int md = l + (r-l) / 2;
        if(idx <= md) return new node(set(idx , val , cur->l , l , md) , cur->r);
        return new node(cur->l , set(idx , val , cur->r , md+1 , r));
    }
    ll query(int l , int r , node *cur , int lx , int rx){
        if(lx >= l && rx <= r) return cur->val;
        if(lx > r || rx < l) return 0;
        int md = lx + (rx-lx) / 2;
        return query(l , r , cur->l , lx , md) + query(l , r , cur->r , md+1 , rx);
    }
};
