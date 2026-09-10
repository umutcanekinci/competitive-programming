class Solution {
public:
    int reverse(int x) {
        long int r = 0;
        int base = 10;
        
        while(x!=0) {
            int last = x%base;
            // r*base+last<=MAX
            // r<=max-last/base
            if (x<0 && r < (numeric_limits<int>::min()-last)/base ||
                x > 0 && r > (numeric_limits<int>::max()-last)/base) {
                return 0;
            }
            r = r*base+last;
            x = x/base;
        }

        return r;
    }
};
