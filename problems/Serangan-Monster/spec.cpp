#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int SUM_NMAX = 2e5;
    const int KMAX = 1e5;
    const int HMAX = 1e9;
    const int PMAX = 1e9;

    int T;
    vector<vector<int>> data;
    vector<int> val;
    vector<string> ans;

    void InputFormat() {
        LINE(T);
        LINES(data) % SIZE(3 * T);
    }

    void OutputFormat1() {
        LINES(ans);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(data_cons(data));
    }

private:
    bool data_cons(vector<vector<int>> &data){
        int sum_n = 0;
        
        if (data.size() != 3 * T) return false;

        for (int i = 0; i < 3 * T; i += 3) {
            if (data[i].size() != 2) return false;
            
            int N = data[i][0];
            sum_n += N;
            
            if (sum_n > SUM_NMAX) return false;
            if (data[i + 1].size() != N) return false;
            if (data[i + 2].size() != N) return false;

            for (int j = 0; j < N; j++) {
                if (data[i + 1][j] < 0 || data[i + 1][j] > HMAX) return false;
                if (data[i + 2][j] < 0 || data[i + 2][j] > PMAX) return false;
            }
        }

        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "2",
            "3 7",
            "17 5 13",
            "2 7 1",
            "3 4",
            "5 5 5",
            "4 4 4"
        });
        Output({
            "YES",
            "NO"
        });
    }

    void BeforeTestCase(){
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
    }

private:
    void random_data(int t, int nmax, vector<vector<int>>& data){
        for(int i = 0; i < t; i++) {
            int n = rnd.nextInt(1, nmax);
            int k = rnd.nextInt(1, KMAX);
            data.push_back({n, k});
            
            vector<int> vec_h = random_array(n, HMAX);
            data.push_back(vec_h);

            vector<int> vec_p = random_array(n, PMAX);
            data.push_back(vec_p);
        }
    }
    
    vector<int> random_array(int n, int nmax){
        vector<int> val;

        for(int i = 0; i < n; i++){
            val.push_back(rnd.nextInt(1, nmax));
        }
        
        return val;
    }
};
