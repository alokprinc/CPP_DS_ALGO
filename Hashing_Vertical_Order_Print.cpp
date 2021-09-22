#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;

    Node(int value)
    {
        key = value;
        left = NULL;
        right = NULL;
    }
};

Node *insertLevelOrder(int arr[], Node *root, int i, int n)
{
    if (i < n)
    {
        Node *temp = new Node(arr[i]);
        root = temp;

        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}
void getVerticalOrder(Node *root, map < int, vector<int>> &m, int hdis)
{
    if(root == NULL){
        return;
    }

    getVerticalOrder(root->left,m,hdis-1);
    
    getVerticalOrder(root->right,m,hdis+1);


}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 6, 6, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = insertLevelOrder(arr, root, 0, n);
    // inOrder(root);
    //  cout<<endl;
    map<int, vector<int>> m;
    int hdis = 0;
    getVerticalOrder(root, m, hdis);
   
    map<int,vector<int>> :: iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        // cout<<it->first<<" -> "<<endl;

       for (int i = 0; i < (it->second).size(); i++)
       {
           cout<<(it->second)[i]<<" ";
       }
       cout<<endl;
        
    }
    
}