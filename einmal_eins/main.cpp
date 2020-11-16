#include <iostream>

using namespace std;

void startTable(){
    cout << "|     #|  1  ||  2  ||  3  ||  4  ||  5  ||  6  ||  7  ||  8  ||  9  ||  10 |" << endl;
    cout << "==============================================================================" << endl;
    for(int i = 1; i <= 10; i++){
        printf("|%3d  #", i);
        for(int j = 1; j <= 10; j++){
            printf("|%3d  |", i*j);
        }
        cout << endl;
    }
}

void startSingle(){
    cout << "Geben Sie eine Zahl ein: ";
    int number;
    cin >> number;
    for(int i = 1; i <= 10 ; i++){
        cout << number << "*" << i << " = " << number*i << endl;
    }
}

int startEinMalEinsRechner(){
    cout << "//Einmal-Eins-Rechner//" << endl;
    cout << "=======================" << endl;
    cout << "Was möchten Sie tun?" << endl;;
    cout << "1: Einmal-Eins einer Zahl ausgeben" << endl;
    cout << "2: Tabelle der Einmal-Eins 1-10 ausgeben" << endl;
    cout << "9: Programm beenden" << endl;

    int input;
    cin >> input;
    switch(input){
        case 1:
            startSingle();
            break;
        case 2:
            startTable();
            break;
        case 9:
            cout << "Programm wird beendet" << endl;
            break;
        default:
            cout << "Fehlerhafte Eingabe" << endl;
    }
    return 0;
}

int main(){
    return startEinMalEinsRechner();
}
