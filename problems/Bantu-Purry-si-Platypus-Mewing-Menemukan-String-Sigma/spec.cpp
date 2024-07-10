#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int TMAX = 3e4;
    const int NMAX = 1e5;
    const int SUM_NMAX = 2e5;

    int T;
    vector<int> N;
    vector<string> data, ans;

    void InputFormat() {
        LINE(T);
        LINES(N, data) % SIZE(T);
    }

    void OutputFormat1() {
        LINES(ans) % SIZE(T);
    }

    void GradingConfig() {
        TimeLimit(3);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1 <= T <= TMAX);
        CONS(data_cons(data));
    }

private:
    bool data_cons(vector<string> &data){
        int sum_n = 0;

        if (N.size() != T) return false;
        if (data.size() != T) return false;

        for(int i = 0; i < T; i++) {
            if (data[i].size() != N[i]) return false;

            sum_n += N[i];
            if (sum_n > SUM_NMAX) return false;

            for (int j = 0; j < N[i]; j++) {
                if (data[i][j] < 'a' || data[i][j] > 'z') return false;
            }
        }

        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "4",
            "1 a",
            "2 ba",
            "15 purrysiplatypus",
            "26 abcdefghijklmnopqrstuvwxyz"
        });
        Output({
            "b",
            "ac",
            "abccdefaghidabe",
            "bcdefghijklmnopqrstuvwxyza"
        });
    }

    void BeforeTestCase() {
        N.clear();
        data.clear();
    }

    void TestCases() {
        for(int i = 0; i < 10; i++)
            CASE(T = 1, random_data(T, 10, data));
        for(int i = 0; i < 10; i++)
            CASE(T = 10, random_data(T, 100, data));
        for(int i = 0; i < 10; i++)
            CASE(T = 100, random_data(T, 1000, data));
        for(int i = 0; i < 5; i++)
            CASE(T = 1, random_data(T, 1e5, data));
        for(int i = 0; i < 5; i++)
            CASE(T = 10, random_data(T, 2e4, data));
        for(int i = 0; i < 10; i++)
            CASE(T = 1000, random_data(T, 200, data));
        for(int i = 0; i < 10; i++)
            CASE(T = 1e4, random_data(T, 20, data));
        for (int i = 0; i < 10; i++)
            CASE(T = 3e4, random_data(T, 5, data));
    }

private:
    void random_data(int t, int nmax, vector<string>& data) {
        for(int i = 0; i < t; i++) {
            int n = rnd.nextInt(1, nmax);
            N.push_back(n);
            data.push_back(random_string(n));
        }
    }

    string random_string(int n) {
        string res = "";
        
        for (int i = 0; i < n; i++) {
            res += 'a' + rnd.nextInt(26);
        }
        
        return res;
    }
};
