
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges,
                     string labels, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for (auto &it : edges) {
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back({v, w});
        }

        if (k == 0) return -1;

        // dist[node][streak]
        vector<vector<long long>> dist(
            n, vector<long long>(k + 1, LLONG_MAX)
        );

        // {distance, node, streak}
        priority_queue<
            tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>
        > pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {

            auto [wt, node, streak] = pq.top();
            pq.pop();

            if (wt != dist[node][streak])
                continue;

            if (node == n - 1)
                return wt;

            for (auto [v, w] : adj[node]) {

                int newStreak;

                if (labels[node] == labels[v])
                    newStreak = streak + 1;
                else
                    newStreak = 1;

                if (newStreak > k)
                    continue;

                long long newWt = wt + w;

                if (newWt < dist[v][newStreak]) {

                    dist[v][newStreak] = newWt;

                    pq.push({
                        newWt,
                        v,
                        newStreak
                    });
                }
            }
        }

        return -1;
    }
};
