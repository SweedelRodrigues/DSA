queue<TreeNode*> q;
q.push(root);

while(!q.empty())
{
    int n = q.size();      // Number of nodes in current level

    vector<int> level;

    while(n--)
    {
        TreeNode* curr = q.front();
        q.pop();

        // Process current node

        if(curr->left)
            q.push(curr->left);

        if(curr->right)
            q.push(curr->right);
    }

    // Store current level
}
