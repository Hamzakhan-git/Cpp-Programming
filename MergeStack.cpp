#include<iostream>
using namespace std;
struct Node{
    int val;
    Node* next;
    Node(int data) : val(data),next(nullptr) {}
};
class Stack{
    public:
    Node* top;
    Node* end;
    Stack() : top(nullptr),end(nullptr) {}

    void push(int data){
        Node* newNode = new Node(data);
        if(top==nullptr){
            top=newNode;
            end=newNode;
        }
        else{
            newNode->next = top;
            top=newNode;
        }

        
    }
    int pop(){
        if(top==nullptr){
            cout<<"UnderFlow";
            return -1;
        }
        int data = top->val;
        Node* temp = top;
        top=top->next;
        if(top==nullptr){
            end=nullptr;
        }
        delete temp;
        return data;

    }
    bool isEmpty(){
        return top==nullptr;
    }
};
void mergeStack(Stack& even,Stack& odd){
    if(even.end ==nullptr){
        even.top = odd.top;
        even.end = odd.end;
    }
    else if(odd.top!=nullptr){
        even.end->next = odd.top;
        even.end = odd.end;
    }
    odd.top = nullptr;
    odd.end = nullptr;
}

int main(){
    Stack even;
    Stack odd;
    int value;
    cout << "Enter elements (type -1 to stop): ";
    while (true) {
        cin >> value;
        if (value == -1) break;
        if (value % 2 == 0) {
            even.push(value);
        } else {
            odd.push(value);
        }
    }

    // Merge the stacks
    mergeStack(even, odd);

    // Display merged stack
    cout << "Merged stack: ";
    while (!even.isEmpty()) {
        cout << even.pop() << " ";
    }
    cout << endl;

    return 0;
}