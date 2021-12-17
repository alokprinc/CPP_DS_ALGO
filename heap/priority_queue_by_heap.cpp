#include <bits/stdc++.h>
using namespace std;

vector<int> data;
void swap(int a,int b){
    int temp;
    temp = data[a];
   data[a] = data[b];
    data[b] = temp;
}
int _size()
{
    return data.size();
}
void upheapify(int childIndex){
    if(childIndex == 0){
        return;
    }
  int li,ri,pi;
  if(childIndex % 2 == 0){
      ri = childIndex;
      pi = (ri-2)/2;
      if(data.at(pi) > data.at(ri)){
           swap(pi,ri);
           upheapify(pi);
       }
  }else{
      li = childIndex;
       pi = (li-1)/2;

       if(data.at(pi) > data.at(li)){
           swap(pi,li);
           upheapify(pi);
       }
  }
}
void downheapify(int pi){
    int li = 2*pi + 1;
    int ri = 2*pi + 2;
    int minindex = pi;
    if(li < data.size() and data.at(li) < data.at(minindex)){
        minindex = li;
    }
    if(ri < data.size() and data.at(ri) < data.at(minindex)){
        minindex = ri;
    }
   if(minindex != pi){
    swap(pi,minindex);
    downheapify(minindex);
   }
}


void add(int val)
{
    data.push_back(val);
    upheapify(data.size()-1);
}

int _remove()
{

    if (_size() == 0)
    {
        cout << "Underflow" << endl;
        return -1;
    }
     swap(0,data.size()-1);
     int removedVal = data.at(data.size()-1);
     data.pop_back();
     downheapify(0);
     return removedVal;

}

int peek()
{

    if (_size() == 0)
    {
        cout << "Underflow" << endl;
        return -1;
    }

    return data.at(0);
}

int main()
{

    while (1)
    {
        string str;
        getline(cin, str);
        if (str[0] == 'a')
        {
            string num = str.substr(4, str.length());
            int val = stoi(num);
            add(val);
        }
        else if (str[0] == 'r')
        {
            int val = _remove();
            if (val != -1)
            {
                cout << val << endl;
            }
        }
        else if (str[0] == 'p')
        {
            int val = peek();
            if (val != -1)
            {
                cout << val << endl;
            }
        }
        else
            break;
    }
}