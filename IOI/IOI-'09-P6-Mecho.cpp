#include <bits/stdc++.h>
using namespace std;

const int MAXN = 201;
typedef long long ll;

int main(){
    int N,S,sx,sy,x,y,ex,ey,len;
    scanf("%d %d",&N,&S);
    int moves[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    pair<int,int> cur;
    char grid[N][N];
    int visit[N][N];
    bool bee[N][N];
    vector<pair<int,int>> bees;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            scanf(" %c",&grid[i][j]);
            if (grid[i][j]=='M'){
                sx = j;
                sy = i;
            }else if(grid[i][j]=='H'){
                bees.push_back({i,j});
            }else if(grid[i][j]=='D'){
                ex = j;
                ey = i;
            }
        }
    }
    int lo = 0, hi = 1000000, mid;
    queue<pair<int,int>> q2;
    queue<pair<int,int>> q;
    while (lo<hi){
        mid = (lo+hi)/2;
        while (!q.empty()) q.pop();
        while (!q2.empty()) q2.pop();
        q.push({sy,sx});
        memset(visit,0,sizeof visit);
        memset(bee,0,sizeof bee);
        for (pair<int,int> i:bees){
            q2.push(i);
            bee[i.first][i.second] = 1;
        }
        visit[sy][sx] = 1;
        for (int i=0;i<mid;i++){
            len = q2.size();
            for (int j=0;j<len;j++){
                cur = q2.front();
                q2.pop();
                for (int k=0;k<4;k++){
                    y = cur.first+moves[k][0];
                    x = cur.second+moves[k][1];
                    if (y<0||y>=N||x<0||x>=N) continue;
                    if (grid[y][x]=='T'||grid[y][x]=='D') continue;
                    if (!bee[y][x]){
                        q2.push({y,x});
                        bee[y][x] = 1;
                    }
                }
            }
        }
        while (!q.empty()&&!visit[ey][ex]){
            for (int i=0;i<S;i++){
                len = q.size();
                for (int j=0;j<len;j++){
                    cur = q.front();
                    q.pop();
                    if (bee[cur.first][cur.second]) continue;
                    for (int k=0;k<4;k++){
                        y = cur.first+moves[k][0];
                        x = cur.second+moves[k][1];
                        if (y<0||y>=N||x<0||x>=N) continue;
                        if (grid[y][x]=='T') continue;
                        if (!visit[y][x]&&!bee[y][x]){
                            q.push({y,x});
                            visit[y][x] = 1;
                        }
                    }
                }
            }
            len = q2.size();
            for (int i=0;i<len;i++){
                cur = q2.front();
                q2.pop();
                for (int k=0;k<4;k++){
                    y = cur.first+moves[k][0];
                    x = cur.second+moves[k][1];
                    if (y<0||y>=N||x<0||x>=N) continue;
                    if (grid[y][x]=='T'||grid[y][x]=='D') continue;
                    if (!bee[y][x]){
                        q2.push({y,x});
                        bee[y][x] = 1;
                    }
                }
            }
        }
        if (visit[ey][ex]) lo = mid+1;
        else hi = mid;
    }
    printf("%d\n",lo-1);
}
