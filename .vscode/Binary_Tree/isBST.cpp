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

//Display function
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


//Height function
int height(Node* node)
{
  return node == nullptr ? -1 : max(height(node->left), height(node->right)) + 1;
}

class bstPair{
    public:
    bool isBst;
    int min;
    int max;
};

bstPair Bst(Node* node) {
  if(node == nullptr){
      bstPair ret;
      ret.isBst=true;
      ret.min = INT_MAX;
      ret.max = INT_MIN;
      return ret;
  }

  bstPair lbst = Bst(node->left);
  bstPair rbst = Bst(node->right);

  bstPair mybst;

  mybst.isBst = lbst.isBst and rbst.isBst and (node->data > lbst.max and node->data < rbst.min);                       
  mybst.min = min(node->data,min(lbst.min,rbst.min));
  mybst.max = max(node->data,max(lbst.max,rbst.max));
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

  bstPair r = Bst(root);
  if (r.isBst == 1)
    cout << "true";
  else
    cout << "false";



}