// https://www.geeksforgeeks.org/problems/count-all-triplets-with-given-sum-in-sorted-array/1

class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        int n = arr.size();
        int ans = 0;
        for(int i=0;i<=n-3;i++){
            int x = arr[i];
            int k = target-x;
            int start = i+1;
            int end = n-1;
            
            // find k in part of array from start to end
            while(start<end){
                int sum = arr[start]+arr[end];
                if(sum<k){
                    start++;
                }
                else if(sum>k){
                    end--;
                }
                else{
                    int e1 = arr[start] , e2 = arr[end];
                    int c1 = 0,c2 = 0;
                    while(start<=end && arr[start]==e1){
                        c1++;
                        start++;
                    }
                    while(start<=end && arr[end]==e2){
                        c2++;
                        end--;
                    }
                    if(e1==e2){
                        ans += (c1*(c1-1))/2;
                    }
                    else{
                        ans += c1*c2;
                    }
                }
            }
        }
        return ans;
    }
};

