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

int length (node*head){
    int l=0;
    node* temp=head;
    while (temp!=NULL){
        l++;
        temp=temp->next;
    }
    return l;
}
node* kappend (node* &head,int k){
    int l=length(head);
    node* newhead;
    node* newtail;
    node* tail=head;
    
    k=k%l;
    int count=1;
    while(tail->next!=NULL){
        if(count==l-k-1){
            newtail=tail;
        }
        if(count==l-k){
            newhead=tail;
        }
        tail=tail->next;
        count++;
    }
    newtail->next=NULL;
    tail->next=head;
    
    return newhead;

}
void evenAfterOdd(node* &head){
    
    node* odd=head;
    

    node* even=head->next;
    node* evenStart=even;
    cout<<evenStart->data;
    while(odd->next!=NULL && even->next!=NULL){
        cout<<"h";
        odd->next=even->next;
        odd=odd->next;

        even->next=odd->next;
        even=even->next;
    }
    cout<<"HHHHHHHHHHHHHHH";
    odd->next=evenStart;
    
    if(odd->next != NULL){
        cout<<endl<<"h";
        even->next=NULL;
        
        cout<<even->data;
        
    }
    
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

}

int main(){
    node* head=NULL;
    InsertAtEnd(head,1);
    InsertAtEnd(head,2);
    InsertAtEnd(head,3);
    InsertAtEnd(head,4);
    InsertAtEnd(head,5);
    InsertAtEnd(head,6);
    
    display(head);
    evenAfterOdd(head);
    display(head);
    //node* newhead=kappend(head,2);
    //display(newhead);
    return 0;
}