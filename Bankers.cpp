#include<bits/stdc++.h>
using namespace std;

struct Bankers{
    int n, m; vector<vector<int>> need, Max, allot;
    vector<int> sequence, available;
    vector<bool> isDone;
    Bankers(){}
    Bankers(int _n, int _m){
        n = _n; m = _m;
        need.resize(n, vector<int> (m, 0));
        Max.resize(n, vector<int> (m, 0));
        allot.resize(n, vector<int> (m, 0));
        available.resize(m, 0);
        
    }
    void Scan(){
        for(int i = 0; i < m; i++){
            cin >> available[i];
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> allot[i][j];
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> Max[i][j];
            }
        }
        
    }
    bool isSafe(){
        isDone.resize(n, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                need[i][j] = Max[i][j] - allot[i][j];
            }
        }
        for(int i = 0; i < n; i++){
            int idx = -1;
            for(int j = 0; j < n; j++){
                if(isDone[j] == false){
                    bool check = false;
                    for(int k = 0; k < m; k++){
                        if(need[j][k] > available[k])check = true;
                    }
                    if(!check){
                        idx = j; break;
                    }
                }
            }
            if(idx == -1){
                return false;
            }
            sequence.push_back(idx);
            isDone[idx] = true;
            for(int j = 0; j < m; j++)available[j] += allot[idx][j];
        }
        return true;
    }
    void solve(){
        Scan();
        bool Safe = isSafe();
        if(Safe){
            cout <<"System is in safe state" << endl;
            cout <<"A safe sequence is - \n";
            for(auto v: sequence)cout << v <<" "; cout << endl;
            cout << "Total available resource"<< endl;
            for(auto v: available)cout << v << " "; cout << endl;
        }
        else {
            cout <<"System in not in safe state" << endl;
        }
    }
};


int main(){
    int n, m;
    cin >> n >> m;
    Bankers bankers(n, m);
    bankers.solve();
}