#include <iostream>
#include <chrono>
using namespace std;

struct Node{
    int value;
    Node* next;
};
struct LinkedList{
    Node* head = NULL;
    Node* tail = NULL;

    void push(int item){
        if(head == NULL){
            struct Node *node = (struct Node*) malloc(sizeof(struct Node));
            head = node;
            node ->value = item;
            node -> next = NULL;
        }
        else{
            struct Node *node = (struct Node*) malloc(sizeof(struct Node));
            node -> value = item;
            node -> next = head;
            head = node;
        }
    }

    void pop() {
        if (head == NULL) {
            cout << "Stack is empty" << endl;
        } else {
            Node* current = head;
            head = head->next;
            //cout << current->value << endl;
            current ->next = NULL;

        }
    }
    void display(){
        Node* current;
        head = current;
        while(current != NULL){
            cout << current-> value << ' ';
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList linkedList;
    srand(time(nullptr));

//    int size;
//    cout << "Enter size:" << endl;
//    cin >> size;

    auto start_time = std::chrono::high_resolution_clock::now();

//    for(int i = 0; i < size; i++){
//        int number = rand()%100;
//        linkedList.push(number);
//    }
//    for(int i = 0; i < 1500; i++){
//        linkedList.pop();
//    }

    linkedList.push(8);
    linkedList.push(10);
    linkedList.push(5);
    linkedList.push(11);
    linkedList.push(15);
    linkedList.push(23);
    linkedList.push(6);
    linkedList.push(18);
    linkedList.push(20);
    linkedList.push(17);
    linkedList.display();
    linkedList.pop();
    linkedList.pop();
    linkedList.pop();
    linkedList.pop();
    linkedList.pop();
    linkedList.display();
    linkedList.push(4);
    linkedList.push(30);
    linkedList.push(3);
    linkedList.push(1);
    linkedList.display();

    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    cout << "Time for duration " << duration.count();

}
