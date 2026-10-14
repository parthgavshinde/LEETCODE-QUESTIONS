class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // If the required sum exceeds the maximum possible sum (all 9s)
        if (sum > 9LL * num) {
            return "";
        }
        
        int nines = sum / 9;
        int remainder = sum % 9;
        int zeros = num - nines - (remainder > 0 ? 1 : 0);
        
        string result(nines, '9');
        if (remainder > 0) {
            result += to_string(remainder);
        }
        result.append(zeros, '0');
        
        return result;
    }
};
