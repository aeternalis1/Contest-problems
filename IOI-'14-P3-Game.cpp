#include <bits/stdc++.h>
using namespace std;

//http://blog.brucemerry.org.za/2014/07/ioi-2014-day-1-analysis.html   <------ credit is due 
#define MAXN 1501

int edges[MAXN]; //number of remaining nodes to connect to
int par[MAXN];

// whenever an edge is added, remove 1 from all remaining components to connect to

int parent(int i){
  if (par[i]==i) return i;
  return parent(par[i]);
}

void merge(int a, int b){
  if (edges[a] >= edges[b]){
    edges[b] = edges[a];
  }
  else if (edges[a] < edges[b]){
    edges[a] = edges[b];
  }
  par[a] = b;
  edges[a]--;
  edges[b]--;
}

void initialize(int n){
  for (int i=0;i<n;i++){
    par[i] = i;
    edges[i] = n-1;
  }
}

int hasEdge(int u, int v){
  int a = parent(u);
  int b = parent(v);
  /*for (int i=0;i<4;i++){
    cout << edges[i] << " ";
  }
  cout << endl;*/
  if (a==b){ //already connected
    return 1;
  }
  if (edges[a] == 1 || edges[b] == 1){
    merge(a,b);
    return 1;
  }
  edges[a]--;
  edges[b]--;
  return 0;
}
