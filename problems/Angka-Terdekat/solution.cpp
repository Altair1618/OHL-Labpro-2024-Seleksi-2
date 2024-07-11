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

void solve() {
    ll n; cin >> n;
    
    stack<ll> s;
    forn(i, n) {
        ll x; cin >> x;

        while (!s.empty() && s.top() >= x) s.pop();
        
        if (i != n - 1) {
            if (s.empty()) prints(-1);
            else prints(s.top());
        } else {
            if (s.empty()) println(-1);
            else println(s.top());
        }

        s.push(x);
    }

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