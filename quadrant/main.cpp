#include <iostream>
#include <string.h>

using namespace std;

int calcQuadrant(){
    cout << "// PUNKTE IM QUADRANT" << endl;
    cout << "Geben Sie die X-Koordinate ein: ";
    int x;
    cin >> x;
    cout << "Geben Sie die Y-Koordinate ein: ";
    int y;
    cin >> y;

    if(x == 0 && y == 0){
        cout << "Es handelt sich um den Nullpunkt" << endl;
    }
    else if(x > 0 && y > 0){
        cout << "Der Punkt befindet sich im ersten Quadranten!" << endl;
    }
    else if(x < 0 && y > 0){
        cout << "Der Punkt befindet sich im zweiten Quadranten!" << endl;
    }
    else if(x < 0 && y < 0){
        cout << "Der Punkt bedindet sich im dritten Quadranten!" << endl;
    }
    else if(x > 0 && y < 0){
        cout << "Der Punkt befindet sich im vierten Quadranten!" << endl;
    }
    else if(x == 0 && y > 0){
        cout << "Liegt auf dem positiven Teil der Y-Achse" << endl;
    }
    else if(x == 0 && y < 0){
        cout << "Liegt auf dem negativen Teil der Y-Achse" << endl;
    }
    else if(x > 0 && y == 0){
        cout << "Liegt auf dem positiven Teil der X-Achse" << endl;
    }
    else if(x < 0 && y == 0){
        cout << "Liegt auf dem negativen Teil der X-Achse" << endl;
    }

    cout << "Beenden?" << endl;
    cout << "1: Ja" << endl;
    cout << "Andere Taste: Nein" << endl;
    int input;
    cin >> input;
    if(input == 1){
        return 0;
    }
    else{
        return calcQuadrant();
    }
}

int main(){
    return calcQuadrant();
}
