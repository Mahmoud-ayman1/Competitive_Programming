#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5,mod=1e9+7;
bool is_prime(ll n)
{
    if(n==1||n==0)return 0;
    else if(n==2)return 1;
    else if(n%2==0)return 0;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)return 0;
    }
    return 1;
}
ll gcd(ll a,ll b)
{
    if(a>b) swap(a,b);
    if(a==0)return b;
    return gcd(b%a,a);
}
int lcm(int a,int b)
{
    return a/gcd(a,b)*b;
}
ll power(ll a,ll b)
{
    if(b==0)return 1;
    ll x=power(a,b/2);
    x*=x;
    if(b%2!=0)x*=a;
    return x;
}
vector<bool> isPrime(N,true);
void sieve()
{
    isPrime[0] = false;
    isPrime[1] = false;

    for(ll i=2;i*i<N;i++)
    {
        if(isPrime[i])
        {
            for(ll j=i*i;j<N;j+=i)
            {
                isPrime[j] = false;
            }
        }
    }
}
vector<pair<ll,ll>> primeFactorze(ll n)
{
    vector<pair<ll,ll>> arr;
    for(ll i=2;i*i<=n;i++)
    {
        int w=0;
        while(n%i==0)
        {
            w++;
            n/=i;
        }
        if(w)arr.push_back({i,w});
    }
    if(n>1)arr.push_back({n,1});
    return arr;
}
vector<long long> divisors(long long n)
{
    vector<ll>arr;
    for (long long i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            arr.push_back(i);
            if (i * i != n)
            {
                arr.push_back(n / i);
            }
        }
    }
    return arr;
}
ll powmod(ll x, ll y)
{
    ll res = 1;
    x = x % mod;
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % mod;
        y = y>>1;
        x = (x*x) % mod;
    }
    return res;
}
ll add(ll a,ll b)
{
    return ((a%mod)+(b%mod))%mod;
}
ll mul(ll a,ll b)
{
    return ((a%mod)*(b%mod))%mod;
}
ll sub(ll a,ll b)
{
    return ((((a%mod)-(b%mod))%mod)+mod)%mod;
}
ll divide(ll a,ll b)
{
    return mul(a,powmod(b,mod-2));
}
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    return 0;
}
