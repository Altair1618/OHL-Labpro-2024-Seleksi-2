#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

int k, num_a = 1, num_b = 0;

signed main()
{
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int temp_a = num_b;
        int temp_b = num_a + num_b;
        num_a = temp_a;
        num_b = temp_b;
    }

    cout << num_a << ' ' << num_b << endl;

    return 0;
}