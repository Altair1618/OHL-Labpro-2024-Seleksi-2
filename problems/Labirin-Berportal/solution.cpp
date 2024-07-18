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

template <int P>
struct MInt {
    int val;

    MInt(long long v = 0) {
        val = (v % P + P) % P;
    }

    constexpr MInt& operator=(const MInt& other) {
        val = other.val;
        return *this;
    }

    constexpr MInt operator+(const MInt& other) const { return MInt(*this) += other; }
    constexpr MInt operator-(const MInt& other) const { return MInt(*this) -= other; }
    constexpr MInt operator*(const MInt& other) const { return MInt(*this) *= other; }
    constexpr MInt operator/(const MInt& other) const { return MInt(*this) /= other; }
    constexpr MInt operator-() const { return MInt(-val); }

    constexpr MInt& operator+=(const MInt& other) {
        val += other.val;
        if (val >= P) val -= P;
        return *this;
    }

    constexpr MInt& operator-=(const MInt& other) {
        val -= other.val;
        if (val < 0) val += P;
        return *this;
    }

    constexpr MInt& operator*=(const MInt& other) {
        val = (long long)val * other.val % P;
        return *this;
    }

    constexpr MInt& operator/=(const MInt& other) {
        return *this *= other.inv();
    }

    friend constexpr MInt operator+(long long v, const MInt& m) { return m + v; }
    friend constexpr MInt operator-(long long v, const MInt& m) { return -m + v; }
    friend constexpr MInt operator*(long long v, const MInt& m) { return m * v; }
    friend constexpr MInt operator/(long long v, const MInt& m) { return MInt(v) / m; }

    constexpr bool operator==(const MInt& other) const { return val == other.val; }
    constexpr bool operator!=(const MInt& other) const { return val != other.val; }
    constexpr bool operator<(const MInt& other) const { return val < other.val; }
    constexpr bool operator>(const MInt& other) const { return val > other.val; }
    constexpr bool operator<=(const MInt& other) const { return val <= other.val; }
    constexpr bool operator>=(const MInt& other) const { return val >= other.val; }
    
    constexpr MInt inv() const {
        assert(gcd(val, P) == 1);
        return pow(P - 2);
    }

    constexpr MInt pow(long long p) const {
        if (p < 0) return inv().pow(-p);

        MInt res = 1, a = val;
        while (p > 0) {
            if (p & 1) res *= a;
            a *= a;
            p >>= 1;
        }
        return res;
    }

    friend istream& operator>>(istream& in, MInt& m) {
        long long v;
        in >> v;
        m = MInt(v);
        return in;
    }

    friend ostream& operator<<(ostream& out, const MInt& m) {
        return out << m.val;
    }
};

template <long long P>
struct MLong {
    long long val;

    MLong(long long v = 0) {
        val = (v % P + P) % P;
    }

    constexpr MLong& operator=(const MLong& other) {
        val = other.val;
        return *this;
    }

    constexpr MLong operator+(const MLong& other) const { return MLong(*this) += other; }
    constexpr MLong operator-(const MLong& other) const { return MLong(*this) -= other; }
    constexpr MLong operator*(const MLong& other) const { return MLong(*this) *= other; }
    constexpr MLong operator/(const MLong& other) const { return MLong(*this) /= other; }
    constexpr MLong operator-() const { return MLong(-val); }

    constexpr MLong& operator+=(const MLong& other) {
        val += other.val;
        if (val >= P) val -= P;
        return *this;
    }

    constexpr MLong& operator-=(const MLong& other) {
        val -= other.val;
        if (val < 0) val += P;
        return *this;
    }

    constexpr MLong& operator*=(const MLong& other) {
        val = (long long)val * other.val % P;
        return *this;
    }

    constexpr MLong& operator/=(const MLong& other) {
        return *this *= other.inv();
    }

    friend constexpr MLong operator+(long long v, const MLong& m) { return m + v; }
    friend constexpr MLong operator-(long long v, const MLong& m) { return -m + v; }
    friend constexpr MLong operator*(long long v, const MLong& m) { return m * v; }
    friend constexpr MLong operator/(long long v, const MLong& m) { return MLong(v) / m; }

    constexpr bool operator==(const MLong& other) const { return val == other.val; }
    constexpr bool operator!=(const MLong& other) const { return val != other.val; }
    constexpr bool operator<(const MLong& other) const { return val < other.val; }
    constexpr bool operator>(const MLong& other) const { return val > other.val; }
    constexpr bool operator<=(const MLong& other) const { return val <= other.val; }
    constexpr bool operator>=(const MLong& other) const { return val >= other.val; }

    constexpr MLong inv() const {
        return pow(P - 2);
    }

    constexpr MLong pow(long long p) const {
        if (p < 0) return inv().pow(-p);
        
        MLong res = 1, a = val;
        while (p > 0) {
            if (p & 1) res *= a;
            a *= a;
            p >>= 1;
        }
        return res;
    }

    friend istream& operator>>(istream& in, MLong& m) {
        long long v;
        in >> v;
        m = MLong(v);
        return in;
    }

    friend ostream& operator<<(ostream& out, const MLong& m) {
        return out << m.val;
    }
};

using Z = MInt<MOD9>;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> x(n), y(n), b(n);

    forn(i, n) {
        cin >> x[i] >> y[i] >> b[i];
    }

    vector<Z> dp(n), predp(n + 1);
    forn(i, n) {
        ll idx = upper_bound(all(x), y[i]) - x.begin();

        dp[i] = predp[i] - predp[idx] + x[i] - y[i];
        predp[i + 1] = predp[i] + dp[i];
    }

    Z ans = k;
    forn(i, n) if (b[i] > 0) ans += dp[i];

    println(ans);
    return;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}