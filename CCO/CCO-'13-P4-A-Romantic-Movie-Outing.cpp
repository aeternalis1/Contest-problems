#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5001;
typedef long long ll;
#define f first
#define s second

ll tree[MAXN][MAXN];

int seen[MAXN][MAXN];

void update(int y, int x, int v){
    for (;y<MAXN;y+=y&-y){
        for (int nx=x;nx<MAXN;nx+=nx&-nx){
            tree[y][nx] += v;
        }
    }
}

ll query(int y, int x){
    ll res = 0;
    for (;y>0;y-=y&-y){
        for (int nx=x;nx>0;nx-=nx&-nx){
            res += tree[y][nx];
        }
    }
    return res;
}

int main(){
    int N,T,a,b,f,c,d;
    char q;
    scanf("%d %d",&N,&T);
    for (int i=0;i<T;i++){
        scanf(" %c %d %d",&q,&c,&d);
        f = 0;
        if (c>1500) f = 1;
        a = c+d+2000;
        b = c-d+2000;
        if (q=='E'){
            if (!f){
                seen[a][b] = 1;
                update(a,b,1);
            }
        }else if (q=='L'){
            if (!f){
                seen[a][b] = 0;
                update(a,b,-1);
            }
        }else{
            if (seen[a][b]||seen[a+1][b-1]){
                printf("No\n");
                continue;
            }
            printf("%lld\n",query(a,b)+query(a+1,b-1));
        }
    }
    vector<ll> ans;
    for (int i=N+1;i<=N+502;i++){
        for (int j=1;j<=1000;j++){
            a = i+j+2000;
            b = i-j+2000;
            if (seen[a][b]) continue;
            ans.push_back(query(a,b));
        }
    }
    sort(ans.begin(),ans.end());
    printf("%lld\n",ans[0]+ans[1]);
}
