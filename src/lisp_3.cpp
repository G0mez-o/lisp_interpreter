#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>

void eval(std::string str)
{
  std::string oper, car, cdr;
  auto iter {std::find_if_not(str.begin(), str.end(), [](char ch) { return ch == '('; })};

  for (; *iter != ' '; ++iter)
  {
    oper += *iter;
  }
  std::cout << oper << std::endl;

  auto iter_1 {std::find_if_not(iter, str.end(), [](char ch) { return ch == ' '; })};
  for (; *iter_1 != ' '; ++iter_1)
  {
    car += *iter_1;
  }
  std::cout << car << std::endl;
  auto iter_2 {std::find_if_not(iter_1, str.end(), [](char ch) { return ch == ' '; })};
  for (; iter_2 != str.end(); ++iter_2)
  {
    cdr += *iter_2;
  }
  std::cout << cdr << std::endl;
}

int main()
{
  eval("(+ dddddddd ())");
  
  return 0;

}
