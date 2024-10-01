#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1,Node* next1,Node * back1){
        data=data1;
        next=next1;
        back=back1;
    }

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }

};

Node * covert2arr(vector <int> &arr){
        Node* head=new Node(arr[0]);
        Node*prev=head;
        for(int i=1;i<arr.size();i++){
            Node* temp=new Node(arr[i],nullptr,prev);
            prev->next=temp;
            prev=temp;
        }
    return head;
    }

Node* deletehead(Node * head){
    if(head==nullptr || head->next==NULL){
        return NULL;
    }
    Node* prev=head;
    head=head->next;
    head->back=nullptr;
    prev->next=nullptr;
    delete prev;
    return head ;
}


Node* deletetail(Node * head){
    Node* tail=head;
    while(tail->next!=nullptr){
        tail=tail->next;
    }
    Node* prev=tail->back;
    tail->back=nullptr;
    prev->next=nullptr;
    free(tail);
    return head;
}

Node * removeKthelement(Node* head, int k){
    int count=0;
    Node* temp=head;
    while (temp!=nullptr){
        count++;
        if(count==k){
            break;
            }
        temp=temp->next;
    }
    Node * prev=temp->back;
    Node * front=temp->next;

    if(prev==NULL && front==NULL){
        return NULL;
    }
    if(prev==NULL){
        return deletehead(head);
    }
    if(front==NULL){
        return deletetail(head);
    }
    else{
        prev->next=front;
        front->back=prev;
        temp->next=NULL;
        temp->back=NULL;
        free(temp);
        return head;
    }
}

void print(Node * head){
    Node * temp=head;
    while (temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
}

int main(){
    vector<int> arr={5,2,1,2,12}; 

    Node*head=covert2arr(arr);

    head=removeKthelement(head,2);

    //head=deletehead(head);

    //head=deletetail(head);

    print(head);
    return 0;

}