# Given two integer arrays nums1 and nums2, return an array of their intersection. 
# Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.
# Input: nums1 = [1,2,2,1], nums2 = [2,2]
# Output: [2,2]
# Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
# Output: [4,9]
# Explanation: [9,4] is also accepted.

def intersection(nums1, nums2):
    nums1_dic = {}
    for num in nums1:
        nums1_dic[num] = nums1_dic.get(num, 0) + 1
    nums2_dic = {}
    for num in nums2:
        nums2_dic[num] = nums2_dic.get(num, 0) + 1
    ans = []
    if len(nums1) <= len(nums2):
        for num in nums1_dic:
            if num in nums2_dic:
                ans += min(nums1_dic[num], nums2_dic[num])*[num]    
    else:
        for num in nums2_dic:
            if num in nums1_dic:
                ans += min(nums1_dic[num], nums2_dic[num])*[num]
    
    return ans

def intersection_opt(nums1, nums2):
    nums1 = sorted(nums1)
    nums2 = sorted(nums2)
    ans = []
    if len(nums1) <= len(nums2):
        shorter = nums1
        longer = nums2
    else:
        shorter = nums2
        longer = nums1
    
    i, j = 0, 0
    while i < len(shorter) and j < len(longer):
        if shorter[i] == longer[j]:
            ans.append(shorter[i])
            i += 1
            j += 1
        elif shorter[i] > longer[j]:
            j += 1
        else:
            i += 1

    return ans

nums1 = [1,2,2,1]
nums2 = [2,2]
print(intersection_opt(nums1, nums2))
nums1 = [4,9,5]
nums2 = [9,4,9,8,4]
print(intersection_opt(nums1, nums2))