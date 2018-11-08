#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 100005;
#define f first
#define s second

int main(){
    freopen("visitfj.in","r",stdin);
    freopen("visitfj.out","w",stdout);
    int N,T,y,x;
    scanf("%d %d",&N,&T);
    ll ans[N][N][3];
    int arr[N][N], chk[N][N];
    int moves[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    memset(chk,0,sizeof chk);
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            scanf("%d",&arr[i][j]);
            for (int k=0;k<3;k++){
                ans[i][j][k] = 1e15;
            }
        }
    }
    queue<pair<int,int>> q;
    pair<int,int> cur;
    q.push({0,0});
    ans[0][0][0] = 0;
    while (!q.empty()){
        cur = q.front();
        q.pop();
        chk[cur.f][cur.s] = 0;
        for (int i=0;i<4;i++){
            y = cur.f+moves[i][0];
            x = cur.s+moves[i][1];
            if (y<0||y>=N||x<0||x>=N) continue;
            for (int j=0;j<3;j++){
                if (j==2){
                    if (ans[cur.f][cur.s][j]+arr[y][x]+T<ans[y][x][0]){
                        ans[y][x][0] = ans[cur.f][cur.s][j]+arr[y][x]+T;
                        if (!chk[y][x]){
                            chk[y][x] = 1;
                            q.push({y,x});
                        }
                    }
                }else{
                    if (ans[cur.f][cur.s][j]+T<ans[y][x][j+1]){
                        ans[y][x][j+1] = ans[cur.f][cur.s][j]+T;
                        if (!chk[y][x]){
                            chk[y][x] = 1;
                            q.push({y,x});
                        }
                    }
                }
            }
        }
    }
    ll res = 1e15;
    for (int i=0;i<3;i++){
        res = min(res,ans[N-1][N-1][i]);
    }
    printf("%lld\n",res);
}
