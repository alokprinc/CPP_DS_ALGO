#include<iostream>
using namespace std;
///   node decelaration
class node
{
public:
    int data;
    node *next;

    node(int value){
        data = value;
        next = NULL;
    }
};

//    Add element
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
}
// Add element to start
node* addToStart(node *&head, int value)
{
    node *toAdd = new node(value);
    toAdd->next = head;
    head = toAdd;
    return head;
}

// print Linked List
void print(node *head)
{

    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

// Search Element in Linked List
bool Search(node *head, int toSearch)
{

    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == toSearch)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
// Delete element in Linked List

void Delete(node *&head, int val)
{
    if (head == NULL)
    {
        return;
    }

    if (head->data == val || head->next == NULL)
    {
        node *toDelete = head;
        head = head->next;

        delete toDelete;
    }
    else
    {
        node *temp = head;
        while (temp->next->data != val)
        {
            temp = temp->next;
        }
        node *toDelete = temp->next; //  TEMP->NEXT IS THE NODE THAT WE HAVE TO DELETE
        temp->next = temp->next->next;
        delete toDelete;
    }
}

// Reverse A Linked list
// Itrative Method

node* Reverse(node* &head)
{

    node *PreviousNode = NULL;
    node *CurrentNode = head;
    node *NextNode;

    while (CurrentNode != NULL)
    {
        NextNode = CurrentNode->next;
        CurrentNode->next = PreviousNode;
        PreviousNode = CurrentNode;
        CurrentNode = NextNode;
    }
    return PreviousNode;
}

// compare 
bool compareLists(node* head1, node* head2) {

int ans = 0;
   while (head1!=NULL && head2 != NULL) {
        if (head1->data != head2->data) {
        ans = 1;
        }
        head1=head1->next;
        head2= head2->next;
   }
   if (ans == 1 || head1 != NULL || head2 != NULL) {
   return false;
   } else {
   return true;
   }
}

node *ReverseRecursive(node *&head)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *newhead = ReverseRecursive(head->next); // Except first element all would be reversed by this line 
    head->next->next = head;
    head->next = NULL;

    return newhead;
}

node *ReverseKnodes(node *&head, int k)
{
    node *PreviousNode = NULL;
    node *CurrentNode = head;
    node *NextNode;

    int count = 0;
    while (CurrentNode != NULL && count < k)
    {
        NextNode = CurrentNode->next;
        CurrentNode->next = PreviousNode;
        PreviousNode = CurrentNode;
        CurrentNode = NextNode;
        count++;
    }
    if (NextNode != NULL)
    {
        head->next = ReverseKnodes(NextNode, k);
    }
    return PreviousNode;
}
// FLOYD'S Algorithm
void cycleMaker(node *&head, int index)
{
    node *temp = head;
    node *startCycleNode;

    int count = 1;
    while (temp->next != NULL)
    {
        if (count == index)
        {
            startCycleNode = temp; // given position will become start node
        }

        temp = temp->next;
        count++;
    }
    temp->next = startCycleNode; // starting point of the cycle which is index stored in the startCycleNode will be Assigned to temp->next
                                 // which is the last node of our list
}
// FLOYD'S Algorithm
bool DetectCycle(node *&head)
{
    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}
/// FLOYD'S Algorithm
void RemoveCycle(node *head)
{
    node *fast = head;
    node *slow = head;
while (slow != fast)
{
    slow= slow->next;
    fast=fast->next->next;
}
fast=head;
while (slow->next!=fast->next)
{
     slow=slow->next;
     fast=fast->next;
}

slow->next = NULL;
  
}

int length(node* head){
    int length = 0;
    node* temp = head;
    while (temp->next != NULL)
    {
        length++;
        temp=temp->next;
    }
    return length;
}

node* AppendLastKnodes(node* &head,int k){
 node* newHead ;
 node* newTail;
 node* temp = head;
 int l = length(head);
 int count = 0;
 k = k % l;
 while (temp->next!=NULL)
 {
     if (count == l-k)
     {
         newTail = temp;
     }
     if (count == l-k+1)
     {
         newHead = temp;
     }
     temp=temp->next;
     count++;
    
 }
  newTail->next= NULL;
     temp->next = head;
     return newHead;

}

void intersectMaker(node* head1,node* head2,int position){
node* temp1 = head1;
node* temp2 = head2;
while (position>0)
{
    temp1=temp1->next;
    position--;
}
while (temp2->next!=NULL)
{
    temp2=temp2->next;
}
temp2->next=temp1;
}

