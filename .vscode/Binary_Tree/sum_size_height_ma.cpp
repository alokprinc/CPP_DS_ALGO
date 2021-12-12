#include<bits/stdc++.h>

using namespace std;

// structure of node
class Node
{
public:
  int data;
  Node* left = nullptr;
  Node* right = nullptr;
  Node(int data)
  {
    this->data = data;
  }
};

class Pair {
public:
  Node* node = nullptr;
  int state = 0;

  Pair(Node* node, int state) {
    this->node = node;
    this->state = state;
  }
};

int idx = 0;
Node* constructTree(vector<int>& arr)
{

  if (idx == arr.size() || arr[idx] == -1)
  {
    idx++;
    return nullptr;
  }
  Node* node = new Node(arr[idx++]);
  node->left = constructTree(arr);
  node->right = constructTree(arr);
  return node;
}

void display(Node* node)
{
  if (node == nullptr)
    return;
  string str = "";
  str += node->left != nullptr ? to_string(node->left->data) : ".";
  str += " <- " + to_string(node->data) + " -> ";
  str += node->right != nullptr ? to_string(node->right->data) : ".";
  cout << str << endl;

  display(node->left);
  display(node->right);
}


int size(Node* node)
{
  if(node == nullptr){
      return 0;
  }
  int ls = size(node->left);
  int rs = size(node->right);
  int ts = ls+rs+1;
  return ts;
}

int height(Node* node)
{
  if(node == nullptr){
      return 0;  // in terms of nodes
      // return -1;  // for finding the height in terms of edges
  }
  int lh = height(node->left);
  int rh = height(node->right);
  int h = max(lh,rh)+1;
  return h;
}

int maximum(Node* node)
{
  if(node == nullptr){
      return INT_MIN;
  }

  int ml = maximum(node->left);
  int mr = maximum(node->right);
  int m = max(max(ml,mr),node->data);
  return m;
}

int sum(Node* node)
{

  if(node == nullptr){
      return 0;
  }

  int ls = sum(node->left);
  int rs = sum(node->right);
  int ts = ls + rs + node->data;

  return ts;
}

int main()
{

  int n;
  cin >> n;

  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
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

  Node* root = constructTree(arr);

  int sz = size(root);
  int sm = sum(root);
  int max = maximum(root);
  int ht = height(root);
  cout << sz << endl;
  cout << sm << endl;
  cout << max << endl;
  cout << ht << endl;
}