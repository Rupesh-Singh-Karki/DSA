class Solution {
public:
    int countPrimes(int n) {
        int count=0;
        vector<bool> prime(n+1, true); //marking all numbers prime
        prime[0]= prime[1]=0; //special case

        for(int i=2; i<n; i++ ){
            if(prime[i]){
                count++;
                for(int j=2*i; j<n; j=j+i){ //making all numbers in its table of respective value of  i non prime
                    prime[j]=0;
                }
            }
        }

        return count;

        
    }
};