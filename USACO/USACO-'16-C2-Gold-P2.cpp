#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 300005;
#define f first
#define s second

int main(){
    freopen("hps.in","r",stdin);
    freopen("hps.out","w",stdout);
    int N,K,cur;
    char c;
    scanf("%d %d",&N,&K);
    int dp[N+1][K+1][3];
    for (int i=0;i<=N;i++){
        for (int j=0;j<=K;j++){
            for (int k=0;k<3;k++){
                dp[i][j][k] = 0;
            }
        }
    }
    for (int i=0;i<N;i++){
        scanf(" %c",&c);
        if (c=='P') cur = 0;
        else if (c=='H') cur = 1;
        else cur = 2;
        for (int j=0;j<=K;j++){
            for (int k=0;k<3;k++){
                if (cur==k){
                    dp[i+1][j][k] = max(dp[i+1][j][k],dp[i][j][k]+1);
                }else{
                    dp[i+1][j][k] = max(dp[i+1][j][k],dp[i][j][k]);
                }
                if (j<K){
                    dp[i+1][j+1][cur] = max(dp[i+1][j+1][cur],dp[i][j][k]+1);
                }
            }
        }
    }
    int ans = 0;
    for (int i=0;i<=N;i++){
        for (int j=0;j<=K;j++){
            for (int k=0;k<3;k++){
                ans = max(ans,dp[i][j][k]);
            }
        }
    }
    printf("%d\n",ans);
}
