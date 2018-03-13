#include <map>
#include <string>
#include <vector>
#include <iostream>

const std::map<char, std::string> NumMap = {
		{'2', "abc"},
		{'3', "def"},
		{'4', "ghi"},
		{'5', "jkl"},
		{'6', "mno"},
		{'7', "pqrs"},
		{'8', "tuv"},
		{'9', "wxyz"}
};

class Solution {
public:
		std::vector<std::string> letterCombinations(std::string digits) 
		{
				          std::vector<std::string> ret_vector, curr_vec;
						  std::map<char, std::string>::const_iterator n_map_iter;
						  std::size_t index = 0;
						  for (const char &c : digits)
						  {
								  if ((n_map_iter = NumMap.find(c)) == NumMap.end())
										  continue;
								  if (index == 0)
								  {
										  for (const char &c : (*n_map_iter).second)
										  {
												  std::string s;
												  ret_vector.push_back(s + c);
										  }
								  }
								  else
								  {
										  for (std::string &str : ret_vector)
										  {
												  for (const char &c : (*n_map_iter).second)
															curr_vec.push_back(str + c);		  
										  }
										  ret_vector = std::move(curr_vec);
										  curr_vec = {};
								  }
								  ++index;
						  }
						  return ret_vector;
		}
};


int main()
{
		std::string a;
		a += 'a';
		Solution s;
		for (auto &item : s.letterCombinations("23"))
				std::cout << item << " ";
		std::cout << std::endl;
		return 0;
}
