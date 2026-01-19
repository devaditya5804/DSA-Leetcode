class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target) return mid;

            if(nums[low] <= nums[mid]){ // check if left half is sorted (else BS wont work)
                if(nums[low]<= target && target <= nums[mid]){ // target lies in the left half
                    high = mid-1; // eliminate right half
                }
                else{
                    low = mid +1; // eliminate left half
                }
            }

            else {  // right half is sorted
                if(target >= nums[mid]&& target<=nums[high]){ // target lies?
                    low=mid+1; // eliminate left half
                }
                else{
                    high = mid-1; // eliminate right half
                } 
            }
        }
        return -1;  // target not found
    }
};