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
    vector<ll> v(n); fora(&x, v) cin >> x;

    priority_queue<pair<ll, ll>> pq;
    forn(i, n) {
        ll x; cin >> x;
        pq.push({-x, v[i]});
    }
    
    ll sum = 0;
    while (k > 0) {
        sum += k;

        while (!pq.empty() && pq.top().second <= sum) pq.pop();
        
        if (pq.empty()) break;
        else k += pq.top().first;
    }

    if (pq.empty()) println("YES");
    else println("NO");
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t = 1;
    cin >> t;
    while (t--) solve();

    return 0;
}