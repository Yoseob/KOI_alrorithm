#if 0
#include <iostream>
#include <stdio.h>
using namespace std;

int whatMagor(char ch){
    
    int m = -1;
    switch (ch) {
        case 'A':
        case 'D':
        case 'E':
            m = 1;
            break;
        case 'C':
        case 'F':
        case 'G':
            m = 0;
            break;
            
        default:
            break;
    }
    
    return  m;
}
int main(){
    //다장조라면 C-major, 가단조라면 A-minor를 출력한다. 항상 둘 중 하나이고, 마디의 마지막음의 개수까지 같은 경우는 없다.
    char input;
    int majors[2] = { 0,}; //   da = 0 ga = 1;
    char pre = '|';
    while ((input = getchar())!= '\n') {
        if(pre == '|'){
            majors[whatMagor(input)]++;
        }
        pre = input;
    }
    if(majors[0] == majors[1]){
        majors[whatMagor(pre)]++;
    }
    int maxMa = majors[0] > majors[1] ? 0 : 1;
    if(maxMa){
        cout << "A-minor"<<endl;
    }else{
        cout << "C-major"<<endl;
    }
    
}
#endif