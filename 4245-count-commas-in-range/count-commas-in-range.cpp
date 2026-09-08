class Solution {
public:
    int countCommas(int n) {
        int count = 0;

        for (int i = 1; i <= n; i++) {
            int num = i;

            while (num >= 1000) {
                count++;
                num /= 1000;
            }
        }

        return count;
    }
};