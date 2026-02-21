class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int sum = 0;
        for (int i=left; i<=right; i++) {
            sum += isPrime(number_of_bits(i));
        }
        return sum;
    }

    bool isPrime(int n) {
  
        // Check if n is 1 or 0
        if (n <= 1)
            return 0;

        // Check if n is 2 or 3
        if (n == 2 || n == 3)
            return 1;

        // Check whether n is divisible by 2 or 3
        if (n % 2 == 0 || n % 3 == 0)
            return 0;
        
        // Check from 5 to square root of n
        // Iterate i by (i+6)
        for (int i = 5; i *i<=n; i = i + 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return 0;

        return 1;
    }

    int number_of_bits(int i) {
        int sum = 0;
        while(i != 0) {
            sum += i % 2;
            i /= 2; 
        }
        return sum;
    }
};