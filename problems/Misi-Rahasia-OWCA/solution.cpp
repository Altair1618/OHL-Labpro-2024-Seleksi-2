#include <utility>
#include <vector>
#include <climits>
#include <queue>
#include <iostream>
using namespace std;

typedef pair<long, long> longpair;
typedef vector<vector<longpair>> graph;

void dijkstra(graph &g, int src, vector<long> &dist)
{
    priority_queue<longpair, vector<longpair>, greater<longpair>> pq;

    pq.emplace(0, src);
    dist[src] = 0;

    int ctr = 0;

    while (ctr < g.size() && !pq.empty())
    {
        auto curr = pq.top();
        pq.pop();

        auto node = curr.second;

        ctr++;

        for (longpair &neighbor : g[node])
        {
            auto neighborNode = neighbor.first, neighborWeight = neighbor.second;
            auto nextWeight = dist[node] + neighborWeight;

            if (nextWeight < dist[neighborNode])
            {
                dist[neighborNode] = nextWeight;
                pq.emplace(dist[neighborNode], neighborNode);
            }
        }
    }
}

long long minimumWeight(graph &normal, graph &reversed, int src1, int src2, int dest)
{
    int n = normal.size();

    vector<long> distSrc1(n, LONG_MAX), distSrc2(n, LONG_MAX), distDest(n, LONG_MAX);

    dijkstra(normal, src1, distSrc1);
    dijkstra(normal, src2, distSrc2);
    dijkstra(reversed, dest, distDest);

    long minWeight = LONG_MAX;

    for (int i = 0; i < n; i++)
    {
        if (distSrc1[i] != LONG_MAX && distSrc2[i] != LONG_MAX && distDest[i] != LONG_MAX)
        {
            auto totalWeight = distSrc1[i] + distSrc2[i] + distDest[i];
            if (totalWeight < minWeight)
            {
                minWeight = totalWeight;
            }
        }
    }

    if (minWeight == LONG_MAX)
    {
        return -1;
    }

    return minWeight;
}

int main()
{
    int v, e;
    cin >> v >> e;

    vector<vector<longpair>> normal(v), reversed(v);

    for (int i = 0; i < e; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;

        normal[from].emplace_back(to, weight);
        reversed[to].emplace_back(from, weight);
    }

    int src1, src2, dest;
    cin >> src1 >> src2 >> dest;

    cout << minimumWeight(normal, reversed, src1, src2, dest) << endl;
}
