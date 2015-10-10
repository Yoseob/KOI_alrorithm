#if 0
#include <iostream>
#include <string>
using namespace std;
string str;
int main(){
    cin >> str;
    int pos = 0;
    
    string arr[8] = {"c=","c-","dz=","d-","lj","nj","s=","z="};
    string swapStr ;
    string temp = "*";
    for(int i = 0 ; i < 8 ; i++){
        swapStr = arr[i];
        if(str.find(swapStr) != string::npos){
            while((pos=str.find(swapStr)) !=string::npos){
                str.erase(pos,swapStr.length());
                str.insert(pos, temp);
            }
        }
    }
    cout << str.size() <<endl;
}
#endif