#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

double getKontostand(){
    string money;
    ifstream money_file("money.txt");
    if (money_file.is_open()){
        while (getline(money_file, money)){
            return stod(money.c_str());
        }
    }
    else{
        return 0;
    }
    return stod(money.c_str());
}

void setKontostand(double money){
    ofstream money_file("money.txt");
    money_file << money;
    money_file.close();
    return;
}

int getPIN(){
    string PIN;
    ifstream PIN_file("PIN.txt");
    if (PIN_file.is_open()){
        while (getline(PIN_file, PIN)){
            return atoi(PIN.c_str());
        }
    }
    else{
        return 0;
    }
    return atoi(PIN.c_str());
}

void setPIN(int PIN){
    ofstream PIN_file("PIN.txt");
    PIN_file << PIN;
    PIN_file.close();
    return;
}

//////////////////////////////////////
//////////////////////////////////////

void showKontostand(){
    cout << "Aktueller Kontostand: " << getKontostand() << endl;
}

void einzahlen(){
    cout << "Wieviel möchten Sie einzahlen?" << endl;
    double money;
    cin >> money;
    double kontostand = getKontostand();
    setKontostand(kontostand + money);
    showKontostand();
}

void auszahlen(){
    cout << "Wieviel möchten Sie abbuchen?" << endl;
    double money;
    cin >> money;
    double kontostand = getKontostand();
    setKontostand(kontostand - money);
    showKontostand();
}

void changePIN(){
    cout << "Geben Sie ihren neuen PIN ein: ";
    int PIN;
    cin >> PIN;
    setPIN(PIN);
    cout << "Ihr PIN wurde geändert." << endl;
}

void startMenu(){
    int input = -1;

    while(input != 9){
        cout << "Herzlich Willkommen bei der Super Bank" << endl;
        cout << "Was möchten Sie tun?" << endl;
        cout << endl;
        cout << "1: Kontostand anzeigen" << endl;
        cout << "2: Geld einzahlen" << endl;
        cout << "3: Geld abbuchen" << endl;
        cout << "4: PIN ändern" << endl;
        cout << endl;
        cout << "9: Beenden" << endl;
        cout << endl;

        cin >> input;

        switch (input){
            case 1:
                showKontostand();
                break;
            case 2:
                einzahlen();
                break;
            case 3:
                auszahlen();
                break;
            case 4:
                changePIN();
                break;
            case 9:
                break;
            default:
                cout << "Unbekannte Funktion" << endl;
                break;
        }

    }
}

void startAutomat(){
    int wrong_count = 0;

    while(wrong_count < 3){
        cout << "Geben Sie ihre PIN ein: ";
        int pin_input;
        cin >> pin_input;
        if(getPIN() == pin_input){
            startMenu();
            break;
        }
        else{
            wrong_count++;
            cout << "Falsche Eingabe. " << wrong_count << " Fehlversuch(e)" << endl;
        }
    }
    if(wrong_count >= 3){
        cout << "Karte wird einbehalten." << endl;
    }
}

int main()
{
    startAutomat();
    return 0;
}
