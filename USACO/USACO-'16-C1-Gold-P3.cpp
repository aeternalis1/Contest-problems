#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 200001;
#define f first
#define s second

int main(){
    freopen("lasers.in","r",stdin);
    freopen("lasers.out","w",stdout);
    int N,c,cur;
    scanf("%d",&N);
    unordered_map<int,vector<pair<int,int>>> xs,ys;
    vector<int> x, y;
    int arr[N+2][2], ans[N+2][4], chk[N+2];
    vector<pair<int,int>> paths[N+2];
    for (int i=0;i<N+2;i++) for (int j=0;j<4;j++) ans[i][j] = 1e8;
    for (int i=0;i<N+2;i++) chk[i] = 0;
    for (int i=0;i<N+2;i++){
        scanf("%d %d",&arr[i][0],&arr[i][1]);
        if (!xs[arr[i][0]].size()) x.push_back(arr[i][0]);
        if (!ys[arr[i][1]].size()) y.push_back(arr[i][1]);
        xs[arr[i][0]].push_back({arr[i][1],i});
        ys[arr[i][1]].push_back({arr[i][0],i});
    }
    for (int i:x){
        sort(xs[i].begin(),xs[i].end());
        for (int j=0;j<(int)xs[i].size()-1;j++){
            paths[xs[i][j].s].push_back({xs[i][j+1].s,0}); //move right
            paths[xs[i][j+1].s].push_back({xs[i][j].s,1}); //move left
        }
    }
    for (int i:y){
        sort(ys[i].begin(),ys[i].end());
        for (int j=0;j<(int)ys[i].size()-1;j++){
            paths[ys[i][j].s].push_back({ys[i][j+1].s,2}); //move up
            paths[ys[i][j+1].s].push_back({ys[i][j].s,3}); //move down
        }
    }
    queue<int> q;
    q.push(0);
    ans[0][0] = ans[0][1] = ans[0][2] = ans[0][3] = 0;
    while (!q.empty()){
        c = q.front();
        q.pop();
        chk[c] = 0;
        for (pair<int,int> i:paths[c]){
            cur = 1e8;
            for (int j=0;j<4;j++){
                if (j==i.s) cur = min(cur,ans[c][j]);
                else cur = min(cur,ans[c][j]+1);
            }
            if (cur<ans[i.f][i.s]){
                ans[i.f][i.s] = cur;
                if (!chk[i.f]){
                    chk[i.f] = 1;
                    q.push(i.f);
                }
            }
        }
    }
    int res = 1e8;
    for (int i=0;i<4;i++) res = min(res,ans[1][i]);
    if (res==1e8) printf("-1\n");
    else printf("%d\n",res);
}
