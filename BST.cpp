#include <iostream>
#include <vector>
#include <climits>
#include <stack>
using namespace std;

struct Node
{
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
struct Info
{
    int min;
    int max;
    int size;
    int ans;
    bool isBST;
};

Node *insertBST(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }

    if (val < root->data)
    {
        root->left = insertBST(root->left, val);
    }
    else
    {
        root->right = insertBST(root->right, val);
    }
    return root;
}

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);

    preOrder(root->right);
}

Node *search(Node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->data == key)
    {
        return root;
    }

    else if (key < root->data)
    {
        return search(root->left, key);
    }
    else if (key > root->data)
    {
        return search(root->right, key);
    }
}

Node *inorderSucc(Node *root)
{
    Node *curr = root;
    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }

    return curr;
}

Node *DELETE(Node *root, int key)
{
    if (key < root->data)
    {
        root->left = DELETE(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = DELETE(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        // case with 2 children of deleting node

        Node *temp = inorderSucc(root->right);
        root->data = temp->data;

        root->right = DELETE(root->right, temp->data);
        return root;
    }
}

// BST from preorder

Node *constructBST(int preorder[], int *preorderidx, int key, int min, int max, int n)
{
    if (*preorderidx >= n)
    {
        return NULL;
    }

    Node *root = NULL;
    if (key < max && key > min)
    {
        root = new Node(key);
        *preorderidx += 1;

        if (*preorderidx < n)
        {
            root->left = constructBST(preorder, preorderidx, preorder[*preorderidx], min, key, n);
        }

        if (*preorderidx < n)
        {
            root->right = constructBST(preorder, preorderidx, preorder[*preorderidx], key, max, n);
        }
    }
    return root;
}

// checking BST or Not

bool isBST(Node *root, Node *min, Node *max)
{
    if (root == NULL)
    {
        return true;
    }
    if (min != NULL && root->data < min->data)
    {
        return false;
    }
    if (max != nullptr && root->data > max->data)
    {
        return false;
    }

    bool leftValid = isBST(root->left, min, root);
    bool rightValid = isBST(root->right, root, max);
    return leftValid and rightValid;
}

// buid balanced BST from array

Node *sortedArrayToBST(int arr[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    int mid = (start + end) / 2;
    Node *root = new Node(arr[mid]);

    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

// CATALAN numbers //

int catalan(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    int res = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        res += catalan(i) * catalan(n - 1 - i);
    }

    return res;
}

//  Possible number of BST by n nodes //
// gives total number of bst possible with number of nodes
vector<Node *> possibleBST(int start, int end)
{

    vector<Node *> trees;
    if (start > end)
    {
        trees.push_back(NULL);
        return trees;
    }
    for (int i = start; i <= end; i++)
    {
        // i is current node
        vector<Node *> leftSubtree = possibleBST(start, i - 1);
        vector<Node *> rightSubtree = possibleBST(i + 1, end);

        for (int j = 0; j < leftSubtree.size(); j++)
        {
            Node *left = leftSubtree[j];
            for (int k = 0; k < rightSubtree.size(); k++)
            {
                Node *right = rightSubtree[k];

                Node *currNode = new Node(i);
                currNode->left = left;
                currNode->right = right;
                trees.push_back(currNode);
            }
        }
    }
    return trees;
}

// zig zag traversal //

void zigzagTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    stack<Node *> currlevel;
    stack<Node *> nextlevel;

    bool LeftToRight = true;

    currlevel.push(root);

    while (!currlevel.empty())
    {
        Node *temp = currlevel.top();
        currlevel.pop();

        if (temp != NULL)
        {
            cout << temp->data << " ";

            if (LeftToRight)
            {
                if (temp->left)
                {
                    nextlevel.push(temp->left);
                }
                if (temp->right)
                {
                    nextlevel.push(temp->right);
                }
            }
            else
            {
                if (temp->right)
                {
                    nextlevel.push(temp->right);
                }

                if (temp->left)
                {
                    nextlevel.push(temp->left);
                }
            }
        }
        if (currlevel.empty())
        {
            LeftToRight = !LeftToRight;
            swap(currlevel, nextlevel);
        }
    }
}

// checking bst identical or not //
bool isIdentical(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    else if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    else
    {
        bool con1 = (root1->data == root2->data);
        bool con2 = isIdentical(root1->left, root2->left);
        bool con3 = isIdentical(root2->right, root2->right);

        if (con1 && con2 && con3)
        {
            return true;
        }
        else
            return false;
    }
}

// Largest binary search tree in BT //
// min is subtree
// max in subtree
// subtree size
// size of largest BST
// isBST
Info largestBSTinBT(Node *root)
{
    if (root == NULL)
    {
        return {INT_MIN, INT_MAX, 0, 0, true};
    }
    if (root->left == NULL && root->right == NULL)
    {
        return {root->data, root->data, 1, 1, true};
    }

    Info leftSubtree = largestBSTinBT(root->left);
    Info rightSubtree = largestBSTinBT(root->right);

    Info curr;
    curr.size = (1 + leftSubtree.size + rightSubtree.size);

    if (leftSubtree.isBST && rightSubtree.isBST && leftSubtree.max < root->data && rightSubtree.min > root->data)
    {
        curr.min = min(leftSubtree.min, min(root->data, rightSubtree.min));
        curr.max = max(leftSubtree.max, max(rightSubtree.max, root->data));

        curr.ans = curr.size;
        curr.isBST = true;

        return curr;
    }

    curr.ans = max(leftSubtree.max, rightSubtree.max);
    curr.isBST = false;
    return curr;
}
// Restoreing BST
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void calculatePointer(Node *root, Node **first, Node **mid, Node **last, Node **prev)
{
    if (root == NULL)
    {
        return;
    }

    calculatePointer(root->left, first, mid, last, prev);

    if (*prev && root->data < (*prev)->data)
    {
        if (!*first)
        {
            *first = *prev;
            *mid = root;
        }
        else
        {
            *last = root;
        }
    }
    *prev = root;

    calculatePointer(root->right, first, mid, last, prev);
}
void restoreBST(Node *root)
{
    Node *first, *mid, *last, *prev;
    first = NULL;
    mid = NULL;
    last = NULL;
    prev = NULL;

    calculatePointer(root, &first, &mid, &last, &prev);

    if (first && last)
    {
        swap(&(first->data), &(last->data));
    }
    else if (first)
    {
        swap(&(first->data), &(mid->data));
    }
}
int main()
{

    // vector<int> a;
    // for (int i = 0; i < 10; i++)
    // {
    //     a.push_back(100 - i);
    // }
    // Node *root = NULL;
    // root = insertBST(root, 95);
    // for (int i = 0; i <= 10; i++)
    // {
    //     insertBST(root, a[i]);
    // }

    // inOrder(root);
    //    if( search(root,99) == NULL){
    //        cout<<" KNF";
    //    } else
    //        cout<<" KF";
    // root = DELETE(root,5);
    // inOrder(root);

    // int preorder[] = {10,2,1,13,11};
    // int n = 5;
    // int preorderidx = 0;
    // Node* root = constructBST(preorder,&preorderidx,preorder[0],INT_MIN,INT_MAX,n);
    // preOrder(root);

    // cout<<isBST(root,NULL,NULL);

    //     int arr[] = {10,20,30,40,50};
    //    Node* root = sortedArrayToBST(arr,0,4);
    //     preOrder(root);

    // for (int i = 0; i < 10; i++)
    // {
    //     cout << catalan(i) << " ";
    // }

    // vector<Node *> totalTrees = possibleBST(1, 10);

    // for (int i = 0; i < totalTrees.size(); i++)
    // {
    //     cout << i + 1 << " :";
    //     preOrder(totalTrees[i]);
    //     cout << endl;
    // }

    // Node* root = new Node(12);
    // root->left = new Node(9);
    // root->right =new Node(15);
    // root->left->left = new Node(5);
    // root->left->right = new Node(10);
    // zigzagTraversal(root);
    // cout<<endl;

    // cout<<isIdentical(root,root)<<endl;

    // cout << "largest bst : " << largestBSTinBT(root).ans;

    Node *root = new Node(12);
    root->left = new Node(9);
    root->right = new Node(11);
    root->left->left = new Node(5);
    root->left->right = new Node(10);
    inOrder(root);
    cout << endl;
    restoreBST(root);
    inOrder(root);
    cout << endl;
}