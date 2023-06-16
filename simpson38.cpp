#include <bits/stdc++.h>
using namespace std;
float func(float x)
{
    return 1 / (1 + (x * x));
}
int main()
{
    int n;
    float sum = 0, a, b, h;
    cin >> a >> b >> n;
    h = (b - a) / n;
    sum = func(a) + func(b);
    int ct = 1;
    for (int i = a + h; i < b; i = i + h)
    {
        if (ct % 3)
        {
            sum += (3 * func(i));
        }
        else
            sum += (2 * func(i));
        ct += 1;
    }
    sum = (sum * 3 * h) / 8;
    cout << sum << endl;
    return 0;
}