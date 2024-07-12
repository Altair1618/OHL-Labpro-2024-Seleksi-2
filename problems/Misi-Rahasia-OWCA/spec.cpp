#include <tcframe/spec.hpp>
#include <vector>
using namespace tcframe;
using namespace std;

const int VMIN = 3, VMAX = 1e5, EMIN = 0, EMAX = 1e5, WMIN = 1, WMAX = 1e5;

class ProblemSpec : public BaseProblemSpec
{
private:
    bool validateNode(int node)
    {
        return 0 <= node && node <= v - 1;
    }

    bool validateEdge()
    {
        for (auto &edge : edges)
        {
            if (edge[0] < 0 || edge[0] >= v || edge[1] < 0 || edge[1] >= v || edge[2] < WMIN || edge[2] > WMAX || edge[0] == edge[1])
            {
                return false;
            }
        }
        return true;
    }

protected:
    int v,
        e,
        ans,
        vAlpha,
        vSigma,
        vD;

    vector<vector<int>> edges;

    void InputFormat()
    {
        LINE(v, e);
        GRID(edges) % SIZE(e, 3);
        LINE(vAlpha, vSigma, vD);
    }

    void OutputFormat()
    {
        LINE(ans);
    }

    void GradingConfig()
    {
        TimeLimit(1);
        MemoryLimit(256);
    }

    void Constraints()
    {
        CONS(VMIN <= v && v <= VMAX);
        CONS(EMIN <= e && e <= EMAX);
        CONS(validateNode(vAlpha) && validateNode(vSigma) && validateNode(vD) && vAlpha != vSigma && vAlpha != vD && vSigma != vD);
        CONS(validateEdge());
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec>
{
protected:
    void SampleTestCase1()
    {
        Input({"6 9",
               "0 2 2",
               "0 5 6",
               "1 0 3",
               "1 4 5",
               "2 1 1",
               "2 3 3",
               "2 3 4",
               "3 4 2",
               "4 5 1",
               "0 1 5"});
        Output({"9"});
    }

    void SampleTestCase2()
    {
        Input({
            "3 2",
            "0 1 2",
            "2 1 1",
            "0 1 2",
        });
        Output({"-1"});
    }

    void BeforeTestCase()
    {
        edges.clear();
    }

    void TestCases()
    {
        for (int i = 0; i < 10; i++)
        {
            int currV = 10;
            vector<int> markas = randomMarkas(currV);
            CASE(v = currV, e = rnd.nextInt(EMIN, EMAX), edges = randomEdges(v, e), vAlpha = markas[0], vSigma = markas[1], vD = markas[2]);
        }
        for (int i = 0; i < 10; i++)
        {
            int currV = 20;
            vector<int> markas = randomMarkas(currV);
            CASE(v = currV, e = rnd.nextInt(EMIN, EMAX), edges = randomEdges(v, e), vAlpha = markas[0], vSigma = markas[1], vD = markas[2]);
        }
        for (int i = 0; i < 10; i++)
        {
            int currV = rnd.nextInt(VMIN, VMAX);
            vector<int> markas = randomMarkas(currV);
            CASE(v = currV, e = rnd.nextInt(EMIN, EMAX), edges = randomEdges(v, e), vAlpha = markas[0], vSigma = markas[1], vD = markas[2]);
        }
        for (int i = 0; i < 10; i++)
        {
            int currV = VMAX;
            vector<int> markas = randomMarkas(currV);
            CASE(v = currV, e = rnd.nextInt(EMIN, EMAX), edges = randomEdges(v, e), vAlpha = markas[0], vSigma = markas[1], vD = markas[2]);
        }
    }

private:
    vector<vector<int>> randomEdges(int v, int e)
    {
        vector<vector<int>> edges;
        for (int i = 0; i < e; i++)
        {
            int from = rnd.nextInt(0, v - 1);
            int to = rnd.nextInt(0, v - 1);
            while (from == to)
            {
                to = rnd.nextInt(0, v - 1);
            }
            int weight = rnd.nextInt(WMIN, WMAX);
            edges.push_back({from, to, weight});
        }
        return edges;
    }

    vector<int> randomMarkas(int v)
    {
        vector<int> markas(3);
        markas[0] = rnd.nextInt(0, v - 1);
        markas[1] = rnd.nextInt(0, v - 1);
        while (markas[0] == markas[1])
        {
            markas[1] = rnd.nextInt(0, v - 1);
        }
        markas[2] = rnd.nextInt(0, v - 1);
        while (markas[0] == markas[2] || markas[1] == markas[2])
        {
            markas[2] = rnd.nextInt(0, v - 1);
        }
        return markas;
    }
};
