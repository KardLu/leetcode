/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int *index = (int*)malloc(sizeof(int) * 2);
    index[0] = -1;
    index[1] = -1;
    for (int i = 0;i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize;j++) {
            if (nums[i] + nums[j] == target) {
                index[0] = i + 1;
                index[1] = j + 1;
            }
        }
        if (index[0] > -1)
            break;
    }

    return index;
}