#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 100005;
#define f first
#define s second

vector<int> paths[MAXN];
int dist[MAXN], ans;

void dfs(int cur, int par, int d){
    if (d>=dist[cur]){
        ans++;
        return;
    }
    for (int i:paths[cur]){
        if (i==par) continue;
        dfs(i,cur,d+1);
    }
}

int main(){
    freopen("atlarge.in","r",stdin);
    freopen("atlarge.out","w",stdout);
    int N,K,a,b;
    scanf("%d %d",&N,&K);
    for (int i=0;i<N-1;i++){
        scanf("%d %d",&a,&b);
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    queue<int> q;
    memset(dist,-1,sizeof dist);
    for (int i=1;i<=N;i++){
        if (paths[i].size()==1){
            dist[i] = 0;
            q.push(i);
        }
    }
    while (!q.empty()){
        a = q.front();
        q.pop();
        for (int i:paths[a]){
            if (dist[i]==-1){
                dist[i] = dist[a]+1;
                q.push(i);
            }
        }
    }
    dfs(K,-1,0);
    printf("%d\n",ans);
}
