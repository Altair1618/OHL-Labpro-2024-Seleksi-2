#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 10e4;
    const int KMAX = 10e4;

    int N, K;
    vector<int> nums;
    int ans;

    void InputFormat() {
        LINE(N, K);
        LINE(nums % SIZE(N));
    }

    void OutputFormat() {
        LINE(ans);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1 <= N <= NMAX);
        CONS(1 <= K <= KMAX);
        CONS(validArray(nums, N));
    }

    bool validArray(const vector<int>& nums, int N) {
        return nums.size() == N;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "6 2",
            "3 2 1 5 6 4"
        });
        Output({
            "5"
        });
    }

    void SampleTestCase2() {
        Input({
            "9 4",
            "3 2 3 1 2 4 5 5 6"
        });
        Output({
            "4"
        });
    }

    void BeforeTestCase() {
        nums.clear();
    }

    void TestCases() {
        CASE(N = 1, K = 1, nums = {1});
        CASE(N = 2, K = 1, nums = {1, 2});
        CASE(N = 2, K = 2, nums = {1, 2});
        CASE(N = 10, K = 5, nums = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1});

        for (int i = 0; i < 10; i++)
            CASE(N = 100, K = 50, nums = generateRandomArray(100));

        for (int i = 0; i < 10; i++)
            CASE(N = 1000, K = 500, nums = generateRandomArray(1000));

        for (int i = 0; i < 10; i++)
            CASE(N = 10000, K = 10000, nums = generateRandomArray(10000));
        
        for (int i = 0; i < 10; i++)
            CASE(N = 10000, K = 1, nums = generateRandomArray(10000));
    }

    vector<int> generateRandomArray(int size) {
        vector<int> arr(size);
        iota(arr.begin(), arr.end(), 1);
        shuffle(arr.begin(), arr.end(), default_random_engine(0));
        return arr;
    }
};
