int lengthOfLIS(ll nums[],int n)
{
    vector<ll> ans;
    ans.push_back(nums[0]);
    for (int i = 1; i < n; i++) {
        if (nums[i] > ans.back()) {
            ans.push_back(nums[i]);
        }
        else {
            int low = lower_bound(ans.begin(), ans.end(),nums[i])- ans.begin();
            ans[low] = nums[i];
        }
    }
    return ans.size();
}
