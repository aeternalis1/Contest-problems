#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000001;
typedef long long ll;

int tree[MAXN*4], tree2[MAXN*4], arr[MAXN];
bool checked[MAXN];

void build(int i, int l, int r){
    if (l==r){
        tree2[i] = l;
        return;
    }
    int mid = (l+r)>>1;
    build(i<<1,l,mid);
    build((i<<1)+1,mid+1,r);
    if (arr[tree2[i<<1]]>arr[tree2[(i<<1)+1]]){
        tree2[i] = tree2[i<<1];
    }else{
        tree2[i] = tree2[(i<<1)+1];
    }
}

void update(int i, int l, int r, int t, int v){
    if (l>t||r<t) return;
    if (l==r){
        tree[i] = v;
        return;
    }
    int mid = (l+r)>>1;
    update(i<<1,l,mid,t,v);
    update((i<<1)+1,mid+1,r,t,v);
    tree[i] = max(tree[i<<1],tree[(i<<1)+1]);
}

void update2(int i, int l, int r, int t){
    if (l>t||r<t) return;
    if (l==r){
        tree[i] = l;
        return;
    }
    int mid = (l+r)>>1;
    update2(i<<1,l,mid,t);
    update2((i<<1)+1,mid+1,r,t);
    if (arr[tree2[i<<1]]>arr[tree2[(i<<1)+1]]){
        tree2[i] = tree2[i<<1];
    }else{
        tree2[i] = tree2[(i<<1)+1];
    }
}

int query(int i, int l, int r, int s, int e, int N){
    if (l>e||r<s||s>e) return N;
    if (l>=s&&r<=e) return tree2[i];
    int mid = (l+r)>>1;
    int v1 = query(i<<1,l,mid,s,e,N), v2 = query((i<<1)+1,mid+1,r,s,e,N);
    if (arr[v1]>arr[v2]) return v1;
    else return v2;
}

int main() {
    int N,K,Q,l,r,a,b;
    scanf("%d %d %d",&N,&K,&Q);
    for (int i=0;i<N;i++){
        scanf("%d",&arr[i]);
    }
    build(1,0,N-1);
    for (int i=0;i<N;i++){
        l = query(1,0,N-1,max(0,i-K+1),i-1,N);
        r = query(1,0,N-1,i+1,min(N-1,i+K-1),N);
        if (arr[i]>=arr[l]&&arr[i]>arr[r]){
            update(1,0,N-1,i,arr[i]+max(arr[l],arr[r]));
        }
    }
    printf("%d\n",tree[1]);
    for (int i=0;i<Q;i++){
        scanf("%d %d",&a,&b);
        a--;
        arr[a] = b;
        update2(1,0,N-1,a);
        l = query(1,0,N-1,max(0,a-K+1),a-1,N);
        r = query(1,0,N-1,a+1,min(N-1,a+K-1),N);
        if (arr[a]>=arr[l]&&arr[a]>arr[r]){
            update(1,0,N-1,a,arr[a]+max(arr[l],arr[r]));
        }else{
            update(1,0,N-1,a,0);
            if (arr[l]){
                a = query(1,0,N-1,l+1,min(N-1,l+K-1),N);
                b = query(1,0,N-1,max(0,l-K+1),l-1,N);
                if (arr[l]>=arr[b]&&arr[l]>arr[a]) update(1,0,N-1,l,arr[l]+max(arr[a],arr[b]));
            }
            if (arr[r]){
                a = query(1,0,N-1,r+1,min(N-1,r+K-1),N);
                b = query(1,0,N-1,max(0,r-K+1),r-1,N);
                if (arr[r]>=arr[b]&&arr[r]>arr[a]) update(1,0,N-1,r,arr[r]+max(arr[a],arr[b]));
            }
        }
        printf("%d\n",tree[1]);
    }
}
