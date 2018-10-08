#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
typedef long long ll;

int main() {
    int N;
    scanf("%d",&N);
    int arr[N][2];
    map<int,vector<int> > xs;
    map<int,vector<int> > ys;
    unordered_map<int,int> ex;
    unordered_map<int,int> ey;
    vector<int> v1;
    vector<int> v2;
    for (int i=0;i<N;i++){
        scanf("%d %d",&arr[i][0],&arr[i][1]);
        if (!ex[arr[i][0]]){
            v1.push_back(arr[i][0]);
        }
        ex[arr[i][0]]++;
        if (!ey[arr[i][1]]){
            v2.push_back(arr[i][1]);
        }
        ey[arr[i][1]]++;
        xs[arr[i][0]].push_back(arr[i][1]);
        ys[arr[i][1]].push_back(arr[i][0]);
    }
    for (int i:v1){
        sort(xs[i].begin(),xs[i].end());
    }
    for (int i:v2){
        sort(ys[i].begin(),ys[i].end());
    }
    ll ans = 0;
    ll l,r,u,d;
    for (int i=0;i<N;i++){
        l = lower_bound(xs[arr[i][0]].begin(),xs[arr[i][0]].end(),arr[i][1])-xs[arr[i][0]].begin();
        r = ex[arr[i][0]]-l-1;
        d = lower_bound(ys[arr[i][1]].begin(),ys[arr[i][1]].end(),arr[i][0])-ys[arr[i][1]].begin();
        u = ey[arr[i][1]]-d-1;
        ans += l*r*d*u;
    }
    printf("%lld\n",ans*2);
}
