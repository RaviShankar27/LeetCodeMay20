class Solution {
public:
    int findComplement(int num) {
        int comp = 0;
        int num_copy = num;
        while(num_copy) {
            comp = comp << 1;
            comp = comp + 1;
            num_copy >>= 1;
        }
        
        return comp ^ num;
    }
};