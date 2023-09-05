#include <iostream>
#include <vector>
#include <algorithm>

void backtrackPermutations(std::vector<int>& nums, std::vector<std::vector<int>>& permutations, int start) {
    if (start == nums.size() - 1) {
        permutations.push_back(nums);
        return;
    }

    for (int i = start; i < nums.size(); i++) {
        std::swap(nums[start], nums[i]);
        backtrackPermutations(nums, permutations, start + 1);
        std::swap(nums[start], nums[i]);
    }
}

std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    std::vector<std::vector<int>> permutations;
    std::sort(nums.begin(), nums.end());  // Sort the input to mimic the behavior of next_permutation
    backtrackPermutations(nums, permutations, 0);
    return permutations;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4};

    std::vector<std::vector<int>> result = permute(nums);

    // Print the generated permutations
    for (const auto& permutation : result) {
        for (int num : permutation) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
