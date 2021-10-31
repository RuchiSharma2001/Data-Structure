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

void makecycle(node * &head ,int pos){
    node* temp=head;
    node* startnode;
    int count=1;
    while(temp->next!=NULL){
        if(count==pos){
            startnode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=startnode;
}
bool isCycle(node* &head){
    node* slow =head;
    node* fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
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

void deletecycle(node* &head){
    node* slow =head;
    node* fast=head;
    do{
        
        slow=slow->next;
        fast=fast->next->next;
    }while(fast!=slow);
    fast=head;
    do{
        slow=slow->next;
        fast=fast->next;
    }while(slow->next!=fast->next);
    slow->next=NULL;
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


int main(){
    node* head=NULL;
    InsertAtEnd(head,1);
    InsertAtEnd(head,2);
    InsertAtEnd(head,3);
    InsertAtEnd(head,4);
    InsertAtEnd(head,5);
    InsertAtEnd(head,6);
    //cout<<lengthNode(head)<<endl;
    makecycle(head,3);
    if(isCycle(head)){
        cout<<"present";
    }
    else {
        cout<<"not present";
    }
    deletecycle(head);
    display(head);
    //deletestart(head);
    //cout<<lengthNode(head)<<endl;
    //node* newhead=reverse(head);
    //InsertAtStart(head,0);
    //node* newhead=recurreverse(head);
    //InsertAtPos(head,9,3);
    //deleteNum(head,3);
    //cout<<lengthNode(head)<<endl;
    //display(head);
    if(isCycle(head)){
        cout<<"present";
    }
    else {
        cout<<"not present";
    }
    return 0;
}