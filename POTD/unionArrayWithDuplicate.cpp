// problem link - https://www.geeksforgeeks.org/problems/union-of-two-arrays3538/1

class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_set<int>s(a.begin(),a.end());
        for(int x:b){
            if(s.find(x)==s.end()){
                s.insert(x);
            }
        }
        return s.size();
    }
};

// Given two arrays a[] and b[], the task is to find the number of elements in the union between these two arrays.

// The Union of the two arrays can be defined as the set containing distinct elements from both arrays. If there are repetitions, then only one element occurrence should be there in the union.

// Note: Elements of a[] and b[] are not necessarily distinct.

// Examples

// Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3]
// Output: 5
// Explanation: Union set of both the arrays will be 1, 2, 3, 4 and 5. So count is 5.

// Input: a[] = [85, 25, 1, 32, 54, 6], b[] = [85, 2] 
// Output: 7
// Explanation: Union set of both the arrays will be 85, 25, 1, 32, 54, 6, and 2. So count is 7.

// Input: a[] = [1, 2, 1, 1, 2], b[] = [2, 2, 1, 2, 1] 
// Output: 2
// Explanation: We need to consider only distinct. So count of elements in union set will be 2.

