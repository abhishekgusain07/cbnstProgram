#include <bits/stdc++.h>
using namespace std;
float func(float s)
{
    return s * s * s - 2 * s - 5;
}
float bisect(float a, float b)
{
    return (a + b) / 2;
}
int main()
{
    int maxIt;
    float x1, x2, x;
    cout << "max iterations ?: ";
    cin >> maxIt;
    do
    {
        cin >> x1 >> x2;
        if (func(x1) * func(x2) < 0)
            break;
        else
        {
            cout << "invalid! try roots again: ";
            continue;
        }
    } while (1);
    int ct = 1;
    while (ct <= maxIt)
    {
        x = bisect(x1, x2);
        if (func(x) * func(x1) < 0)
            x2 = x;
        else
            x1 = x;
        ct += 1;
    }
    cout << "final root = " << x << endl;
    return 0;
}