#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int SUM_NMAX = 1e5;
    const int AMAX = 1e9;
    int T;
    vector<vector<int>> data, ans;
    vector<int> val;

    void InputFormat() {
        LINE(T);
        LINES(data) % SIZE(2 * T);
    }

    void OutputFormat1() {
        LINES(ans) % SIZE(T);
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
        
        if (data.size() != 2 * T) return false;

        for(int i = 0; i < 2 * T; i += 2) {
            if (data[i].size() != 1) return false;
            
            int N = data[i][0];
            sum_n += N;
            
            if (sum_n > SUM_NMAX) return false;
            if (data[i + 1].size() != N) return false;

            for (int j = 0; j < N; j++) {
                if (data[i + 1][j] < 0 || data[i + 1][j] > AMAX) return false;
            }
        }

        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "1",
            "8",
            "1 3 4 2 5 3 4 2",
        });
        Output({
            "-1 1 3 1 2 2 3 1"
        });
    }

    void BeforeTestCase(){
        data.clear();
    }

    void TestCases() {
        for(int i = 0; i < 10; i++)
            CASE(T = 1, random_data(T, 10, data, AMAX));
        for(int i = 0; i < 10; i++)
            CASE(T = 10, random_data(T, 100, data, AMAX));
        for(int i = 0; i < 10; i++)
            CASE(T = 100, random_data(T, 1000, data, AMAX));
        for(int i = 0; i < 5; i++)
            CASE(T = 1, random_data(T, 1e5, data, AMAX));
        for(int i = 0; i < 5; i++)
            CASE(T = 10, random_data(T, 1e4, data, AMAX));
        for(int i = 0; i < 10; i++)
            CASE(T = 1000, random_data(T, 100, data, AMAX));
        for(int i = 0; i < 10; i++)
            CASE(T = 1e4, random_data(T, 10, data, AMAX));
    }

private:
    void random_data(int t, int nmax, vector<vector<int>>& data, int amax){
        for(int i = 0; i < t; i++) {
            int n = rnd.nextInt(1, nmax);
            data.push_back({n});
            
            vector<int> vec_a = random_array(n, amax);
            data.push_back(vec_a);
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
