#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 5000001;
#define f first
#define s second

bool chk[MAXN][2];

int main(){
    freopen("feast.in","r",stdin);
    freopen("feast.out","w",stdout);
    int T,A,B,cur;
    scanf("%d %d %d",&T,&A,&B);
    chk[0][0] = chk[0][1] = 1;
    queue<int> q;
    q.push(0);
    while (!q.empty()){
        cur = q.front();
        q.pop();
        if (chk[cur][0]){
            if (cur+A<=T&&!chk[cur+A][0]){
                chk[cur+A][0] = 1;
                q.push(cur+A);
            }
            if (cur+B<=T&&!chk[cur+B][0]){
                chk[cur+B][0] = 1;
                q.push(cur+B);
            }
            if (cur/2&&!chk[cur/2][1]){
                chk[cur/2][1] = 1;
                q.push(cur/2);
            }
        }else{
            if (cur+A<=T&&!chk[cur+A][1]){
                chk[cur+A][1] = 1;
                q.push(cur+A);
            }
            if (cur+B<=T&&!chk[cur+B][1]){
                chk[cur+B][1] = 1;
                q.push(cur+B);
            }
        }
    }
    for (int i=T;i>=0;i--){
        if (chk[i][0]||chk[i][1]){
            printf("%d\n",i);
            return 0;
        }
    }
}

//http://www.usaco.org/index.php?page=viewproblem2&cpid=573
