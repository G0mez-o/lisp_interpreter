//Changing lisp_1.cpp by iterator and STL algorithm
#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>

void check_depth(std::string str)
{
  for (auto iter {str.begin()}; iter != str.end(); ++iter)
  {
    if (std::)
  }
}

int main(void)
{
    std::cout << "This is Lisp interpreter by Osada" << std::endl;

    while (true)
    {
        std::cout << ">>";
        std::string s;
        std::getline( std::cin, s );
        if (s.front() != '(' || s.back() != ')') //checking first and end parentheses in s-expression
        {
            std::cout << "This is not s-expression!" << std::endl;
            continue;
        }

        int depth = 0;

        for (auto iter {s.begin()}; iter != s.end(); ++iter) //checking the number of parentheses in s-expression
        {
            if (*iter == '(')
            {
                ++depth;
            } 
            if (*iter == ')')
            {
                --depth;
            }
        }

        if (depth != 0)
        {
            std::cout << "This is not uncompleted s-expression." << std::endl;
            std::cout << "depth: " << depth;
            if (depth > 0)
            {
                std::cout << " --There are " << depth << " more left-parentheses than right-parenthese in this s-expression." << std::endl;
            }
            if (depth < 0)
            {
                std::cout << " --There are " << -depth << " more right-parentheses than left-parentheses in this s-expression." << std::endl;
            }
            continue;
        }

        for (auto iter {s.begin()}; iter != s.end(); ++iter)
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
    return 0; 
}
