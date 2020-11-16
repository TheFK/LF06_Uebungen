#include <iostream>

using namespace std;

void dollarToEuro(){
    cout << "Geben Sie den aktuellen Wechselkurs ein: ";
    double kurs;
    cin >> kurs;

    cout << "Geben Sie den Dollar-Wert ein: ";
    double dollar;
    cin >> dollar;

    double euro;
    euro = dollar * kurs;
    cout << dollar << " Dollar sind: " << euro << " Euro" << endl;
    cout << endl;
}

void euroToDollar(){
    cout << "Geben Sie den aktuellen Wechselkurs ein: ";
    double kurs;
    cin >> kurs;

    cout << "Geben Sie den Euro-Wert ein: ";
    double euro;
    cin >> euro;

    double dollar;
    dollar = euro * kurs;
    cout << euro << " Euro sind: " << dollar << " Dollar" << endl;
    cout << endl;
}

int start_menu(){
    cout << "//WECHSELKURS-RECHNER//" << endl;
    cout << "Hier können Sie Euro in Dollar und umgekehrt umrechnen lassen" << endl;
    cout << endl;
    cout << "Was möchten Sie tun?" << endl;
    cout << "1: Dollar -> Euro" << endl;
    cout << "2: Euro -> Dollar" << endl;
    cout << "..." << endl;
    cout << "9: Programm beenden" << endl;

    int input;
    cin >> input;
    if(input == 1){
        dollarToEuro();
    }
    else if(input == 2){
        euroToDollar();
    }
    else if(input == 9){
        return 0;
    }
    else{
        cout << "Fehlerhafte Eingabe" << endl;
        return 1;
    }

    start_menu();
}


int main()
{
    return start_menu();
}
