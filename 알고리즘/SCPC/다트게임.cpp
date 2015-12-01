#if 0 

#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

class Point{
public:
    int y , x ;
    Point(int x , int y):x(x),y(y) {}
};


double where;
int scores[] ={6,13,4,18,1,20,5,12,9,14,11,8,16,7,19,3,17,2,15,10};
int a,b,c,d,e;

void init(){
    cin >> a>>b>>c>>d>>e;
}
double whereisPin(Point p){
    
    return sqrt(pow(p.x, 2) + pow(p.y, 2));
    
}
double getPointAngle(Point p){
    double ang =atan2(p.y, p.x)* 180 / 3.14f;
    
    if(ang <0){
        ang +=360;
    }
    ang+=9;
    if(ang> 360){
        ang-=360;
    }
    return ang;
}


bool isTriple(){
    
    return where >b && where < c;
}

bool isbull(){
    
    return where < a;
}



int main(int argc, char** argv) {
    int T;
    int test_case;
    
    
    scanf("%d", &T);	//Codeground 시스템에서는 C++ 에서도 scanf 사용을 권장합니다.
    for(test_case = 1; test_case <= T; ++test_case) {
        
        
        
        int x; int y;
        init();
        int total = 0;
        int pins = 0;
        cin >> pins;
        for(int i = 0 ; i < pins; i ++){
            cin >> x >> y ;
            Point point(x,y);
            where = whereisPin(point);
            if(where < e){
                int s = 0;
                if(isbull()){
                    s =50;
                }else{
                    int bonus;
                    double myPoint = getPointAngle(point);
                    myPoint =  (myPoint/18) ;
                    int score = scores[(int)myPoint];
                    if(where > d){
                        bonus = 2;
                    }else if(isTriple()){
                        bonus = 3;
                    }else{
                        bonus = 1;
                    }
                    
                    s =(score * bonus);
                }
                
                total+=s;
                
            }
            
        }
        
        printf("Case #%d\n", test_case);
        cout << total <<endl;
    }
    
    return 0;	//	정상종료 시 반드시 0을 리턴해야 합니다.
}

/*
 
 1
 10 50 60 80 90
 5
 
 */
#endif