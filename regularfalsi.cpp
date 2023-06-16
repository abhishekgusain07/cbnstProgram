#include <bits/stdc++.h>
using namespace std;
float func(float s)
{
    return s * s * s - 2 * s - 5;
}
float bisect(float a, float b)
{
    float ans;
    ans = (a * (func(b)) - b * (func(a))) / (func(b) - func(a));
    return ans;
}
int main()
{
    int maxIt;
    float epsilon = 0.0001;
    float x1, x2, x3, x;
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
    do
    {
        x = bisect(x1, x2);
        if (func(x) * func(x1) < 0)
            x2 = x;
        else
            x1 = x;
        x3 = bisect(x1, x2);
        if (abs(x3 - x) < epsilon)
        {
            cout << "ans ---> " << x << endl;
            break;
            return 0;
        }
        x = x3;
        ct += 1;
    } while (ct <= maxIt);
    return 0;
}