const int N=1e5+5;
struct KMP{
    int longestPrefix[N]={};vector<int>ans;
    void calcPrefix(string patern)
    {
        int n=patern.size();
        for(int i=1,idx=0;i<n;i++)
        {
            while(idx>0&&patern[idx]!=patern[i])idx=longestPrefix[idx-1];
            if(patern[i]==patern[idx])idx++;
            longestPrefix[i]=idx;
        }
    }
    void kmp(string s,string pat)
    {
        int n=s.size(),m=pat.size();
        calcPrefix(pat);
        for(int i=0,idx=0;i<n;i++)
        {
            while(idx>0&&s[i]!=pat[idx])idx=longestPrefix[idx-1];
            if(s[i]==pat[idx])idx++;
            if(idx==m)ans.push_back(i-m+1),idx=longestPrefix[idx-1];
        }
    }
};
