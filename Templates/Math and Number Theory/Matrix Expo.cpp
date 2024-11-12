#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int mod=1e9+7;
struct Matrix {
    vector<vector<ll>>m;
    Matrix() {
        m.assign(2,vector<ll>(2,0));
    }
    Matrix operator*(Matrix&other)const{
        Matrix ans;
        for (ll i = 0; i < 2; i++)
            for (ll j = 0; j < 2; j++)
                for (ll k = 0; k < 2; k++)
                    ans.m[i][j]+=m[i][k]*other.m[k][j],
                        ans.m[i][j]%=mod;
        return ans;
    }
};
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    Matrix base;
    base.m={
            {1,0},
            {0,0}
    };
    Matrix trans;
    trans.m={
            {19,7},
            {6,20}
    };
    auto powmod=[&](ll pw){
        while(pw)
        {
            if(pw&1)base=base*trans;
            trans=trans*trans;
            pw/=2;
        }
    };
    int n;cin>>n;
    powmod(n);
    cout<<base.m[0][0];
    return 0;
}
