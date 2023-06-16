#include <bits/stdc++.h>
using namespace std;
float func(float x)
{
    return x * x * x;
}
int main()
{
    float sum = 0, a, b, h, n;
    cin >> a >> b >> n;
    h = (b - a) / n;
    sum = func(a) + func(b);
    for (int i = a + h; i < b; i =i+h)
    {
        sum += 2 * func(i);
    }
    float ans = (sum * h) / 2;
    cout << ans << endl;
    return 0;
}