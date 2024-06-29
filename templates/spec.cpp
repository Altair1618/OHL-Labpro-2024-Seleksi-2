#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 1e5;
    const int AMAX = 1e9;
    int N;
    vector<int> val;

    int ans;
    void InputFormat() {
        LINE(N);
        LINE(val % SIZE(N));
    }

    void OutputFormat1() {
        LINE(ans);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1 <= N <= NMAX);
        CONS(array_cons(val));
    }

private:
    bool array_cons(vector<int> &val){
        if(val.size() != N)return false;
        for(int x : val){
            if(x > AMAX || x <= 0)return false;
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "5",
            "1 2 3 4 5"
        });
        Output({
            "15"
        });
    }

    void BeforeTestCase(){
        val.clear();
    }

    void TestCases() {
        for(int i=0;i<10;i++)CASE(N = NMAX, random_array(N, val, AMAX));
    }

private:
    void random_array(int n, vector<int>& val, int nmax){
        for(int i=0;i<n;i++){
            val.push_back(rnd.nextInt(1, nmax));
        }
    }
};
