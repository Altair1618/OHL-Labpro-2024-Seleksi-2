#include <bits/stdc++.h>

using namespace std;

int ac() {
    exit(42);
}

int wa() {
    exit(43);
}

int main(int argc, char *argv[]) {
    ifstream tc_in(argv[1]);
    ifstream tc_out(argv[2]);

    long long t, a, b, c, d;
    pair<long long, long long> jury_ans, out_ans;
    tc_in >> t;

    for (int i = 0; i < t; i++) {
        tc_in >> a >> b >> c >> d;
        tc_out >> jury_ans.first >> jury_ans.second;
        cin >> out_ans.first >> out_ans.second;

        if (jury_ans.first == -1 && jury_ans.second == -1) {
            if (out_ans.first != -1 || out_ans.second != -1) {
                cout << "Output should be -1 -1 in line " << i + 1 << "\n";
                return wa();
            }

            continue;
        }

        if (out_ans.first <= a) {
            cout << "First number should be greater than " << a << " in line " << i + 1 << "\n";
            return wa();
        }

        if (out_ans.first > c) {
            cout << "First number should be less than or equal to " << c << " in line " << i + 1 << "\n";
            return wa();
        }

        if (out_ans.second <= b) {
            cout << "Second number should be greater than " << b << " in line " << i + 1 << "\n";
            return wa();
        }

        if (out_ans.second > d) {
            cout << "Second number should be less than or equal to " << d << " in line " << i + 1 << "\n";
            return wa();
        }

        if ((out_ans.first * out_ans.second) % (a * b) != 0) {
            cout << "Product of the numbers is not divisible by " << a * b << " in line " << i + 1 << "\n";
            return wa();
        }
    }

    cout << "Output correct\n";
    return ac();
}