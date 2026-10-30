
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges,
                string labels, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
        }

        const long long INF = 1e18;

        vector<vector<long long>> dist(
            n, vector<long long>(k + 1, INF)
        );

        using T = tuple<long long, int, int>;

        priority_queue<T, vector<T>, greater<T>> pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while(!pq.empty()) {
            auto [cost, u, cnt] = pq.top();
            pq.pop();

            if(cost > dist[u][cnt])
                continue;

            if(u == n - 1)
                return (int)cost;

            for(auto [v, w] : adj[u]) {

                int newCnt;

                if(labels[u] == labels[v])
                    newCnt = cnt + 1;
                else
                    newCnt = 1;

                if(newCnt > k)
                    continue;

                long long newCost = cost + w;

                if(newCost < dist[v][newCnt]) {
                    dist[v][newCnt] = newCost;
                    pq.push({newCost, v, newCnt});
                }
            }
        }

        return -1;
    }
};
