#if 0
#include <iostream>
#include <stdio.h>

using namespace std;

int textToNumber(char ch){
    int ret =0;
    switch (ch) {
        case 'A':
        case 'B':
        case 'C':
            ret = 2;
            break;
            
        case 'D':
        case 'E':
        case 'F':
            ret = 3;
            break;
        case 'G':
        case 'H':
        case 'I':
            ret = 4;
            break;
        case 'J':
        case 'K':
        case 'L':
            ret = 5;
            break;
        case 'M':
        case 'N':
        case 'O':
            ret = 6;
            break;
        case 'P':
        case 'Q':
        case 'R':
        case 'S':
            ret =7;
            break;
        case 'T':
        case 'U':
        case 'V':
            ret = 8;
            break;
        case 'W':
        case 'X':
        case 'Y':
        case 'Z':
            ret = 9;
            break;
            
        default:
            break;
    }
    return ret+1;
}

int main(){
    
    int sum = 0;
    char input;
    while ((input = getchar())!= '\n') {
        sum += textToNumber(input);
    }
    cout << sum <<endl;
    
}
#endif