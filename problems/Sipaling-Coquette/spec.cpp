#include <tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

const int NMIN = 4, NMAX = 1e5, XYMIN = 0, XYMAX = 1e3;

class ProblemSpec : public BaseProblemSpec
{
protected:
    int n, ans, xTarget, yTarget;
    vector<vector<int>> points;

    void InputFormat()
    {
        LINE(n);
        GRID(points) % SIZE(n, 2);
        LINE(xTarget, yTarget);
    }

    void OutputFormat()
    {
        LINE(ans);
    }

    void GradingConfig()
    {
        TimeLimit(1);
        MemoryLimit(64);
    }

    void Constraints()
    {
        CONS(NMIN <= n && n <= NMAX);
        CONS(validatePoints());
        CONS(validatePoint(xTarget, yTarget));
    }

private:
    static bool validatePoint(int x, int y)
    {
        return XYMIN <= x && x <= XYMAX && XYMIN <= y && y <= XYMAX;
    }
    bool validatePoints()
    {
        for (auto &point : points)
        {
            if (!validatePoint(point[0], point[1]))
            {
                return false;
            }
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec>
{
protected:
    void SampleTestCase1()
    {
        Input({"8", "0 0", "0 1", "2 1", "2 0", "2 1", "0 2", "4 2", "4 0", "0 0"});
        Output({"3"});
    }

    void BeforeTestCase()
    {
        points.clear();
    }

    void TestCases()
    {
        for (int i = 0; i < 3; i++)
        {
            int currN = 100;
            auto currPoints = randomPoints(currN);
            CASE(n = currN, points = currPoints, xTarget = rnd.nextInt(XYMIN, XYMAX), yTarget = rnd.nextInt(XYMIN, XYMAX));
        }
        for (int i = 0; i < 10; i++)
        {
            int currN = 100;
            auto currPoints = randomPoints(currN);
            auto currTarget = currPoints[rnd.nextInt(0, currN - 1)];
            CASE(n = currN, points = currPoints, xTarget = currTarget[0], yTarget = currTarget[1]);
        }
        for (int i = 0; i < 20; i++)
        {
            int currN = rnd.nextInt(NMIN, NMAX);
            auto currPoints = randomPoints(currN);
            auto currTarget = currPoints[rnd.nextInt(0, currN - 1)];
            CASE(n = currN, points = currPoints, xTarget = currTarget[0], yTarget = currTarget[1]);
        }
        for (int i = 0; i < 50; i++)
        {
            int currN = NMAX;
            auto currPoints = randomPoints(currN);
            auto currTarget = currPoints[rnd.nextInt(0, currN - 1)];
            CASE(n = currN, points = currPoints, xTarget = currTarget[0], yTarget = currTarget[1]);
        }
    }

private:
    vector<vector<int>> randomPoints(int n)
    {
        vector<vector<int>> points;
        for (int i = 0; i < n; i++)
        {
            points.push_back({rnd.nextInt(XYMIN, XYMAX), rnd.nextInt(XYMIN, XYMAX)});
        }
        return points;
    }
};
