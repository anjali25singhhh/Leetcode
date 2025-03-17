class Solution {
public:
    bool divideArray(vector<int>& nums) {
        // Create a frequency array with a fixed size, 
        // assuming that 500 is the maximum number expected to be in the `nums` array.
        vector<int> frequency(501, 0); // Initialize all elements to 0

        // Increment the frequency count for each number in the `nums` array.
        for (int num : nums) {
            frequency[num]++;
        }
      
        // Check if all numbers occur an even number of times.
        for (int freq : frequency) {
            // If a number occurs an odd number of times, it's not possible 
            // to divide the array into pairs such that each pair consists of equal numbers.
            if (freq % 2 != 0) {
                return false;
            }
        }
      
        // If the code reaches this point, all numbers occur an even number of times,
        // and the array can be divided into pairs of equal numbers.
        return true;
    }
};
