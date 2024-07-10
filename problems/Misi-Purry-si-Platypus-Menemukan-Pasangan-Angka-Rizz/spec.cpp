#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int TMAX = 10;
    const int VMAX = 1e9;

    int T;
    vector<vector<int>> data, ans;

    void InputFormat() {
        LINE(T);
        LINES(data) % SIZE(T);
    }

    void OutputFormat1() {
        LINES(ans) % SIZE(T);
    }

    void GradingConfig() {
        TimeLimit(4);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1 <= T <= TMAX);
        CONS(data_cons(data));
    }

private:
    bool data_cons(vector<vector<int>> &data){
        if (data.size() != T) return false;

        for(int i = 0; i < T; i++) {
            if (data[i].size() != 4) return false;

            if (data[i][0] >= data[i][2]) return false;
            if (data[i][1] >= data[i][3]) return false;

            for (int j = 0; j < 4; j++) {
                if (data[i][j] < 0 || data[i][j] > VMAX) return false;
            }
        }

        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "10",
            "1 1 2 2",
            "8 9 14 18",
            "3 4 5 8",
            "36 60 48 87",
            "12 20 14 25",
            "1024 729 373248 730",
            "1024 729 373247 730",
            "5040 20310 40319 1000000000",
            "999999999 999999999 1000000000 1000000000",
            "168435456 168435456 1000000000 1000000000"
        });
        Output({
            "2 2",
            "12 18",
            "4 6",
            "-1 -1",
            "-1 -1",
            "373248 730",
            "-1 -1",
            "5041 102362400",
            "-1 -1",
            "170459136 998614806"
        });
    }

    void BeforeTestCase(){
        data.clear();
    }

    void TestCases() {
        for(int i = 0; i < 10; i++)
            CASE(T = 1, random_data(T, 10, data, VMAX));
        for(int i = 0; i < 10; i++)
            CASE(T = 10, random_data(T, 100, data, VMAX));
        for(int i = 0; i < 10; i++)
            CASE(T = 100, random_data(T, 1000, data, VMAX));
        for(int i = 0; i < 5; i++)
            CASE(T = 1, random_data(T, 1e5, data, VMAX));
        for(int i = 0; i < 5; i++)
            CASE(T = 10, random_data(T, 2e4, data, VMAX));
        for(int i = 0; i < 10; i++)
            CASE(T = 1000, random_data(T, 200, data, VMAX));
        for(int i = 0; i < 10; i++)
            CASE(T = 1e4, random_data(T, 20, data, VMAX));
    }

private:
    void random_data(int t, int nmax, vector<vector<int>>& data, int amax){
        for(int i = 0; i < t; i++) {
            int a = rnd.nextInt(1, amax - 1);
            int b = rnd.nextInt(1, amax - 1);
            int c = rnd.nextInt(a + 1, amax);
            int d = rnd.nextInt(b + 1, amax);
            data.push_back({a, b, c, d});
        }
    }
};
