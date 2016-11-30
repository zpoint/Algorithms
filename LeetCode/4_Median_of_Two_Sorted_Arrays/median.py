#!/usr/bin/env python
# -*- coding:utf-8 -*-

"""
The solution below can't Solve mismatch length of two arr

1) Calculate the medians m1 and m2 of the input arrays ar1[]
   and ar2[] respectively.
2) If m1 and m2 both are equal then we are done.
     return m1 (or m2)
3) If m1 is greater than m2, then median is present in one
   of the below two subarrays.
    a)  From first element of ar1 to m1 (ar1[0...|_n/2_|])
    b)  From m2 to last element of ar2  (ar2[|_n/2_|...n-1])
4) If m2 is greater than m1, then median is present in one
   of the below two subarrays.
   a)  From m1 to last element of ar1  (ar1[|_n/2_|...n-1])
   b)  From first element of ar2 to m2 (ar2[0...|_n/2_|])
5) Repeat the above process until size of both the subarrays
   becomes 2.
6) If size of the two arrays is 2 then use below formula to get
  the median.
    Median = (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1]))/2
"""


# Buggy
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        length1 = len(nums1)
        length2 = len(nums2)
        if length1 < 2:
            return self.short_handle(nums1, nums2)
        elif length2 < 2:
            return self.short_handle(nums2, nums1)

        mid1 = self.median(nums1)
        mid2 = self.median(nums2)
        if mid1 == mid2:
            return mid1
        elif mid1 < mid2: # nums1 right part, nums2 left part
            return self.cut_num(nums2, nums1)
        else:
            return self.cut_num(nums1, nums2)

    def short_handle(self, nums_short, nums):
        if nums_short:
            index = 0
            length = len(nums)
            while index < length:
                if nums_short[0] < nums[index]:
                    nums.insert(index, nums_short[0])
                    break
                index += 1
            if length == len(nums):
                nums.append(nums_short[0])
        return self.median(nums)

    def median(self, nums):
        if len(nums) == 1:
            return float(nums[0])
        elif len(nums) % 2:  # odd
            return float(nums[len(nums) / 2])
        else:
            return (nums[len(nums) / 2] + nums[len(nums) / 2 - 1]) / 2.0

    """
    def cut_num(self, left_nums, right_nums):
        right_part = right_nums[len(right_nums) / 2:]
        left_part_len = len(left_nums) / 2
        if (left_part_len + len(right_part)) % 2 != (len(left_nums) + len(right_nums)) % 2:
            left_part = left_nums[:len(left_nums) / 2 + 1]
        else:
            left_part = left_nums[:len(left_nums) / 2]
        return self.findMedianSortedArrays(left_part, right_part)
    """

    def cut_num(self, left_nums, right_nums):
        left_part = left_nums[:len(left_nums) / 2]
        right_part_len = len(right_nums) / 2 + 1 if len(right_nums) % 2 else len(right_nums) / 2
        if (len(left_part) + right_part_len) % 2 != (len(left_nums) + len(right_nums)) % 2:
            right_part = right_nums[right_part_len - 1:]
            print "right", right_part
        else:
            right_part = right_nums[right_part_len:]
        print left_part
        print right_part
        return self.findMedianSortedArrays(left_part, right_part)


a = Solution()

print a.findMedianSortedArrays([1, 2], [1, 2, 3])
print a.findMedianSortedArrays([1,3,4], [2, 5])
print a.findMedianSortedArrays([1, 2], [3, 4, 5, 6])

print a.findMedianSortedArrays([2, 6], [1, 3, 4, 5])
print a.findMedianSortedArrays([], [3, 4, 5])