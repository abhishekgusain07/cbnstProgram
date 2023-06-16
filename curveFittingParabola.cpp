#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<float> x(n), y(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    for (int i = 0; i < n; ++i)
        cin >> y[i];
    float sumx = 0, sumx2 = 0, sumx3 = 0, sumx4 = 0;
    float sumy = 0, sumxy = 0, sumx2y = 0;
    for (int i = 0; i < n; ++i)
    {
        sumx += x[i];
        sumx2 += (x[i] * x[i]);
        sumx3 += (x[i] * x[i] * x[i]);
        sumx4 += (x[i] * x[i] * x[i] * x[i]);
        sumy += y[i];
        sumxy += (x[i] * y[i]);
        sumx2y += (x[i] * x[i] * y[i]);
    }
    int nn = 3;
    vector<vector<float>> a(nn, vector<float>(nn + 1));
    a[0][0] = sumx2;
    a[1][0] = sumx3;
    a[2][0] = sumx4;
    a[0][1] = sumx;
    a[1][1] = sumx2;
    a[2][1] = sumx3;
    a[0][2] = n;
    a[1][2] = sumx;
    a[2][2] = sumx2;
    a[0][3] = sumy;
    a[1][3] = sumxy;
    a[2][3] = sumx2y;
    for (int i = 0; i < nn; ++i)
    {
        for (int j = 0; j < nn; ++j)
        {
            if (j > i)
            {
                float ratio = a[j][i] / a[i][i];
                for (int k = 0; k <= nn; ++k)
                {
                    a[j][k] = a[j][k] - (ratio * a[i][k]);
                }
            }
        }
    }
    vector<float> ans(nn);
    ans[nn - 1] = a[nn - 1][nn] / a[nn - 1][nn - 1];
    for (int i = nn - 2; i >= 0; --i)
    {
        float sum = 0;
        for (int j = i + 1; j < nn; ++j)
        {
            sum = sum + a[i][j] * ans[j];
        }
        ans[i] = (a[i][nn] - sum) / a[i][i];
    }
    for (auto &val : ans)
        cout << val << " ";
    cout << endl;
    return 0;
}