class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size=digits.size();

        for( int i=size-1;i>=0;i--)
        {
            int dig = digits[i]+1;
            if(dig==10)
            {
                digits[i]=0;
            }
            else {
                digits[i]=dig;
                return digits;
                }
        }

        digits.push_back(1);
        reverse(digits.begin(),digits.end());
        return digits;
    }
};