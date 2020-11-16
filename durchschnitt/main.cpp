#include <iostream>

using namespace std;

void aufgabeA(){
    float summe = 0;
    float input;
    for(int i = 1; i <= 10; i++){
        cout << "Zahl " << i << " eingeben: ";
        cin >> input;
        summe += input;
    }

    cout << "Durchschnitt: " << summe/10.0;
}

void aufgabeB(){
    int anzahl;
    float summe = 0;
    float input;

    cout << "Anzahl: ";
    cin >> anzahl;
    for(int i = 1; i <= anzahl; i++){
        cout << "Zahl " << i << " eingeben: ";
        cin >> input;
        summe += input;
    }

    cout << "Durchschnitt: " << summe/anzahl;
}

void aufgabeC(){
    int anzahl = 0;
    float summe = 0;
    float input = 1;

    while(input > 0 && input <= 1000){
        cout << "Zahl eingeben: ";
        cin >> input;
        summe += input;
        anzahl++;
    }

    cout << "Durchschnitt: " << summe/anzahl;
}

int startMenu(){
    cout << "1: a)" << endl;
    cout << "2: b)" << endl;
    cout << "3: c)" << endl;

    int input;
    cin >> input;

    switch(input){
        case 1:
            aufgabeA();
            break;
        case 2:
            aufgabeB();
            break;
        case 3:
            aufgabeC();
            break;
    }
    return 0;
}

int main()
{
    return startMenu();
}
