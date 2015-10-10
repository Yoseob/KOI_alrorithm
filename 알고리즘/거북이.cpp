#if 0

#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <math.h>
using namespace std;

class Point{
public:
    int i;
    int j;
    Point(){};
    Point(int i , int j ) : i(i), j(j){};
    Point plusPoint(Point p){
        this->i = this->i +p.i;
        this->j += p.j;
        return *this;
        
    }
    bool isEquals(Point p){
        return ((p.i == this->i)&&(p.j == this->j));
    }
};


class goobook{
    
    
public:
    Point minPoint, maxPoint ;
    Point gbDir;
    Point current;
    goobook(Point dir) : gbDir(dir),current({0,0}),maxPoint({0,0}),minPoint({0,0}){
        printcrnt();
    }
    
    void changeDir(Point p){
        gbDir = p;
        printcrnt();
    }
    Point goFront(){
        Point ret = current.plusPoint(gbDir);
        printcrnt();
        return ret;
    }
    Point goBack(Point p){
        Point ret = current.plusPoint(p);
        printcrnt();
        return ret;
    }
private:
    
    void printcrnt(){
        if(current.i > maxPoint.i){
            maxPoint.i = current.i;
        }
        if(current.j > maxPoint.j){
            maxPoint.j = current.j;
        }
        if(current.i < minPoint.i){
            minPoint.i = current.i;
        }
        if(current.j < minPoint.j){
            minPoint.j = current.j;
        }
    }
};

int changeDir(int dir , char c){
    if(c == 'R'){
        dir --;
    }else if(c=='L'){
        dir ++;
    }
    if(dir == -1) dir = 3;
    else if(dir ==4)  dir = 0;
    
    return dir;
}
map<int,Point> m;




Point getReverseDir(Point p){
    Point retPoint;
    
    if(p.isEquals(m[0])){
        retPoint = m[2];
    }else if(p.isEquals(m[1])){
        retPoint = m[3];
    }else if(p.isEquals(m[2])){
        retPoint = m[0];
    }else if(p.isEquals(m[3])){
        retPoint = m[1];
    }
    
    return retPoint;
}


int main(){
    int tc;
    cin >> tc;
    
    m[0] = {-1,0};
    m[1] = {0,-1};
    m[2] = {1,0};
    m[3] = {0,1};
    
    
    
    string input;
    while (tc--) {
        
        goobook gb(m[0]);
        int dirIndex = 0;
        
        cin >> input;
        
        char t;
        for(int i = 0 ;i<input.length(); i++){
            t= input.at(i);
            
            switch (t) {
                case 'R':
                case 'L':
                    dirIndex = changeDir(dirIndex, t);
                    gb.changeDir(m[dirIndex]);
                    break;
                case 'F':
                    gb.goFront();
                    break;
                    
                case 'B':
                    gb.goBack(getReverseDir(m[dirIndex]));
                    break;
                    
                default:
                    break;
            }
            
        }
        
        
        int lengthi = abs(gb.maxPoint.i)+abs(gb.minPoint.i);
        int lengthj =abs(gb.minPoint.j)+abs(gb.maxPoint.j);
        cout << lengthi* lengthj <<endl;
    }
}
#endif