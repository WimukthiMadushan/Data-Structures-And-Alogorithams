#include <iostream>
using namespace std;

void swap(int array[],int first, int second){
    int temp = array[first];
    array[first] = array[second];
    array[second] = temp;
}
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    int largest = root;
    int left = 2*root +1 ;
    int right = 2*root + 2;

    if(left <= n-1 && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= n-1 && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest != root){
        swap(arr,largest,root);
        heapify(arr, n, largest);
    }
}
void buildHeap(int array[], int size){
    for(int i = size/2-1; i >= 0 ; i--){
        heapify(array, size,i);
    }
}
// implementing heap sort
void heapSort(int arr[], int n)
{
    buildHeap(arr,n);
    for(int i = n - 1; i >=0; i--){
        swap(arr,0,i);
        heapify(arr,i,0);
    }
    // build heap
    // extracting elements from heap one by one
}
/* print contents of array */
void displayArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
// main program
int main(){
    cout << "Enter size of the array:";
    int size;
    cin >> size;
    int heap_arr[size];
    for(int i = 0; i < size; i++){
        cout << "Enter element:";
        cin >> heap_arr[i];
    }

    int n =  size;
    cout<<"Input array"<<endl;
    displayArray(heap_arr,n);

    heapSort(heap_arr, n);

    cout << "Sorted array"<<endl;
    displayArray(heap_arr, n);

}
