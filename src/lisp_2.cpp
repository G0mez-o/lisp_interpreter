//Changing lisp_1.cpp by iterator and STL algorithm
#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>

#define str_condition auto iter {str.begin()}; iter != str.end(); ++iter

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
  }
  return 0; 
}
