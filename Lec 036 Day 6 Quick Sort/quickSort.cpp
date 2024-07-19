#include<iostream>
using namespace std;


int partition( int arr[], int s, int e) {

    int pivot = arr[s];

    int cnt = 0;
    for(int i = s+1; i<=e; i++) {
        if(arr[i] <=pivot) {
            cnt++;
        }
    }

    //place pivot at right position
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]); //yaha pivot apni desired place par aa chuka hai

    //left and right wala part smbhal lete h 
    int i = s, j = e;

    while(i < pivotIndex && j > pivotIndex) {

        while(arr[i] <= pivot) 
        {
            i++; //i tab tak badaya jab tak hume pivot sai badi value nhi mil gyi
        }

        while(arr[j] > pivot) {
            j--;//same j ko bhi kam kiya jab tak pivot sai choti value nhi mil gyi
        }

        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]); //yaha par i and j ko swap kar diya
        }

    }

    return pivotIndex; //yaha pivot ka idex return kar diya

}

void quickSort(int arr[], int s, int e) {

    //base case
    if(s >= e) 
        return ;

    //partitioon karenfe
    int p = partition(arr, s, e);

    //left part sort karo
    quickSort(arr, s, p-1);

    //right wala part sort karo
    quickSort(arr, p+1, e);

}

int main() {

    int arr[10] = {4,6,8,14,9,3,6,18,1,13};
    int n = 10;

    quickSort(arr, 0, n-1);

    for(int i=0; i<n; i++) 
    {
        cout << arr[i] << " ";
    } cout << endl;


    return 0;
}