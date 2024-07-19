#include<vector>
using namespace std;

void insertionSort(int n, vector<int> &arr){
    
    for(int i = 1; i<n; i++) {
        int temp = arr[i];
        int j = i-1;
        for(; j>=0; j--) {
            
            if(arr[j] > temp) {
                //shift
                arr[j+1] = arr[j];  //yeh hone kai baad j ki value -1 ho jayegio tabhi neeche j+1 ko temp diya hai
            }
            else { // ruk jao
                break;
            }
            
        }
        //copy temp value
        arr[j+1] = temp;  //j jaha pahucha hoga usse ek pehle hi value put hogi kyuki us j par toh
        //loop exit ya break hogyi hogi
        
    } 
}