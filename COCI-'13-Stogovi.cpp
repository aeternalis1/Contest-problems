#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300005;
const int mod = 1e9+7;
typedef long long ll;

vector<int> paths[MAXN], tour;
int dep[MAXN], pos[MAXN], tree[MAXN*8], par[MAXN], ids[MAXN];

void dfs(int cur, int par){
    pos[cur] = tour.size();
    tour.push_back(cur);
    for (int i:paths[cur]){
        dep[i] = dep[cur]+1;
        dfs(i,cur);
        tour.push_back(cur);
    }
}

void build(int i, int l, int r){
    if (l==r){
        tree[i] = tour[l];
        return;
    }
    int mid = (l+r)/2;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    tree[i] = min(tree[i*2],tree[i*2+1]);
}

int query(int i, int l, int r, int s, int e){
    if (l>e||r<s) return 1e9;
    if (l>=s&&r<=e) return tree[i];
    int mid = (l+r)/2;
    return min(query(i*2,l,mid,s,e),query(i*2+1,mid+1,r,s,e));
}

int main() {
    int N,a,b,c;
    char q;
    vector<pair<int,int>> qs;
    scanf("%d",&N);
    for (int i=0;i<=N;i++){
        ids[i] = i;
    }
    for (int i=1;i<=N;i++){
        scanf(" %c",&q);
        if (q=='a'){
            scanf("%d",&a);
            paths[ids[a]].push_back(i);
            par[i] = ids[a];
        }else if(q=='b'){
            scanf("%d",&a);
            qs.push_back({-1,ids[a]});
            ids[i] = par[ids[a]];
            par[i] = par[par[ids[a]]];
        }else{
            scanf("%d %d",&a,&b);
            ids[i] = ids[a];
            par[i] = par[ids[a]];
            qs.push_back({i,b});
        }
    }
    dfs(0,-1);
    build(1,0,tour.size()-1);
    for (pair<int,int> i:qs){
        if (i.first==-1){
            printf("%d\n",i.second);
            continue;
        }
        a = ids[i.first];
        b = ids[i.second];
        if (pos[a]>pos[b]) swap(a,b);
        c = query(1,0,tour.size()-1,pos[a],pos[b]);
        printf("%d\n",dep[c]);
    }
}
