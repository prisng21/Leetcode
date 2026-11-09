
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {

        int n = board.size();
        int target = n * n;

        queue<pair<int, int>> q;
        vector<bool> vis(target + 1, false);

        q.push({1, 0});
        vis[1] = true;

        while (!q.empty()) {

            int curr = q.front().first;
            int moves = q.front().second;
            q.pop();

            if (curr == target)
                return moves;

            for (int next = curr + 1; next <= min(curr + 6, target); next++) {

                int r = n - 1 - (next - 1) / n;
                int c = (next - 1) % n;

                if ((n - 1 - r) % 2 == 1)
                    c = n - 1 - c;

                int dest = next;

                if (board[r][c] != -1)
                    dest = board[r][c];

                if (!vis[dest]) {
                    vis[dest] = true;
                    q.push({dest, moves + 1});
                }
            }
        }

        return -1;
    }
};
