#include <iostream>
#include <chrono>

using namespace std;

int stack_array[3000];
int top = -1;

void push(int item){
    int length = size(stack_array);

    if(top == length-1)
        cout << "Array is full" << endl;
    else{
        top++;
        stack_array[top] = item;
    }
}

int pop(){
    if(top ==-1)
        cout << "Stack is empty";
    else{
        int value = stack_array[top];
        top--;
        return value;
    }
}
void display(){
    for(int i = 0; i <= top; i++)
        cout << stack_array[i] << ' ';
    cout << endl;
}

int main(){

    srand(time(nullptr));

    auto start_time = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < size(stack_array); i++){
        int number = rand()%100;
        push(number);
    }
    for(int i = 0; i < 100; i++){
        pop();
    }


//    push(8);
//    push(10);
//    push(5);
//    push(11);
//    push(15);
//    push(23);
//    push(6);
//    push(18);
//    push(20);
//    push(17);
//    display();
//    pop();
//    pop();
//    pop();
//    pop();
//    pop();
//    display();
//    push(4);
//    push(30);
//    push(3);
//    push(1);
//    display();


    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    cout << "Time taken by operation: " <<duration.count();

}


