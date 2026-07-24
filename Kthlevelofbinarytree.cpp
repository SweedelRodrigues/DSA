#include <iostream>
#include <vector>

using namespace std;

// Node class
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

// Print Kth Level
void kthLevel(Node* root, int k)
{
    if(root == NULL)
        return;

    if(k == 1)
    {
        cout << root->data << " ";
        return;
    }

    kthLevel(root->left, k - 1);
    kthLevel(root->right, k - 1);
}

int main()
{
    // Tree:
    //         1
    //       /   \
    //      2     3
    //     /     / \
    //    7     4   5

    vector<int> preorder =
    {
        1,
        2,
        7,-1,-1,
        -1,
        3,
        4,-1,-1,
        5,-1,-1
    };

    Node* root = buildTree(preorder);

    int k;

    cout << "Enter K: ";
    cin >> k;

    cout << "Nodes at Level " << k << " : ";

    kthLevel(root, k);

    cout << endl;

    return 0;
}