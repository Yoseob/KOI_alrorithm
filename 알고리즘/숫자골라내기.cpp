#if 0

#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int , int> m;

int arr[2];
int size;
void divd(long long input){
    
    m.clear();
    
    int temp = 0;
    for(int i = 0 ; i < size; i ++){
        cin >> temp;
        
        m[temp]++;
        
    }
}

int main(int argc, char** argv) {
    int T;
    int test_case;
    
    
    scanf("%d", &T);	//Codeground 시스템에서는 C++ 에서도 scanf 사용을 권장합니다.
    for(test_case = 1; test_case <= T; ++test_case) {
        
        
        cin >> size;
        divd(0);
        
        map<int,int> ::iterator iter = m.begin();
        int bufSize = 0;
        memset(arr, 0, sizeof(arr));
        
        for(iter = m.begin(); iter != m.end(); iter++){
            if(((*iter).second) %2 == 1){
                arr[bufSize++] = (*iter).first;
                if(bufSize ==2){
                    arr[0] = (arr[0] ^ arr[1]);
                    bufSize = 1;
                    
                }
            }
            
            
        }
        printf("Case #%d\n", test_case);
        cout << arr[0] <<endl;
        
    }
    
    return 0;	//	정상종료 시 반드시 0을 리턴해야 합니다.
}


/*
 1
 4
 2 5 3 3
 
 */
#endif