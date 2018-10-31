#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200001;
typedef long long ll;
#define f first
#define s second

int par[MAXN], ran[MAXN], sz[MAXN], seen[MAXN], arr[MAXN], ans[MAXN];

int p(int c){
    if (par[c]==c) return c;
    return p(par[c]);
}

void merge(int a, int b){
    if (ran[a]>ran[b]){
        par[b] = a;
        sz[a] += sz[b];
    }else if (ran[a]<ran[b]){
        par[a] = b;
        sz[b] += sz[a];
    }else{
        ran[a]++;
        par[b] = a;
        sz[a] += sz[b];
    }
}


int main(){
    freopen("closing.in","r",stdin);
    freopen("closing.out","w",stdout);
    int N,M,a,b,cur,res;
    scanf("%d %d",&N,&M);
    vector<int> paths[N];
    int arr[N];
    for (int i=0;i<M;i++){
        scanf("%d %d",&a,&b);
        a--;
        b--;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    for (int i=0;i<N;i++){
        scanf("%d",&arr[i]);
        arr[i]--;
        par[i] = i;
        sz[i] = 1;
    }
    for (int i=N-1;i>=0;i--){
        cur = arr[i];
        res = 1;
        for (int j:paths[cur]){
            if (seen[j]){
                a = p(cur);
                b = p(j);
                if (a!=b) merge(a,b);
                res = max(res,sz[a]);
                res = max(res,sz[b]);
            }
        }
        if (res!=N-i) ans[i] = 1;
        seen[cur] = 1;
    }
    for (int i=0;i<N;i++){
        if (ans[i]) printf("NO\n");
        else printf("YES\n");
    }
}
