#include <bits/stdc++.h>
using namespace std;

const int MAXN = 201;
typedef long long ll;

struct s{
    int a,b,c;
    bool operator<(const s&e){
        if (e.a==a){
            if (e.b==b){
                return e.c>c;
            }
            return e.b<b;
        }
        return e.a<a;
    }
};

int main(){
    int N,T,P,res,res2;
    scanf("%d %d %d",&N,&T,&P);
    int arr[N][T], nums[T];
    for (int i=0;i<T;i++) nums[i] = N;
    for (int i=0;i<N;i++){
        for (int j=0;j<T;j++){
            scanf("%d",&arr[i][j]);
            if (arr[i][j]) nums[j]--;
        }
    }
    vector<s> li;
    for (int i=0;i<N;i++){
        res = 0;
        res2 = 0;
        for (int j=0;j<T;j++){
            if (arr[i][j]){
                res2++;
                res+=nums[j];
            }
        }
        li.push_back({res,res2,i});
    }
    sort(li.begin(),li.end());
    for (int i=0;i<N;i++){
        if (li[i].c==P-1){
            printf("%d %d\n",li[i].a,i+1);
            return 0;
        }
    }
}
