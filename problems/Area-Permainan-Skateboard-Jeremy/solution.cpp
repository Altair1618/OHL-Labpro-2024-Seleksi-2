#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (nodes[i] != -1) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != -1) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

using namespace std;

class Solution {
public:
    int maxi = 0;
    
    pair<int, int> dfs(TreeNode* root)
    {        
        if(root == NULL)
        {
            return {-1, -1};
        }
                
        pair<int, int> left = dfs(root -> left);
        pair<int, int> right = dfs(root -> right);
        int temp_max = max(1 + left.second, 1 + right.first);
        maxi = max(maxi, temp_max);
        return {left.second + 1, right.first + 1};
    }
    
    int longestZigZag(TreeNode* root) {
        dfs(root);
        return maxi;
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> nodes(N);
    for (int i = 0; i < N; ++i) {
        cin >> nodes[i];
    }

    TreeNode* root = buildTree(nodes);

    Solution sol;
    int result = sol.longestZigZag(root);
    cout << result << endl;

    return 0;
}
