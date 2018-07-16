#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>

int main()
{
  std::string str = "abcdefg";
  std::string test;
  for (auto iter {str.begin()}; iter != str.end(); ++iter)
  {
    test += *iter;
  }
  std::cout << str << std::endl;
  return 0;
}
