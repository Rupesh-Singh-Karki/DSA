#include <bits/stdc++.h> 
class NStack
{
    int *arr;
    int *top;
    int *next;
    int freespot;
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        arr = new int[S];
        top = new int[N];
        next = new int[S];

        for(int i =0; i<N; i++){
            top[i]=-1;
        }

        for(int i =0 ; i<S; i++){
            next[i]=i+1;
        }
        next[S-1] = -1;
        freespot = 0;

    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        //checking overflow
        if(freespot==-1){
            return false;
        }
        //using freespot
        int index = freespot;
        //updating freespot
        freespot = next[index];

        //assigning value of stack;
        arr[index]=x;

        //updating next;
        next[index]=top[m-1];

        top[m-1]=index;

        return true;

    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        //check underflow condition
        if(top[m-1] == -1) {
            return -1;
        }
        //index mai us stack ka top ka index le liya
        int index = top[m-1];
        
        top[m-1] = next[index];
        next[index] = freespot;
        //end mai free spot ko index kai value par set kardiya
        freespot = index;
        return arr[index];
    }
};