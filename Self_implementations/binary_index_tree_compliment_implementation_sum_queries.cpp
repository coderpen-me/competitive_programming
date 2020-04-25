class NumArray {
public:
    NumArray(vector<int> &nums):tem(nums) {
        bit.resize(nums.size()+1, 0);
        for(int i =0; i< nums.size(); i++)
            add(i+1, nums[i]);
    }
    
    void add(int index, int d)
    {
        while(index <= tem.size())
        {
            bit[index] += d;
            index += (index&-index);
        }
    }
    
    int sum(int index)
    {
        int ans = 0;
        while(index > 0)
        {
            ans += bit[index];
            index -= (index&-index);
        }
        return ans;
    }
    
    void update(int i, int val) {
        add(i+1, val-tem[i]);
        tem[i] = val;
    }
 
    int sumRange(int i, int j) {
        return sum(j+1) - sum(i);
    }
private:
    vector<int> bit;
    vector<int>& tem;
};