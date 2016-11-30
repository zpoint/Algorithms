#!/usr/bin/env python
# -*- coding:utf-8 -*-
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        start_index = stop_index = 0
        common_set = set()
        longest = 0
        length = len(s)
        while stop_index < length:
            if s[stop_index] not in common_set:
                common_set.add(s[stop_index])
                stop_index += 1
                if len(common_set) > longest:
                    longest = len(common_set)
            else:
                start_index = s[start_index:stop_index].index(s[stop_index]) + start_index + 1
                common_set = set(s[start_index:stop_index + 1])
                stop_index += 1
        return longest

a = Solution()
print a.lengthOfLongestSubstring("loddktdji")