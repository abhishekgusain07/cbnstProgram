#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<float> x(n), y(n);
    for(int i=0; i< n; ++i){
        cin >> x[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> y[i];
    }
    float sumx =0,sumy= 0,sumxy=0,sumxx=0;
    for(int i = 0; i < n; ++i) {
        sumx += x[i];
        sumy += y[i];
        sumxy += (x[i]*y[i]);
        sumxx += (x[i]*x[i]);
    }
    vector<vector<float>> a(2, vector<float>(3));
    a[0][0] = n;
    a[0][1] = sumx;
    a[0][2] = sumy;
    a[1][0] = sumx;
    a[1][1] = sumxx;
    a[1][2] = sumxy;
    vector<float> ans(2);
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 2; ++j) {
            if(j > i) {
                float ratio = a[j][i]/a[i][i];
                for(int k = 0; k <= 2; ++k){
                    a[j][k] = a[j][k]-(ratio*a[i][k]);
                }
            }
        }
    }
    ans[1] = a[1][2]/a[1][1];
    ans[0] = (a[0][2]-(a[0][1]*ans[1]))/a[0][0];
    cout << ans[0] << " "<< ans[1]<< endl;
    return 0;
}