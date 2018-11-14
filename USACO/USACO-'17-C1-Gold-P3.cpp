#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 100005;
#define f first
#define s second

int main(){
    freopen("hayfeast.in","r",stdin);
    freopen("hayfeast.out","w",stdout);
    ll N,M;
    scanf("%lld %lld",&N,&M);
    ll arr[N][2], cur=0, ans = 1e18;
    for (int i=0;i<N;i++){
        scanf("%lld %lld",&arr[i][0],&arr[i][1]);
    }
    priority_queue<pair<ll,int>> pq;
    for (int l=0,r=0;r<N;r++){
        cur += arr[r][0];
        pq.push({arr[r][1],r});
        while (cur<M&&r<N-1){
            cur += arr[++r][0];
            pq.push({arr[r][1],r});
        }
        while (cur-arr[l][0]>=M){
            cur -= arr[l][0];
            l++;
        }
        while (pq.top().s<l) pq.pop();
        ans = min(ans,pq.top().f);
    }
    printf("%lld\n",ans);
}
