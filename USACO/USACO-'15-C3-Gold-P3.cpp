#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5000001;
typedef long long ll;
#define f first
#define s second

struct edge{
    int a,b,c;
    bool operator<(const edge&e)const{
        return e.a>a;
    }
};

int par[MAXN],ran[MAXN];
edge edges[MAXN*2];

int p(int c){
    if (c==par[c]) return c;
    return p(par[c]);
}

void merge(int a, int b){
    if (ran[a]>ran[b]){
        par[b] = a;
    }else if(ran[a]<ran[b]){
        par[a] = b;
    }else{
        ran[a]++;
        par[b] = a;
    }
}

int main(){
    freopen("fencedin.in","r",stdin);
    freopen("fencedin.out","w",stdout);
    int A,B,N,M,a,b,c,d,e,f;
    scanf("%d %d %d %d",&A,&B,&N,&M);
    int arr[N+2], arr2[M+2];
    for (int i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    for (int i=0;i<M;i++){
        scanf("%d",&arr2[i]);
    }
    arr[N] = arr2[M] = 0;
    arr[N+1] = A;
    arr2[M+1] = B;
    sort(arr,arr+N+2);
    sort(arr2,arr2+M+2);
    N++;
    M++;
    int ind = 0;
    for (int i=0;i<=(N+1)*(M+1);i++){
        par[i] = i;
    }
    for (int i=0;i<M;i++){
        for (int j=0;j<N;j++){
            a = i*N+j;
            b = (i+1)*N+j;
            c = i*N+j+1;
            e = arr2[i+1]-arr2[i];
            f = arr[j+1]-arr[j];
            if (j==N-1&&i==M-1) break;
            if (j==N-1){
                edges[ind++] = {f,a,b};
            }else if (i==M-1){
                edges[ind++] = {e,a,c};
            }else{
                edges[ind++] = {f,a,b};
                edges[ind++] = {e,a,c};
            }
        }
    }
    sort(edges,edges+ind);
    int cnt = 0;
    ll ans = 0;
    for (int j=0;j<ind;j++){
        edge i = edges[j];
        a = p(i.b);
        b = p(i.c);
        if (a==b) continue;
        cnt += 1;
        ans += i.a;
        merge(a,b);
        if (cnt==N*M) break;
    }
    printf("%lld\n",ans);
}
