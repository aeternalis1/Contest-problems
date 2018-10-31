#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 200001;

int main() {
    freopen("split.in","r",stdin);
    freopen("split.out","w",stdout);
    int N;
    ll ans,res=1e18,a,b;
    scanf("%d",&N);
    pair<ll,ll> arr[2][N];
    ll nums[N][2];
    for (int i=0;i<N;i++){
        scanf("%lld %lld",&arr[0][i].first,&arr[0][i].second);
        arr[1][i].first = arr[0][i].second;
        arr[1][i].second = arr[0][i].first;
    }
    sort(arr[0],arr[0]+N);
    sort(arr[1],arr[1]+N);
    ans = (arr[0][N-1].first-arr[0][0].first)*(arr[1][N-1].first-arr[1][0].first);
    for (int i=0;i<2;i++){
        a = 1e9;
        b = 0;
        for (int j=0;j<N;j++){
            a = min(arr[i][j].second,a);
            b = max(arr[i][j].second,b);
            nums[j][0] = a;
            nums[j][1] = b;
        }
        a = 1e9;
        b = 0;
        for (int j=N-1;j>0;j--){
            a = min(arr[i][j].second,a);
            b = max(arr[i][j].second,b);
            if (arr[i][j].first!=arr[i][j-1].first){
                res = min(res,(arr[i][N-1].first-arr[i][j].first)*(b-a)+(arr[i][j-1].first-arr[i][0].first)*(nums[j-1][1]-nums[j-1][0]));
            }
        }
    }
    printf("%lld\n",ans-res);
}
