#include <iostream>
#include <vector>

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
  return node == nullptr ? -1 : max(height(node->left), height(node->right)) + 1; // for no of edges: -1, and in terms of no of nodes return 0;
}

// diameter inefficient n(square)
int diameter(Node* node){
    if(node == nullptr){
        return -1;
    }

    int lh = height(node->left);
    int rh = height(node->right);
    int ld = diameter(node->left);
    int rd = diameter(node->right);

    int total = max(max(ld,rd),lh+rh+2);
    return total;
}
class DiaPair{
    public:
    int ht;
    int dia;
    DiaPair(int ht,int dia){
        this->ht = ht;
        this->dia = dia;
    }
};
// diameter efficient of n time
DiaPair diameter2(Node* node){
    if(node ==nullptr){
        DiaPair retPair = {-1,0};
        return retPair;
    }

    DiaPair mpl  = diameter2(node->left);
    DiaPair mpr = diameter2(node->right);

    DiaPair myPair(-1,0);
    myPair.ht = max(mpl.ht ,mpr.ht )+1;
    myPair.dia =  max(max(mpl.dia,mpr.dia),mpl.ht+mpr.ht+2);
    
    return myPair;
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

  int dia = 0;
//   dia = diameter(root);
DiaPair ans = diameter2(root);

  cout << ans.dia;



}