#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 200001;
#define f first
#define s second

int d(int a, int b, int c, int d){
    return pow(c-a,2)+pow(d-b,2);
}

int main(){
    freopen("checklist.in","r",stdin);
    freopen("checklist.out","w",stdout);
    int N,M;
    scanf("%d %d",&N,&M);
    int arr[N][2],arr2[M][2];
    ll dp[N+1][M+1][2];
    for (int i=0;i<N;i++){
        scanf("%d %d",&arr[i][0],&arr[i][1]);
    }
    for (int i=0;i<M;i++){
        scanf("%d %d",&arr2[i][0],&arr2[i][1]);
    }
    for (int i=0;i<=N;i++){
        for (int j=0;j<=M;j++){
            dp[i][j][0] = dp[i][j][1] = 1e18;
        }
    }
    dp[1][0][0] = 0;
    for (int i=1;i<N;i++){
        for (int j=0;j<M;j++){
            if (j) dp[i][j+1][1] = min(dp[i][j+1][1],d(arr2[j][0],arr2[j][1],arr2[j-1][0],arr2[j-1][1])+dp[i][j][1]);
            dp[i][j+1][1] = min(dp[i][j+1][1],d(arr[i-1][0],arr[i-1][1],arr2[j][0],arr2[j][1])+dp[i][j][0]);
        }
        for (int j=0;j<=M;j++){
            if (i<N-1){
                if (i) dp[i+1][j][0] = min(dp[i+1][j][0],d(arr[i][0],arr[i][1],arr[i-1][0],arr[i-1][1])+dp[i][j][0]);
                if (j) dp[i+1][j][0] = min(dp[i+1][j][0],d(arr2[j-1][0],arr2[j-1][1],arr[i][0],arr[i][1])+dp[i][j][1]);
            }
        }
    }
    printf("%lld\n",min(dp[N-1][M][0]+d(arr[N-2][0],arr[N-2][1],arr[N-1][0],arr[N-1][1]),dp[N-1][M][1]+d(arr2[M-1][0],arr2[M-1][1],arr[N-1][0],arr[N-1][1])));
}
