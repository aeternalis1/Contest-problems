#include <bits/stdc++.h>
using namespace std;

const int MAXN = 201;
typedef long long ll;
int lets[200];
int cnt[200];

int main(){
    int W,S,cur,tot=0,res=0,ans=0;
    char c;
    scanf("%d %d",&W,&S);
    queue<int> q;
    if (W>S){
        printf("0\n");
        return 0;
    }
    for (int i=0;i<W;i++){
        scanf(" %c",&c);
        lets[c-'A']++;
        if (lets[c-'A']==1) tot++;
    }
    for (int i=0;i<W-1;i++){
        scanf(" %c",&c);
        cur = c-'A';
        q.push(cur);
        cnt[cur]++;
        if (cnt[cur]==lets[cur]) res++;
    }
    for (int i=0;i<=S-W;i++){
        scanf(" %c",&c);
        cur = c-'A';
        q.push(cur);
        cnt[cur]++;
        if (cnt[cur]==lets[cur]) res++;
        if (res==tot) ans++;
        cur = q.front();
        q.pop();
        cnt[cur]--;
        if (cnt[cur]==lets[cur]-1) res--;
    }
    printf("%d\n",ans);
}
