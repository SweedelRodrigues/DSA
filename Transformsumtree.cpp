#include <iostream>
#include <vector>
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

    Node *root = new Node(preorder[idx]);

    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

void preorderTraversal(Node *root)
{
    if(root == NULL)
        return;

    cout << root->data << " ";

    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int sumTree(Node *root)
{
    if(root == NULL)
        return 0;

    int leftsum = sumTree(root->left);
    int rightsum = sumTree(root->right);

    root->data += leftsum + rightsum;

    return root->data;
}

int main()
{
    vector<int> preorder =
    {
        1,2,-1,-1,3,4,-1,-1,5,-1,-1
    };

    Node *root = buildTree(preorder);

    cout << "Preorder before conversion: ";
    preorderTraversal(root);

    sumTree(root);

    cout << "\nPreorder after conversion: ";
    preorderTraversal(root);

    return 0;
}