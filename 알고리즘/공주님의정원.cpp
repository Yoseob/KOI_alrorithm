#if 0
#include <iostream>
#include <list>

using namespace std;


class Date{
    public :
    int month;
    int day;
    
    Date(){}
    Date(int m , int d) : month(m),day(d){
        
    }
    
    int calcTerm(Date d){
        
        int tempTerm = 0;
        for(int i = month; i < d.month ; i ++){
            switch (i) {
                case 4:
                case 6:
                case 9:
                case 11:
                    tempTerm +=30;
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    tempTerm+=31;
                    break;
                default:
                    tempTerm+=28;
                    break;
            }
            
        }
        
        tempTerm-=day;
        tempTerm+=d.day;
        return tempTerm;
    }
};

class Flower{
public:
    int term;
    Date begin,end;
    Flower(Date d , Date e) : begin(d), end(e){
        term = d.calcTerm(e);
    }
    Flower(){}
};

Date start(3,1) , finish(11,30);

int main(){
    
    Flower list[10000];
    
    
    int numberofFlower = 0;
    cin >> numberofFlower;
    
    int a,b,c,d;
    int i ;
    for(i = 0; i<numberofFlower; i ++) {
        cin >>a >>b >>c >>d ;
        Flower f(Date(a,b),Date(c,d));
        list[i] = f;
    }
    
    
}


#endif