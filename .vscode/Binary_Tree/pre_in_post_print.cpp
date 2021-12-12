#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
class Node
{
public:
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int data)
    {
        this->data = data;
    }
};

class Pair
{
public:
    Node *node = nullptr;
    int state = 0;
    Pair(Node *node, int state)
    {
        this->node = node;
        this->state = state;
    }
};

Node *construct(vector<int> &arr)
{
    Node *root = new Node(arr[0]);
    pair<Node *, int> p = {root, 1};

    stack<pair<Node *, int>> st;
    st.push(p);

    int idx = 1;
    while (!st.empty())
    {
        if (st.top().second == 1)
        {
            st.top().second++;
            if (arr[idx] != -1)
            {
                st.top().first->left = new Node(arr[idx]);
                pair<Node *, int> lp = {st.top().first->left, 1};
                st.push(lp);
            }
            else
            {
                st.top().first->left = nullptr;
            }
            idx++;
        }
        else if (st.top().second == 2)
        {
            st.top().second++;
            if (arr[idx] != -1)
            {
                st.top().first->right = new Node(arr[idx]);
                pair<Node *, int> rp = {st.top().first->right, 1};
                st.push(rp);
            }
            else
            {
                st.top().first->right = nullptr;
            }
            idx++;
        }
        else
        {
            st.pop();
        }
    }
    return root;
}
// void preOrder(Node* node){
//     if(node == nullptr){
//         return;
//     }

//     stack<Node*> st;
//     st.push(node);

//     while(!st.empty()){
//         Node* remNode = st.top();
//         cout<<remNode->data<<" ";
//         st.pop();
//          if(remNode->right != nullptr){
//             st.push(remNode->right);
//         }
        
//         if(remNode->left != nullptr){
//             st.push(remNode->left);
//         }
       
//     }

// }
// void iterativePrePostInTraversal(Node *node){
//     preOrder(node);
//     // inOrder(node);
//     // postOrder(node);
// }
void iterativePrePostInTraversal(Node *node)
{
    stack<Pair> st;
    Pair rootPair = {node, 0};
    st.push(rootPair);

    vector<int> preOrder;
    vector<int> InOrder;
    vector<int> postOrder;
    while (st.size() > 0)
    {
        Pair rem = st.top();
        
        if (rem.state == 0)
        {
            // pre , state++, left
            
            preOrder.push_back(rem.node->data);
            rem.state++;

            if (rem.node->left != nullptr)
            {
                Pair leftPair = {rem.node->left, 0};
                st.push(leftPair);
            }
            
        }
        else if(rem.state == 1)
        { 
            // Inoreder, state++ , right
            InOrder.push_back(rem.node->data);
           
            rem.state++;

            if (rem.node->right != nullptr)
            {
                Pair rightPair = {rem.node->right, 0};
                st.push(rightPair);
            }
        }
        else
        {  
            // post ,pop
            postOrder.push_back(rem.node->data);
            st.pop();
            
        } 

        return;
    }
    for(auto a: preOrder){
        cout<<a<<" ";
    } cout<<endl;
        for(auto a: InOrder){
        cout<<a<<" ";
    } cout<<endl;
        for(auto a: postOrder){
        cout<<a<<" ";
    } cout<<endl;
 
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        if (temp == "n")
        {
            arr[i] = -1;
        }
        else
        {
            arr[i] = stoi(temp);
        }
    }
    Node *root = construct(arr);
    iterativePrePostInTraversal(root);
}