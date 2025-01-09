// https://www.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1

#include <iostream>
#include <vector>
using namespace std;

// Function to find a continuous sub-array which adds up to
// a given number.
vector<int> subarraySum(vector<int>& arr, int target) {
    int n = arr.size();
    int sum = 0;
    int i=0;
    for(int j=0;j<n;j++){
        sum += arr[j];
        while(sum>target){
            sum -= arr[i];
            i++;
        }
        
        if(sum==target){
            return {i+1,j+1};
        }
    }
    return {-1};
  }

int main() {
    vector<int> arr = {15, 2, 4, 8, 9, 5, 10, 23};
    int target = 23;
    vector<int> res = subarraySum(arr, target);
    for (int ele : res)
        cout << ele << " ";
    return 0;
}
