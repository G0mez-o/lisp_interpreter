//in this program, you can calculate four arithmetic operations in s-expression for interpreter checking depth of s-expression.
#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <list>
#define str_condition auto iter {str.begin()}; iter != str.end(); ++iter

bool check_str_cal(std::string str)
{
  bool check = std::none_of(str.cbegin(), str.cend(), isalpha);
  if (!check)
  {
    std::cout << "In this s-expression, there is alphabet so can't calculate thie s-expression!!" << std::endl;
  }
  return (check);
}

std::string eval(std::string str, int num, std::string check)
{
  std::list<std::string> ls; 
  std::string oper, car, cdr;

  auto iter {std::find_if_not(str.begin(), str.end(), [](char ch) { return ch == '('; })};

  std::cout << "----- start to get operator -----" << std::endl;

  for (; *iter != ' ' ||  iter != str.end() ; ++iter)
  {
    oper += *iter;
  }

  std::cout << "----- end to get operator -----" << std::endl;

  std::cout << "oper:" << oper << std::endl;

  if (oper != "+" && oper != "-" && oper != "*" && oper != "/") { std::cout << "return oper" << std::endl; return oper; }


  auto iter_1 {std::find_if_not(iter, str.end(), [](char ch) { return ch == ' '; })};
  if (*iter_1 == '(')
  {
    int count = 0;
    for (; ; ++iter_1)
    {
      car += *iter_1;
      if (*iter_1 == ')') { --count; }

      if (*iter_1 == '(') { ++count; }

      std::cout << "car-->" << car << "---Hello---count:" << count << std::endl;

      if (count == 0) { break; }
      
    }
  }
  else
  {
    for (; *iter_1 != ' '; ++iter_1)
    {
      car += *iter_1;
      std::cout << "car-->" << car << std::endl;
    }
  }

  std::cout << "-----break-----" << std::endl;

  auto iter_2 {std::find_if_not(iter_1, str.end(), [](char ch) { return ch == ' '; })};
  if (*iter_2 == '(')
  {
    int count = 0;
    for (; ; ++iter_2)
    {
      cdr += *iter_2;
      if (*iter_2 == ')') { --count; }

      if (*iter_2 == '(') { ++count; }

      std::cout << "cdr-->" << cdr << "---Hello---count" << count << std::endl;

      if (count == 0) { break; }
    }
  }
  else
  {
    for (; *iter_2 != ')'; ++iter_2)
    {
      cdr += *iter_2;
      std::cout << "cdr-->" << cdr << std::endl;
    }
  }
  std::cout << "-----break2-----" << std::endl;

  std::cout << "eval " << check << "------eval------" << ++num  << std::endl;

  double x = std::stod(eval(car, num, "car"));
  double y = std::stod(eval(cdr, num, "cdr"));
  
  if (oper == "+")
  { 
    double val = x + y;
    std::cout << "----- end of eval for + -----" << std::endl;
    return { std::to_string(val) };
  }
  if (oper == "-")
  {
    double val = x - y;
    std::cout << "----- end of eval for - -----" << std::endl;
    return { std::to_string(val) };
  }
  if (oper == "*")
  {
    double val = x * y;
    std::cout << "----- end of eval for * -----" << std::endl;
    return { std::to_string(val) };
  }
  if (oper == "/")
  {
    double val = x / y;
    std::cout << "----- end of eval for / -----" << std::endl;
    return { std::to_string(val) };
  }
}


void introduction_sentence()
{
  std::cout <<"Welcom to Osada Lisp <https://github.com/ShunjiroOsada/lisp_interpreter>"<< std::endl;
  std::cout << "This is Lisp interpreter by Osada" << std::endl;
}

void s_exp_analysis(std::string str)
{
  for (str_condition)
  {
    if (*iter == '(' || *iter == ')')
    {
      std::cout << *iter << ", ";
    }
    if (*iter != '(' && *iter != ')' && *iter != ' ')
    {
      if (*(iter+1) != '(' && *(iter+1) != ')' && *(iter+1) != ' ')
      {
        std::cout << *iter;
      }
      else
      {
        std::cout << *iter << ", ";
      }
    }
  }
  std::cout << std::endl;
}

//+ std::count(str.begin(), str.end(), ')')

bool check_depth(std::string str)
{
  int depth = std::count(str.begin(), str.end(), '(') - std::count(str.begin(), str.end(), ')');
  if (depth != 0)
  {
    std::cout << "This is not uncompleted s-expression." << std::endl;
    std::cout << "depth: " << depth;
    if (depth > 0)
    {
      std::cout << " --> There are " << depth << " more left-parentheses than right-parentheses in this s-expression." << std::endl;
    }
    else
    {
      std::cout << " --> There are " << -depth << " more right-parentheses than left-parentheses in this s-expression." << std::endl;
    }
    return false;
  }
  return true;
}

int main(void)
{
  introduction_sentence();
  unsigned int count = 0;
  unsigned int mis_count = 0;
  while (true)
  { 
    ++count;
    std::cout << '[' << count << ']' << '[' << mis_count << "]>";
    std::string s;
    std::getline( std::cin, s );
    if (!check_depth(s)) { ++mis_count; continue; }
    s_exp_analysis(s);
    if (!check_str_cal(s)) {++mis_count; continue; }
    else { std::cout<< eval(s, 0, "all") << std::endl; }
  }
  return 0; 
}
