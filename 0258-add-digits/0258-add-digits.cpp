class Solution {
public:
    int addDigits(int num) {
        if(num==0) return 0;
        while(num>=10)
        {
            int ans=0;
            while(num>0)
            {
                ans+=num%10;
                num=num/10;
            }
            num=ans;
        }
        return num;
    }
};