class Solution {
public:
    int numSteps(string s) {
        int index = 0;
        while (isOne(s)) {
            if (isEven(s)) {
                divideByTwo(s);
            } else {
                addOne(s);
            }
            index++;
        }
        return index;
    }

    bool isOne(string &s) {
        for (int i=0; i<s.size()-1; i++) {
            if (s[i] == '1') {
                return true;
            }
        }
        return false;
    }

    bool isEven(string &s) {
        return s[s.size()-1] == '0';
    }

    void addOne(string &s) {
        int size = s.size();
        for(int i=size-1; i>=0; i--) {
            char ch = s[i];
            if (ch == '0') {
                s[i] = '1';
                return;
            } else {
                s[i] = '0';
            }
        }
        s = '1' + s;
    }

    void divideByTwo(string &s) {
        int l = s.size();
        int starting = l-2;
        for(int i=starting; i>=0; i--) {
            s[i+1] = s[i];
        }
        s[0] = '0';
    }

    // int numSteps(string s) {
    //     return numSteps(binaryToDecimal(s));
    // }

    // long long binaryToDecimal(string s) {
    //     long long result = 0;

    //     int l = s.size();
    //     for (int i=l-1; i>=0; i--) {
    //         char ch = s[i];
    //         result += (ch == '0') ? 0 : pow(2, l-1-i);
    //     }
    //     return result;
    // }

    // long long pow(int base, int power) {
    //     if (power <= 0) {
    //         return 1;
    //     }
    //     return pow(base, power - 1) * base;
    // }

    // int numSteps(int n) {
    //     int i = 0;
    //     while (n != 1) {
    //         if (n % 2) {
    //             n++;
    //         } else {
    //             n /= 2;
    //         }
    //         i++;
    //     }
    //     return i;
    // }
};