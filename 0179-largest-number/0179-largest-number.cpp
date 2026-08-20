class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for(auto x:nums)
        {
            arr.push_back(to_string(x));
        }
        string ans="";
        sort(arr.begin(),arr.end(),[](string a,string b){return a+b>b+a;});
        for(int i=0;i<arr.size();i++)
        {
            ans=ans+arr[i];
        }
        if(arr[0]=="0")
        {
            return "0";
        }

        return ans;
    }
};