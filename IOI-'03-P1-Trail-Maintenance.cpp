#include <bits/stdc++.h>
using namespace std;

const int MAXN = 201;
typedef long long ll;

struct edge{
    int a,b,c;
    bool operator<(const edge&e){
        return e.c>c;
    }
};

int par[MAXN];
int r[MAXN];

int p(int c){
    if (c==par[c]) return c;
    return p(par[c]);
}

void merge(int a, int b){
    if (r[a]>r[b]){
        par[b] = a;
    }else if(r[a]<r[b]){
        par[a] = b;
    }else{
        r[a]++;
        par[b] = a;
    }
}

int main(){
    int N,W,a,b,c,cnt,res;
    scanf("%d %d",&N,&W);
    edge edges[W];
    for (int i=0;i<W;i++){
        scanf("%d %d %d",&edges[i].a,&edges[i].b,&edges[i].c);
        edges[i].a--;
        edges[i].b--;
        cnt = 0;
        res = 0;
        sort(edges,edges+i+1);
        for (int j=0;j<N;j++){
            par[j] = j;
            r[j] = 0;
        }
        for (int j=0;j<=i;j++){
            a = p(edges[j].a);
            b = p(edges[j].b);
            if (a==b) continue;
            merge(a,b);
            cnt++;
            res+=edges[j].c;
            if (cnt==N-1) break;
        }
        if (cnt!=N-1) cout << -1 << endl;
        else cout << res << endl;
    }
}
