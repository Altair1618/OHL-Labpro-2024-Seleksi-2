#include <tcframe/spec.hpp>
#include <string>
using namespace tcframe;
using namespace std;

const int MNMIN = 1, MNMAX = 100;

class ProblemSpec : public BaseProblemSpec
{
protected:
    int m, n;
    int newM, newN;
    string custom;

    void InputFormat()
    {
        LINE(m, n);
    }

    void OutputFormat()
    {
        LINE(newM, newN);
        LINE(custom);
    }

    void GradingConfig()
    {
        TimeLimit(1);
        MemoryLimit(64);
    }

    void Constraints()
    {
        CONS(MNMIN <= m && m <= MNMAX);
        CONS(MNMIN <= n && n <= MNMAX);
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec>
{
protected:
    void SampleTestCase1()
    {
        Input({"1 2"});
        Output({"-1 -4", "Wrapper"});
    }

    void TestCases()
    {
        for (int i = 0; i <= 10; i++)
            CASE(m = rnd.nextInt(1, 100), n = rnd.nextInt(1, 100));
    }
};
