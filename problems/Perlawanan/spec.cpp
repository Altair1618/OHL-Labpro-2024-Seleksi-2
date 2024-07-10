#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int LENMAX = 1e5;

    string s, ans;

    void InputFormat() {
        LINE(s);
    }

    void OutputFormat1() {
        LINE(ans);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1 <= s.size() <= LENMAX);
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "abacaba"
        });
        Output({
            "No"
        });
    }

    void SampleTestCase2() {
        Input({
            "iiq"
        });
        Output({
            "Yes"
        });
    }

    void BeforeTestCase() {
        s.clear();
        ans.clear();
    }

    void TestCases() {
        for (int i = 0; i < 10; i++) {
            CASE(s = randomString(10, 3));
        }
        for (int i = 0; i < 10; i++) {
            CASE(s = randomString(100, 5));
        }
        for (int i = 0; i < 10; i++) {
            CASE(s = randomString(1000, 5));
        }
        for (int i = 0; i < 10; i++) {
            CASE(s = randomString(LENMAX, 26));
        }
        for (int i = 0; i < 10; i++) {
            CASE(s = randomString(rnd.nextInt(1, LENMAX), 26));
        }
        for (int i = 0; i < 10; i++) {
            CASE(s = randomString(rnd.nextInt(1, LENMAX), 3));
        }
    }

private:
    string randomString(int len, int max) {
        string ret = "";

        for (int i = 0; i < len; i++) {
            if (i > 0 && rnd.nextInt(1, 3) != 1) {
                ret += ret.back();
            } else {
                ret += (char) ('a' + rnd.nextInt(0, max - 1));
            }
        }

        return ret;
    }
};
