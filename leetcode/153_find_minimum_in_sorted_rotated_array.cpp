class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        return findMin_approach2(nums);
    }
    int findMin_approach1(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, high = n - 1;
        if (nums[0] <= nums[n - 1])
        {
            return nums[0];
        }
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[mid + 1])
            {
                return nums[mid + 1];
            }
            if (nums[mid - 1] > nums[mid])
            {
                return nums[mid];
            }
            if (nums[low] > nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return -1;
    }

    int findMin_approach2(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, high = n - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[mid + 1])
            {
                return nums[mid + 1];
            }
            if (mid > 0 && nums[mid - 1] > nums[mid])
            {
                return nums[mid];
            }
            if (nums[mid] > nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return nums[low];
    }
};