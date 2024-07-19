#include<queue>
int getKthLargest(vector<int> &arr, int k)
{
	priority_queue<int, vector<int>, greater<int>> mini;

    int size = arr.size();
	for(int i=0;i<size;i++){
		int sum =0;
		for(int j=i;j<size;j++){
			sum+=arr[j];
			if(mini.size()<k){
				mini.push(sum);
			}
			else{
				if(sum>mini.top()){ //if sum greater toh pop and push
                //min element pop ho jayega end mai humare pas 2 sum pade honge unmai sai chota wala 2nd largest hoga
					mini.pop();
					mini.push(sum);
				}
			}
		}
	}


    int ans = mini.top();
    return ans;
}