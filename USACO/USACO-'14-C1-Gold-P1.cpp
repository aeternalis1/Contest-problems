#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
typedef long long ll;
#define f first
#define s second


int main() {
    freopen("guard.in","r",stdin);
    freopen("guard.out","w",stdout);
    int N,H;
    scanf("%d %d",&N,&H);
    ll arr[N][3], dp[(1<<N)];
    memset(dp,-1,sizeof dp);
    for (int i=0;i<N;i++){
        scanf("%lld %lld %lld",&arr[i][0],&arr[i][1],&arr[i][2]);
    }
    dp[0] = 1e10;
    ll res = 0, ans = -1;
    for (int i=0;i<(1<<N);i++){
        if (dp[i]!=-1){
            res = 0;
            for (int j=0;j<N;j++){
                if (!(i&(1<<j))){
                    dp[i^(1<<j)] = max(dp[i^(1<<j)],min(dp[i]-arr[j][1],arr[j][2]));
                }else{
                    res += arr[j][0];
                }
            }
            if (res>=H){
                ans = max(ans,dp[i]);
            }
        }
    }
    if (ans!=-1) printf("%lld\n",ans);
    else printf("Mark is too tall");
}
