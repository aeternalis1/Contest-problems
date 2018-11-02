#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 200001;
#define f first
#define s second

struct edge{
    int a,b,c;
    bool operator<(const edge&e) const{
        return e.a>a;
    }
};

int p[MAXN], ran[MAXN];

int par(int i){
    if (i==p[i]) return i;
    return par(p[i]);
}

int merge(int a, int b){
    if (ran[a]>ran[b]){
        p[b] = a;
    }else if (ran[a]<ran[b]){
        p[a] = b;
    }else{
        ran[a]++;
        p[b] = a;
    }
}

int d(int a, int b, int c, int d){
    return pow(c-a,2)+pow(d-b,2);
}

int main(){
    freopen("moocast.in","r",stdin);
    freopen("moocast.out","w",stdout);
    int N,a,b;
    scanf("%d",&N);
    int arr[N][2];
    vector<edge> edges;
    for (int i=0;i<N;i++){
        p[i] = i;
        scanf("%d %d",&arr[i][0],&arr[i][1]);
    }
    for (int i=0;i<N;i++){
        for (int j=i+1;j<N;j++){
            edges.push_back({d(arr[i][0],arr[i][1],arr[j][0],arr[j][1]),i,j});
        }
    }
    sort(edges.begin(),edges.end());
    int ans = 0, cnt=0;
    for (edge i:edges){
        a = par(i.b);
        b = par(i.c);
        if (a==b) continue;
        cnt++;
        ans = max(ans,i.a);
        merge(a,b);
        if (cnt==N-1) break;
    }
    printf("%d\n",ans);
}
