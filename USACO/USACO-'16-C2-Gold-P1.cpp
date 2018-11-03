#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 100005;
#define f first
#define s second

int tree[MAXN];

void upd(int i){
    for (;i<MAXN;i+=i&-i) tree[i]++;
}

int qry(int i){
    int res = 0;
    for (;i>0;i-=i&-i) res += tree[i];
    return res;
}

int main(){
    freopen("bphoto.in","r",stdin);
    freopen("bphoto.out","w",stdout);
    int N;
    scanf("%d",&N);
    int arr[N], ans[N][2];
    vector<int> nums;
    for (int i=0;i<N;i++){
        scanf("%d",&arr[i]);
        nums.push_back(arr[i]);
    }
    sort(nums.begin(),nums.end());
    for (int i=0;i<N;i++){
        arr[i] = lower_bound(nums.begin(),nums.end(),arr[i])-nums.begin()+1;
    }
    for (int i=0;i<N;i++){
        ans[i][0] = i-qry(arr[i]-1);
        upd(arr[i]);
    }
    for (int i=0;i<MAXN;i++){
        tree[i] = 0;
    }
    for (int i=N-1;i>=0;i--){
        ans[i][1] = N-i-qry(arr[i]-1)-1;
        upd(arr[i]);
    }
    int res = 0;
    for (int i=0;i<N;i++){
        if (min(ans[i][0],ans[i][1])*2<max(ans[i][0],ans[i][1])) res++;
    }
    printf("%d\n",res);
}
