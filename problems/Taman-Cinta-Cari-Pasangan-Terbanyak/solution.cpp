#include <bits/stdc++.h>

#define ll                      long long
#define all(v)                  (v).begin(), (v).end()
#define forn(var, n)            for (ll var = 0; var < n; ++var)
#define forr(var, start, end)   for (ll var = start; var < end; ++var)
#define fori(var, start, end)   for (ll var = start; var > end; --var)
#define fora(var, obj)          for (auto var : obj)
#define MOD1                    (ll) (1e9 + 7)
#define MOD9                    (ll) (998244353)
#define prints(x)               cout << (x) << " "
#define println(x)              cout << (x) << "\n"
#define newl()                  cout << "\n"

using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            int res = k - nums[i];
            if (map[res] > 0) {
                count++;
                map[res]--;
            } else {
                map[nums[i]]++;
            }
        }
        return count;
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    forn(i, n) {
        cin >> nums[i];
    }

    Solution sol;
    int result = sol.maxOperations(nums, k);
    cout << result << endl;

    return 0;
}
