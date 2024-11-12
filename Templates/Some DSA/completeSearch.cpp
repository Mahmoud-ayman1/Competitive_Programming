vector<ll>sub;
for(int mask=0;mask<(1<<n);mask++)
{
    sub.clear();
    for(int i=0;i<n;i++)
    {
        if(mask&(1<<i))
        {
            sub.push_back(s[i]);
        }
    }
    // what you need to do with sub
}
