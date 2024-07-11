#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 2e4;
    const int AMAX = 1e9;
    
    int N;
    string ans;
    vector<int> data, val;

    void InputFormat() {
        LINE(N);
        LINE(data);
    }

    void OutputFormat1() {
        RAW_LINE(ans);
    }

    void GradingConfig() {
        TimeLimit(3);
        MemoryLimit(512);
    }

    void Constraints() {
        CONS(1 <= N <= NMAX);
        CONS(data_cons(data));
    }

private:
    bool data_cons(vector<int> &data){
        if (data.size() != N) return false;

        for(int i = 0; i < N; i++) {
            if (data[i] < 1 || data[i] > AMAX) return false;
        }

        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "5",
            "20 33 6 36 27"
        });
        Output({
            "[20, 1, 33, 3, 6, 6, 36, 9, 27]"
        });
    }

    void BeforeTestCase(){
        data.clear();
    }

    void TestCases() {
        for(int i = 0; i < 10; i++)
            CASE(random_data(10, data, AMAX));
        for(int i = 0; i < 10; i++)
            CASE(random_data(100, data, AMAX));
        for(int i = 0; i < 10; i++)
            CASE(random_data(1000, data, AMAX));
        for(int i = 0; i < 5; i++)
            CASE(random_data(1e4, data, AMAX));
        for(int i = 0; i < 5; i++)
            CASE(random_data(2e4, data, AMAX));
    }

private:
    void random_data(int nmax, vector<int>& data, int amax){
        N = rnd.nextInt(1, nmax);
        data = random_array(N, amax);
    }
    
    vector<int> random_array(int n, int nmax){
        vector<int> val;

        for(int i = 0; i < n; i++){
            val.push_back(rnd.nextInt(1, nmax));
        }
        
        return val;
    }
};
