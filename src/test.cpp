#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <list>
#include <cctype>
int main()
{
  std::string str = "cde";
  bool result = std::all_of(str.cbegin(), str.cend(), isalpha);
  std::cout << result << std::endl;
  return 0;
}
