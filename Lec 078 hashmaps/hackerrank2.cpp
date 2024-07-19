#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

int longestSubarray(vector<int>& nums) {
    int left = 0, right = 0, maxLen = 0;
    unordered_map<int, int> freq;

    while (right < nums.size()) {
        freq[nums[right]]++;

        // Check if we have more than two distinct values or if the values differ by more than 1
        while (freq.size() > 2 || (freq.size() == 2 && abs(freq.begin()->first - next(freq.begin())->first) > 1)) {
            freq[nums[left]]--; //decrementing the frequency of distinct number from starting
            if (freq[nums[left]] == 0) {
                freq.erase(nums[left]);
            }
            left++; //remeber element accesed is in the array not unordere_list
            
        }

        maxLen = max(maxLen, right - left + 1);
        right++;
    }

    return maxLen;
}

int main() {
    vector<int> nums = {1, 2, 2, 2,3,3,3, 3, 4,4,4,4, 5};
    cout << "Length of the longest subarray: " << longestSubarray(nums) << endl;  // Output should be 4
    return 0;
}

//dry run
/*
Let's dry run the code to understand how it processes the input and computes the result. We'll trace the values of the variables as the algorithm progresses through the input array.

**Code Overview:**
The goal of the function `longestSubarray` is to find the length of the longest contiguous subarray containing at most two distinct integers with the difference between those two integers being no more than 1.

**Initial Setup:**
- `left = 0`
- `right = 0`
- `maxLen = 0`
- `freq` is an empty unordered map

**Input:**
`nums = [1, 2, 2, 3, 3, 4, 5]`

### Dry Run:

**Iteration 1:**
- `right = 0`, `nums[right] = 1`
- `freq` becomes `{1: 1}`
- `freq.size() = 1`, which is less than 2, so the inner while loop does not execute.
- `maxLen` is updated to `max(0, 0 - 0 + 1) = 1`
- `right` is incremented to 1

**Iteration 2:**
- `right = 1`, `nums[right] = 2`
- `freq` becomes `{1: 1, 2: 1}`
- `freq.size() = 2`, but the difference between 1 and 2 is 1, so the inner while loop does not execute.
- `maxLen` is updated to `max(1, 1 - 0 + 1) = 2`
- `right` is incremented to 2

**Iteration 3:**
- `right = 2`, `nums[right] = 2`
- `freq` becomes `{1: 1, 2: 2}`
- `freq.size() = 2`, and the difference between 1 and 2 is still 1, so the inner while loop does not execute.
- `maxLen` is updated to `max(2, 2 - 0 + 1) = 3`
- `right` is incremented to 3

**Iteration 4:**
- `right = 3`, `nums[right] = 3`
- `freq` becomes `{1: 1, 2: 2, 3: 1}`
- `freq.size() = 3`, which triggers the inner while loop since we have more than 2 distinct values.

  **Inner While Loop Execution:**
  - `freq[1] = 1` (decrement frequency of 1)
  - `freq` becomes `{1: 0, 2: 2, 3: 1}`
  - `1` is removed from `freq` because its frequency is 0
  - `freq` becomes `{2: 2, 3: 1}`
  - `left` is incremented to 1
  
  - `freq.size() = 2`, and the difference between 2 and 3 is 1, so the inner while loop exits.

- `maxLen` is updated to `max(3, 3 - 1 + 1) = 3`
- `right` is incremented to 4

**Iteration 5:**
- `right = 4`, `nums[right] = 3`
- `freq` becomes `{2: 2, 3: 2}`
- `freq.size() = 2`, and the difference between 2 and 3 is 1, so the inner while loop does not execute.
- `maxLen` is updated to `max(3, 4 - 1 + 1) = 4`
- `right` is incremented to 5

**Iteration 6:**
- `right = 5`, `nums[right] = 4`
- `freq` becomes `{2: 2, 3: 2, 4: 1}`
- `freq.size() = 3`, which triggers the inner while loop since we have more than 2 distinct values.

  **Inner While Loop Execution:**
  - `freq[2] = 2` (decrement frequency of 2)
  - `freq` becomes `{2: 1, 3: 2, 4: 1}`
  - `freq.size() = 3`, so the while loop continues.
  - `freq[2] = 1` (decrement frequency of 2)
  - `freq` becomes `{2: 0, 3: 2, 4: 1}`
  - `2` is removed from `freq` because its frequency is 0
  - `freq` becomes `{3: 2, 4: 1}`
  - `left` is incremented to 2
  
  - `freq.size() = 2`, and the difference between 3 and 4 is 1, so the inner while loop exits.

- `maxLen` is updated to `max(4, 5 - 2 + 1) = 4`
- `right` is incremented to 6

**Iteration 7:**
- `right = 6`, `nums[right] = 5`
- `freq` becomes `{3: 2, 4: 1, 5: 1}`
- `freq.size() = 3`, which triggers the inner while loop since we have more than 2 distinct values.

  **Inner While Loop Execution:**
  - `freq[3] = 2` (decrement frequency of 3)
  - `freq` becomes `{3: 1, 4: 1, 5: 1}`
  - `freq.size() = 3`, so the while loop continues.
  - `freq[3] = 1` (decrement frequency of 3)
  - `freq` becomes `{3: 0, 4: 1, 5: 1}`
  - `3` is removed from `freq` because its frequency is 0
  - `freq` becomes `{4: 1, 5: 1}`
  - `left` is incremented to 3
  
  - `freq.size() = 2`, and the difference between 4 and 5 is 1, so the inner while loop exits.

- `maxLen` is updated to `max(4, 6 - 3 + 1) = 4`
- `right` is incremented to 7

**Exit Loop:**
- `right = 7`, which is equal to `nums.size()`, so the loop exits.

The final `maxLen` is 4. Thus, the length of the longest subarray where the difference between the two distinct values is at most 1 is 4.

### Conclusion:
The function correctly identifies that the longest subarray fitting the criteria is `[2, 2, 3, 3]` with a length of 4.
*/
