#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
typedef long long ll;
ll arr[MAXN], sums[MAXN];

int solve(ll r, ll B, int N){
    ll dis = 0;
    for (int i=0;i<N-r+1;i++){
        if (r%2) dis = sums[r+i]-sums[r/2+i]+sums[i]-sums[r/2+1+i];
        else{
            dis = arr[r/2+i]*(r/2)-(sums[r/2+i]-sums[i]);
            //printf("%d %d %d\n",arr[r/2+i]*(r/2),sums[r/2+i]-sums[i],dis);
            dis += (sums[r+i]-sums[r+i-r/2+1])-(arr[r/2+i]*(r/2-1));
            //printf("%d %d\n",sums[r+i]-sums[r+i-r/2+1],arr[r/2+i]*(r/2-1));
        }
        //if (r==3) printf("%d %d\n",i,dis);
        //printf("%d %d %d\n",sums[r+i],sums[i],sums[r/2+1+i]);
        if (dis<=B) return 1;
    }
    return 0;
}

int besthub(int R, int L, int X[], ll B){
    for (int i=0;i<R;i++) arr[i] = X[i];
    for (int i=0;i<=R;i++) sums[i+1] = sums[i]+arr[i];
    int lo = 1;
    int hi = R+1;
    //return solve(3,B,R);
    while (lo<hi){
        int mid = (lo+hi)/2;
        if (solve(mid,B,R)) lo = mid+1;
        else hi = mid;
    }
    return lo-1;
}
