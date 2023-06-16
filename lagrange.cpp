#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout << "enter n: ";
    cin >> n;
    vector<float> x(n), y(n);
    cout << "enter values of x: ";
    for(int i = 0; i < n; ++i)cin >> x[i];
    cout << "enter values of j: ";
    for(int j = 0; j < n; ++j)cin >> y[j];
    
    float xx;
    cin >> xx;
    float sum = 0;
    for(int i = 0; i < n; ++i) {
        float term = 1;
        for(int j = 0; j < n; ++j) {
            if(i!= j) {
                term = term*(xx-x[j])/(x[i]-x[j]);
            }
        }
        sum += (term*y[i]);
    }
    cout << sum << endl;
    return 0;
}