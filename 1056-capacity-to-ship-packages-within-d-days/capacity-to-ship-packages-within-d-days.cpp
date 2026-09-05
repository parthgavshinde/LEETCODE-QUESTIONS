class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = INT_MIN;
        int high = 0 ;
        int minC = 0 ;
        for(int i : weights)
        {
            low = max(low,i);
            high += i ;
        }
        int mid = 0 ;
        while(low<high)
        {
            mid = low + (high-low)/2;
            int day = 0 ;
            int c = 0 ;
            int l = 1 ;
            while(day<weights.size())
            {
                if((c+weights[day])>mid)
                {
                    l++;
                    c = 0 ;
                }
                c += weights[day];
                day++;

            }
            if(l>days)
            {
               low = mid+1;
            }
            else
            {
                
                high =mid;
            }



        }
        return low;
    }
};