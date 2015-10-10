#if 0


#if 0
#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool isPillrand(string str){
    
    int finish = (int)str.length() - 1;
    int pillrand = false;
    for(int i = 0; i <str.length()/2;i++){
        
        if(str[i] == str[finish-i]){
            pillrand = true;
        }else{
            pillrand = false;
            return pillrand;
        }
    }
    return pillrand;
}


vector<string> pills , unPills;
string input;
int inputSize;

void inputText(){
    inputSize = 0;
    cin >>inputSize;
    
    //Do clear before input;
    pills.clear();
    unPills.clear();
    
    while (inputSize--) {
        cin >> input;
        if(isPillrand(input)){
            pills.push_back(input);
        }else{
            unPills.push_back(input);
        }
    }
}



bool machingPillWithUnPills(string &str){
    vector<string>::iterator iter = unPills.begin();
    string currentPillRand = str;
    string temp;
    while (iter != unPills.end()) {
        
        if(str != (*iter)) {
            currentPillRand = str + (*iter);
            if(isPillrand((currentPillRand))){
                str = currentPillRand;
                return true;
            }
        }
        iter++;
    }
    
    return false;
}
bool machingPillWithPills(string &str){
    vector<string>::iterator iter = pills.begin();
    string currentPillRand = str;
    string temp;
    while (iter != pills.end()) {
        
        if(str != (*iter)){
            currentPillRand = str + (*iter);
            if(isPillrand((currentPillRand))){
                str = currentPillRand;
                return true;
            }
        }
        iter++;
    }
    
    return false;
}


bool findPillRandText(){
    
    vector<string>::iterator iter = pills.begin();
    string currentPillRand;
    while (iter != pills.end()) {
        currentPillRand = (*iter);
        if(machingPillWithUnPills(currentPillRand)){
            cout << currentPillRand <<endl;
            return true;
        }
        if(machingPillWithPills(currentPillRand)){
            cout << currentPillRand <<endl;
            return true;
        }
        
        iter++;
    }
    
    return false;
}

bool findUnPillRandText(){
    
    vector<string>::iterator iter = unPills.begin();
    string currentPillRand;
    while (iter != unPills.end()) {
        currentPillRand = (*iter);
        if(machingPillWithUnPills(currentPillRand)){
            cout << currentPillRand <<endl;
            return true;
        }
        if(machingPillWithPills(currentPillRand)){
            cout << currentPillRand <<endl;
            return true;
        }
        iter++;
    }
    
    return false;
}

int main(){
    
    int tc;
    cin >> tc;
    
    while (tc--) {
        inputText();
        if(!findPillRandText()){
            if(!findUnPillRandText()){
                cout << 0 <<endl;
            }
        }
    }
    
}
#endif




#include <iostream>
#include <string>
#include <vector>

using namespace std;


bool isPillrand(string str){
    
    int finish = (int)str.length() - 1;
    int pillrand = false;
    for(int i = 0; i <str.length()/2;i++){
        
        if(str[i] == str[finish-i]){
            pillrand = true;
        }else{
            pillrand = false;
            return pillrand;
        }
    }
    return pillrand;
}


vector<string> pills;
string input;
int inputSize;

void inputText(){
    inputSize = 0;
    cin >>inputSize;
    
    //Do clear before input;
    pills.clear();
    while (inputSize--) {
        cin >> input;
        
        pills.push_back(input);
        
    }
}
bool machingPillWithPills(string &str){
    vector<string>::iterator iter = pills.begin();
    string currentPillRand = str;
    string temp;
    while (iter != pills.end()) {
        
        if(str != (*iter)){
            currentPillRand = str + (*iter);
            if(isPillrand((currentPillRand))){
                str = currentPillRand;
                return true;
            }
            
            currentPillRand = (*iter)+str;
            if(isPillrand((currentPillRand))){
                str = currentPillRand;
                return true;
            }
        }
        iter++;
    }
    
    return false;
}
bool machingPillWithPills(string &str ,vector<string>::iterator iter1){
    vector<string>::iterator iter = pills.begin();
    string currentPillRand = str;
    string temp;
    while (iter != pills.end()) {
        
        if(iter1 != (iter)){
            currentPillRand = str + (*iter);
            if(isPillrand((currentPillRand))){
                str = currentPillRand;
                return true;
            }
            
            currentPillRand = (*iter)+str;
            if(isPillrand((currentPillRand))){
                str = currentPillRand;
                return true;
            }
        }
        iter++;
    }
    
    return false;
}


bool findUnPillRandText(){
    
    vector<string>::iterator iter = pills.begin();
    string currentPillRand;
    while (iter != pills.end()) {
        currentPillRand = (*iter);
        if(machingPillWithPills(currentPillRand , iter)){
            cout << currentPillRand <<endl;
            return true;
        }
        iter++;
    }
    
    return false;
}


int main(){
    
    int tc;
    cin >> tc;
    
    while (tc--) {
        inputText();
        if(!findUnPillRandText()){
            cout << 0 <<endl;
        }
        
    }
    
}




#endif