#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 200001;
#define first f;
#define second s;

int main() {
    freopen("248.in","r",stdin);
    freopen("248.out","w",stdout);
    int N, ans = 0;
    scanf("%d",&N);
    int arr[N], dp[N][N];
    memset(dp,0,sizeof dp);
    for (int i=0;i<N;i++){
        scanf("%d",&arr[i]);
        dp[i][i] = arr[i];
    }
    for (int i=1;i<N;i++){ //interval size
        for (int l=0;l<N-i;l++){ //left bound
            int r = l+i;
            for (int m=l;m<r;m++){
                if (dp[l][m]==dp[m+1][r]&&dp[l][m]){
                    dp[l][r] = dp[l][m]+1;
                }
            }
        }
    }
    for (int i=0;i<N;i++) for (int j=0;j<N;j++) ans = max(ans,dp[i][j]);
    printf("%d\n",ans);
}
