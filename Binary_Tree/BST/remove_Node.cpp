#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
  Node(int val) {
    data = val;
    left = nullptr;
    right = nullptr;
  }
};

Node* construct(vector<int>& arr) {
  Node* root = new Node(arr[0]);
  pair<Node*, int> p = {root, 1};

  stack<pair<Node*, int>> st;
  st.push(p);

  int idx = 1;
  while (!st.empty()) {

    if (st.top().second == 1) {
      st.top().second++;
      if (arr[idx] != -1) {
        st.top().first->left = new Node(arr[idx]);
        pair<Node*, int> lp = {st.top().first->left, 1};
        st.push(lp);
      }
      else {
        st.top().first->left = nullptr;
      }
      idx++;
    }
    else if (st.top().second == 2) {
      st.top().second++;
      if (arr[idx] != -1) {
        st.top().first->right = new Node(arr[idx]);
        pair<Node*, int> rp = {st.top().first->right, 1};
        st.push(rp);
      } else {
        st.top().first->right = nullptr;
      }
      idx++;
    }
    else {
      st.pop();
    }

  }
  return root;
}
void display(Node* node) {
  if (node == nullptr) {
    return;
  }

  string str = " <- " + to_string(node->data) + " -> ";

  string left = (node->left == nullptr) ? "." :  "" + to_string(node->left->data);
  string right = (node->right == nullptr) ? "." : "" + to_string(node->right->data);

  str = left + str + right;
  cout << str << endl;

  display(node->left);
  display(node->right);
}

int max(Node* root) {
  if (root->right == nullptr) {
    return root->data;
  }
  return max(root->right);
}


Node* remove(Node* node, int data) {
//     Write your code here
    if(node == nullptr){
        return nullptr;
    }

    if(data < node->data){
        node->left = remove(node->left,data);
    }else if(data > node->data){
        node->right = remove(node->right,data);
    }else{
        if(node->left != nullptr and  node->right != nullptr){
            int lmax = max(node->left);
            node->data = lmax;
            node->left = remove(node->left,lmax);
            return node;

        }else if(node->left != nullptr){
            return node->left;
        }else if(node->right != nullptr){
            return node->right;
        }else{
            return nullptr;
        }
    }
    return node;
}
int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    string x;
    cin >> x;
    if (x == "n") {
      arr[i] = -1;

    }
    else {
      arr[i] = stoi(x);
    }
  }
  int data;
  cin >> data;
  Node* root = construct(arr);

  root = remove(root, data);

  display(root);
}