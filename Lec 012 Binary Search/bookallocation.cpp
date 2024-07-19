// https://bit.ly/3GiCqY0 

#include<vector>
using namespace std;

bool ispossible(vector<int> arr, int n, int m, int mid){
    int studentcount=1;
    int pagesum=0;
    for(int i=0; i<n; i++){
        if(pagesum+arr[i]<=arr[mid]){
            pagesum += arr[i];

        }
        else{
            studentcount++;
            if(studentcount>m || arr[i]>mid){ //condition student ki value given sai jyada na ho
                return false;
            }
            pagesum = arr[i]; //next studdent ka yaha sai shuru hogaya
        }

    }
    return true;



}

int allocatebooks(vector<int> arr, int n, int m){ //m=size of student
    int start=0;
    int sum = 0;

    for(int i=0; i<n; i++){
        sum+=arr[i];
    }
    int end=sum; //range ban gayi (eg 0 sai 100)
    int ans=-1;
    int mid = start+(end-start)/2;
    while(start<=end){
        if(ispossible(arr,n,m,mid)){
            ans=mid;
            end=mid-1;  
        }
        else{
            start=mid+1; //agar let mid=50 bhi nhi ban rhi hai toh usse piche wali bhi nhi banengi
        }
        mid=start+(end-start)/2;
    }
    return mid;
}