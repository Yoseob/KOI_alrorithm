#if 0 
#include <iostream>
#define MARGIN 65
using namespace std;


char charSet[101][11] = {0,};
int check[26] = {0,};
int ret = 0;
int lengthOne= 0;

void printfValid(int *arr){
    for(int i = 0; i<26; i++){
        
        printf("%d ",arr[i]);
        
    }
    cout << endl;
}
void validation(int index){
    
    char current;
    char i=0;
    int count = 0;
    int tempCheck[26]= {0,};
    for(int s= 0; s<26;tempCheck[s]=check[s],s++);
    int validSet[26]={0,};
    
    int validCount = 0;
    int unCount = 0;
    while ((current = charSet[index][i++])!= '\0') {
        int temp = current-MARGIN;
        if(tempCheck[temp] !=0){
            validSet[temp]++;
            tempCheck[temp]--;
            validCount++;
        }else{
            validSet[temp]--;
            unCount--;
        }
        count++;
    }
    
    
    for(int j = 0; j<26; validCount+=(check[j]-validSet[j]), j++);
    cout << count << " = " <<validCount<< " : ";
    if((validCount==lengthOne && count ==lengthOne) &&(unCount == -1 || unCount == 0)){  //사이즈는 같고 하나 다른게 있을때와
        ret++;
        cout << charSet[index] <<" ";
    }else if((validCount == lengthOne&&count == lengthOne-1) &&unCount == 0){ // 하나적고 틀린게 없을때 하나 만고 틀린게 없을때
        cout << charSet[index] <<" ";
        ret++;
    }else if( (validCount == lengthOne+1 && count == lengthOne)&& (unCount == -1)){
        cout << charSet[index] <<" ";
        ret++;
    }else if((count-1 == lengthOne&& (validCount == lengthOne || validCount-1 == lengthOne)) && unCount==0){
        ret++;
        cout << charSet[index] <<" ";
    }else if(count -1 == lengthOne && validCount-1==lengthOne && unCount == 0){
        ret++;
        cout << charSet[index] <<" ";
    }
    printfValid(validSet);
    
    
    
}

int main(){
    
    int size;
    cin >> size;
    for(int i= 0; i<size; i ++){
        cin >> charSet[i];
        if(i == 0){
            char temp ;
            while ((temp = charSet[i][lengthOne++])!= '\0') {
                check[temp-MARGIN] ++;
            }
        }
    }
    
    lengthOne--;
    cout << lengthOne << endl;
    for(int i = 0; i<size; i++){
        validation(i);
    }
    cout << ret-1 <<endl;
}

/*
 5
 DLDYTJQ
 DYTJQDL
 DYTJQFL
 DLDYV
 YODLSJQ
 
 4
 AABCC
 AABC
 ABBCC
 BCDBD
 */

#endif