#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
  int data = 0;
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



int height(Node* node)
{
  return node == nullptr ? -1 : max(height(node->left), height(node->right)) + 1;
}

class bst {
public:
  bool isbst = false;
  int max = 0;
  int min = 0;
  Node* root = nullptr;
  int size = 0;
};

bst Bst(Node* node) {

  if(node == nullptr){
      bst ret;
      ret.isbst = true;
      ret.max = INT_MIN;
      ret.min = INT_MAX;
      ret.root = nullptr;
      ret.size = 0;
      return ret;
  }

    bst ls = Bst(node->left);
    bst rs = Bst(node->right);

    bst mybst;
    mybst.isbst = ls.isbst and rs.isbst and (ls.max < node->data and rs.min > node->data);
    mybst.max = max(max(ls.max,rs.max),node->data);
    mybst.min  = min(min(ls.min,rs.min),node->data);
    
    if(mybst.isbst){
        mybst.root = node;
        mybst.size = ls.size + rs.size + 1;
    }else if(ls.size > rs.size){
        mybst.root = node->left;
        mybst.size = ls.size;
    }else{
        mybst.root = node->right;
        mybst.size = rs.size;
    }
    return mybst;
}

int main() {
  int n;
  cin >> n;

  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    string tmp;
    cin >> tmp;
    if (tmp == "n") {
      arr[i] = -1;
    } else {
      arr[i] = stoi(tmp);
    }
  }

  Node* root = constructTree(arr);

  bst r = Bst(root);
  cout << r.root->data << "@" << r.size;



}