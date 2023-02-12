#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int main(){
    srand(time(nullptr));
    int map[10][10] = {};
    int HeroX = 2; //Monday
    int HeroY = 7; //6509050044 -> 7
    int MonsterX = 8; // 10 - day(Monday is 2) = 8
    int MonsterY = 4; //650905004 -> 4 <-7
    int TreeX = rand() % 10;
    int TreeY = rand() % 10;
    int _Taxicab = abs(MonsterX - HeroX) + abs(MonsterY - HeroY);
    float _Euclidean = sqrt(pow(MonsterX - HeroX,2)+pow(MonsterY - HeroY,2));
    int _Chebyshev = (abs(MonsterX - HeroX) > abs(MonsterY - HeroY)) ? abs(MonsterX - HeroX) : abs(MonsterY - HeroY);

    map[TreeX][TreeY] = 1;
    map[HeroX][HeroY] = 2;
    map[MonsterX][MonsterY] = 3;

    for (int i = 9; i > -1; i--){
        for (int j = 0; j < 10; j++){
            cout << map[j][i] << " ";
        }
        cout << endl;
    }
    cout << "Taxicap distance = " << _Taxicab << endl;
    cout << "Euclidean distance = " << _Euclidean << endl;
    cout << "Chebyshev distance = " << _Chebyshev << endl;
    return 0; // Mr. Pattanapol Saelim 65090500447
}