#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 100005;
#define f first
#define s second

int main(){
    freopen("dining.in","r",stdin);
    freopen("dining.out","w",stdout);
    int N,M,K,a,b,c;
    scanf("%d %d %d",&N,&M,&K);
    vector<pair<int,int>> paths[N];
    int ans[N];
    for (int i=0;i<N;i++) ans[i] = 2e9;
    for (int i=0;i<M;i++){
        scanf("%d %d %d",&a,&b,&c);
        a--;
        b--;
        paths[a].push_back({b,c});
        paths[b].push_back({a,c});
    }
    queue<int> q;
    int dist[N], chk[N];
    memset(chk,0,sizeof chk);
    for (int i=0;i<N;i++) dist[i] = 2e9;
    q.push(N-1);
    dist[N-1] = 0;
    while (!q.empty()){
        c = q.front();
        q.pop();
        chk[c] = 0;
        for (pair<int,int> i:paths[c]){
            if (dist[i.f]>dist[c]+i.s){
                dist[i.f] = dist[c]+i.s;
                if (!chk[i.f]){
                    chk[i.f] = 1;
                    q.push(i.f);
                }
            }
        }
    }
    for (int i=0;i<K;i++){
        scanf("%d %d",&a,&b);
        ans[a-1] = dist[a-1]-b;
        q.push(a-1);
    }
    while (!q.empty()){
        c = q.front();
        q.pop();
        chk[c] = 0;
        for (pair<int,int> i:paths[c]){
            if (ans[i.f]>ans[c]+i.s){
                ans[i.f] = ans[c]+i.s;
                if (!chk[i.f]){
                    chk[i.f] = 1;
                    q.push(i.f);
                }
            }
        }
    }
    for (int i=0;i<N-1;i++){
        if (ans[i]<=dist[i]){
            printf("1\n");
        }else{
            printf("0\n");
        }
    }
}
