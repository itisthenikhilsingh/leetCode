class Solution {
public:
   
    int fib(int n) {
        //this is in in tabularatio way;
        if (n<2) return n;

        int prev=0;
        int prev2=1;

        for(int i =1;i<n;i++)
        {
            int cur=prev+prev2;
            prev=prev2;
            prev2= cur;

        }
        return prev2;
        
    }
};