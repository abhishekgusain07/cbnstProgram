#include <bits/stdc++.h>

using namespace std;
void print(vector<vector<int>> a){
    for(auto &vec : a){
        for(auto &val : vec)
            cout << val << " ";
        cout << endl;
    }
}
int main()
{
   int n;
   cin >> n;
   vector<vector<int>> a(n, vector<int>(n+1));
   for(int i = 0; i < n; ++i) {
    for(int j = 0; j <n+1; ++j)
        cin >> a[i][j];
   }
   for(int i = 0; i < n; ++i) {
    for(int j = 0; j <n; ++j){
        if(i< j){
            int ratio = a[j][i]/a[i][i];
            for(int k = 0; k <= n; ++k) {
                a[j][k] = a[j][k] - (ratio*a[i][k]);
            }
        }
    }
   }
   print(a);
   vector<int> ans(n);
   ans[n-1] = a[n-1][n]/a[n-1][n-1];
   for(int i = n-2; i>=0; --i){
       int sum = 0;
       for(int j= i+1; j<n; ++j){
           sum += (a[i][j]*ans[j]);
       }
       ans[i] = (a[i][n]-sum)/a[i][i];
   }
   for(auto &val : ans){
       cout << val << endl;
   }
    return 0;
}
