#include <iostream>
#include <string>
#include <ctype.h>
#include "parsing_functions.h"
using namespace std;

int main()
{

    string line;
    string number1, number2;
    int temp1, temp2;
    float temp1f, temp2f;
    char *p_op = nullptr;
    bool flag;
    cin >> line;
    int counter = 0, counter_num = 0, counter_residue = 0;

    count_num_of_operators(line, counter, counter_residue);
    count_first_num(line, number1, counter_num);
    find_if_first_num_is_int_or_float(number1, temp1f, temp1, flag);
    counter_residue = counter_residue - counter_num;
    line = line.substr(counter_num, counter_residue);
    cout << "Ostatak" << line << endl;
    for (int i = 0; i < counter; i++)
    {
        counter_num = 0;
        for (char x : line)
        {
            if (p_op == nullptr)
            {
                p_op = new char;
                *p_op = x;
                counter_num++;
                continue;
            }
            if (isdigit(x) || x == '.')
            {
                number2 += x;
            }
            else
            {
                break;
            }
            counter_num++;
        }
        if (number2.find('.') != std::string::npos)
        {
            temp2f = stof(number2);
            if (flag == true)
            {
                if (*p_op == '+')
                {
                    temp1f = add(temp1f, temp2f);
                    cout << "float, float" << endl;
                    flag = true;
                }
                else if (*p_op == '-')
                {
                    temp1f = substract(temp1f, temp2f);
                    cout << "float, float" << endl;
                    flag = true;
                }
            }
            else
            {
                if (*p_op == '+')
                {
                    temp1f = add(temp1, temp2f);
                    cout << "int, float" << endl;
                    flag = true;
                }
                else if (*p_op == '-')
                {
                    temp1f = substract(temp1, temp2f);
                    cout << "int, float" << endl;
                    flag = true;
                }
            }
        }
        else
        {
            temp2 = stoi(number2);
            if (flag == true)
            {
                if (*p_op == '+')
                {
                    temp1f = add(temp1f, temp2);
                    cout << "float, int" << endl;
                    flag = true;
                }
                else if (*p_op == '-')
                {
                    temp1f = substract(temp1f, temp2);
                    cout << "float, int" << endl;
                    flag = true;
                }
            }
            else
            {
                if (*p_op == '+')
                {
                    temp1 = add(temp1, temp2);
                    cout << "int, int" << endl;
                    flag = false;
                }
                else if (*p_op == '-')
                {
                    temp1 = substract(temp1, temp2);
                    cout << "int, int" << endl;
                    flag = false;
                }
            }
        }
        delete p_op;
        p_op = nullptr;
        number2 = "";
        counter_residue = counter_residue - counter_num;
        line = line.substr(counter_num, counter_residue);
    }
    cout << "Result is: " << temp1 << endl;
    cout << "Result is: " << temp1f << endl;
    return 0;
}
