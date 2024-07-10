#include <tcframe/spec.hpp>
#include <bits/stdc++.h>
using namespace tcframe;
using namespace std;

class ProblemSpec : public BaseProblemSpec {
protected:
    const int NMAX = 1000;
    const int MMAX = 1000;

    int N, M;
    string ans;
    vector<string> mat;

    void InputFormat() {
        LINE(N, M);
        LINES(mat) % SIZE(N);
    }

    void OutputFormat1() {
        LINE(ans);
    }

    void GradingConfig() {
        TimeLimit(3);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1 <= N <= NMAX);
        CONS(1 <= M <= MMAX);
        CONS(matrix_cons(mat));
    }

private:
    bool matrix_cons(vector<string> &mat){
        if (mat.size() != N) return false;

        int s_found = 0, t_found = 0;
        for (int i = 0; i < N; i++) {
            if (mat[i].size() != M) return false;
            
            for (int j = 0; j < M; j++) {
                if (!valid_char(mat[i][j])) return false;
                if (mat[i][j] == 'S') s_found++;
                if (mat[i][j] == 'T') t_found++;
            }
        }

        if (s_found != 1 || t_found != 1) return false;
        return true;
    }

    bool valid_char(char c) {
        return c == '.' || c == '*' || c == 'S' || c == 'T';
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
            "5 5",
            "..S..",
            "****.",
            "T....",
            "****.",
            "....."
        });
        Output({
            "YES"
        });
    }

    void SampleTestCase2() {
        Input({
            "5 5",
            "S....",
            "****.",
            ".....",
            ".****",
            "..T.."
        });
        Output({
            "NO"
        });
    }

    void BeforeTestCase(){
        mat.clear();
    }

    void TestCases() {
        for (int i = 0; i < 5; i++)
            CASE(N = 5, M = 5, random_matrix(N, M, mat));
        for (int i = 0; i < 5; i++)
            CASE(N = 5, M = 5, yes_matrix(N, M, mat));
        for (int i = 0; i < 5; i++)
            CASE(N = 20, M = 20, random_matrix(N, M, mat));
        for (int i = 0; i < 5; i++)
            CASE(N = 20, M = 20, yes_matrix(N, M, mat));
        for (int i = 0; i < 5; i++)
            CASE(N = 50, M = 50, random_matrix(N, M, mat));
        for (int i = 0; i < 5; i++)
            CASE(N = 50, M = 50, yes_matrix(N, M, mat));
        for (int i = 0; i < 5; i++)
            CASE(N = 100, M = 100, random_matrix(N, M, mat));
        for (int i = 0; i < 5; i++)
            CASE(N = 100, M = 100, yes_matrix(N, M, mat));
        for (int i = 0; i < 5; i++)
            CASE(N = 500, M = 500, random_matrix(N, M, mat));
        for (int i = 0; i < 5; i++)
            CASE(N = 500, M = 500, yes_matrix(N, M, mat));
        for (int i = 0; i < 5; i++)
            CASE(N = 1000, M = 1000, random_matrix(N, M, mat));
        for (int i = 0; i < 5; i++)
            CASE(N = 1000, M = 1000, yes_matrix(N, M, mat));
    }

private:
    void random_matrix(int n, int m, vector<string>& mat){
        mat = vector<string>(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mat[i].push_back('X');
            }
        }

        int s_row = rnd.nextInt(0, N-1);
        int s_col = rnd.nextInt(0, M-1);
        int t_row = rnd.nextInt(0, N-1);
        int t_col = rnd.nextInt(0, M-1);

        mat[s_row][s_col] = 'S';
        mat[t_row][t_col] = 'T';

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (mat[i][j] != 'X') continue;

                int rand_val = rnd.nextInt(1, 10);
                
                if (rand_val < 3) mat[i][j] = '*';
                else mat[i][j] = '.';
            }
        }
    }

    void yes_matrix(int n, int m, vector<string>& mat){
        mat = vector<string>(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mat[i].push_back('X');
            }
        }

        int s_row = rnd.nextInt(0, N-1);
        int s_col = rnd.nextInt(0, M-1);
        int t_row = rnd.nextInt(0, N-1);
        int t_col = rnd.nextInt(0, M-1);

        mat[s_row][s_col] = 'S';
        mat[t_row][t_col] = 'T';

        int start_row, start_col, end_row, end_col;
        if (s_row < t_row) {
            start_row = s_row;
            start_col = s_col;
            end_row = t_row;
            end_col = t_col;
        } else {
            start_row = t_row;
            start_col = t_col;
            end_row = s_row;
            end_col = s_col;
        }

        for (int i = start_row; i <= end_row; i++) {
            if (mat[i][start_col] == 'X') mat[i][start_col] = '.';
        }

        for (int i = start_col; i < end_col; i++) {
            if (mat[end_row][i] == 'X') mat[end_row][i] = '.';
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (mat[i][j] != 'X') continue;

                int rand_val = rnd.nextInt(1, 10);
                
                if (rand_val < 3) mat[i][j] = '*';
                else mat[i][j] = '.';
            }
        }
    }
};
