class Solution {
public:
    int lengthOfLastWord(string s) {

        int count = 0 ; 
        int c = 0 ;
        for(int i = s.size()-1 ; i>=0; i--)
        {
            if(s[i] == ' ' && c==1 )
            {
                break;
            }
            if(s[i]!= ' ')
            {
                count++;
                c = 1 ; 
            }
        }
        return count ; 
    }
};