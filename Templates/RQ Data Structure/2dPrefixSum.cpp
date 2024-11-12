void _2d_prefix()
{
    for(int i=1;i<=n;i++)
    {
        for(int o=1;o<=m;o++)
        {
            s[i][o]+=s[i][o-1];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int o=1;o<=m;o++)
        {
            s[i][o]+=s[i-1][o];
        }
    }
}
int query(int l1,int r1,int l2,int r2)
{
    int x=f[l2][r2]-f[l1-1][r2];
    int y=f[l2][r1-1]-f[l1-1][r1-1];
    return x-y;
}
