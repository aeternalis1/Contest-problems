#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 100005;
#define f first
#define s second

int main(){
    freopen("lazy.in","r",stdin);
    freopen("lazy.out","w",stdout);
    int N,K;
    scanf("%d %d",&N,&K);
    int arr[N][N], nums[N+1][N+1];
    memset(nums,0,sizeof nums);
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            scanf("%d",&arr[i][j]);
            for (int k=max(0,i-K);k<=min(N-1,i+K);k++){
                nums[k][max(0,j-(K-abs(i-k)))] += arr[i][j];
                nums[k][min(N-1,j+(K-abs(i-k)))+1] -= arr[i][j];
            }
        }
    }
    int cur, ans = 0;
    for (int i=0;i<N;i++){
        cur = 0;
        for (int j=0;j<N;j++){
            cur += nums[i][j];
            ans = max(ans,cur);
        }
    }
    printf("%d\n",ans);
}
