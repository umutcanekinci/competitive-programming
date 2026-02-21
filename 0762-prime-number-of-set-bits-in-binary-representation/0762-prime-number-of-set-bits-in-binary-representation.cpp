class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        
        // 20'ye kadar olan asal sayıların bitmask hali:
        // (1 << 2) | (1 << 3) | (1 << 5) | ... şeklinde
        // Bu sayı ikilik sistemde asalların olduğu pozisyonlarda 1 içerir.
        unsigned int primeMask = 0b10100010100010101100; 

        for (int i = left; i <= right; ++i) {
            // 1. Bit sayısını tek seferde hesapla
            int bits = __builtin_popcount(i);
            
            // 2. Bu sayı asal mı? Mask üzerinden kontrol et (O(1))
            if ((primeMask >> bits) & 1) {
                count++;
            }
        }
        
        return count;
    }
};