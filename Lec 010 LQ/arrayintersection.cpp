//You are given two arrays 'A' and 'B' of size 'N' and 'M' respectively.
//Both these arrays are sorted in non-decreasing order. You have to
//find the intersection of these two arrays.
//Intersection of two arrays is an array that consists of all the
//common elements occurring in both arrays.

#include <bits/stdc++.h> 
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	vector<int> ans;
	for(int i=0; i<n; i++){

		for(int p=0; p<m; p++){

			if(arr1[i]==arr2[p]){
				ans.pusb_back(arr1[i]);
				arr2[p]= INT_MIN32; //any no out of constraints
				break;
			}
		}
	}
	return ans;

}