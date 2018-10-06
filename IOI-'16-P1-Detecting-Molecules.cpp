#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200001;
typedef long long ll;
pair<int,int> arr[MAXN];

int find_subset(int l, int u, int w[], int n, int result[]){
    for (int i=0;i<n;i++) arr[i] = {w[i],i};
    sort(arr,arr+n);
    int l1=0,r1=0;
    ll res = 0;
    while (r1<n){
        while (res<l&&r1<n){
            res += arr[r1].first;
            r1++;
        }
        while (res>u&&l1<r1){
            res -= arr[l1].first;
            l1++;
        }
        if (res>=l&&res<=u){
            int m=0;
            for (int i=l1;i<r1;i++){
                result[m++] = arr[i].second;
                //printf("%d\n",arr[i].second);
            }
            return m;
        }
    }
    return 0;
}
