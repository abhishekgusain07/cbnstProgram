#include<bits/stdc++.h>
using namespace std;
float func(float x) {
    return x*x*x - 5*x+1;
}
float findx(float a, float b) {
    return (((a*func(b) - b*func(a))/(func(b)-func(a))));
}
int main() {
    int maxIt,ct=1;
    float epsilon = 0.0001;
    cout << "max Iterations : ";
    cin >> maxIt;
    float x1, x2, x;
    cin >> x1 >> x2;
    x = findx(x1, x2);
    do {
        x1 = x2;
        x2 = x;
        x = findx(x1, x2);
        if(abs(x-x2) < epsilon){
            cout << " ans -> " << x << endl;
            break;
            return 0;
        }
        ct++;
    }while(ct <= maxIt);
    cout << "ans --> "<< x << endl;
    return 0;
}