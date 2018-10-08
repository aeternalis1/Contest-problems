#include <bits/stdc++.h>
using namespace std;

int main(){
  cin.sync_with_stdio(0);
  cin.tie(0);
  int S;
  vector<float>sheepx;
  vector<float>sheepy;
  int dist;
  float x,y;
  cin >> S;
  bool sheep[S];
  vector<int>sheepi;
  for (int i=0;i<S;i++){
    cin >> x >> y;
    sheepx.push_back(x*100);
    sheepy.push_back(y*100);
    sheep[i] = false;
  }
  for (int i=0;i<100000;i++){
    dist = 100000000;
    sheepi.clear();
    for (int l=0;l<S;l++){
      if (pow(pow(sheepx[l]-i,2)+pow(sheepy[l],2),0.5) < dist){
        dist = pow(pow(sheepx[l]-i,2)+pow(sheepy[l],2),0.5);
        sheepi.clear();
        sheepi.push_back(l);
      }
      else if(pow(pow(sheepx[l]-i,2)+pow(sheepy[l],2),0.5)==dist){
        sheepi.push_back(l);
      }
    }
    for (int l=0;l<sheepi.size();l++){
      sheep[sheepi[l]] = true;
    }
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(2);
  for (int i=0;i<S;i++){
    if (sheep[i]){
      cout << "The sheep at (" << sheepx[i]/100 << ", " << sheepy[i]/100 << ") might be eaten." << endl;
    }
  }
  return 0;
}
