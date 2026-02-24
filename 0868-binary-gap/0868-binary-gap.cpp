class Solution {
public:
    int binaryGap(int n) {
        int max = 0, current = 0;
        bool found = false;
        while (n) {
            if (found) {
                current++;
            }

            if (n & 1) {
                if (!found) {
                    found = true;
                } else {
                    if (current > max) {
                        max = current;
                    }
                }
                current = 0;
            }
            n = n >> 1;
        }
        return max;
    }
};