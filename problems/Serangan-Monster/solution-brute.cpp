#include <bits/stdc++.h>

#define ll                      long long
#define all(v)                  (v).begin(), (v).end()
#define forn(var, n)            for (ll (var) = 0; (var) < (n); ++(var))
#define forr(var, start, end)   for (ll (var) = (start); (var) < (end); ++(var))
#define fori(var, start, end)   for (ll (var) = (start); (var) > (end); --(var))
#define fora(var, obj)          for (auto (var) : (obj))
#define MOD1                    (ll) (1e9 + 7)
#define MOD9                    (ll) (998244353)
#define prints(x)               cout << (x) << " "
#define println(x)              cout << (x) << "\n"
#define newl()                  cout << "\n"

using namespace std;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> h(n); fora(&x, h) cin >> x;
    vector<ll> p(n); fora(&x, p) cin >> x;

    while (k > 0) {
        ll cnz = n;
        ll red = LONG_LONG_MAX;

        forn(i, n) {
            h[i] = max(0LL, h[i] - k);

            if (h[i] == 0) cnz--;
            else red = min(red, p[i]);
        }
    
        if (cnz == 0) break;
        k -= red;
    }

    bool allz = true;
    forn(i, n) {
        if (h[i] > 0) {
            allz = false;
            break;
        }
    }

    if (allz) println("YES");
    else println("NO");
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}