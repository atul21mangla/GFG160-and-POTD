// https://www.geeksforgeeks.org/problems/longest-distinct-characters-in-string5848/1

class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int n = s.length();
        int res = INT_MIN;
        unordered_set<char>st;
        int i=0;
        for(int j=0;j<n;j++){
            if(st.find(s[j])!=st.end()){
                while(i<j and st.count(s[j])!=0){
                    st.erase(s[i]);
                    i++;
                }
            }
            st.insert(s[j]);
            res = max(res,static_cast<int>(st.size()));
        }
        return res;
    }
};
