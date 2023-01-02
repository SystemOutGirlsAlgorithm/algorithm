class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) return true;

        unordered_map<int, vector<int>> m;
        for (auto i: edges) {
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
        }

        queue<int> q;
        q.push(source);

        vector<bool> visited(n, false);
        visited[source] = true;

        while (!q.empty()) {
            int p = q.front();
            q.pop();
            visited[p] = true;
            if (p == destination) return true;
            for (auto i: m[p]) if (!visited[i]) q.push(i);
        }
        
        return false;
    }
};

// 라섹 수술 후 복귀했습니다~!