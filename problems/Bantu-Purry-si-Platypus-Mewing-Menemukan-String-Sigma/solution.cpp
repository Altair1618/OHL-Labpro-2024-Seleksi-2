#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

int t;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int free, point_to[26], parent[26];
    for (int i = 0; i < 26; i++)
        parent[i] = i;
    memset(point_to, -1, sizeof(point_to));
    set<int> v;
    bool visited[26];
    memset(visited, 0, sizeof(visited));
    if (s[0] == 'a')
    {
        free = 1;
    }
    else
    {
        free = 0;
    }
    for (int i = 0; i < n; i++)
    {
        int cur = s[i] - 'a';
        if (point_to[cur] != -1)
            continue;
        if (free == cur)
        {
            visited[cur] = true;
            bool found = false;
            for (int j = 0; j < 26; j++)
            {
                if (!visited[j])
                {
                    free = j;
                    found = true;
                    break;
                }
            }
            if (!found)
                free = -1;
        }
        if (!v.empty())
        {
            bool found = false;
            for (auto it : v)
            {
                if (it > free && free != -1)
                    break;
                if (it != parent[cur])
                {
                    visited[cur] = true;
                    point_to[cur] = it;
                    for (int j = 0; j < 26; j++)
                    {
                        if (j != it && parent[j] == parent[it])
                            parent[j] = parent[cur];
                    }
                    parent[it] = parent[cur];
                    v.erase(it);
                    v.insert(parent[it]);
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                if (free != -1)
                {
                    point_to[cur] = free;
                    visited[free] = true;
                    visited[cur] = true;
                    parent[free] = parent[cur];
                    v.insert(parent[cur]);
                    found = false;
                    for (int j = 0; j < 26; j++)
                    {
                        if (!visited[j])
                        {
                            free = j;
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                        free = -1;
                }
                else
                {
                    for (auto it : v)
                    {
                        point_to[cur] = it;
                        parent[it] = parent[cur];
                        v.erase(it);
                        break;
                    }
                }
            }
        }
        else
        {
            point_to[cur] = free;
            visited[free] = true;
            visited[cur] = true;
            parent[free] = parent[cur];
            v.insert(parent[cur]);
            bool found = false;
            for (int j = 0; j < 26; j++)
            {
                if (!visited[j])
                {
                    free = j;
                    found = true;
                    break;
                }
            }
            if (!found)
                free = -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << (char)('a' + point_to[s[i] - 'a']);
    }
    cout << endl;
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
