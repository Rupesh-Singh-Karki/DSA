#include <bits/stdc++.h> 
#include<queue>
class node{
    public:
    int data;
    int i;
    int j;

    node(int data, int row, int col){
        this->data = data;
        i = row;
        j = col;
    }
};

class compare{
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<node*, vector<node*>, compare> minheap;

    //step1 sare arrays k first element indsert h
    for(int i=0;i<k;i++){
        node* tmp = new node(kArrays[i][0],i,0);
        minheap.push(tmp);
    }

    vector<int> ans;

    while(!minheap.empty()){
        node* tmp = minheap.top();

        ans.push_back(tmp->data);
        minheap.pop();

        int i = tmp->i;
        int j = tmp->j;

        if(j+1<kArrays[i].size()){ //smallest elemnt ans mai dalne kai baad pop phir uska next element array ka minheap mai dal diya
            node* next = new node(kArrays[i][j+1],i,j+1);
            minheap.push(next);
        }
    }

    return ans;
}
