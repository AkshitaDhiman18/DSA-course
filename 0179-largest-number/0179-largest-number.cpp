class Solution {
public:
    // Merge Function
    void merge(vector<string> &strs, int low, int mid, int high) {
        vector<string> temp;   // merged result yahan store hoga
        
        int left = low;
        int right = mid + 1;
        
        // Step 1: Dono halves ko compare karke temp mein daalo
        while (left <= mid && right <= high) {
            if (strs[left] + strs[right] > strs[right] + strs[left]) {
                temp.push_back(strs[left]);
                left++;
            } else {
                temp.push_back(strs[right]);
                right++;
            }
        }
        
        // Step 2: Agar left half mein kuch bacha hai, usko daal do
        while (left <= mid) {
            temp.push_back(strs[left]);
            left++;
        }
        
        // Step 3: Agar right half mein kuch bacha hai, usko daal do
        while (right <= high) {
            temp.push_back(strs[right]);
            right++;
        }
        
        // Step 4: temp ko wapas original strs mein copy karo
        for (int i = low; i <= high; i++) {
            strs[i] = temp[i - low];
        }
    }
    
    // Merge Sort Function
    void mergesort(vector<string> &strs, int low, int high) {
        if (low >= high) return;   // base case: single element ya invalid range
        
        int mid = low + (high - low) / 2;
        
        mergesort(strs, low, mid);        // left half sort karo
        mergesort(strs, mid + 1, high);   // right half sort karo
        merge(strs, low, mid, high);      // dono sorted halves ko merge karo
    }
    
    // Main Function jo LeetCode call karega
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Numbers ko strings mein convert karo
        vector<string> strs;
        for (int i = 0; i < n; i++) {
            strs.push_back(to_string(nums[i]));
        }
        
        // Step 2: Custom merge sort call karo
        mergesort(strs, 0, n - 1);
        
        // Step 3: Sorted strings ko concatenate karo
        string result = "";
        for (int i = 0; i < n; i++) {
            result += strs[i];
        }
        
        // Step 4: Edge case - agar sabse pehla character '0' hai, matlab saare zeros hain
        if (result[0] == '0') {
            return "0";
        }
        
        return result;
    }
};