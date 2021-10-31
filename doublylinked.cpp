#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;
    node (int val){
        data=val;
        next=NULL;
        prev=NULL;
}
};

void insertAtHead(node* &head,int val){
    
    node* n=new node(val);
    n->next=head;
    if(head!=NULL)
    head->prev=n;
    head=n;
}
 
void deleteAtHead(node* &head){
    node* todelete=head;
    head=head->next;
    head->prev=NULL;
    delete todelete;
}

void deletenode(node* &head,int pos){
    node* temp=head;
    if(pos==1){
        deleteAtHead(head);
        return;
    }
    for(int i=1;i<pos&&temp->next!=NULL;i++){
        temp=temp->next;
    }

    temp->prev->next=temp->next;
    if(temp->next!=NULL)
    temp->next->prev=temp->prev;
    delete temp;
}
void deletenum(node* &head,int pos){
    node* temp=head;
    if(head->data==pos){
        deleteAtHead(head);
        return;
    }
    while(temp->data!=pos&&temp->next!=NULL){
        temp=temp->next;
    }

    temp->prev->next=temp->next;
    if(temp->next!=NULL)
    temp->next->prev=temp->prev;
    delete temp;
}

void InsertAtTail(node* &head,int val){
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }
    node* n=new node(val);
    node* temp=head;
    
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    
    n->prev=temp;
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
void reversenode(node* &head){
    node *temp=NULL;
    node* current=head;
    while(current!=NULL){
        temp=current->prev;
        current->prev=current->next;
        current->next=temp;
        current=current->prev;
    }
    if(temp!=NULL){
        head=temp->prev;
    }
}

void insertAtPos(node* &head,int val,int pos){
    if(pos==1){
        insertAtHead(head,val);
        return;
    }
    node* n=new node(val);
    node* temp=head;
    int i;
    for( i=1;i<pos-1&&temp->next!=NULL;i++){
        
        temp=temp->next;
        
    }
    if(temp->next==NULL&&i==pos){
        InsertAtTail(head,val);
    }
    n->prev=temp;
    n->next=temp->next;
    temp->next=n;
    
    temp->next->prev=n;
}

int lengthnode(node*head){
    int c=0;
    node* tem=head;
    while(tem!=NULL){
        c++;
        tem=tem->next;
    }
    return c;
}
int main(){
node* head=NULL;
    InsertAtTail(head,1);
    InsertAtTail(head,2);
    InsertAtTail(head,3);
    InsertAtTail(head,4);
    InsertAtTail(head,5);
    display(head);
    cout<<lengthnode(head);
    insertAtHead(head,6);
    //deletenode(head,6);
    //display(head);
    //deletenode(head,1);
    display(head);
    insertAtPos(head,0,2);
    //deletenum(head,1);
    //reversenode(head);
    display(head);
    return 0;
}