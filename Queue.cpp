#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

// implementation using array
// #define n 1000000
// class queue
// {
// int* arr;
// int front;
// int back;

// public:
//   queue(){
//       arr = new int[n];
//       front = -1;
//       back = -1;

//    }

//    void enqueue(int x){
//        if (back == n-1)
//        {
//            cout<<"Queue Overflow"<<endl;
//            return;
//        }

//        back++;
//        arr[back] = x;

//        if (front == -1)
//        {
//            front++;

//        }

//    }

//    void dequeue(){

//        if (front == -1 or front > back)
//        {
//            cout<<"No element found"<<endl;
//        }
//        front++;

//    }

//    int peek(){
//        if (front == -1 or front > back){
//             cout<<"No element found"<<endl;
//        }
//         return arr[front];
//    }

//    bool empty(){
//        if (front == -1 or front > back){
//             return true;
//        }
//        return false;
//    }

//    void print(queue q){
//        while (!q.empty())
// {
//     cout<<q.peek()<<" -> ";
//     q.dequeue();
// }
//    }
// };

// implementation using Linked List

// class node
// {
// public:
//     int data;
//     node *next;
//     node(int value)
//     {
//         data = value;
//         next = NULL;
//     }
// };

// class queue
// {
//     node *front;
//     node *back;

// public:
//     queue()
//     {
//         front = NULL;
//         back = NULL;
//     }

//     void enqueue(int x)
//     {
//         node *n = new node(x);
//         if (front == NULL)
//         {
//             back = n;
//             front = n;
//             return;
//         }
//         back->next = n;
//         back = n;
//     }
//     void dequeue()
//     {

//         if (front == NULL)
//         {
//             cout << "Queue empty" << endl;
//             return;
//         }
//         node *toDelete = front;
//         front = front->next;

//         delete toDelete;
//     }
//     int peek()
//     {

//         if (front == NULL)
//         {
//             cout << "Queue empty" << endl;
//             return -1;
//         }
//         return front->data;
//     }

//     bool empty()
//     {
//         if (front == NULL)
//         {

//             return true;
//         }
//         return false;
//     }

//     void print(queue q)
//     {
//         while (!q.empty())
//         {
//             cout << q.peek() << " ";
//             q.dequeue();
//         }
//     }
// };

// implementation queue using stack

// class queue
// {
//     stack<int> s1;
//     stack<int> s2;

// public:

// //  O(1);
//     void enqueue(int x)
//     {
//         s1.push(x);
//     }

// //  O(n)

//     int dequeue()
//     {

//         if (s1.empty() && s2.empty())
//         {
//             cout << " Queue Empty" << endl;
//             return -1;
//         }
//         if (s2.empty())
//         {
//             while (!s1.empty())
//             {
//                 s2.push(s1.top());
//                 s1.pop();
//             }
//         }
//         int top_element = s2.top();
//         s2.pop();
//         return top_element;
//     }

//     bool empty()
//     {
//         if (s1.empty() && s2.empty())
//         {
//             return true;
//         }
//         return false;
//     }

// };

// implementation queue using stack using recursion (optimized method)

class queue
{
    stack<int> s1;
    

public:

//  O(1);
    void enqueue(int x)
    {
        s1.push(x);
    }

//  O(n)

    int dequeue()
    {

        if (s1.empty() )
        {
            cout << " Queue Empty" << endl;
            return -1;
        }
       int x = s1.top();
       s1.pop();
       if (s1.empty())
       {
           return x;
       }
       int item = dequeue();
       s1.push(x);
       return item;
    }

    bool empty()
    {
        if (s1.empty() )
        {
            return true;
        }
        return false;
    }

};

int main()
{
    queue q;
    for (int i = 0; i < 10; i++)
    {
        q.enqueue(i);
    }

    cout<<q.dequeue()<<" ";
     cout<<q.dequeue()<<" ";
      cout<<q.dequeue()<<" ";
       cout<<q.dequeue()<<" ";
        cout<<q.dequeue()<<" ";
}