#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

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

vector<int> bottomView(Node *root)
{
    vector<int> ans;

    if(root == NULL)
        return ans;

    map<int,int> mp;
    queue<pair<Node*,int>> q;

    q.push({root,0});

    while(!q.empty())
    {
        Node* curr = q.front().first;
        int hd = q.front().second;
        q.pop();

        // Store the latest node at each HD
        mp[hd] = curr->data;

        if(curr->left)
            q.push({curr->left,hd-1});

        if(curr->right)
            q.push({curr->right,hd+1});
    }

    for(auto it:mp)
        ans.push_back(it.second);

    return ans;
}

int main()
{
    vector<int> preorder =
    {
        1,
        2,-1,4,-1,-1,
        3,5,-1,-1,6,-1,-1
    };

    Node* root = buildTree(preorder);

    vector<int> ans = bottomView(root);

    cout<<"Bottom View : ";

    for(int x:ans)
        cout<<x<<" ";

    cout<<endl;
}