#include<bits/stdc++.h>
using namespace std;
#define epsilon 0.0001
float f(float x) {
    return x*x*x-3*x-5;
}
float differentiate(float x){
    return 3*x*x-3;
}
float findValueAt(float x) {
    return x-(f(x)/differentiate(x));
}
int main() {
    int maxIt;
    cin >> maxIt;
    float a, b, x0, x;
    do{
        cout << "enter roots: ";
        cin >> a >> b;
        if(f(a)*f(b) < 0){
            cout << "valid: ";
            break;
        }else{
            cout << "invalid! try again: ";
            continue;
        }
    }while(1);
    if(abs(f(a)) < abs(f(b)))x0 = a;
    else x0 = b;
    for(int i = 0; i < maxIt; ++i) {
        x = findValueAt(x0);
        if(abs(x-x0) < epsilon){
            cout << "ans --> " << x << endl;
            return 0;
        }
        x0 = x;
    }
    cout << "ans --> " << x << endl;
    return 0;
}