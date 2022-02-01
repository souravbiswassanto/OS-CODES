#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, headPointer, curP;
    cin >> n >> headPointer;
    long long sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> curP;
        sum += abs(curP - headPointer);
        headPointer = curP;
    }
    cout << "Total Head movement\n"<< sum << endl;
}