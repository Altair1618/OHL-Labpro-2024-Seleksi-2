#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 2e4;
    
    int N, K;
    string lst;
    vector<int> ans;

    void InputFormat() {
        LINE(N);
        LINE(K);
    }

    void OutputFormat1() {
        LINES(ans) % SIZE(N - 1);
        RAW_LINE(lst);
    }

    void GradingConfig() {
        TimeLimit(3);
        MemoryLimit(512);
    }

    void Constraints() {
        CONS(2 <= N <= NMAX);
        CONS(1 <= K < N);
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "7",
            "3"
        });
        Output({
            "3",
            "6",
            "2",
            "7",
            "5",
            "1",
            "Survivor: 4"
        });
    }

    void SampleTestCase2() {
        Input({
            "5",
            "3"
        });
        Output({
            "3",
            "1",
            "5",
            "2",
            "Survivor: 4"
        });
    }

    void BeforeTestCase(){
        ans.clear();
    }

    void TestCases() {
        for(int i = 0; i < 10; i++)
            CASE(random_data(10));
        for(int i = 0; i < 10; i++)
            CASE(random_data(100));
        for(int i = 0; i < 10; i++)
            CASE(random_data(1000));
        for(int i = 0; i < 5; i++)
            CASE(random_data(1e4));
        for(int i = 0; i < 5; i++)
            CASE(random_data(2e4));
    }

private:
    void random_data(int nmax){
        N = rnd.nextInt(2, nmax);
        K = rnd.nextInt(1, N - 1);
    }
};
