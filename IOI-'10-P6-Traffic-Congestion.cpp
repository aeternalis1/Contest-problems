#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000001;
typedef long long ll;
vector<int> paths[MAXN];
int dp[MAXN], par[MAXN], val[MAXN];

int dfs(int c, int p){
    dp[c] = val[c];
    for (int i:paths[c]){
        if (i==p) continue;
        par[i] = c;
        dp[c] += dfs(i,c);
    }
    return dp[c];
}

int LocateCentre(int N, int P[], int S[], int D[]){
    for (int i=0;i<N-1;i++){
        paths[S[i]].push_back(D[i]);
        paths[D[i]].push_back(S[i]);
    }
    for (int i=0;i<N;i++) val[i] = P[i];
    dfs(0,-1);
    int ans = 2e9+1, res, ind;
    for (int i=0;i<N;i++){
        res = dp[0]-dp[i];
        for (int j:paths[i]){
            if (j==par[i]) continue;
            res = max(res,dp[j]);
        }
        if (res<ans){
            ans = res;
            ind = i;
        }
    }
    return ind;
}
