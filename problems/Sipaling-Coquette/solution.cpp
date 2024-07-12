#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int countPitaCoquette(vector<pair<int, int>> &points, int counts[1001][1001], int x1, int y1)
{
    int count = 0;

    if (counts[x1][y1] == 0)
        return 0;

    for (auto &[x3, y3] : points)
    {
        int dx = abs(x1 - x3), dy = abs(y1 - y3);

        if (dx == 0 || dx != 2 * dy)
        {
            continue;
        }

        count += counts[x1][y3] * counts[x3][y1];
    }

    count *= counts[x1][y1];

    return count;
}

int main()
{
    int n, xTarget, yTarget;
    cin >> n;

    vector<pair<int, int>> v(n);
    int counts[1001][1001] = {};

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
        counts[v[i].first][v[i].second]++;
    }

    cin >> xTarget >> yTarget;
    cout << countPitaCoquette(v, counts, xTarget, yTarget) << endl;

    return 0;
}
