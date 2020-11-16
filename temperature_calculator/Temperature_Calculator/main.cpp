#include <iostream>

using namespace std;

int start_calc(){
    cout << "Willkommen beim Termperatur-Rechner" << endl;
    cout << "Was moechten Sie tun?" << endl;
    cout << "1: Celsius in Fahrenheit" << endl;
    cout << "2: Fahrenheit in Celsius" << endl;
    cout << "9: Beenden" << endl;

    int input;
    cin >> input;
    if(input == 1){ // Celsius to Fahrenheit
        cout << "Celsius in Fahrenheit umrechnen:" << endl;
        cout << "Bitte geben Sie eine Celsius Temperatur ein:" << endl;
        double celsius;
        cin >> celsius;
        double fahrenheit;
        fahrenheit = (celsius * 9/5) + 32;
        cout << "Temperatur in Fahrenheit: " << fahrenheit << " Grad Fahrenheit" << endl;
    }
    else if(input == 2){ // Fahrenheit to Celsius
        cout << "Fahrenheit in Celsius umrechnen:" << endl;
        cout << "Bitte geben Sie eine Fahrenheit Temperatur ein:" << endl;
        double fahrenheit;
        cin >> fahrenheit;
        double celsius;
        celsius = (fahrenheit - 32) * 5/9;
        cout << "Temperatur in Celsius: " << celsius << " Grad Celsius" << endl;
    }
    else if(input == 9){ // End Program
        cout << "Programm wird geschlossen." << endl;
        return 0;
    }
    else { // Error
        cout << "Fehlerhafte Eingabe" << endl;
        return 1;
    }

    cout << endl;
    return start_calc();
}

int main()
{
    return start_calc();
}
