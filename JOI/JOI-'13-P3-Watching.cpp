#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 2001
#define MAXP 1001

int dp[MAXN][MAXP]; //all segments up to [i] have been covered with the min. number of w cameras, using [j] w*2 cameras

vector<int> nums;

bool solve(int N, int w, int w2, int P, int Q){
    for (int i=0;i<=N;i++){
        for (int j=0;j<=P;j++){
            dp[i][j] = 10000;
        }
    }
    dp[0][0] = 0;
    int ind1,ind2;
    for (int i=1;i<=N;i++){
        ind1 = lower_bound(nums.begin(),nums.end(),nums[i]+w2)-nums.begin();
        if (ind1>N||nums[ind1]>=nums[i]+w2) ind1--;
        ind2 = lower_bound(nums.begin(),nums.end(),nums[i]+w)-nums.begin();
        if (ind2>N||nums[ind2]>=nums[i]+w) ind2--;
        for (int j=0;j<min(i,P+1);j++){
            if (dp[i-1][j]==10000) continue;
            if (dp[i-1][j]!=Q){
                dp[ind1][j] = min(dp[ind1][j],dp[i-1][j]+1);
            }
            if (j<P){
                dp[ind2][j+1] = min(dp[ind2][j+1],dp[i-1][j]);
            }
        }
    }
    for (int i=0;i<=P;i++){
        if (dp[N][i]!=10000) return 1;
    }
    return 0;
}


int main(){
    int N,P,Q,cur;
    scanf("%d %d %d",&N,&P,&Q);
    nums.push_back(0);
    unordered_map<int,bool> seen;
    if (P+Q>=N){
        printf("1\n");
        return 0;
    }
    for (int i=0;i<N;i++){
        scanf("%d",&cur);
        if (!seen[cur]) nums.push_back(cur);
        seen[cur] = 1;
    }
    sort(nums.begin(),nums.end());
    N = nums.size()-1;
    int lo = 1, hi = 1e9, mid;
    while (lo<hi){
        mid = (lo+hi)/2;
        if (P<Q){
            if (solve(N,mid,mid*2,P,Q)){
                hi = mid;
            }else{
                lo = mid+1;
            }
        }else{
            if (solve(N,mid*2,mid,Q,P)){
                hi = mid;
            }else{
                lo = mid+1;
            }
        }
    }
    printf("%d\n",lo);
}
