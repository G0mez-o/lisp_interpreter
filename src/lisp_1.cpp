#include <iostream>
#include <cstdlib>
#include <string>

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

        for (int i = 0; i != s.size(); ++i) //checking the number of parentheses in s-expression
        {
            if (s.at(i) == '(')
            {
                ++depth;
            } 
            if (s.at(i) == ')')
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

        for (int i = 0; i != s.size(); ++i)
        {
            if (s.at(i) == '(' || s.at(i) == ')')
            {
                std::cout << s.at(i) << ", ";
            }
            if (s.at(i) != '(' && s.at(i) != ')' && s.at(i) != ' ')
            {
                if (s.at(i+1) != '(' && s.at(i+1) != ')' && s.at(i+1) != ' ')
                {
                    std::cout << s.at(i);
                }
                else
                {
                    std::cout << s.at(i) << ", ";
                }
            }
        }
        std::cout << std::endl;
    }
    return 0; 
}
