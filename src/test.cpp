#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <list>

std::string eval(std::string str)
{
  std::list<std::string> ls; 
  std::string oper, car, cdr;

  auto iter {std::find_if_not(str.begin(), str.end(), [](char ch) { return ch == '('; })};

  for (; *iter != ' '; ++iter)
  {
    oper += *iter;
  }

  if (oper != "+" && oper != "-" && oper != "*" && oper != "/") { return oper; }

  auto iter_1 {std::find_if_not(iter, str.end(), [](char ch) { return ch == ' '; })};
  if (*iter_1 == '(')
  {
    int count = 0;
    for (; ; ++iter_1)
    {
      car += *iter_1;
      if (*iter_1 == ')') { --count; }

      if (*iter_1 == '(') { ++count; }

      if (count == 0) { break; }
    }
  }
  else
  {
    for (; *iter_1 != ' '; ++iter_1)
    {
      car += *iter_1;
    }
  }
  auto iter_2 {std::find_if_not(iter_1, str.end(), [](char ch) { return ch == ' '; })};
  if (*iter_2 == '(')
  {
    int count = 0;
    for (; ; ++iter_2)
    {
      cdr += *iter_2;
      if (*iter_2 == ')') { --count; }

      if (*iter_2 == '(') { ++count; }

      if (count == 0) { break; }
    }
  }
  else
  {
    for (; *iter_2 != ')'; ++iter_2)
    {
      cdr += *iter_2;
    }
  }

  double x = std::stod(eval(car));
  double y = std::stod(eval(cdr));
  
  if (oper == "+")
  { 
    double val = x + y;
    return { std::to_string(val) };
  }
  if (oper == "-")
  {
    double val = x - y;
    return { std::to_string(val) };
  }
  if (oper == "*")
  {
    double val = x * y;
    return { std::to_string(val) };
  }
  if (oper == "/")
  {
    double val = x / y;
    return { std::to_string(val) };
  }
}

int main()
{
  std::string str= eval("(* 4 (/ 5 (+ 4 5)))");
  std::cout << str << std::endl;
  return 0;

}
