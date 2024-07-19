#include<iostream>
using namespace std;

int countDistinctWays(int nStairs) {
    
    //base case
    if(nStairs<0){
        return 0;
    }
    if(nStairs==0){
        return 1;
    }
//ya to ham last stair mai 2nd last stair sai 1 step mai ayenge ya phir 3rd last sai 2 step mai.
    return countDistinctWays(nStairs-1)+countDistinctWays(nStairs-2);
}