#include <iostream>

using namespace std;

int startFakultaetRechner(){
    cout << "///Fakultät-Rechner///" << endl;
    cout << "Zahl eingeben: ";
    int input;
    cin >> input;

    if(input >= 0){
        int fakultaet = 1;

        for(int i = 1; i <= input; i++){
            fakultaet = fakultaet * input;
        }

        cout << "Die Fakultät von "  << input << " ist: " << fakultaet << endl;
    }
    else{
        cout << "Fakultät von negativen Zahlen ist nicht definiert" << endl;
    }

    return 0;
}

int main(){
    return startFakultaetRechner();
}
