// [Expected Approach 1] Using Hash Set - O(n^2) Time and O(n) Space

// Reference - https://www.geeksforgeeks.org/3-sum-count-all-triplets-with-given-sum/?ref=ml_lbp

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Returns number of pairs in arr[idx..n-1] with sum equal
// to 'target'
int getPairsCount(vector<int> &arr, int idx, int target) {
    unordered_map<int, int> freq;
    int count = 0;

    for (int i = idx; i < arr.size(); i++) {

        // Check if the complement (target - arr[i])
        // exists in the map. If yes, increment count
        if (freq.find(target - arr[i]) != freq.end()) {
            count += freq[target - arr[i]];
        }

        // Increment the frequency of arr[i]
        freq[arr[i]]++;
    }
    return count;
}

// Returns count of triplets with sum = target
int countTriplets(vector<int> &arr, int target) {
    int cnt = 0;
    int n = arr.size();

    // Iterating over the first element of the triplet
    for (int i = 0; i < n - 2; i++) {
        int rem = target - arr[i];
        cnt += getPairsCount(arr, i + 1, rem);
    }
    return cnt;
}

int main() {
    vector<int> arr = {0, -1, 2, -3, 1};
    int target = -2;

    cout << countTriplets(arr, target);
    return 0;
}
