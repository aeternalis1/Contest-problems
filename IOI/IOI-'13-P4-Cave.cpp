void exploreCave(int N){
  int combo[N]; //next combination to check, holds answers for what position each switch should be in
  int found[N]; //which switches have been confirmed and should not be changed
  for (int i=0;i<N;i++){
    found[i] = -1;
  }
  int low,high,mid;
  int switches[N]; //which door does switch[i] connect to? Elements in this array should not change. Final answer array.
  int door;
  for (int i=N-1;i>=0;i--){
    low = 0;
    high = i;
    for (int j=0;j<N;j++){
      if (found[j] == -1){
        combo[j] = 0; //default all switches that have not been confirmed to 'up' position
      }
    }
    int open;
    door = tryCombination(combo);
    if (door==N-i-1){
      open = 1;
    }
    else{
      open = 0;
    }
    while (low<high){
      mid = low+(high-low)/2;
      int cnt = 0;
      for (int j=0;j<N;j++){
        if (found[j] == -1){
          combo[j] = 0;
          if (low<=cnt&&cnt<=mid){
            combo[j] = 1;
          }
          cnt++;
        }
      }
      door = tryCombination(combo);
      if (door!=N-i-1&&!open || door==N-i-1&&open){ //the subset of switches that was changed were relevant
        low = mid+1;
      }
      else{
        high = mid;
      }
    }
    int ind = 0;
    for (int j=0;j<N;j++){
      if (found[j]==-1){
        if (low==0){
          ind = j;
          break;
        }
        low--;
      }
    }
    switches[ind] = N-i-1;
    found[ind] = open;
    combo[ind] = open;
  }
  answer(found,switches);
}
