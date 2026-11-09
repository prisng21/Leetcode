
class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {

        int n = graph.size();

        const int DRAW = 0;
        const int MOUSE = 1;
        const int CAT = 2;

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n, vector<int>(2, DRAW))
        );

        vector<vector<vector<int>>> degree(
            n, vector<vector<int>>(n, vector<int>(2, 0))
        );

        queue<vector<int>> q;

        // Calculate degrees
        for (int m = 0; m < n; m++) {
            for (int c = 0; c < n; c++) {

                degree[m][c][0] = graph[m].size();

                for (int next : graph[c]) {
                    if (next != 0) {
                        degree[m][c][1]++;
                    }
                }
            }
        }

        // Initialize terminal states
        for (int i = 0; i < n; i++) {

            for (int turn = 0; turn < 2; turn++) {

                // Mouse reaches hole
                dp[0][i][turn] = MOUSE;
                q.push({0, i, turn});

                // Cat catches mouse
                if (i != 0) {
                    dp[i][i][turn] = CAT;
                    q.push({i, i, turn});
                }
            }
        }

        // BFS
        while (!q.empty()) {

            auto state = q.front();
            q.pop();

            int m = state[0];
            int c = state[1];
            int turn = state[2];

            int result = dp[m][c][turn];

            if (turn == 0) {

                // Previous move was made by CAT
                for (int prevCat : graph[c]) {

                    if (prevCat == 0)
                        continue;

                    int pm = m;
                    int pc = prevCat;
                    int pt = 1;

                    if (dp[pm][pc][pt] != DRAW)
                        continue;

                    if (result == CAT) {

                        dp[pm][pc][pt] = CAT;
                        q.push({pm, pc, pt});

                    } else {

                        degree[pm][pc][pt]--;

                        if (degree[pm][pc][pt] == 0) {
                            dp[pm][pc][pt] = MOUSE;
                            q.push({pm, pc, pt});
                        }
                    }
                }

            } else {

                // Previous move was made by MOUSE
                for (int prevMouse : graph[m]) {

                    int pm = prevMouse;
                    int pc = c;
                    int pt = 0;

                    if (dp[pm][pc][pt] != DRAW)
                        continue;

                    if (result == MOUSE) {

                        dp[pm][pc][pt] = MOUSE;
                        q.push({pm, pc, pt});

                    } else {

                        degree[pm][pc][pt]--;

                        if (degree[pm][pc][pt] == 0) {
                            dp[pm][pc][pt] = CAT;
                            q.push({pm, pc, pt});
                        }
                    }
                }
            }
        }

        return dp[1][2][0];
    }
};
