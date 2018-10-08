#include <bits/stdc++.h>
using namespace std;

const int MAXN = 201;
typedef long long ll;

int main(){
    int N,M,a,cur,cur2;
    scanf("%d %d",&N,&M);
    int arr[N], nums[M], take[M];
    priority_queue<int,vector<int>,greater<int>> pq;
    queue<int> q;
    for (int i=0;i<N;i++){
        scanf("%d",&arr[i]);
        pq.push(i);
    }
    for (int i=0;i<M;i++){
        scanf("%d",&nums[i]);
        take[i] = -1;
    }
    int ans = 0;
    for (int i=0;i<M*2;i++){
        scanf("%d",&a);
        if (a>0){
            a--;
            if (pq.size()){
                cur = pq.top();
                pq.pop();
                ans += arr[cur]*nums[a];
                take[a] = cur;
            }else{
                q.push(a);
            }
        }else{
            pq.push(take[-(a+1)]);
        }
        while (!q.empty()&&!pq.empty()){
            cur = q.front();
            cur2 = pq.top();
            q.pop();
            pq.pop();
            take[cur] = cur2;
            ans += nums[cur]*arr[cur2];
        }
    }
    printf("%d\n",ans);
}
