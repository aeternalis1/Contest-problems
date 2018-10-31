#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 200001;
#define f first
#define s second

int main() {
    freopen("cbarn.in","r",stdin);
    freopen("cbarn.out","w",stdout);
    int N;
    scanf("%d",&N);
    int arr[N], sums[N*2], dist[N], cnt = 0, ind = -1;
    deque<pair<int,int>> q;
    for (int i=0;i<N;i++){
        scanf("%d",&arr[i]);
        sums[i] = sums[i+N] = arr[i];
    }
    for (int i=0;i<N*2;i++){
        if (sums[i]){
            if (i>=N&&!cnt){
                ind = i-N;
                break;
            }
            cnt += sums[i]-1;
        }else{
            cnt = max(0,cnt-1);
        }
    }
    pair<int,int> cur;
    cnt = 0;
    for (int i=0;i<N;i++){
        if (arr[(ind+i)%N]){
            q.push_back({arr[(ind+i)%N],i});
            cnt += arr[(ind+i)%N];
        }
        cur = q.front();
        q.pop_front();
        dist[(ind+i)%N] = (i-cur.s);
        cur.f--;
        if (cur.f) q.push_front(cur);
    }
    ll ans = 0;
    for (int i=0;i<N;i++){
        ans += (ll)dist[i]*dist[i];
    }
    printf("%lld\n",ans);
}
