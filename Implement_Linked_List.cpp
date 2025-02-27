#include<iostream>
using namespace std;
struct Node
{
 int val;
 Node* next;
 Node(int data) : val(data),next(nullptr) {}
};

class LinkedList{
    private:
    Node* head;
    public:
    LinkedList() : head(nullptr) {}

    void add(int data){
        Node* newNode = new Node(data);
        if(head==nullptr){
            head = newNode;
        }
        else{
            Node* temp = head;
            while(temp->next!=nullptr ){
                temp=temp->next;
            }
            temp->next = newNode;
        }
    }
    void display(){
        Node* temp = head;
        while(temp!=nullptr){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;

    }
    void removeNode(int data){
        if(head == nullptr){
            return;
        }
        if(head->val==data){
            Node* temp = head;
            head=head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while(temp->next!=nullptr && temp->next->val == data){
            temp = temp->next;
        }
        if(temp->next!=nullptr){
            Node* todelete = temp->next;
            temp->next=temp->next->next;
            delete todelete;
        }
    }
};



int main(){
    LinkedList list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);
    cout<<"List: ";
    list.display();
    list.removeNode(3);
    cout<<"After remove: ";
    list.display();
    return 0;
}