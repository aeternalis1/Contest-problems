#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10001;
typedef long long ll;
#define f first
#define s second

vector<pair<int,int>> paths[2][MAXN];
vector<pair<int,int>> edges[2][MAXN];
ll dist[2][MAXN];
int ans[MAXN];

void dij(int a, int q){
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    pq.push({0,a});
    dist[q][a] = 0;
    pair<ll,int> cur;
    while (!pq.empty()){
        cur = pq.top();
        pq.pop();
        if (cur.f!=dist[q][cur.s]) continue;
        for (pair<int,int> i: paths[q][cur.s]){
            if (dist[q][cur.s]+i.s<dist[q][i.f]){
                dist[q][i.f] = dist[q][cur.s]+i.s;
                pq.push({dist[q][i.f],i.f});
            }
        }
    }
}

int main(){
    freopen("gpsduel.in","r",stdin);
    freopen("gpsduel.out","w",stdout);
    int N,M;
    ll a,b,c,d;
    scanf("%d %d",&N,&M);
    for (int i=0;i<M;i++){
        scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
        paths[0][b].push_back({a,c});
        paths[1][b].push_back({a,d});
        edges[0][a].push_back({b,c});
        edges[1][a].push_back({b,d});
    }
    for (int i=0;i<=N;i++){
        dist[0][i] = dist[1][i] = 1e15;
        ans[i] = 1e9;
    }
    dij(N,0);
    dij(N,1);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,1});
    ans[1] = 0;
    pair<int,int> cur;
    while (!pq.empty()){
        cur = pq.top();
        pq.pop();
        if (cur.f!=ans[cur.s]) continue;
        a = 1e15;
        b = 1e15;
        for (pair<int,int> i:edges[0][cur.s]){
            a = min(a,dist[0][i.f]+i.s);
        }
        for (pair<int,int> i:edges[1][cur.s]){
            b = min(b,dist[1][i.f]+i.s);
        }
        for (int i=0;i<edges[0][cur.s].size();i++){
            c = (dist[0][edges[0][cur.s][i].f]+edges[0][cur.s][i].s!=a)+(dist[1][edges[0][cur.s][i].f]+edges[1][cur.s][i].s!=b);
            if (c+ans[cur.s]<ans[edges[0][cur.s][i].f]){
                ans[edges[0][cur.s][i].f] = c+ans[cur.s];
                pq.push({ans[edges[0][cur.s][i].f],edges[0][cur.s][i].f});
            }
        }
    }
    printf("%d\n",ans[N]);
}
