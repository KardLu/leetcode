class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> visited;
        vector<int> indices;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (visited.find(target - nums[i]) != visited.end()) {
                indices.push_back(visited[target - nums[i]] + 1);
                indices.push_back(i + 1);
            }else {
                visited[nums[i]] = i;
            }
        }
        return indices;
    }
};