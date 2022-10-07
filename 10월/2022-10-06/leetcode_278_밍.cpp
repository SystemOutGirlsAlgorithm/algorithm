// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        unsigned int mid, first = 1, last = n;
        int minbad;
        while (first <= last) {
            mid = (first+last)/2;
            if (isBadVersion(mid)) {
                minbad = (int)mid;
                last = mid - 1;
            }
            else {
                first = mid + 1;
            }
        }
        return minbad;
    }
};