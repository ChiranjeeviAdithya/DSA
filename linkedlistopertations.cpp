#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data; 
    Node* next;
    
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
}; // ✅ semicolon here

Node* converttoll(vector<int>& arr) {
    if (arr.empty()) return nullptr;

    Node* head = new Node(arr[0], nullptr);
    Node* mover = head;

    for (int i = 1; i < arr.size(); i++) {  // ✅ Start from 1
        Node* temp = new Node(arr[i], nullptr);
        mover->next = temp;
        mover = mover->next;
    }

    return head;
}
Node* insertion(Node* head,int val)
{
    Node* temp=new Node(val,head);
    return temp;

}
Node* inserttail(Node* head,int val)
{
    if(head==NULL)
    {
        return new Node(val,nullptr);
    }
    Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    Node* last=new Node(val,nullptr);
    temp->next=last;
    return head;
}
Node* insertposition(Node* head,int val,int pos)
{
    if (head==NULL)
    { 
        if(pos==1)
        {
        return new Node(val,nullptr);
    }
    else 
    {
        return head;
    }
}
    if(pos==1)
    {
        return new Node(val,head);
    }
    int cnt=0;
    Node* temp=head;
    while(temp!=NULL)
    {
        cnt++;
        if(cnt==(pos-1))
        {
          Node* newnode=new Node(val,temp->next);
          temp->next=newnode;
           break;
        }
        temp=temp->next;
    }
    return head;
}
Node* insertbeforevalue(Node* head,int val,int bval)
{
    if (head==NULL)
    { 
     return head;
}
    if(head->data == bval)
    {
        return new Node(val,head);
    }
    int cnt=0;
    Node* temp=head;
    while(temp->next!=NULL)
    {
        cnt++;
        if(temp->next->data==bval)
        {
          Node* newnode=new Node(val,temp->next);
          temp->next=newnode;
           break;
        }
        temp=temp->next;
    }
    return head;
}
void print(Node* head)
{ 
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node* removekth(Node* head,int k)
{
    if(head==NULL)
    {
        return head;
    }
    if(k==1)
    {
        Node* temp=head;
        head=head->next;
        delete temp;
                return head;

                
    }
    int cnt=0;
    Node* temp=head;
    Node* prev=nullptr;
    while(temp!=NULL)
    {
        cnt++;
     if(cnt==k)
     {
        prev->next=prev->next->next;
        delete temp;
        break;
     }  
     prev=temp;
     temp=temp->next;
    }
    return head;

}
int main() {
    vector<int> array = {1, 2, 3, 4};  // ✅ Semicolon added
    Node* head = converttoll(array);
    head=insertbeforevalue(head,100,3);
    print(head);
    return 0;
}
