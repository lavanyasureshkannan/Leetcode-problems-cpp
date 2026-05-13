class Solution {
public:

    struct TrieNode {
        TrieNode* child[26] = {};
        string word = "";
    };

    TrieNode* root = new TrieNode();

    void insert(string &word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->child[idx])
                node->child[idx] = new TrieNode();
            node = node->child[idx];
        }
        node->word = word;
    }

    void dfs(int i, int j,
             vector<vector<char>>& board,
             TrieNode* node,
             vector<string>& res) {

        char c = board[i][j];

        if (c == '#' || !node->child[c - 'a']) return;

        node = node->child[c - 'a'];

        if (node->word != "") {
            res.push_back(node->word);
            node->word = ""; // avoid duplicates
        }

        board[i][j] = '#';

        int n = board.size();
        int m = board[0].size();

        // 🔥 4 explicit DFS calls (your style)
        
        if (i + 1 < n)
            dfs(i + 1, j, board, node, res);

        if (i - 1 >= 0)
            dfs(i - 1, j, board, node, res);

        if (j + 1 < m)
            dfs(i, j + 1, board, node, res);

        if (j - 1 >= 0)
            dfs(i, j - 1, board, node, res);

        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        for (auto &w : words)
            insert(w);

        vector<string> res;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(i, j, board, root, res);
            }
        }

        return res;
    }
};