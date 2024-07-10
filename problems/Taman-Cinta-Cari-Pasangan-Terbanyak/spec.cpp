#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 10e5;
    const int KMAX = 10e9;

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
        CONS(validArray(nums, n));
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
        CASE(n = 1, k = 1, nums = {1});
        CASE(n = 2, k = 2, nums = {1, 1});
        CASE(n = 10, k = 10, nums = generateRandomArray(10, 1, 10));
        CASE(n = 100, k = 50, nums = generateRandomArray(100, 1, 50));
        CASE(n = 1000, k = 500, nums = generateRandomArray(1000, 1, 500));
        CASE(n = 10000, k = 1000, nums = generateRandomArray(10000, 1, 1000));
        CASE(n = 100000, k = 100000, nums = generateRandomArray(100000, 1, 100000));
    }

    vector<int> generateRandomArray(int size, int minValue, int maxValue) {
        vector<int> arr(size);
        for (int i = 0; i < size; ++i) {
            arr[i] = rand() % (maxValue - minValue + 1) + minValue;
        }
        return arr;
    }
};
