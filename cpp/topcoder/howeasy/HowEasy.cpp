#include "HowEasy.h"

int HowEasy::pointVal(string str)
{
    string strsub, token;
    size_t pos,  next, isthere;
    bool flag;
    int wcount=0, length=0, avg=0, d=250;
    float average;
    pos = str.find_first_of(" ");
    token = str.substr(0, pos);
    while(pos != string::npos){
        flag = true;
        // Logic to see if token is word
        isthere = token.find_first_of("0123456789");
        if (isthere != string::npos){
            flag = false;
        }
        else if (token[0] == '.'){
            flag = false;
        }
        else{
            isthere = token.find_first_of(".");
            if (isthere != token.find_last_of("."))
                    flag = false;
        }
        if (flag){
            wcount+=1;
            length+=token.length();
        }
        next = str.find_first_of(" ", pos+1);
        token = str.substr(pos+1, next-pos-1);
        pos = next;
    }
    // Logic to see if token is word
    flag = true;
    // Logic to see if token is word
    isthere = token.find_first_of("0123456789");
    if (isthere != string::npos){
        flag = false;
    }
    else if (token[0] == '.'){
        flag = false;
    }
    else{
        isthere = token.find_first_of(".");
        if (isthere != token.find_last_of("."))
                flag = false;
    }
    if (flag){
        wcount+=1;
        length+=token.length();
    }
    if (wcount != 0)
        avg = length/wcount;
    if (avg <= 3){
        d = 250;
    }
    else if (avg <=5){
        d = 500;
    }
    else {
        d = 1000;
    }
    return d;
}
