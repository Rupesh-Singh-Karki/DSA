#include<iostream>
#include<stack> // ways 1.array 2. kLL
using namespace std;

class stack{
    public:
    int *arr;
    int size;
    int top;

    stack(int size){
        this -> size = size;
        arr = new int[size];
        top-=1;
    }

    //properties
    void push(int element){
        if(size-top>1){
            arr[top]=element;
        }
        else{
            cout<<"stack overflow"<<endl;
        }
    }

    void pop(){
        if(top >=0){
            top --;
        }
        else{
            cout<<"stack undeflow"<<endl;
        }
    }

    int peek(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout<<"stack is empty"<<endl;
        }
    }

    bool isempty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }

};

int main(){


    
    return 0;
}