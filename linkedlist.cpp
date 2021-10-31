#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};


void InsertAtStart(node* &head,int val){
    node *insert=new node(val);
    insert->next=head;
    head=insert;
}

void InsertAtPos(node* &head,int val,int pos){
    node* insert=new node(val);
    node* temp=head;
    int i;
    for(i=0;i<pos-1&&temp->next!=NULL;i++){
        temp=temp->next;
    }
    insert->next=temp;
    temp=insert;
    cout<<insert;
    
}


void InsertAtEnd(node* &head,int val){
    node *insert=new node(val);
    if(head==NULL){
        head=insert;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=insert;
}



void deletestart(node* &head){

    if(head==NULL)
    {
        cout<<"Empty"<<endl;
        return;
    }
    node* temp=head;
    head=head->next;
    delete temp;   
}



void deleteend(node* &head){
    if(head==NULL){
        cout<<"Empty";
        return;
    }
    node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
        
    }
    node* next = temp->next->next;
    delete temp->next;
    temp->next=next;
}



void deleteNode(node *&head, int position)
{
    if (head == NULL)
        return;
    node* temp = head;
    if (position == 0)
    {
         
        head = temp->next;
         
        delete temp;           
        return;
    }

    for(int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;
 
    if (temp == NULL || temp->next == NULL)
        return;
 
     node *next = temp->next->next;
 
    delete temp->next;
    temp->next = next;
}




void deleteNum(node *&head, int del)
{
    if (head == NULL)
        return;
    node* temp = head;

    for(int i = 0; temp != NULL && temp->next->data!=del; i++)
        temp = temp->next;
 
     node *next = temp->next->next;
 
    delete temp->next;
    temp->next = next;
}




node* reverse(node *head){
    node* prev=NULL;
    node* currptr=head;
    node* nextptr;
    while(currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=prev;
        prev=currptr;
        currptr=nextptr;

    }
    return prev;
}


node* kreverse(node*head, int k){
    node* prev=NULL;
    node* currptr=head;
    node* nextptr;

    int t=0;
    while(currptr!=NULL&&t<k){
        nextptr=currptr->next;
        currptr->next=prev;
        prev=currptr;
        currptr=nextptr;
        t++;
    }
    if(nextptr!=NULL)
    head->next=kreverse(nextptr,k);
    return prev;
}

bool search(node *&head, int d)
{
    int c=0;
    if (head == NULL)
        return false;
    node* temp = head;

    for(int i = 0; temp != NULL; i++){
        if(temp->data==d){
            return true;
            break;
        }
        temp = temp->next;
    }
    return false;
}



int lengthNode(node* head){
    int c=0;
    node* temp=head;
    while (temp!=NULL){
        c++;
        temp=temp->next;
    }
    return c;
}


node* recurreverse(node* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    node* newhead=recurreverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}

void display(node* head){
    
    if(head==NULL){
        cout<<"Empty"<<endl;
        return;
    }
    node* temp=head;
    while (temp!=NULL){
        cout<<temp->data;
        temp=temp->next;
        if(temp!=NULL){
            cout<<"->";
        }
    }
    cout<<endl;
}


int main(){
    node* head=NULL;
    InsertAtEnd(head,1);
    InsertAtEnd(head,2);
    InsertAtEnd(head,3);
    InsertAtEnd(head,4);
    InsertAtEnd(head,5);
    cout<<lengthNode(head)<<endl;
    display(head);
    //deletestart(head);
    //cout<<lengthNode(head)<<endl;
    //node* newhead=reverse(head);
    //InsertAtStart(head,0);
    //node* newhead=recurreverse(head);
    //InsertAtPos(head,9,3);
    node* newhead=kreverse(head,2);
    display(newhead);
    //deleteNum(head,3);
    //cout<<lengthNode(head)<<endl;
    //display(head);
    //if(search(head,1)){
      //  cout<<"present";
    //}
    //else{
      //  cout<<"not present";
    //}
    return 0;
}