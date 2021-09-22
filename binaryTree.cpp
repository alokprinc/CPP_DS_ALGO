#include <iostream>
#include <queue>
#include<climits>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};
void preOrder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}


void inOrder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int search(int inorder[], int start, int end, int curr)
{
    for (int i = start; i < end; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }
}

// make tree from given preorder and inorder //

// steps to solve

// pick element from preorder and create anode
// increment preorder index
// search for picked element's position in inorder
// call to build left subtree from inorder's position -1
// call to build reght subtree from inorder position +1 to n
// return node

Node *build_tree_pre_to_in(int preorder[], int inorder[], int start, int end)
{
    static int idx;
    if (start > end)
    {
        return NULL;
    }

    int curr = preorder[idx];
    idx++;
    Node *node = new Node(curr);
    if (start == end)
    {
        return node;
    }

    int pos = search(inorder, start, end, curr);
    node->left = build_tree_pre_to_in(preorder, inorder, start, pos - 1);
    node->right = build_tree_pre_to_in(preorder, inorder, pos + 1, end);
    return node;
}

// make tree from given preorder and inorder //

// start from the end of postorder and pick an element to create a Node
// decrement postorer index
// search fron picked element's pos in in order
// call to build right subtree from inorder's pos+1 to n
// call to bulid left subtree from inorder 0 to pos - 1
// return node

Node *build_tree_post_to_in(int postorder[], int inorder[], int start, int end)
{
    static int idx = 4;
    if (start > end)
    {
        return NULL;
    }

    int curr = postorder[idx];
    idx--;
    Node *node = new Node(curr);
    if (start == end)
    {
        return node;
    }

    int pos = search(inorder, start, end, curr);
    node->right = build_tree_post_to_in(postorder, inorder, pos + 1, end);
    node->left = build_tree_post_to_in(postorder, inorder, start, pos - 1);
    return node;
}

// printing level order traversal

void printlevelOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            cout << node->data << " ";
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
}

//  sumAtK
int sumAtK(Node *root, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    int sum = 0;

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        if (node != NULL)
        {
            if (level == k)
            {
                sum += node->data;
            }
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
            level++;
        }
    }
    return sum;
}

// count nodes

int countNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int count = countNodes(root->left) + countNodes(root->right) + 1;
    return count;
}
// sum of nodes

int sumOfNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int sum = sumOfNodes(root->left) + sumOfNodes(root->right) + root->data;
    return sum;
}

// heigth of nodes  O(n)  n is number  of nodes

int Height(Node *root)
{

    if (root == NULL)
    {
        return 0;
    }

    int lheight = Height(root->left);
    int rheight = Height(root->right);
    int theight = max(lheight, rheight) + 1;
    return theight;
}
///   diameter calculation O(n*2)
int Diameter(Node *root)
{

    if (root == NULL)
    {
        return 0;
    }
    int lhieght = Height(root->left);
    int rheight = Height(root->right);

    int currDia = lhieght + rheight + 1;

    int lDia = Diameter(root->left);
    int rDia = Diameter(root->right);

    int tDia = max(currDia, max(lDia, rDia));
}
//  Diameter calculation Optimised way O(n)

int DiameterOpt(Node *root, int *height)
{

    if (root == NULL)
    {
        *height = 0;
        return 0;
    }

    int lh = 0, rh = 0;
    int lDia = DiameterOpt(root->left, &lh);
    int rDia = DiameterOpt(root->right, &rh);
    int currDia = lh + rh + 1;

    *height = max(lh, rh) + 1;

    return max(currDia, max(lDia, rDia));
}
// sum replace function O(n) //

void sumReplace(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    sumReplace(root->left);
    sumReplace(root->right);

    if (root->left != NULL)
    {
        root->data += root->left->data;
    }
    if (root->right != NULL)
    {
        root->data += root->right->data;
    }
}

// Balanced Height tree O(n*2)

