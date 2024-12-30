// problem link - https://www.geeksforgeeks.org/problems/key-pair5616/1

// User function template for C++
class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // sort(arr.begin(),arr.end());
        // int i=0 , j=arr.size()-1;
        // while(i<j){
        //     if(arr[j]-arr[i]==target)return true;
        //     else if(arr[j]-arr[i]>target)j--;
        //     else i++;
        // }
        // return false;
        unordered_map<int,int>mpp;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>target)continue;
            if(mpp.find(arr[i])!=mpp.end())return true;
            else
            mpp[target-arr[i]] = arr[i];
        }
        return false;
    }
};
