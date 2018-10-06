#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000001;
typedef long long ll;
vector<int> paths[MAXN];
int ans[MAXN][3];

int LocateCentre(int N, int P[], int S[], int D[]){
    for (int i=0;i<N-1;i++){
        paths[S[i]].push_back(D[i]);
        paths[D[i]].push_back(S[i]);
    }
    queue<int> q;
    int ind = 0, cur;
    memset(ans,-1,sizeof ans);
    q.push(ind);
    ans[ind][0] = 0;
    while (!q.empty()){
        cur = q.front();
        q.pop();
        for (int i:paths[cur]){
            if (ans[i][0]==-1){
                q.push(i);
                ans[i][0] = ans[cur][0]+P[cur];
            }
        }
    }
    int res = 0;
    for (int i=0;i<N;i++){
        if (ans[i][0]>res){
            res = ans[i][0];
            ind = i;
        }
    }
    for (int l=1;l<=2;l++){
        q.push(ind);
        ans[ind][l] = 0;
        while (!q.empty()){
            cur = q.front();
            q.pop();
            for (int i:paths[cur]){
                if (ans[i][l]==-1){
                    q.push(i);
                    ans[i][l] = ans[cur][l]+P[cur];
                }
            }
        }
        res = 0;
        for (int i=0;i<N;i++){
            if (ans[i][l]>res){
                res = ans[i][l];
                ind = i;
            }
        }
    }
    res = 2e9+1;
    for (int i=0;i<N;i++){
        if (max(ans[i][1],ans[i][2])<res){
            res = max(ans[i][1],ans[i][2]);
            ind = i;
        }
    }
    return ind;
}
