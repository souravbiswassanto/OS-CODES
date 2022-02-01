#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, head;
    cin >> n >> head;
    vector<int> curP(n);
    for(int i = 0; i < n; i++){
        cin >> curP[i];
    }
    cout << "Order of movement -> \n";
    cout <<head << " -> "; long long sum = 0;
    for(int i = 0; i < n; i++){
        int idx = -1; int Min = INT_MAX;
        for(int j = 0; j < n; j++){
            if(curP[j] != INT_MAX){
                if(Min > abs(head - curP[j])){
                    idx = j; Min = abs(head - curP[j]);
                }
            }
        }
        cout << curP[idx]<<" -> "; sum += abs(head - curP[idx]); 
        head = curP[idx]; curP[idx] = INT_MAX;
    }
    cout <<endl; cout <<"Total head movement: \n";
    cout << sum << endl;
    return 0;
}