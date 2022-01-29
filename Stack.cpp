#include <iostream>
#include <queue>
using namespace std;

// stack using array

// #define n 1000000
// class Stack{
//     int* arr;
//     int top;
//     public:
//     Stack(){
//         arr = new int[n];
//         top =-1;
//     }

//     void Push(int x){
//         if (top == n-1)
//         {
//             cout<<"Stack Overflow"<<endl;
//             return;
//         }
//         top ++;
//         arr[top] = x;

//     }

//     void Pop(){
//         if (top == -1)
//         {
//             cout<<"No element to pop"<<endl;
//         }
//         top--;
//     }

//     int Top(){
//         if (top == -1)
//         {
//             cout<<"No element at top"<<endl;
//         }
//         return arr[top];
//     }

//     bool Empty(){
//         return top == -1;
//     }

// };

// void print(Stack stack){
//         for (int i = 0; i < 10; i++)
// {
//     cout<<stack.Top()<<endl;
//     stack.Pop();
// }
//     }

// stack using queue method 1 ( push -> costly)

// class Stack{
// queue<int> q1;
// queue<int> q2;
// int n;

// public:
// void stack(){
//     n=0;
// }
// void push(int x){
// q2.push(x);
// n++;
// while (!q1.empty())
// {
//   q2.push(q1.front());
//     q1.pop();
// }
// queue<int> temp = q1;
// q1= q2;
// q2 = temp;
// }
// void pop(){
//     if (q1.empty())
//     {
//         cout<<" stack empty"<<endl;
//         return;
//     }
//     q1.pop();
//     n--;
// }
// int top(){
//     return q1.front();
// }
// int size(){
//     return n;
// }

// };

// stack using queue method 1 ( pop -> costly)

class Stack
{
    queue<int> q1;
    queue<int> q2;
    int n;

public:
    void stack()
    {
        n = 0;
    }
    void push(int x)
    {
        q1.push(x);
        n++;
    }
    void pop()
    {
        if (q1.empty())
        {
            cout << " stack empty" << endl;
            return;
        }
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        n--;

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }
    int top()
    {
        if (q1.empty())
        {
            cout << " stack empty" << endl;
            return -1;
        }
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int ans = q1.front();
        q2.push(ans);

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
        return ans;
    }
    int size()
    {
        return n;
    }
};

int main()
{

    Stack stack;

    for (int i = 0; i < 10; i++)
    {
        stack.push(i);
    }
    for (int i = 0; i < 10; i++)
    {
        cout << stack.top() << " ";
        stack.pop();
    }
    
}