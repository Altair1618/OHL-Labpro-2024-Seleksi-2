#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 45;

    int N;
    vector<int> ans;

    void InputFormat() {
        LINE(N);
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
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "1"
        });
        Output({
            "0 1"
        });
    }

    void SampleTestCase2() {
        Input({
            "4"
        });
        Output({
            "2 3"
        });
    }

    void SampleTestCase3() {
        Input({
            "10"
        });
        Output({
            "34 55"
        });
    }

    void BeforeTestCase(){
        ans.clear();
    }

    void TestCases() {
        for(int i = 0; i < 45; i++)
            CASE(N = i + 1);
    }
};
