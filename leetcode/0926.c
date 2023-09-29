#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minSubArrayLen(int target, int *nums, int numsSize)
{
    // 滑动窗口结束条件 right 指针 末尾 窗口之和小于 target
    int right = 0, left = 0; // 左右窗口边界
    int sum = nums[left];    // 纪录窗口之和
    int len = numsSize + 1;  // 长度搞一个无效值
    while (right < numsSize)
    {
        while (sum >= target)
        {
            len = (right - left + 1) < len ? (right - left + 1) : len;
            sum -= nums[left++];
        }
        right++;
        if (right == numsSize)
        {
            break;
        }
        sum += nums[right];
    }
    if (len == (numsSize + 1))
    {
        len = 0;
    }

    return len;
}

int main()
{
    int target = 7;
    int nums[] = {2, 3, 1, 2};
    int numsSize = sizeof(nums) / sizeof(int);
    int ret = minSubArrayLen(target, nums, numsSize);
    printf("%d", ret);

    return 0;
}