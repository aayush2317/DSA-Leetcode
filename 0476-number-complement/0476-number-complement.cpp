class Solution {
public:
    int findComplement(int num) {
        int a[32],i=0;
        while(num>0)
        {
            a[i++]=1-num%2;
            num=num/2;
        }
        int result=0;
        long long power=1;
        for(int j=0;j<i;j++)
        {
            result+=a[j]*power;
            power*=2;
        }
        return result;
    }
};