int intersectionPoint(node* head1,node* head2){
    node* pointer1 = head1;
    node* pointer2 = head2;  
    int l1 = length(head1);
     int l2 = length(head2);
     int diff;

     if (l1>l2)
     {
         diff = l1-l2;
         pointer1 = head1;
         pointer2 = head2;
     } 
     if (l2>l1)
     {
        diff = l2-l1;
        pointer1 = head2;
         pointer2 = head1;
     }
     while (diff)
     {
         pointer1 = pointer1->next;
         if (pointer1==NULL)
         {
             return -1;
         }
         diff--;
     }
   
     while (pointer1 != NULL, pointer2 != NULL)
     {
         if (pointer1==pointer2)
         {
            return pointer1->data;
            
         }
         
         pointer1= pointer1->next;
         pointer2=pointer2->next;
     }
        
        return -1;
} 

// RECURSIVE METHOD
node* mergeRecursiveTwoSortedLinkedList(node* &head1,node* &head2){
if(head1==NULL){
    return head2;
}
if(head2==NULL){
    return head1;
}

    node* result;
if(head1->data < head2->data){
    result = head1;
    result->next = mergeRecursiveTwoSortedLinkedList(head1->next,head2);
} else{
    result = head2;
    result->next = mergeRecursiveTwoSortedLinkedList(head1,head2->next);
}
  return result;
}

//   ITRATIVE METHOD
node* mergeItrativeTwoSortedLinkedList(node* &head1,node* &head2){
        node* poniter1 = head1;
        node* poniter2 = head2;
       
        node* dummyNode = new node(-1);
 node* poniter3=dummyNode;

        while(poniter1 != NULL && poniter2!=NULL){
            if (poniter1->data < poniter2->data)
            {
                poniter3->next = poniter1;
                    poniter1=poniter1->next;
            } else{
                 poniter3->next = poniter2;
                    poniter2=poniter2->next;
            }
            poniter3=poniter3->next;
        }

        while (poniter1!=NULL)
        {
          poniter3->next = poniter1;
          poniter1=poniter1->next;
          poniter3=poniter3->next;
        }
        while (poniter2!=NULL)
        {
          poniter3->next = poniter2;
          poniter2=poniter2->next;
          poniter3=poniter3->next;
        }

        return dummyNode->next;
        
}

// CIRCULAR LINKED LIST
void makeCircularLinkedList(node* head){
    node* temp = head;
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    
}

// Addition of element in Circular Linked list  (AT TAIL)
void addToCircularLinkedList(node* &head, int value){
if (head == NULL)
{
    add(head,value);
    return;
}

node* temp = head;
node* toAdd = new node(value);
while (temp->next != head)
{
    temp = temp->next;
}
temp->next = toAdd;
toAdd->next = head;
}
// Addition of element in Circular Linked list  (AT head)

void addToHeadCircularLinkedList(node* &head, int value){
node* temp =head;
node* toAdd = new node(value);

if (head==NULL)
{
    toAdd->next= toAdd;
    head = toAdd;
    return;
}

while (temp->next!=head)
{
    temp = temp ->next;
}
temp->next = toAdd;
toAdd->next= head;
head = toAdd;
}

// DELETE IN CIRCULAR LINKED LIST

void deleteAtHeadCircularLinkedList(node* &head){
        node* temp1 = head;
        while (temp1->next!=head)
        {
            temp1 = temp1->next;
        }
        node* toDelete = head;
        temp1->next = head->next;
        head= head->next;
        delete toDelete;
}
void deleteInCircularLinkedList(node* &head,int pos){
    node* temp = head;
    if (head==NULL)
    {
        return;
    }
    
    if (pos == 1)
    {
        deleteAtHeadCircularLinkedList(head);
        return;
    }
    
   int count =1;
   while (count!=pos-1)
   {
       temp = temp->next;
       count++;
   }
   node* toDelete = temp->next;
   temp->next = temp->next->next;
   delete toDelete;

}

void evenAfterOdd(node* &head){
    node* even = head->next;
    node* odd =head;
    node* evenStart = even;
    while (odd->next != NULL && even->next != NULL){
        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }  odd->next =evenStart; 
    if (odd->next == NULL)
    {
        even->next=NULL;
    }   
}

// MAIN FUNCTION
int main()
{
    node *head = NULL;
  for (int i = 1; i < 10; i++)
  {
      addToStart(head,i);
  }
  
 
   print(head);
}