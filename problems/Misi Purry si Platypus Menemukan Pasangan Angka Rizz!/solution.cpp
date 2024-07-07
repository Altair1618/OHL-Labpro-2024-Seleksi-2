#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

int t;

int binser(int x)
{
    int lo = 1, hi = x, mid;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (mid * mid >= x)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return lo;
}

void solve()
{
    int a, b, c, d;
    vector<int> faktor_a, faktor_b, faktor;
    vector<int> akara, akarb;
    cin >> a >> b >> c >> d;
    int x = a * b;
    for (int i = 1; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            faktor_a.push_back(i);
            faktor_a.push_back(a / i);
        }
    }
    for (int i = 1; i * i <= b; i++)
    {
        if (b % i == 0)
        {
            faktor_b.push_back(i);
            faktor_b.push_back(b / i);
        }
    }
    sort(faktor_a.begin(), faktor_a.end());
    unique(faktor_a.begin(), faktor_a.end());
    sort(faktor_b.begin(), faktor_b.end());
    unique(faktor_b.begin(), faktor_b.end());
    for (int i = 0; i < faktor_a.size(); i++)
    {
        for (int j = 0; j < faktor_b.size(); j++)
        {
            faktor.push_back(faktor_a[i] * faktor_b[j]);
        }
    }
    sort(faktor.begin(), faktor.end());
    unique(faktor.begin(), faktor.end());

    for (auto i : faktor)
    {
        int faktor1 = i, faktor2 = x / i;
        if (c / faktor1 - a / faktor1 > 0 && d / faktor2 - b / faktor2 > 0)
        {
            cout << faktor1 * (a / faktor1) + faktor1 << ' ' << faktor2 * (b / faktor2) + faktor2 << endl;
            return;
        }
        if (c / faktor2 - a / faktor2 > 0 && d / faktor1 - b / faktor1 > 0)
        {
            cout << faktor2 * (a / faktor2) + faktor2 << ' ' << faktor1 * (b / faktor1) + faktor1 << endl;
            return;
        }
    }
    cout << "-1 -1" << endl;
}

signed main()
{
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--)
        solve();
    return 0;
}
