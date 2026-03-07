class Solution {
public:
    /*
        1. Make odds 1 evens 0
        2. Make odds 0 evens 1
    */

int minFlips(string s) {
        int n = s.size();
        string doubled = s + s;
        
        // target1: 010101...
        // target2: 101010...
        int diff1 = 0, diff2 = 0;
        int res = n; // Max possible flips is n
        
        for (int i = 0; i < 2 * n; i++) {
            // Check diff against target1 (0 at even index, 1 at odd)
            if (doubled[i] != (i % 2 == 0 ? '0' : '1')) diff1++;
            
            // Check diff against target2 (1 at even index, 0 at odd)
            if (doubled[i] != (i % 2 == 0 ? '1' : '0')) diff2++;
            
            // Once the window is size n, start tracking the minimum
            if (i >= n) {
                // Remove the character that is no longer in the window (at index i - n)
                if (doubled[i - n] != ((i - n) % 2 == 0 ? '0' : '1')) diff1--;
                if (doubled[i - n] != ((i - n) % 2 == 0 ? '1' : '0')) diff2--;
            }
            
            // Only update result when we have a full window of size n
            if (i >= n - 1) {
                res = min({res, diff1, diff2});
            }
        }
        
        return res;
    }

    // int minFlips(string s) {
    //     int l = s.size();
    //     int val = l;
    //     int startsWith[2] = {0, 0};
        
    //     for (int i=0; i<l; i++) {
    //         startsWith[0] = 0;
    //         startsWith[1] = 0;
            
    //         for(int j=i; j<i+l; j++) {
    //             char ch = s[j%l];
    //             if(j%2) {
    //                 startsWith[ch == '0']++;
    //             } else {
    //                 startsWith[ch == '1']++;
    //             }
    //         }           
    //         val = min({val, startsWith[0], startsWith[1]});
    //     }
    //     return val;
    // }
};