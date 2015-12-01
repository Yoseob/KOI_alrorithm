#warning Have to Solve
#if 0
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;


string inputs[100];
int size;
void init(){
    cin >> size;
    for(int i = 0 ; i <size; i++){
        cin >> inputs[i];
    }
}


bool impl(string s , string s1){
    for(int i = 0; i <s1.size(); i++){
        string temp  = s1;
        
        temp.erase(i,1);
        if(temp == s){
            cout <<temp <<endl;
            return true;
        }
    }
    return false;
}
bool comp(char c ,char c2){
    return c<c2;
}

bool isSubString(string s , string s2){
    
    for(int i = 0; i <s2.size(); i++){
        string temp  = s2;
        
        temp.erase(i,1);
        if(s.find(temp) != string::npos){
            
            return true;
        }
    }
    return false;
}

bool isSame(string str , string str1){
    
    sort(str.begin(), str.end(), comp);
    sort(str1.begin(), str1.end(), comp);
    
    if(str == str1) {
        return true;
    }
    
    int absNumber = int(str.length() - str1.length());
    if(abs(absNumber) > 1){
        return false;
    }
    if (absNumber == 0){
        return isSubString(str, str1);
    }
    
    if(str.size() <  str1.size()){
        return impl(str ,str1);
    }else if(str.size() > str1.size()){
        return impl(str1 ,str);
    }
    
    return false;
}

void findKindlyString(){
    string target = inputs[0];
    int sameCount = 0;
    for(int i = 1; i <size; i++){
        if(isSame(target, inputs[i])){
            sameCount++;
        }
    }
    cout <<sameCount <<endl;
}
int main(){
    
    init();
    findKindlyString();
    
    
    
}
#endif