struct SOS{
    vector<int>dp;int MXN,Log;
    SOS(int n,vector<int>&v)
    {
        Log=n;
        MXN=1<<n;
        dp=vector<int>(MXN);
        dp=v;
    }
    void forward1(){	// adding element to all its super set
        for(int bit=0;bit<Log;bit++)for(int i=0;i<MXN;i++)if(i&(1<<bit)){dp[i]+=dp[i^(1<<bit)];}}
    void backward1(){	//add a[i] to a[j] if j&i = i
        for(int bit=0;bit<Log;bit++)for(int i=MXN;i>=0;i--)if(i&(1<<bit)){dp[i]-=dp[i^(1<<bit)];}}
    void forward2(){// add elements to its subsets
        for(int bit=0;bit<Log;bit++)for(int i=MXN;i>=0;i--)if(i&(1<<bit)){dp[i^(1<<bit)]+=dp[i];}}
    void backward2(){
        for(int bit=0;bit<Log;bit++)for(int i=0;i<MXN;i++)if(i&(1<<bit)){dp[i^(1<<bit)]-=dp[i];}}
};
