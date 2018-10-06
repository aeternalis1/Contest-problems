#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
typedef long long ll;

int dp[2][MAXN];
bool checked[2][MAXN];

struct state{
    int a,b,c,d,e,f;
};

int convert(state c){
    return c.a+c.b*(1<<2)+c.c*(1<<4)+c.d*(1<<6)+c.e*(1<<8)+c.f*(1<<10);
}

int val(int a, int b, int c){
    if (!b) return 1;
    if (!a&&(b!=c)) return 2;
    if (!a) return 1;
    if (a==b&&b==c) return 1;
    if (a!=b&&b!=c&&a!=c) return 3;
    return 2;
}
//MBF MFB
int main(){
    int N, len, a, b, v;
    state cur, temp;
    char c;
    scanf("%d",&N);
    int arr[N];
    for (int i=0;i<N;i++){
        scanf(" %c",&c);
        if (c=='M') arr[i] = 1;
        else if (c=='F') arr[i] = 2;
        else arr[i] = 3;
    }
    memset(dp,-1,sizeof dp);
    queue<state> q;
    q.push({0,0,0,0,0,0});
    dp[0][0] = 0;
    for (int i=0;i<N;i++){
        len = q.size();
        for (int j=0;j<len;j++){
            cur = q.front();
            q.pop();
            temp = cur;
            a = convert(cur);
            checked[i&1][a] = 0;
            cur.a = cur.b;
            cur.b = cur.c;
            cur.c = arr[i];
            b = convert(cur);
            v = val(cur.a,cur.b,cur.c);
            if (v+dp[i&1][a]>dp[(i&1)^1][b]){
                dp[(i&1)^1][b] = v+dp[i&1][a];
                if (!checked[(i&1)^1][b]){
                    checked[(i&1)^1][b] = 1;
                    q.push(cur);
                }
            }
            temp.d = temp.e;
            temp.e = temp.f;
            temp.f = arr[i];
            b = convert(temp);
            v = val(temp.d,temp.e,temp.f);
            if (v+dp[i&1][a]>dp[(i&1)^1][b]){
                dp[(i&1)^1][b] = v+dp[i&1][a];
                if (!checked[(i&1)^1][b]){
                    checked[(i&1)^1][b] = 1;
                    q.push(temp);
                }
            }
        }
    }
    int ans = 0;
    for (int i=0;i<MAXN;i++){
        ans = max(ans,dp[N&1][i]);
    }
    printf("%d\n",ans);
}
