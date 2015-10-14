#if 0
#include <cstdio>
#include <map>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n , k ;

vector<int> v;
//map<int , int> m;
int m[200];
int maxVal;


bool comp(int a ,int b){
    return a > b;
}
void init(){
    cin >> n  >> k;
    int input;
    
    v.clear();
    for(int i = 0 ; i < n; i ++){
        cin >> input;
        v.push_back(input);
    }
    
    sort(v.begin(), v.end(), comp);
    
    
}

int takeSubject(){
    
    int sum = 0;
    for(int i = 0 ; i< k ; i++){
        sum+= v[i];
    }
    return sum;
    
}
int main(int argc, char** argv) {
    int T;
    int test_case;
    /* 아래 freopen 함수는 input.txt 를 read only 형식으로 연 후,
     앞으로 표준 입력(키보드) 대신 input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
     만약 본인의 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면,
     그 아래에서 cin 을 사용하여 표준 입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
     따라서 본인의 PC 에서 테스트 할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 됩니다.
     단, 이 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다. */
    //freopen("input.txt", "r", stdin);
    
    scanf("%d", &T);	//Codeground 시스템에서는 C++ 에서도 scanf 사용을 권장합니다.
    for(test_case = 1; test_case <= T; ++test_case) {
        //	이 부분에서 알고리즘 프로그램을 작성하십시오.
        
        
        init();
        printf("Case #%d\n", test_case);
        cout << takeSubject() <<endl;
        
        
    }
    
    return 0;	//	정상종료 시 반드시 0을 리턴해야 합니다.
}

/*
 1
 5 2
 20 50 30 30 50
 */
#endif