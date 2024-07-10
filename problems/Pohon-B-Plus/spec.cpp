#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int DMIN = 3;
    const int DMAX = 10;
    const int NMAX = 1e5;
    const int VMAX = 1e9;

    int D, N, searchCount;
    vector<int> val, qval, qtype, ansc;
    vector<vector<int>> ansf;
    vector<string> anss, tree;

    void InputFormat() {
        LINE(D, N);
        LINES(qtype, qval) % SIZE(N);
    }

    void BeforeOutputFormat() {
        searchCount = 0;

        for (int i = 0; i < qtype.size(); i++) {
            if (qtype[i] == 2) searchCount++;
        }
    }

    void OutputFormat1() {
        LINES(anss, ansf) % SIZE(searchCount);
        LINES(tree);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(DMIN <= D <= DMAX);
        CONS(1 <= N <= NMAX);
        CONS(query_cons(qtype, qval));
    }

private:
    bool query_cons(vector<int>& op, vector<int>& val) {
        if (op.size() != N) return false;
        if (val.size() != N) return false;

        for (int i = 0; i < N; i++) {
            if (op[i] < 1 || op[i] > 2) return false;
            if (val[i] < 1 || val[i] > VMAX) return false;
        }

        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "3 13",
            "1 1",
            "1 13",
            "1 12",
            "1 11",
            "1 10",
            "1 9",
            "1 8",
            "1 7",
            "1 6",
            "1 5",
            "1 4",
            "2 11",
            "2 2"
        });
        Output({
            "YES 2 3 1",
            "NO 2 1 1",
            "RESULT:",
            "--1",
            "-4",
            "--4",
            "--5",
            "6",
            "--6",
            "--7",
            "-8",
            "--8",
            "--9",
            "10",
            "--10",
            "--11",
            "-12",
            "--12",
            "--13"
        });
    }

    void BeforeTestCase(){
        val.clear();
        qval.clear();
        qtype.clear();
        ansf.clear();
        anss.clear();
        tree.clear();
    }

    void TestCases() {
        for(int i = 0; i < 10; i++)
            CASE(
                D = 3, N = 10,
                qtype = random_array(N, 2),
                qval = query_array(qtype, 20)
            );
        for(int i = 0; i < 10; i++)
            CASE(
                D = 3, N = 100,
                qtype = random_array(N, 2),
                qval = query_array(qtype, 200)
            );
        for(int i = 0; i < 10; i++)
            // CASE(T = 100, random_data(T, 1000, data));
            CASE(
                D = 3, N = 1000,
                qtype = random_array(N, 2),
                qval = query_array(qtype, 2000)
            );
        for(int i = 0; i < 5; i++)
            // CASE(T = 1, random_data(T, 1e5, data));
            CASE(
                D = 3, N = NMAX,
                qtype = random_array(N, 1),
                qval = query_array(qtype, VMAX)
            );
        for(int i = 0; i < 5; i++)
            CASE(
                D = 5, N = NMAX,
                qtype = random_array(N, 2),
                qval = query_array(qtype, VMAX)
            );
        for(int i = 0; i < 10; i++)
            CASE(
                D = 10, N = NMAX,
                qtype = random_array(N, 2),
                qval = query_array(qtype, VMAX)
            );            
    }

private:
    vector<int> random_array(int n, int nmax){
        vector<int> val;

        for(int i = 0; i < n; i++){
            val.push_back(rnd.nextInt(1, nmax));
        }
        
        return val;
    }

    vector<int> query_array(vector<int> op, int nmax) {
        int n = op.size();

        vector<int> out, inserted;

        for(int i = 0; i < n; i++){
            if (op[i] == 1) {
                out.push_back(rnd.nextInt(1, nmax));
                inserted.push_back(out.back());
            } else {
                if (inserted.size() == 0) {
                    out.push_back(rnd.nextInt(1, nmax));
                } else {
                    int r = rnd.nextInt(1, 4);

                    if (r == 1) {
                        out.push_back(rnd.nextInt(1, nmax));
                    } else {
                        out.push_back(inserted[rnd.nextInt(0, inserted.size() - 1)]);
                    }
                }
            }
        }
        
        return out;
    }
};
