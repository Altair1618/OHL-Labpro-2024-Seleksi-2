#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 1e5;
    const int KMAX = 1e9;

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
        CONS(1 <= N && N <= NMAX);
        CONS(1 <= K && K <= KMAX);
        CONS(validArray(nums, N));
    }

    bool validArray(const vector<int>& nums, int n) {
        if (nums.size() != n) return false;
        for (int num : nums) {
            if (num < 1 || num > KMAX) return false;
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "5 5",
            "1 2 3 4 3"
        });
        Output({
            "2"
        });
    }

    void SampleTestCase2() {
        Input({
            "4 2",
            "1 1 1 1"
        });
        Output({
            "2"
        });
    }

    void SampleTestCase3() {
        Input({
            "4 5",
            "1 2 3 4"
        });
        Output({
            "2"
        });
    }

    void SampleTestCase4() {
        Input({
            "5 6",
            "3 1 3 4 3"
        });
        Output({
            "1"
        });
    }

    void BeforeTestCase() {
        nums.clear();
    }

    void TestCases() {
        CASE(N = 1, K = 1, nums = {1});
        CASE(N = 2, K = 2, nums = {1, 1});

        for (int i = 0; i < 10; i++)
            CASE(N = 10, K = 10, nums = generateRandomArray(10, 1, 10));

        for (int i = 0; i < 10; i++)
            CASE(N = 100, K = 50, nums = generateRandomArray(100, 1, 50));

        for (int i = 0; i < 10; i++)
            CASE(N = 1000, K = 500, nums = generateRandomArray(1000, 1, 500));
        
        for (int i = 0; i < 10; i++)
            CASE(N = 10000, K = KMAX, nums = generateRandomArray(10000, 1, KMAX));
        
        for (int i = 0; i < 10; i++)
            CASE(N = 100000, K = KMAX, nums = generateRandomArray(100000, 1, KMAX));
    }

    vector<int> generateRandomArray(int size, int minValue, int maxValue) {
        vector<int> arr(size);
        for (int i = 0; i < size; ++i) {
            arr[i] = rand() % (maxValue - minValue + 1) + minValue;
        }
        return arr;
    }
};
