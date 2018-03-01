#include <iostream>
#include <vector>
#include <tuple>

#define MAX_I (-1 ^ (1 << 31))
#define MIN_I (-1 & (1 << 31))

class Solution {
public:
	inline int max(int a, int b)
	{
			return a > b ? a : b;
	}

	inline int min(int a, int b)
	{
			return a < b and a != MIN_I ? a : b;
	}

	inline std::tuple<int, int> get_val(std::vector<int> &arr, std::size_t c, const int edge = 0)
	{
			int l = c / 2 - 1, r = (c + 3) / 2 - 1, l_val, r_val;
			if (l < 0)
					l_val = edge == 0 ? (arr.size() == 1 ? arr[0] : MIN_I) : edge;
		    else
					l_val = arr[l];
			if (r >= (int)arr.size())
					r_val = edge == 0 ? (arr.size() == 1 ? arr[0] : MAX_I) : edge;
			else
					r_val = arr[r];
			return std::make_tuple(l_val, r_val);	
	}

	inline double get_final(std::size_t c1, std::size_t c2, std::vector<int> &shorter, std::vector<int> &longer)
	{
			bool c1_in_pos = c1 % 2, c2_in_pos = c2 % 2;
			if (not c1_in_pos and not c2_in_pos)
			{
					int l_c1, r_c1, l_c2, r_c2;
					std::tie(l_c1, r_c1) = get_val(shorter, c1, MIN_I);
					std::tie(l_c2, r_c2) = get_val(longer, c2, MIN_I);
					return (max(l_c1, l_c2) + min(r_c1, r_c2)) / 2.0;
			}
			else if (c1_in_pos and c2_in_pos)
			{
					return (shorter[(c1 - 1) / 2] + longer[(c2 - 1) / 2]) / 2.0;
			}
			else if (c1_in_pos)
					return double(shorter[(c1 - 1) / 2]);
			else
					return double(longer[(c2 - 1) / 2]);

	}

    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
			std::vector<int> &shorter = nums1.size() < nums2.size() ? nums1 : nums2, &longer = nums1.size() < nums2.size() ? nums2 : nums1;
			std::size_t n = shorter.size(), m = longer.size(), left = 0, right = 2 * n + 1, c1 = -2, c2, prev_c1 = -1;
			int l_c1, r_c1, l_c2, r_c2;
			while (true)
			{
					prev_c1 = c1;
					c1 = (left + right) / 2;
					c2 = n + m - c1;
					std::tie(l_c1, r_c1) = get_val(shorter, c1);
					std::tie(l_c2, r_c2) = get_val(longer, c2);
					if (l_c1 > r_c2)
							right = c1;
					else if (l_c2 > r_c1)
							left = c1;
					else
							return get_final(c1, c2, shorter, longer);
			}
			return get_final(c1, c2, shorter, longer);
    }
};

int main()
{
		std::vector<int> ivec1 = {1, 3}, ivec2 = {2}, jvec1 = {1, 2}, jvec2 = {3, 4}, hvec1 = {}, hvec2 = {2, 3}, kvec1 = {1}, kvec2 = {2, 3}, lvec1 = {1, 0, 0, 0, 0, 0}, lvec2 = {1, 0, 0, 0, 0, 1};
		Solution s;
		std::cout << "i result: " << s.findMedianSortedArrays(ivec1, ivec2) << std::endl;
		std::cout << "j result: " << s.findMedianSortedArrays(jvec1, jvec2) << std::endl;
		std::cout << "h result: " << s.findMedianSortedArrays(hvec1, hvec2) << std::endl;
		std::cout << "k result: " << s.findMedianSortedArrays(kvec1, kvec2) << std::endl;
		std::cout << "l result: " << s.findMedianSortedArrays(lvec1, lvec2) << std::endl;
}
