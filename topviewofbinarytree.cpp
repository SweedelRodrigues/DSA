#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

// Node Structure
class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Build Tree using Preorder
int idx = -1;

Node* buildTree(vector<int> &preorder)
{
    idx++;

    if(preorder[idx] == -1)
        return NULL;

    Node* root = new Node(preorder[idx]);

    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

// Top View
vector<int> topView(Node* root)
{
    vector<int> ans;

    if(root == NULL)
        return ans;

    map<int,int> m;
    queue<pair<Node*,int>> q;

    q.push({root,0});

    while(!q.empty())
    {
        Node* curr = q.front().first;
        int hd = q.front().second;
        q.pop();

        // Store first node of each horizontal distance
        if(m.find(hd) == m.end())
        {
            m[hd] = curr->data;
        }

        if(curr->left)
        {
            q.push({curr->left, hd-1});
        }

        if(curr->right)
        {
            q.push({curr->right, hd+1});
        }
    }

    for(auto it : m)
    {
        ans.push_back(it.second);
    }

    return ans;
}

int main()
{
    // Preorder Representation
    //          1
    //        /   \
    //       2     3
    //        \   / \
    //         4 5   6

    vector<int> preorder =
    {
        1,
        2,-1,4,-1,-1,
        3,5,-1,-1,6,-1,-1
    };

    Node* root = buildTree(preorder);

    vector<int> ans = topView(root);

    cout << "Top View : ";

    for(int x : ans)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}