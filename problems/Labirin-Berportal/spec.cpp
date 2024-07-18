#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 2e5;
    const int KMAX = 1e9;

    int N, K, ans;
    vector<vector<int>> data;
    set<int> s, check;

    void InputFormat() {
        LINE(N, K);
        LINES(data) % SIZE(N);
    }

    void OutputFormat1() {
        LINE(ans);
    }

    void GradingConfig() {
        TimeLimit(2);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1 <= N <= NMAX);
        CONS(1 <= K <= KMAX);
        CONS(data_cons(data));
    }

private:
    bool data_cons(vector<vector<int>> &data) {        
        if (data.size() != N) return false;

        for(int i = 0; i < N; i++) {
            if (data[i].size() != 3) return false;
            
            if (data[i][0] < 2 || data[i][0] >= K) return false;
            if (check.count(data[i][0])) return false;
            check.insert(data[i][0]);

            if (data[i][1] < 1 || data[i][1] >= data[i][0]) return false;
            if (check.count(data[i][1])) return false;
            check.insert(data[i][1]);

            if (data[i][2] < 0 || data[i][2] > 1) return false;
        }

        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "4 9",
            "3 2 0",
            "6 5 1",
            "7 4 0",
            "8 1 1"
        });
        Output({
            "23"
        });
    }

    void SampleTestCase2() {
        Input({
            "5 1000000000",
            "199999999 100000000 1",
            "599999999 400000000 0",
            "799999999 300000000 0",
            "899999999 700000000 1",
            "999999999 500000000 0"
        });
        Output({
            "3511290"
        });
    }

    void BeforeTestCase(){
        data.clear();
        s.clear();
        check.clear();
    }

    void TestCases() {
        for (int i = 0; i < 10; i++)
            CASE(random_data(10, data, 100));
        for (int i = 0; i < 10; i++)
            CASE(random_data(100, data, 1e4));
        for (int i = 0; i < 10; i++)
            CASE(random_data(1e3, data, KMAX));
        for (int i = 0; i < 10; i++)
            CASE(random_data(1e4, data, KMAX));
        for (int i = 0; i < 10; i++)
            CASE(random_data(2e5, data, KMAX));
    }

private:
    void random_data(int nmax, vector<vector<int>>& data, int kmax) {
        N = rnd.nextInt(1, nmax);
        K = rnd.nextInt(2 * N + 1, kmax);

        for(int i = 0; i < N; i++) {
            int x, y, b;

            do {
                x = rnd.nextInt(2, K - 1);
            } while(s.count(x));
            s.insert(x);

            do {
                y = rnd.nextInt(1, x - 1);
            } while(s.count(y));
            s.insert(y);

            b = rnd.nextInt(0, 1);
            data.push_back({x, y, b});
        }

        sort(data.begin(), data.end());
    }
};
