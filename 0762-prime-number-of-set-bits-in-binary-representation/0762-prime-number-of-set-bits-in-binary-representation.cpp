class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int sum = 0;
        for (int i=left; i<=right; i++) {
            cout << number_of_bits(i);
            sum += check(number_of_bits(i));
        }
        return sum;
    }

    bool check(int i) {
        if (i == 0 || i == 1) {
            return 0;
        }

        for(int j=2; j<i; j++) {
            if (i % j == 0) {
                return 0;
            }
        }
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