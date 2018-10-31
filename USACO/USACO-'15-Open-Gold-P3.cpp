#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000001;
typedef long long ll;
#define f first
#define s second

int main(){
    freopen("trapped.in","r",stdin);
    freopen("trapped.out","w",stdout);
    int N;
    scanf("%d",&N);
    pair<int,int> arr[N];
    for (int i=0;i<N;i++){
        scanf("%d %d",&arr[i].s,&arr[i].f);
    }
    sort(arr,arr+N);
    int need[N-1], curmax = 0;
    for (int i=0;i<N-1;i++){
        curmax = max(arr[i].s,curmax);
        need[i] = curmax;
    }
    curmax = 0;
    for (int i=N-1;i>0;i--){
        curmax = max(arr[i].s,curmax);
        need[i-1] = min(need[i-1],curmax);
    }
    int l,r,cur,ans=0;
    int can[N];
    memset(can,0,sizeof can);
    for (int i=0;i<N-1;i++){
        l = i;
        r = i+1;
        cur = arr[i+1].f-arr[i].f;
        while (l>=0&&r<=N-1){
            if (can[l]||can[r-1]){
                l = -1;
                break;
            }
            if (cur<=arr[l].s&&cur<=arr[r].s) break;
            if (cur>arr[l].s){
                if (l) cur += arr[l].f-arr[l-1].f;
                l--;
            }
            if (cur>arr[r].s){
                if (r<N-1) cur += arr[r+1].f-arr[r].f;
                r++;
            }
            if (cur>need[i]){
                break;
            }
        }
        if (!(cur>need[i]||l<0||r>=N)) ans += arr[i+1].f-arr[i].f;
        else can[i] = 1;
    }
    printf("%d\n",ans);
}
