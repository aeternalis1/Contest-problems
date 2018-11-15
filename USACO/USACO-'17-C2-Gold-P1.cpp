#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 100005;
#define f first
#define s second

struct edge{
    int a,b,c;
    bool operator<(const edge&e) const{
        return e.c>c;
    }
};

struct query{
    int a,b,c;
    bool operator<(const query&q) const{
        return q.a<a;
    }
};

int par[MAXN], ran[MAXN], sz[MAXN];

int p(int a){
    if (par[a]==a) return a;
    return p(par[a]);
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
    freopen("mootube.in","r",stdin);
    freopen("mootube.out","w",stdout);
    int N,Q;
    scanf("%d %d",&N,&Q);
    for (int i=0;i<=N;i++){
        sz[i] = 1;
        par[i] = i;
    }
    edge edges[N-1];
    query qs[Q];
    int ans[Q];
    for (int i=0;i<N-1;i++){
        scanf("%d %d %d",&edges[i].a,&edges[i].b,&edges[i].c);
    }
    for (int i=0;i<Q;i++){
        scanf("%d %d",&qs[i].a,&qs[i].b);
        qs[i].c = i;
    }
    sort(edges,edges+N-1);
    sort(qs,qs+Q);
    int ind = N-2;
    for (int i=0;i<Q;i++){
        while (ind>=0&&edges[ind].c>=qs[i].a){
            merge(p(edges[ind].a),p(edges[ind].b));
            ind--;
        }
        ans[qs[i].c] = sz[p(qs[i].b)];
    }
    for (int i=0;i<Q;i++){
        printf("%d\n",ans[i]-1);
    }
}
