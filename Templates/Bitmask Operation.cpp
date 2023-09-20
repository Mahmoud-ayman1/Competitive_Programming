bool Knowbit(ll n,int i)
{
    return (n>>i)&1;
}
ll Setbit(ll n,int i)
{
    return n|(1<<i);
}
ll Resetbit(ll n,int i)
{
    return n&(~(1<<i));
}
ll flip(ll n,int i)
{
    return n^(1<<i);
}
bool isPowerOfTwo(int n)
{
    if(n==0)return 0;
    return !(n&(n-1));
}
