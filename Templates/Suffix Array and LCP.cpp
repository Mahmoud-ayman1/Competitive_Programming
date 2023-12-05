void countSort(vector<int>&p,vector<int>&c)
{
    int n=p.size();
    vector<int>cnt(n);
    for(auto it:c) cnt[it]++;
    vector<int>p_new(n),pos(n);
    pos[0]=0;
    for(int i=1;i<n;i++) pos[i]=pos[i-1]+cnt[i-1];
    for(auto it:p)
    {
        int i=c[it];
        p_new[pos[i]]=it;
        pos[i]++;
    }
    p=p_new;
}
pair<vector<int>,vector<int>>SuffixArray_LCP(string &s)
{
    s+='$';
    int n=s.size();
    vector<pair<char,int>>suf(n);
    for(int i=0;i<n;i++) suf[i]={s[i],i};
    sort(suf.begin(),suf.end());
    vector<int>p(n),c(n);
    for(int i=0;i<n;i++) p[i]=suf[i].second;
    c[p[0]]=0;
    for(int i=1;i<n;i++)
    {
        if(suf[i].first==suf[i-1].first) c[p[i]]=c[p[i-1]];
        else c[p[i]]=c[p[i-1]]+1;
    }
    int k=0;
    while((1<<k)<n)
    {
        for(int i=0;i<n;i++) p[i]=(p[i]-(1<<k)+n)%n;
        countSort(p,c);
        vector<int>c_new(n);
        c_new[p[0]]=0;
        for(int i=1;i<n;i++)
        {
            pair<int,int>last={c[p[i-1]],c[(p[i-1]+(1<<k))%n]};
            pair<int,int>cur={c[p[i]],c[(p[i]+(1<<k))%n]};
            if(cur==last) c_new[p[i]]=c_new[p[i-1]];
            else c_new[p[i]]=c_new[p[i-1]]+1;
        }
        c=c_new;
        k++;
    }
    vector<int>lcp(n);
    k=0;
    for(int i=0;i<n-1;i++)
    {
        int pi=c[i],j=p[pi-1];
        while(s[i+k]==s[j+k]) k++;
        lcp[pi]=k;
        k=max(k-1,0);
    }
    return {p,lcp};
}
