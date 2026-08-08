class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (i == j) {
                    dist[i][j] = 0;
                }
            }
        }

        for (auto e : edges) {
            int i = e[0];
            int j = e[1];
            int w = e[2];

            dist[i][j] = w;
            dist[j][i] = w;
        }

        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {

                    if (dist[i][via] != INT_MAX && dist[via][j] != INT_MAX) {
                        dist[i][j] =
                            min(dist[i][j], dist[i][via] + dist[via][j]);
                    }
                }
            }
        }

        int ansCity = -1;
        int totalCity = n;

        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {

                if (dist[i][j] <= distanceThreshold) {
                    count++;
                }
            }

            if (count <= totalCity) {
                ansCity = i;
                totalCity = count;
            }
        }

        return ansCity;
    }
};