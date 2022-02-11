#include <iostream>
using namespace std;

class node
{

public:
    int data;
    node *next;
    node *previous;

    node(int value)
    {

        data = value;
        next = NULL;
        previous = NULL;
    }
};

void add(node *&head, int value)
{
 node *toAdd = new node(value);
    if (head == NULL)
    {
       head = toAdd;
       return;
    }
    
    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = toAdd;
    toAdd->previous = temp;
}

void print(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << endl;
    cout<<"NULL";
}

void Delete(node* &head,int value){
        node* temp = head;
        while (temp->data != value)
        {
            temp = temp->next;
        } 
       temp->previous->next = temp->next;

       temp->next->previous = temp->previous;  
        
}

int main()
{
    node *head = NULL;
    for (int  i = 0; i < 11; i++)
    {
        add(head, i);
    }
    

    print(head);
    
}