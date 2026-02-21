class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size();
        int l2 = nums2.size();
        int total = l1 + l2;
        int m = total / 2;
        bool isOdd = (l1 + l2) % 2;
        int last;
        int i = 0;
        while (!(nums1.size() == 0 && nums2.size() == 0)) {
            int n;
            if (nums1.size() == 0) {
                n = nums2.back();
                nums2.pop_back();
            }
            else if (nums2.size() == 0) {
                n = nums1.back();
                nums1.pop_back();
            }
            else if (nums1.back() > nums2.back()) {
                n = nums1.back();
                nums1.pop_back();
            }
            else {
                n = nums2.back();
                nums2.pop_back();
            }
            total--;
            if (total == m) {
                if (isOdd) {
                    return n;
                }
                last = n;
            }
            if (!isOdd && total == m-1) {
                return (double)(last + n) / 2;
            }
        }
        return 0;
    }
};