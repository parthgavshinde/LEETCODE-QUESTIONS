class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = INT_MIN;

        for (int x : piles) {
            if (x > high) {
                high = x;
            }
        }

   
        while (low < high) {

            int speed = (low + high) / 2;
            int hours = 0 ;
            for (int i = 0; i < piles.size(); i++) {
                
                hours += (piles[i]+speed-1)/speed;
                
            }
            if(hours>h)
            {
                low = speed +1; 
            }
            else
            {
                high = speed;
            }
        }

        return low;
    }
};