#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1501;

int sz[MAXN];

void initialize(int n){
}

int hasEdge(int u, int v){
    if (u<v) swap(u,v);
    if (++sz[u]==u) return 1;
    return 0;
}
