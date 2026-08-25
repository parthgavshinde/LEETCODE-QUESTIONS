class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int> s(nums.begin(),nums.end());
        int maxi = 0;
        for(int x: s)
        {
            if(s.find(x-1)==s.end())
            {
                int curr = x;
                int count = 1 ;

                while(s.find(curr+1)!=s.end())
                {
                    count++;
                    curr++;
                }

                maxi= max(maxi,count); 

            }
        }
        return maxi;

    }
};