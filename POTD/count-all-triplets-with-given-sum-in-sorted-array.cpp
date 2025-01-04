// https://www.geeksforgeeks.org/problems/count-all-triplets-with-given-sum-in-sorted-array/1

// C++ program to count all triplets having sum equal to
// target by exploring all possible triplets

// EXPLANATION !!!!!!!! ---------------------------------------------------------

// Using Two Pointers Technique
// The idea is to fix the first element of the triplet at index i and then using two pointers technique to count the other two elements. For each index i, initialize left pointer to i + 1 and right pointer to n - 1.

// For each triplet, calculate the sum as arr[i] + arr[left] + arr[right] and evaluate:

// If sum = target: A valid triplet is found. Additionally, handle duplicates by counting the frequencies of arr[left] and arr[right] and updating the result accordingly. Then move both pointers to the next distinct values.
// If sum < target: Increment the left pointer to explore larger values and increase the sum.
// If sum > target: Decrement the right pointer to explore smaller values and decrease the sum.


#include <iostream>
#include <vector>
using namespace std;

int countTriplets(vector<int> &arr, int target) {
    int n = arr.size();
    int res = 0;

    // Iterate through each element as the first element of the triplet
    for (int i = 0; i < n - 2; i++) {
        int left = i + 1, right = n - 1;

        // Use two-pointer approach to find triplets
        while (left < right) {

            // Calculate the sum of the triplet
            int sum = arr[i] + arr[left] + arr[right];

            // If sum is smaller, move to bigger values
            if (sum < target) {
                left += 1;
            }
          
            // If sum is greater, move to smaller values
            else if (sum > target) {
                right -= 1;
            }
            else if (sum == target) {
                int ele1 = arr[left], ele2 = arr[right];
                int cnt1 = 0, cnt2 = 0;

                // Count frequency of the current value at 'left'
                while (left <= right && arr[left] == ele1) {
                    left++;
                    cnt1++;
                }

                // Count frequency of the current value at 'right'
                while (left <= right && arr[right] == ele2) {
                    right--;
                    cnt2++;
                }

                // If both the elements are same, then count of
                // pairs = the number of ways to choose 2
                // elements among cnt1 elements
                if (ele1 == ele2)
                    res += (cnt1 * (cnt1 - 1)) / 2;

                // If the elements are different, then count of
                // pairs = product of the count of both elements
                else
                    res += (cnt1 * cnt2);
            }
        }
    }
    return res;
}

int main() {
    vector<int> arr = {-3, -1, -1, 0, 1, 2};
    int target = -2;

    cout << countTriplets(arr, target) << endl;
    return 0;
}
