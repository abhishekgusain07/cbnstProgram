#include <bits/stdc++.h>
using namespace std;
float f(float x)
{
    return x * x * x + x * x - 1;
}
float findValueAt(float x)
{
    return 1 / sqrt(1 + x);
}
float differentiate(float x)
{
    return 1 / 2.0 * (pow(1, pow((1 + x), 3 / 2.0)));
}
int main()
{
    int maxIt;
    float epsilon = 0.0001;
    cout << "Max Iterations: " << endl;
    cin >> maxIt;
    float a, b, x, x0;
    do
    {
        cout << "enter value of roots: ";
        cin >> a >> b;
        if (f(a) * f(b) < 0)
        {
            cout << "valid" << endl;
            break;
        }
        else
        {
            cout << "invalid roots: ";
            continue;
        }
    } while (1);
    x0 = (a + b) / 2;
    if (differentiate(x0) < 1)
        cout << "correct form: " << endl;
    else
        cout << "incorrect Form: " << endl;

    for (int i = 0; i < maxIt; ++i)
    {
        x = findValueAt(x0);
        if (abs(x - x0) < epsilon)
        {
            cout << "final value: " << x << endl;
        }
        x0 = x;
    }
    cout << "final value : " << x << endl;
}