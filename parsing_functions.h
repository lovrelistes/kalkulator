#ifndef PARSING_FUNCTIONS
#define PARSING_FUNCTIONS
#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;
template <typename T>
T add(T &number1, T &number2)
{
    return number1 + number2;
}
template <typename T, typename I>
auto add(T &number1, I &number2)
{
    return number1 + number2;
}

template <typename T>
T substract(T &number1, T &number2)
{
    return number1 - number2;
}

template <typename T, typename I>
auto substract(T &number1, I &number2)
{
    return number1 - number2;
}

void count_num_of_operators(string &line, int &counter, int &counter_residue){
    for (char x : line)
    {
        if (!isdigit(x) && x != '.')
        {
            counter++;
        }
        counter_residue++;
    }
}

void count_first_num(string &line,string &number1,int &counter_num){
    for (char x : line)
    {
        if (isdigit(x) || x == '.')
        {
            number1 += x;
            counter_num++;
        }
        else
        {
            break;
        }
    }
    cout<<number1<<endl;
}

void find_if_first_num_is_int_or_float(string &number1,float &temp1f,int &temp1,bool &flag){
    if (number1.find('.') != std::string::npos)
    {
        temp1f = stof(number1);
        flag = true;
    }
    else
    {
        temp1 = stoi(number1);
        flag = false;
    }

}
#endif
