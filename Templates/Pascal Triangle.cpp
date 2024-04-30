ll c[n][n]={};
c[0][0]=1;
for(int i=1;i<n;i++)
{
    c[i][0]=c[i][i]=1;
    for(int o=1;o<i;o++)
    {
        c[i][o]=c[i-1][o-1]+c[i-1][o];
    }
}
