const int N=305;
int n,dp[N][27][27];
class Solution {
public:
    int dis(int a,int b,int c,int d){
        if(a==-1) return 0;
        return abs(a-c)+abs(b-d);
    }
    pair<int,int> pos(int x){
        if(x==26) return {-1,-1};
        return {x/6,x%6};
    }
    int solve(string&s,int i=0,int a=26,int b=26){
        if(i==n) return 0;
        int&ret=dp[i][a][b];
        if(~ret) return ret;
        auto[A,B]=pos(a);
        auto[X,Y]=pos(b);
        auto[L,R]=pos(s[i]-'A');
        return ret=min(
                solve(s,i+1,s[i]-'A',b)+dis(A,B,L,R),
                solve(s,i+1,a,s[i]-'A')+dis(X,Y,L,R)
            );
    }
    int minimumDistance(string word) {
        n=word.size();
        for(int i=0;i<n;i++){
            memset(dp[i],-1,sizeof dp[i]);
        }
        return solve(word);
    }
};
