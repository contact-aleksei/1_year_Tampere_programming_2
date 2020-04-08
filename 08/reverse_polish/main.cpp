#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

int main()
{
    cout <<"Input an expression in reverse Polish notation (end with #):" <<endl;
    cout <<"EXPR> ";
    string line;
    string elements;
    int a=0, b=0, c=0, length=0, divisionbyzero=0;
    char checkelement,op1='m', op2='k', not_operator='#';
    int arrayWithNumbers[3] = {0,0,0};
    int arrayWithNumbers2[5] = {0,0,0,0,0};
    char op3='t', op4='f';
    getline (std::cin,line);
    int counter = 0, k=0, m=0, l=0;
    stringstream ss(line);
    length=line.length();
    if ((line.at(0)=='+')or (line.at(0)=='-')or (line.at(0)=='*')or (line.at(0)=='/')) {
            cout<<"Error: Expression must start with a number";
            return 1;
        }
    else if (length==7){
        while (getline(ss, elements, ' ') && counter < 5) {
            char cstr[elements.size() + 1];
            strcpy(cstr, elements.c_str());

            checkelement = elements[0];
            if (isdigit(checkelement)){
                stringstream geek(elements);
                int x = 0;
                geek >> x;
                arrayWithNumbers[k]=x;
                k++;
                counter ++;
            }

            else{

                if (m==0){
                    op1 = elements[0];
                    }
                if ((counter==0) and (op1=elements[0])){
                    cout<<"Error: Expression must start with a number";
                    return 1;
                }
                m++;
                counter ++;
            }



            if ((op1=='+')){
                a=arrayWithNumbers[0];
                b=arrayWithNumbers[1];
                c=a+b;
            }
            else if ((op1=='-')){
                a=arrayWithNumbers[0];
                b=arrayWithNumbers[1];
                c=a-b;
            }
            else if ((op1=='*')){
                a=arrayWithNumbers[0];
                b=arrayWithNumbers[1];
                c=a*b;
            }
            else if ((op1=='/')){
                a=arrayWithNumbers[0];
                b=arrayWithNumbers[1];
                if (b==0){
                    cout<<"Error: Division by zero";
                    return 1;
                }
                else{
                    c=a/b;
                }
            }
            else {
                cout<<"Error: Unknown character";
                return 1;
            }
        }
    }


    else if (length==9){
        while (getline(ss, elements, ' ') && counter < 6) {
            char cstr[elements.size() + 1];
            strcpy(cstr, elements.c_str());

            checkelement = elements[0];
            if (isdigit(checkelement)){
                stringstream geek(elements);
                int x = 0;
                geek >> x;
                arrayWithNumbers[k]=x;
                k++;
                counter ++;

            }
            else{

                if (m==0){
                    op1 = elements[0];
                    if (counter==3){
                        l=1;
                    }
                }
                if (m==1){
                    op2 = elements[0];
                    if (counter==4 and l==1){
                        l=2;
                    }
                }
                if (m==2){
                    not_operator = elements[0];
                }
                if ((counter==0) and (op1=elements[0])){
                    cout<<"Error: Expression must start with a number";
                    return 1;

                }

                m++;
                counter ++;
            }

        }
        if (m==3){
            cout<<"Error: Too few operands";
            return 1;
        }
        else{
            cout<<"Error: Too few operators";
            return 1;
        }


    }















    else if ((length<11) and (length>9)){
        cout<<"Error: Too few operators";
        return 1;
        }
    else if ( (length>11) and (length!=19)){
        cout<<"Error: Too few operands";
        return 1;
        }
    else if (length==11){
        while (getline(ss, elements, ' ') && counter < 7) {
            char cstr[elements.size() + 1];
            strcpy(cstr, elements.c_str());

            checkelement = elements[0];
            if (isdigit(checkelement)){
                stringstream geek(elements);
                int x = 0;
                geek >> x;
                arrayWithNumbers[k]=x;
                k++;
                counter ++;

            }
            else{

                if (m==0){
                    op1 = elements[0];
                    if (counter==3){
                        l=1;
                    }
                }
                if (m==1){
                    op2 = elements[0];
                    if (counter==4 and l==1){
                        l=2;
                    }
                }
                if (m==2){
                    not_operator = elements[0];
                }
                if ((counter==0) and (op1=elements[0])){
                    cout<<"Error: Expression must start with a number";
                    return 1;

                }

                m++;
                counter ++;
            }
        }

        if (l!=2) {

            if ((op1=='+')){
                a=arrayWithNumbers[0];
                b=arrayWithNumbers[1];
                c=a+b;
            }
            else if ((op1=='-')){
                a=arrayWithNumbers[0];
                b=arrayWithNumbers[1];
                c=a-b;
            }
            else if ((op1=='*')){
                a=arrayWithNumbers[0];
                b=arrayWithNumbers[1];
                c=a*b;
            }
            else if ((op1=='/')){
                a=arrayWithNumbers[0];
                b=arrayWithNumbers[1];
                if (b==0){

                    divisionbyzero=1;
                }
                else{
                    c=a/b;
                }



            }

            else {
                cout<<"Error: Unknown character";
                return 1;
            }

            if (divisionbyzero==1){
                cout<<"Error: Division by zero";
                return 1;}
            else {
                if ((op2=='+') and (not_operator=='#')){
                    b=arrayWithNumbers[2];
                    c=c+b;
                    cout<< "Correct: "<<c<<" is the result";
                    return 0;
                }
                else if ((op2=='-') and (not_operator=='#')){
                    b=arrayWithNumbers[2];
                    c=c-b;
                    cout<< "Correct: "<<c<<" is the result";
                    return 0;
                }
                else if ((op2=='*') and (not_operator=='#')){
                    b=arrayWithNumbers[2];
                    c=c*b;
                    cout<< "Correct: "<<c<<" is the result";
                    return 0;
                }
                else if ((op2=='/') and (not_operator=='#')){
                    b=arrayWithNumbers[2];
                    if (b==0){
                        cout<<"Error: Division by zero";
                        return 1;
                    }
                    else{
                        c=c/b;
                        cout<< "Correct: "<<c<<" is the result";
                        return 0;
                    }
                }

                else {
                    cout<<"Error: Unknown character";
                    return 1;
                }
                }
        }




        else if(l==2){
            if ((op1=='+')){
                a=arrayWithNumbers[1];
                b=arrayWithNumbers[2];
                c=a+b;
            }
            else if ((op1=='-')){
                a=arrayWithNumbers[1];
                b=arrayWithNumbers[2];
                c=a-b;

            }
            else if ((op1=='*')){
                a=arrayWithNumbers[1];
                b=arrayWithNumbers[2];
                c=a*b;
            }
            else if ((op1=='/')){
                a=arrayWithNumbers[1];
                b=arrayWithNumbers[2];
                c=a/b;
                if (b==0){

                    divisionbyzero=1;
                }

            }

            else {
                cout<<"Error: Unknown character";
                return 1;
            }

            if (divisionbyzero==1){
                cout<<"Error: Division by zero";
                return 1;}
            else {
                if ((op2=='+') and (not_operator=='#')){
                    b=arrayWithNumbers[0];
                    c=b+c;
                    cout<< "Correct: "<<c<<" is the result";
                    return 0;
                }
                else if ((op2=='-') and (not_operator=='#')){
                    b=arrayWithNumbers[0];
                    c=b-c;
                    cout<< "Correct: "<<c<<" is the result";
                    return 0;
                }
                else if ((op2=='*') and (not_operator=='#')){
                    b=arrayWithNumbers[0];
                    c=b*c;
                    cout<< "Correct: "<<c<<" is the result";
                    return 0;
                }
                else if ((op2=='/') and (not_operator=='#')){
                    b=arrayWithNumbers[0];
                    if (c==0){
                        cout<<"Error: Division by zero";
                        return 1;
                    }
                    else{
                        c=b/c;
                        cout<< "Correct: "<<c<<" is the result";
                        return 0;
                    }


                }

                else {
                    cout<<"Error: Unknown character";
                    return 1;
                }
            }
        }
    }



//for 5 operands for 5 operands for 5 operands for 5 operands


    else if (length==19){
        while (getline(ss, elements, ' ') && counter < 11) {
            char cstr[elements.size() + 1];
            strcpy(cstr, elements.c_str());

            checkelement = elements[0];
            if (isdigit(checkelement)){
                stringstream geek(elements);
                int x = 0;
                geek >> x;
                arrayWithNumbers2[k]=x;
                k++;
                counter ++;

            }
            else{

                if (m==0){
                    op1 = elements[0];
                    if (counter==4){
                        l=1;
                    }
                }
                if (m==1){
                    op2 = elements[0];
                    if (counter==5 and l==1){
                        l=2;
                    }
                }
                if (m==2){
                    op3 = elements[0];
                    if (counter==7 and l==2){
                        l=3;
                    }
                }
                if (m==3){
                    op4 = elements[0];
                    not_operator = elements[0];
                }


                if ((counter==0) and (op1=elements[0])){
                    cout<<"Error: Expression must start with a number";
                    return 1;

                }

                m++;
                counter ++;


            }

        }

        if(m==5){

            if ((op1=='+')){

                a=arrayWithNumbers2[2];
                b=arrayWithNumbers2[3];
                c=a+b;
            }
            else if ((op1=='-')){
                a=arrayWithNumbers2[2];
                b=arrayWithNumbers2[3];
                c=a-b;

            }
            else if ((op1=='*')){
                a=arrayWithNumbers2[2];
                b=arrayWithNumbers2[3];
                c=a*b;
            }
            else if ((op1=='/')){
                a=arrayWithNumbers2[2];
                b=arrayWithNumbers2[3];
                c=a/b;
                if (b==0){

                    divisionbyzero=1;
                }

                }

            else {
                cout<<"Error: Unknown character";
                return 1;
            }


            if (divisionbyzero==1){
                cout<<"Error: Division by zero";
                return 1;}
            else{

                if ((op2=='+')){

                    b=arrayWithNumbers2[1];
                    c=c+b;
                }
                else if ((op2=='-')){
                    b=arrayWithNumbers2[1];
                    c=c-b;

                }
                else if ((op2=='*')){
                    b=arrayWithNumbers2[1];
                    c=c*b;
                }
                else if ((op2=='/')){
                    b=arrayWithNumbers2[1];
                    c=c/b;
                    if (b==0){

                        divisionbyzero=1;
                    }


                }
            }


                if (divisionbyzero==1){
                    cout<<"Error: Division by zero";
                    return 1;}
                else{

                    if ((op3=='+')){

                        b=arrayWithNumbers2[4];
                        c=c+b;
                    }
                    else if ((op3=='-')){
                        b=arrayWithNumbers2[4];
                        c=c-b;

                    }
                    else if ((op3=='*')){
                        b=arrayWithNumbers2[4];
                        c=c*b;
                    }
                    else if ((op3=='/')){
                        b=arrayWithNumbers2[4];
                        c=c/b;
                        if (b==0){

                            divisionbyzero=1;
                        }


                    }
                }










            if (divisionbyzero==1){
                cout<<"Error: Division by zero";
                return 1;}
            else {
                if ((op4=='+')){
                    b=arrayWithNumbers2[0];
                    c=c+b;
                    cout<< "Correct: "<<c<<" is the result";
                    return 0;
                }
                else if ((op4=='-')){
                    b=arrayWithNumbers2[0];
                    c=c-b;
                    cout<< "Correct: "<<c<<" is the result";
                    return 0;
                }
                else if ((op4=='*') ){
                    b=arrayWithNumbers2[0];
                    c=c*b;
                    cout<< "Correct: "<<c<<" is the result";
                    return 0;
                }
                else if ((op4=='/')){
                    b=arrayWithNumbers2[0];
                    if (b==0){
                        cout<<"Error: Division by zero";
                        return 1;
                    }
                    else{
                        c=c/b;
                        cout<< "Correct: "<<c<<" is the result";
                        return 0;
                    }
                }
                else {
                    cout<<"Error: Unknown character";
                    return 1;
                }
            }
        }
    }

//end for 5 operands for 5 operands for 5 operands for 5 operands







}//end of the program
