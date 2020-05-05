class Solution {
public:
    
    int BST(int left, int right) {
        if (left > right) return -1;
        
        if (right -left <= 1) {
            if (isBadVersion(left))
                return left;
            else if (isBadVersion(right))
                return right;
            else
                return -1;
        }
        
        int mid = left + (right-left)/2;
        if (!isBadVersion(mid)) {
            return BST(mid+1, right);
        }
        else {
            return BST(left,mid);
        }
    }
    
     int firstBadVersion(int n) {
         int result  = -1;
         if (n <= 0) return result;
         return BST(1,n);
     }
    
};