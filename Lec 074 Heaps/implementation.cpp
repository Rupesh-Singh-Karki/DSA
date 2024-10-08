#include<iostream>
using namespace std;
class heap{
    public:
    int arr[100];
    int size =0;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    /*
    (if array starts from 1 index)
    if node is at ith index then
    left child = 2*i
    right child = 2*i+1
    parent node = i/2
    */

    void insert(int val){
        size = size+1;
        int index = size;
        arr[index] = val;


        while(index>1){
            int parent = index/2;

            if (arr[parent]<arr[index])
            {
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else{
                return;
            }
            
        }
    }

    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i];
        }cout<<endl;
    }

    void deletefromheap(){
        if(size==0){
            cout<<"nothing to delete"<<endl;
            return;
        }

        arr[1]=arr[size];
        size--;

        //take root node to its correct possition
        int i=1;
        while(i<size){
            int leftindex = 2*i;
            int rightindex = 2*i+1;

            if(leftindex<size && arr[i]<arr[leftindex])
            {
                swap(arr[i],arr[leftindex]);
                i=leftindex;
            }
            else if(rightindex<size && arr[i]<arr[rightindex]){
                swap(arr[i],arr[rightindex]);
                i=rightindex;
            }
            else{
                return;
            }
        }
    }
};

void heapify(int arr[],int n,int i){

    int largest =i;
    int left = 2*i;
    int right= 2*i+1;

    if(left<=n && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<=n && arr[largest]<arr[right]){
        largest=right;
    }

    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

void heapsort(int arr[],int n){
    int size =n;
    while(size>1){
        swap(arr[size],arr[1]); //bring largest elemnt to its right place
        size--;

        heapify(arr,size,1); //heapify remaining
    }
}