class Solution {
public:
    inline long long invert(int val) {
        return (long long)val * -1;
    }
    
    int divide(int dividend, int divisor) {
        long long target_divisor = divisor;
        long long target_dividend = dividend;
        if (target_divisor == 0) {return dividend;}
        bool minus = false;
        if (target_divisor < 0) {
            target_divisor = invert(target_divisor);
            minus = not minus;
        }
        if (target_dividend < 0) {
            target_dividend = invert(target_dividend);
            minus = not minus;
        }
            
            
        long long count = 0;
        if (target_divisor == 1 or target_divisor == -1) {
            return minus ? invert(target_dividend) : dividend == -2147483648 ? 2147483647 : target_dividend;
        }
        
        while (target_dividend >= target_divisor) {
            ++count;            
            target_dividend -= target_divisor;
        }
        
        return minus ? invert(count) : count;
    }
};