bool balancedHeight(Node *root)
{

    if (root == NULL)
    {
        return true;
    }

    if (balancedHeight(root->left) == false)
    {
        return false;
    }
    if (balancedHeight(root->right) == false)
    {
        return false;
    }

    int lh = Height(root->left);
    int rh = Height(root->right);

    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Balanced Height tree optimised way O(n) //

bool balancedHeightOpt(Node *root, int *height)
{
    if (root == NULL)
    {
        return true;
    }
    int lh = 0, rh = 0;
    if (balancedHeightOpt(root->left, &lh) == false)
    {
        return false;
    }
    if (balancedHeightOpt(root->right, &rh) == false)
    {
        return false;
    }

    *height = max(lh, rh) + 1;

    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// right view tree O(n) //
void rightView(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size(); // represents node in that level
        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();

            if (i == n - 1)
            {
                cout << curr->data << " ";
            }
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
}

// left view  O(n)  //

void leftView(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();

        for (int i = 1; i <= n; i++)
        {
            Node *curr = q.front();
            q.pop();

            if (i == 1)
            {
                cout << curr->data << " ";
            }
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
}

// Lowest common ancestor

Node *LCA(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node *left = LCA(root->left, n1, n2);
    Node *right = LCA(root->right, n1, n2);

    if (left != NULL && right != NULL)
    {
        return root;
    }
    if (left == NULL && right == NULL)
    {
        return NULL;
    }

    if (left != NULL)
    {
        return LCA(root->left, n1, n2);
    }

    return LCA(root->right, n1, n2);
}

// distance of a node from LCA

int dist(Node *root, int k, int distance)
{
    if (root == NULL)
    {
        return -1;
    }

    if (root->data == k)
    {
        return distance;
    }

    int left = dist(root->left, k, distance + 1);
    if (left != -1)
    {
        return left;
    }
    int right = dist(root->right, k, distance + 1);
    return right;
}

// distance between two nodes //

int distanceBetweenNodes(Node *root, int n1, int n2)
{
    Node *lca = LCA(root, n1, n2);

    int d1 = dist(lca, n1, 0);
    int d2 = dist(lca, n2, 0);

    return d1 + d2;
}

// flatten tree without using any data structure //
// steps
//1. recursively flatten left and right subtrees.
//2.  store left tail and right tail.
//3. store subtree in temp and make left subtree right subtree.
//4.  join right subtree with left tail.
//5. return right tail.

void flatten(Node *root)
{
    if (root == NULL || root->left == NULL || root->right == NULL)
    {
        return;
    }
    if (root->left != NULL)
    {
        flatten(root->left);

        Node *temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node *t = root->right;
        while (t->right != NULL)
        {
            t = t->right;
        }
        t->right = temp;
    }
    flatten(root->right);
}

//  print Node at K distance of a target Node

// case1-> subtree of target
void printSubTree(Node *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout<<root->data<<" ";
        return;
    }

    printSubTree(root->left,k-1);
    printSubTree(root->right,k-1);
        
}
// subtree of ancestor of target 
int printNodeAtK(Node *root, Node *target, int k)
{
    if (root == NULL || k < 0)
    {
        return -1;
    }

    if (root == target)
    {
        printSubTree(root, k);
        return 0;
    }

    int dl = printNodeAtK(root->left, target, k);
    if (dl != -1)
    {
        if (dl + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printSubTree(root->right, k - dl - 2);
        }
        return 1 + dl;
    }

    int dr = printNodeAtK(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printSubTree(root->left, k - dr - 2);
        }
        return 1 + dr;
    }
}

// max path sum //

int maxPathSumUtil(Node* root,int &ans){
    if (root == NULL )
    {
       return -1; 
    }
    int left  = maxPathSumUtil(root->left,ans);
    int right = maxPathSumUtil(root->right,ans);

    int nodeMax = max(max(root->data+left+right,root->data),max(root->data+left,root->data+right));

     ans = max(ans,nodeMax);

     int singlePathSum = max(root->data,max(root->data+left,root->data + right));
     return singlePathSum;   
}

int maxPathSum(Node* root){
    int ans = INT_MIN;
    maxPathSumUtil(root,ans);
    return ans;
}
int main()
{
    /*     1
          / \
         2   3
        / \ / \
       4  5 6  7 
                    */

    // int inorder[] = {4, 2, 1, 5, 3};
    // int preorder[] = {1, 2, 4, 3, 5};
    // int postorder[] = {4, 2, 5, 3, 1};
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // struct Node *root2 = new Node(1);
    // root2->left = new Node(2);
    // root2->left->left = new Node(3);
    // preOrder(root);
    // cout<<endl;
    // inOrder(root);
    //  cout<<endl;
    // postOrder(root);

    //build tree
    //Node* root  = build_tree_pre_to_in(preorder,inorder,0,4);
    //  Node *root = build_tree_post_to_in(postorder, inorder, 0, 4);

    // cout<<sumAtK(root,1);
    //cout<<countNodes(root);
    //cout<<sumOfNodes(root);
    //cout<<Height(root);
    //  cout<<Diameter(root)<<endl;
    // printlevelOrder(root);

    // int height = 0;
    //  cout<<DiameterOpt(root,&height);
    // preOrder(root);
    // cout << endl;
    // sumReplace(root);
    // preOrder(root);
    // cout << endl;
    /*
    if (balancedHeightOpt(root,&height))
    {
        cout << "Balanced tree" << endl;
    }
    else
    {
        cout << "Unbalanced tree" << endl;
    }
*/
    // rightView(root);
    // leftView(root);

    // cout<<distanceBetweenNodes(root,4,7);

    // inOrder(root);
    // cout << endl;
    // flatten(root);
    // inOrder(root);

    //printNodeAtK(root,root->left,1);

    cout<<maxPathSum(root);


}