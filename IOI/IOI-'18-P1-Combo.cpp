#include <bits/stdc++.h>
using namespace std;

string guess_sequence(int N){
    int cur = 1, res;
    vector<char> lets;
    string ans, temp;
    lets.push_back('A');
    lets.push_back('B');
    lets.push_back('X');
    lets.push_back('Y');
    char f = 0;
    temp = "AB";
    res = press(temp);
    if (res){
        temp = "A";
        res = press(temp);
        if (res) f = 'A';
        else f = 'B';
    }else{
        temp = "X";
        res = press(temp);
        if (res) f = 'X';
        else f = 'Y';
    }
    ans.append(1u,f);
    lets.erase(remove(lets.begin(), lets.end(), f), lets.end());
    if (N==1) return ans;
    while (cur<N-1){
        temp = ans;
        temp.append(1u,lets[0]);
        for (int i=0;i<3;i++){
            temp.append(ans);
            temp.append(1u,lets[1]);
            temp.append(1u,lets[i]);
        }
        res = press(temp);
        if (res==cur){
            ans.append(1u,lets[2]);
        }else if (res==cur+1){
            ans.append(1u,lets[0]);
        }else{
            ans.append(1u,lets[1]);
        }
        cur++;
    }
    temp = ans;
    temp.append(1u,lets[0]);
    temp.append(1u,f);
    temp.append(ans);
    temp.append(1u,lets[1]);
    res = press(temp);
    if (res==N){
        temp = ans;
        temp.append(1u,lets[0]);
        res = press(temp);
        if (res==N){
            ans.append(1u,lets[0]);
        }else{
            ans.append(1u,lets[1]);
        }   
    }else{
        ans.append(1u,lets[2]);
    }
    return ans;
}
