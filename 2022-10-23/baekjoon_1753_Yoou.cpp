// 백준 1753 최단경로
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define MAX_V 20001
#define INF 3000000
using namespace std;

vector<pair<int, int> >connected[MAX_V];
int shortest_dist[MAX_V];
int V, E, K;

void input(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> V >> E;
    cin >> K;
    int u, v, w;
    for(int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        connected[u].push_back(make_pair(v, w));
    }
    for(int i = 1; i <= V; i++)
        shortest_dist[i] = INF;
}

void dijkstra(void)
{
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq; // first : distance, second : node
    int curr, curr_w, temp, temp_w;
    pq.push(make_pair(0, K));
    shortest_dist[K] = 0;
    while (!pq.empty())
    {
        curr = pq.top().second;
        curr_w = pq.top().first;
        pq.pop();
        for(int i = 0; i < connected[curr].size(); i++)
        {
            temp = connected[curr][i].first;
            temp_w = connected[curr][i].second;
            if (shortest_dist[temp] > curr_w + temp_w)
            {
                shortest_dist[temp] = curr_w + temp_w;
                pq.push(make_pair(shortest_dist[temp], temp));
            }
        }
    }
}

void print_ans(void)
{
    for(int i = 1; i <= V; i++)
    {
        if (i == K)
            cout << 0;
        else if (shortest_dist[i] == INF)
            cout << "INF";
        else
            cout << shortest_dist[i];
        cout << "\n";
    }
}

int main(void)
{
    input();
    dijkstra();
    print_ans();
    return (0);
}