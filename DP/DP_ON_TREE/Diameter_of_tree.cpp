#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node *insert_Node(Node *root, int val, int i)
{
    if (root == nullptr)
    {
        return new Node(val);
    }

    if (i % 2 != 0)
    {
        root->left = insert_Node(root->left, val, i);
    }
    else
    {
        root->right = insert_Node(root->right, val, i);
    }
    return root;
}
void preorder(struct Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";

    inorder(root->right);
}

int diameter(Node *root, int res)
{
    if (root == nullptr)
        return 0;

    int l = diameter(root->left, res);
    int r = diameter(root->right, res);

    int temp = 1 + max(l, r);

    int ans = max(temp, 1 + l + r);

    res = max(res, ans);
    return res;
}
int max_path_sum(Node *root, int res)
{
    if (root == nullptr)
    {
        return 0;
    }

    int l = max_path_sum(root->left, res);
    int r = max_path_sum(root->right, res);

    int temp = max(max(l, r) + root->data, root->data);
    int ans = max(l + r + root->data, temp);
    res = max(ans, temp);

    return res;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *root = nullptr;
    int n = arr.size();
    // for (int i = 0; i < n; i++)
    // {
    //    root = insert_Node(root,arr[i],i);
    // }
    root = new Node(arr[0]);
    root->left = new Node(arr[1]);
    root->right = new Node(arr[2]);
    root->left->left = new Node(arr[3]);
    root->left->right = new Node(arr[4]);

    // preorder(root);
    // cout << endl;
    // int inorder[] = {4, 2, 1, 5, 3};
    // int preorder[] = {1, 2, 4, 3, 5};
    // cout << diameter(root, 0);

    cout<<max_path_sum(root,0);
}
