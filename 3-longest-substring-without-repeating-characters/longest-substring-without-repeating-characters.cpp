class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==1) return 1 ; 
        int maxi = 0 ; 
        unordered_set<char> st ; 
        int left  = 0 ;
        for(int i = 0; i<s.size(); i++)
        {
            while(st.find(s[i])!=st.end())
            {
                st.erase(s[left]);
                left++;
            }

            st.insert(s[i]);

           maxi = max(maxi,i-left+1);

        }
        return maxi;
    }
};