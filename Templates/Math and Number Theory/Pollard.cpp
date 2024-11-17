class Pollard
{
    using ul = uint64_t;
    using db = long double;
    map<ul,int>cnt_primes;
    vector<ul>primes,divisors;
    ul modMul(ul a,ul b,const ul mod)
    {
        ll ret=a*b-mod*(ul)((db)a*b/mod);
        return ret+((ret<0)-(ret>=(ll)mod))*mod;
    }
    ul modPow(ul a,ul b,const ul mod)
    {
        if (b==0)
        {
            return 1;
        }
        ul res=modPow(a,b/2,mod);
        res=modMul(res,res,mod);
        return b&1?modMul(res,a,mod):res;
    }

    bool rabin_miller(ul n)
    {
        if(n<2||n%6%4!=1)
        {
            return n-2<2;
        }
        ul A[]={2,325,9375,28178,450775,9780504,1795265022},s=__builtin_ctzll(n-1),d=n>>s;
        for(auto a:A)
        {
            ul p=modPow(a,d,n),i=s;
            while(p!=1&&p!=n-1&&a%n&&i--)
            {
                p=modMul(p,p,n);
            }
            if(p!=n-1&&i!=s)
            {
                return 0;
            }
        }
        return 1;
    }
    ul pollard(ul n) // return some nontrivial factor of n
    {
        auto f=[n,this](ul x){return modMul(x,x,n)+1;};
        ul x=0,y=0,t=30,prd=2,i=1,q;
        while(t++%40||__gcd(prd,n)==1)
        {  /// speedup: don't take gcd every it
            if (x == y)
            {
                x=++i,y=f(x);
            }
            if((q=modMul(prd,max(x,y)-min(x,y),n)))
            {
                prd=q;
            }
            x=f(x),y=f(f(y));
        }
        return __gcd(prd,n);
    }
    void factor_rec(ul n, map<ul, int> &cnt) {
        if (n == 1) return;
        if (rabin_miller(n)) {
            ++cnt[n];
            return;
        }
        ul u = pollard(n);
        factor_rec(u, cnt), factor_rec(n / u, cnt);
    }
    void calcDivisorsRec(ul cur, int i) {
        if (i >= primes.size()) {
            divisors.push_back(cur);
            return;
        }
        int r = cnt_primes[primes[i]];
        for (int j = 0; j <= r; j++) {
            calcDivisorsRec(cur, i + 1);
            cur = cur * primes[i];
        }
    }
    void calcDivisors(ul x) {
        cnt_primes.clear();
        primes.clear();
        divisors.clear();
        factor_rec(x, cnt_primes);
        for (auto &u : cnt_primes) {
            primes.push_back(u.first);
        }
        calcDivisorsRec(1, 0);
    }
}pollard;
