#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

int add(int &number1, int &number2)
{
    return number1 + number2;
}
int substract(int &number1,int &number2){
    return number1 - number2;
}

int main()
{
    string line;
    string number1, number2;
    int temp;
    char *p_op = nullptr;
    cin >> line;
    int counter=0,counter_num=0,counter_residue=0;
    for (char x : line)
    {
        if (!isdigit(x))
        {
            counter++;
        }
        counter_residue++;
    }
    for (char x:line){
        if (isdigit(x)){
        number1 += x;
        counter_num++;
        }else{
            break;
        }
    }
    temp=stoi(number1);
    counter_residue=counter_residue-counter_num;
    line=line.substr(counter_num,counter_residue);

    for (int i = 0; i < counter; i++)
    {
        counter_num=0;
        for (char x : line)
        {
            if (p_op == nullptr){
                p_op = new char;
                *p_op = x;
                counter_num++;
                continue;
                }
            if (isdigit(x)){
                number2 += x;
            }else{
                break;
            }
            counter_num++;

        }
        int number22 = stoi(number2);
        if (*p_op == '+')
        {
            temp = add(temp, number22);
        }else if(*p_op == '-'){
            temp = substract(temp, number22);
        }
        delete p_op;
        p_op=nullptr;
        number2="";
        counter_residue=counter_residue-counter_num;
        line=line.substr(counter_num,counter_residue);
    }
    cout<<"Result is: "<<temp<<endl;
    return 0;
}
