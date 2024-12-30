//  https://leetcode.com/problems/majority-element-ii/submissions/1492558793/

// Brute force - O(N^2)

vector<int> findMajority(vector<int> &arr) {
    int n = arr.size();
    vector<int> res;

    for (int i = 0; i < n; i++) {
        
        // Count the frequency of arr[i]
        int cnt = 0;
        for (int j = i; j < n; j++) {
            if (arr[j] == arr[i])
                cnt += 1;
        }
      
        // Check if arr[i] is a majority element
        if (cnt > (n / 3)) {
          
            // Add arr[i] only if it is not already
            // present in the result
            if (res.size() == 0 || arr[i] != res[0]) {
                res.push_back(arr[i]);
            }
        }
      
        // If we have found two majority elements, 
        // we can stop our search
    }

    return res;
}

// [Better Approach] Using Hash Map or Dictionary - O(n) Time and O(n) Space

vector<int> findMajority(vector<int> &arr) {
    int n = arr.size();
    unordered_map<int, int> freq;
    vector<int> res;

    // find frequency of each number
    for (int ele : arr)
        freq[ele]++;

    // Iterate over each key-value pair in the hash map
    for (auto it : freq) {
        int ele = it.first;
        int cnt = it.second;

        // Add the element to the result, if its frequency
        // if greater than floor(n/3)
        if (cnt > n / 3)
            res.push_back(ele);
    }
    return res;
}

// [Expected Approach] Boyer-Moore’s Voting Algorithm - O(n) Time and O(1) Space

int n = arr.size();
vector<int>ans;
int cd1 = -1 , cd2 = -1;
int cnt1 = 0 , cnt2 = 0;
for(int x:arr){
    if(x==cd1){
        cnt1++;
    }
    else if(x==cd2)cnt2++;
    
    else if(cnt1==0){
        cd1 = x;
        cnt1++;
    }
    else if(cnt2==0){
        cd2 = x;
        cnt2++;
    }
    else{
        cnt1--;
        cnt2--;
    }
}
cnt1=0,cnt2=0;
for(int x:arr){
    if(x==cd1)cnt1++;
    else if(x==cd2)cnt2++;
}
if(cnt1>n/3)ans.push_back(cd1);
if(cnt2>n/3)ans.push_back(cd2);
sort(ans.begin(),ans.end());
return ans;
