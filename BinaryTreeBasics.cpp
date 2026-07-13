#include <iostream>
#include <vector>
#include <queue>
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

static int idx = -1;

// Build Binary Tree
Node* buildTree(vector<int> preorder)
{
    idx++;

    if(preorder[idx] == -1)
        return NULL;

    Node* root = new Node(preorder[idx]);

    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

// Preorder Traversal
void preorder(Node* root)
{
    if(root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Inorder Traversal
void inorder(Node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Postorder Traversal
void postorder(Node* root)
{
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Level Order Traversal (Level Wise)
void levelOrder(Node* root)
{
    if(root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        int n = q.size();

        while(n--)
        {
            Node* curr = q.front();
            q.pop();

            cout << curr->data << " ";

            if(curr->left)
                q.push(curr->left);

            if(curr->right)
                q.push(curr->right);
        }

        cout << endl;
    }
}

int main()
{
    vector<int> preorderTree =
    {
        1,2,-1,-1,3,4,-1,-1,5,-1,-1
    };

    Node* root = buildTree(preorderTree);

    cout << "Preorder : ";
    preorder(root);

    cout << "\nInorder : ";
    inorder(root);

    cout << "\nPostorder : ";
    postorder(root);

    cout << "\n\nLevel Order :" << endl;
    levelOrder(root);

    return 0;
}