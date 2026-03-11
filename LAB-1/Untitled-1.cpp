#include<iostream>
#include<string>
using namespace std;

typedef struct Node{
   string data;
   Node*next;
   };
   Node* head = NULL;
   
void add(string a) {
    Node* newNode =new Node();
    newNode->data = a;
    newNode->next == NULL;
    
    if(head == NULL) head=newNode;
    
}
void remove(string a){
    if(head == NULL){
        return;
    }
    if(head-> next == NULL){
        delete head;
        head = NULL;
        return;
    }
}
void see(){
    newNode = head;
    while (newNode != NULL) {
        cout << "[" << newNode->data << "] -> ";
        newNode = newNode->next;
    }
    cout << "NULL\n";
}

int main()
{
   
    while(true){
        string  b;
        string a;
        printf("Please enter your word: ");
        cin >> b;
        add(a);
        remove(a);
        see();

        return false;
    }
    return 0;
}