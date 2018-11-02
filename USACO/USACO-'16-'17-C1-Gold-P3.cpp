#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5000001;
typedef long long ll;
#define f first
#define s second

int main(){
    freopen("dream.in","r",stdin);
    freopen("dream.out","w",stdout);
    int N,M,y,x,y2,x2,cnt;
    scanf("%d %d",&N,&M);
    int grid[N][M], chk[N][M][2], en[N][M];
    int moves[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            chk[i][j][0] = chk[i][j][1] = 1e8;
            en[i][j] = 0;
        }
    }
    for (int i=0;i<N;i++) for (int j=0;j<M;j++) scanf("%d",&grid[i][j]);
    queue<pair<int,int>> q;
    pair<int,int> cur;
    q.push({0,0});
    chk[0][0][0] = 0;
    while (!q.empty()){
        cur = q.front();
        q.pop();
        en[cur.f][cur.s] = 0;
        for (int j=0;j<4;j++){
            y = cur.f+moves[j][0];
            x = cur.s+moves[j][1];
            if (y<0||y>=N||x<0||x>=M) continue;
            if (!grid[y][x]) continue;
            bool f = 0;
            if (grid[y][x]==1){
                if (chk[cur.f][cur.s][0]+1<chk[y][x][0]){
                    chk[y][x][0] = chk[cur.f][cur.s][0]+1;
                    if (!en[y][x]) f = 1;
                }
                if (chk[cur.f][cur.s][1]+1<chk[y][x][1]){
                    chk[y][x][1] = chk[cur.f][cur.s][1]+1;
                    if (!en[y][x]) f = 1;
                }
            }else if (grid[y][x]==2){
                if (min(chk[cur.f][cur.s][0],chk[cur.f][cur.s][1])+1<chk[y][x][1]){
                    chk[y][x][1] = min(chk[cur.f][cur.s][0],chk[cur.f][cur.s][1])+1;
                    if (!en[y][x]) f = 1;
                }
            }else if (grid[y][x]==3){
                if (chk[cur.f][cur.s][1]+1<chk[y][x][1]){
                    chk[y][x][1] = chk[cur.f][cur.s][1]+1;
                    if (!en[y][x]) f = 1;
                }
            }else{
                cnt = 1;
                y2 = y;
                x2 = x;
                while (y2>=0&&y2<N&&x2>=0&&x2<M&&grid[y2][x2]==4){
                    y2 += moves[j][0];
                    x2 += moves[j][1];
                    cnt++;
                }
                if (y2<0||y2>=N||x2<0||x2>=M||grid[y2][x2]==0||grid[y2][x2]==3){
                    y2 -= moves[j][0];
                    x2 -= moves[j][1];
                    cnt--;
                }
                if (min(chk[cur.f][cur.s][0],chk[cur.f][cur.s][1])+cnt<chk[y2][x2][0]){
                    chk[y2][x2][0] = min(chk[cur.f][cur.s][0],chk[cur.f][cur.s][1])+cnt;
                    if (!en[y2][x2]){
                        en[y2][x2] = 1;
                        q.push({y2,x2});
                    }
                }
            }
            if (f){
                en[y][x] = 1;
                q.push({y,x});
            }
        }
    }
    /*for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            printf("%d ",chk[i][j][0]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            printf("%d ",chk[i][j][1]);
        }
        printf("\n");
    }*/
    if (min(chk[N-1][M-1][0],chk[N-1][M-1][1])==1e8) printf("-1\n");
    else printf("%d\n",min(chk[N-1][M-1][0],chk[N-1][M-1][1]));
}

//http://www.usaco.org/index.php?page=viewproblem2&cpid=575
