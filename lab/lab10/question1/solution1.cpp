#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

bool contain(vector<int> v, int n){
	for(int i = 0; i < v.size(); ++i){
		if(n == v[i])
			return true;
	}
	return false;
}

bool containsDuplicate (vector<int>& nums){
	//Type your answer here:
	sort(nums.begin(), nums.end());
	// cout << *unique(nums.begin(), nums.end()) << endl;
	if(nums.size() != unique(nums.begin(), nums.end()) - nums.begin())
		return true;
	return false;
}