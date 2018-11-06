#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 100005;
#define f first
#define s second

struct state{
    int a,b,c,d,e,f;
};

int main(){
    freopen("cownav.in","r",stdin);
    freopen("cownav.out","w",stdout);
    int N,y,x;
    scanf("%d",&N);
    char arr[N][N];
    int ans[N][N][N][N][4][4]; //up, right, down, left are 0,1,2,3 respectively
    int moves[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    memset(ans,0,sizeof ans);
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            scanf(" %c",&arr[i][j]);
        }
    }
    ans[N-1][0][N-1][0][0][1] = 1;
    queue<state> q;
    state cur, temp;
    q.push({N-1,0,N-1,0,0,1});
    while (!q.empty()){
        cur = q.front();
        q.pop();
        if (cur.a==0&&cur.b==N-1&&cur.c==0&&cur.d==N-1){
            printf("%d\n",ans[0][N-1][0][N-1][cur.e][cur.f]-1);
            return 0;
        }
        temp = cur;
        if (cur.a!=0||cur.b!=N-1){
            y = cur.a+moves[cur.e][0];
            x = cur.b+moves[cur.e][1];
        }else{
            y = cur.a;
            x = cur.b;
        }
        if (!(y<0||y>=N||x<0||x>=N)&&arr[y][x]=='E'){
            temp.a = y;
            temp.b = x;
        }
        if (cur.c!=0||cur.d!=N-1){
            y = cur.c+moves[cur.f][0];
            x = cur.d+moves[cur.f][1];
        }else{
            y = cur.c;
            x = cur.d;
        }
        if (!(y<0||y>=N||x<0||x>=N)&&arr[y][x]=='E'){
            temp.c = y;
            temp.d = x;
        }
        if (!ans[temp.a][temp.b][temp.c][temp.d][temp.e][temp.f]){
            ans[temp.a][temp.b][temp.c][temp.d][temp.e][temp.f] = ans[cur.a][cur.b][cur.c][cur.d][cur.e][cur.f]+1;
            q.push(temp);
        }
        temp = cur;
        temp.e = (cur.e+1)%4;
        temp.f = (cur.f+1)%4;
        if (!ans[temp.a][temp.b][temp.c][temp.d][temp.e][temp.f]){
            ans[temp.a][temp.b][temp.c][temp.d][temp.e][temp.f] = ans[cur.a][cur.b][cur.c][cur.d][cur.e][cur.f]+1;
            q.push(temp);
        }
        temp = cur;
        temp.e = (cur.e+3)%4;
        temp.f = (cur.f+3)%4;
        if (!ans[temp.a][temp.b][temp.c][temp.d][temp.e][temp.f]){
            ans[temp.a][temp.b][temp.c][temp.d][temp.e][temp.f] = ans[cur.a][cur.b][cur.c][cur.d][cur.e][cur.f]+1;
            q.push(temp);
        }
    }
}
