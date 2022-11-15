7. Reverse integer 

class Solution {
public:
    int reverse(int x) {
        int rem =0;
        int rev =0;
        while(x!=0){
          //  finding ones place
            rem = x % 10;
            // 32 bit
            if (rev > INT_MAX /10 || rev< INT_MIN/10){
                return 0;
            }
            rev = (rev * 10) + rem;
            x = x /10;
        }
        return rev;
    }
};

// TC: O(log(X))
//SC: O(1)
