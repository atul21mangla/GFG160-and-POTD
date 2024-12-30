// https://www.geeksforgeeks.org/problems/count-pairs-with-given-sum--150253/1

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Code here
        int count=0;
        unordered_map<int,int>mpp;
        for(int x:arr){
            int cmp = target-x;
            if(mpp.find(cmp)!=mpp.end()){
                count += mpp[cmp];
                mpp[x]++;
            }
            else{
                mpp[x]++;
            }
        }
        return count;
    }
};
