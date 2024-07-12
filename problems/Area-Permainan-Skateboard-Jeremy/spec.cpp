#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 5 * 10e4;

    int N;
    vector<int> nodes;
    int ans;

    void InputFormat() {
        LINE(N);
        LINE(nodes % SIZE(N));
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
        CONS(validNodes(nodes, N));
    }

    bool validNodes(const vector<int>& nodes, int N) {
        if (nodes.size() != N) return false;
        for (int node : nodes) {
            if (node < -1) return false;
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "15",
            "1 -1 1 1 1 -1 -1 1 1 -1 1 -1 -1 -1 1"
        });
        Output({
            "3"
        });
    }

    void SampleTestCase2() {
        Input({
            "11",
            "1 1 1 -1 1 -1 -1 1 1 -1 1"
        });
        Output({
            "4"
        });
    }

    void SampleTestCase3() {
        Input({
            "1",
            "1"
        });
        Output({
            "0"
        });
    }

    void SampleTestCase4() {
        Input({
            "2",
            "1 2"
        });
        Output({
            "1"
        });
    }

    void BeforeTestCase() {
        nodes.clear();
    }

    void TestCases() {
        CASE(N = 1, nodes = {1});
        CASE(N = 2, nodes = {1, 2});
        CASE(N = 3, nodes = {1, -1, 2});
        CASE(N = 7, nodes = {1, 2, 3, -1, 4, -1, -1});
        CASE(N = 15, nodes = generateCompleteBinaryTree(15));
        CASE(N = 31, nodes = generateCompleteBinaryTree(31));
        
        for (int i = 0; i < 10; ++i)
            CASE(N = 100, nodes = generateRandomBinaryTree(100));
        
        for (int i = 0; i < 10; ++i)
            CASE(N = 1000, nodes = generateRandomBinaryTree(1000));
        
        for (int i = 0; i < 10; ++i)
            CASE(N = 10000, nodes = generateRandomBinaryTree(10000));

        for (int i = 0; i < 10; ++i)
            CASE(N = 50000, nodes = generateRandomBinaryTree(50000));
    }

    vector<int> generateCompleteBinaryTree(int size) {
        vector<int> arr(size);
        for (int i = 0; i < size; ++i) {
            arr[i] = i + 1;
        }
        return arr;
    }

    vector<int> generateRandomBinaryTree(int size) {
        vector<int> arr(size);
        for (int i = 0; i < size; ++i) {
            arr[i] = (rand() % (size + 1)) - 1;
        }
        arr[0] = 1;
        return arr;
    }
};
