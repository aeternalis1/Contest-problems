#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
typedef long long ll;
#define f first
#define s second
const ll mod = 1e9+7;

ll tree[2][MAXN];

void update(int i, int v, int q){
    for (;i<MAXN;i+=i&-i) tree[q][i] += v;
}

ll query(int i, int q){
    ll res = 0;
    for (;i>0;i-=i&-i) res += tree[q][i];
    return res;
}

int main(){
    freopen("sleepy.in","r",stdin);
    freopen("sleepy.out","w",stdout);
    int N;
    scanf("%d",&N);
    int arr[N], pos[N+1], ans[N];
    for (int i=0;i<N;i++){
        scanf("%d",&arr[i]);
        pos[arr[i]] = i;
    }
    int cur=arr[N-1], ind=N-1;
    ll t1, t2, t3, t4;
    int len1 = 0, len2 = 0;
    int cnt = 0;
    for (int i=N-2;i>=0;i--){
        if (arr[i]<arr[i+1]){
            update(arr[i],1,0);
            len1++;
            ind--;
        }else{
            break;
        }
    }
    for (int i=0;i<ind;i++){
        if (arr[i]<cur){
            t1 = query(arr[i],0); // number of elements < arr[i]
            t2 = len1-t1; //number of elements > arr[i] (on left side)
            t3 = ind-len2-t2; //absolute position of left bound
            t4 = N-(len2+len1+1)+t1-1;
            ans[i] = t4;
            update(arr[i],1,0);
            len1++;
        }else{
            t1 = query(arr[i],1);
            t2 = len2-t1;
            ans[i] = N-t2-1;
            update(arr[i],1,1);
            len2++;
        }
        if (!ans[i]) break;
        cnt++;
    }
    printf("%d\n",cnt);
    for (int i=0;i<cnt;i++){
        if (i==cnt-1) printf("%d\n",ans[i]);
        else printf("%d ",ans[i]);
    }
}
