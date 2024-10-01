#include<bits/stdc++.h>
using namespace std;

   class Node{
    public:
    int data;
    Node* next;
    
    public:
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }

    public:
    Node(int data1){
        data=data1; 
        next=nullptr;
    }
   };
 
 Node* convertArr2ll(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1; i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
 }

Node* removehead(Node* head){
    if(head== nullptr){return NULL;}
    Node *temp=head;
    head=head->next;
    free(temp);
    return head;
}

Node* removetail(Node* head){
    if(head==NULL || head->next==nullptr){
        return nullptr;
    }
    Node* temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=nullptr;
    return head;
}
Node* removeK(Node* head,int k){
    if(head==NULL){return head;}
    int count=0;
    if(k==1){
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    Node* temp=head;Node * prev=NULL;
    while(temp!=nullptr){
        count++;
        if(count==k){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }

}
Node* removeel(Node* head,int k){
    if(head==NULL){return head;}
    if(head->data==k){
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    Node* temp=head;Node * prev=NULL;
    while(temp!=nullptr){;
        if(temp->data==k){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }

}

Node* newhead(Node* head,int value){
    return new Node(value,head);
}

Node* inserttail(Node* head,int value){
    if(head==NULL){
        return new Node(value);
    }
    Node *temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    Node* Newnode=new Node(value);
    temp->next=Newnode;
    return head;
}

Node* insertatposition(Node* head,int el,int k){
    if(head==NULL){
        if(k==1){
            return new Node(el);
        }else{
            return nullptr;
        }
    }
    if(k==1){
        Node * temp=new Node(el,head);
        return temp;
    }
    int count=0;
    Node* temp=head;
    while(temp!=nullptr){
        count++;
        if(count==k-1){
            Node * newnode=new Node(el);
            newnode->next=temp->next;
            temp->next=newnode;
            break;
        }
        temp=temp->next;
    }
    return head;
}


   int main(){
    vector <int> arr={12,5,8,7}; 
    Node* head=convertArr2ll(arr);
    //head=removehead(head);
    //head=newhead(head,100);
    //head=inserttail(head,101);
    head=insertatposition(head,100,3);
    Node* temp=head;
    //head=removeel(head,7);
    int count=0;
    while(temp){
        count++;
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<count;
    // Node * y=new Node(arr[0] );
    // cout<<y->data;

   }
