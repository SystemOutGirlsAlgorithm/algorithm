#include <iostream>
#include <vector>
using namespace std;

int T, N, K, W;
int D[1001];
vector<int> order[1001];    // [도착] -> { 출발, .. }, (출발)->(도착) => [도착].size() == 0 : 루트(초기) 노드.
int order_cost[1001];

int Order_cost(int node) {
    //printf("Order_cost(%d)\n", node);
    if (order[node].size() == 0) {
        //printf("\tsize 0 : [%d]\n", node);
        return order_cost[node] = D[node];
    }

    if (order_cost[node] != -1) {
        //printf("\torder_cost[%d]", node);
        return order_cost[node];
    }

    int Cost = D[node];
    for (int i = 0; i < order[node].size(); i++) {
        Cost = max(Order_cost(order[node][i]) + D[node], Cost);
        //printf("\t%dnode Cost : %d\n",node, Cost);
    }
    return order_cost[node] = Cost;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> K;
        // order_cost, order, 초기화
        for (int i = 1; i <= N; i++) {
            order_cost[i] = -1;
            order[i].clear();
        }
        for (int i = 1; i <= N; i++) {
            cin >> D[i];
        }
        int a, b;
        for (int i = 0; i < K; i++) {
            cin >> a >> b;
            order[b].push_back(a);
        }
        cin >> W;
        cout << Order_cost(W) << "\n";
    }

    return 0;
}