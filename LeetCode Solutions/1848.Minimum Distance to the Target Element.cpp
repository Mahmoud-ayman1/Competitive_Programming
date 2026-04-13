class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int l=start,r=start;
        while(l>=0||r<nums.size()){
            if(l>=0&&nums[l]==target) return abs(start-l);
            if(r<nums.size()&&nums[r]==target) return abs(start-r);
            l--;
            r++;
        }
        return -1;
    }
};
