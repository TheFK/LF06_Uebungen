#include <iostream>

using namespace std;

void strCountMenu(){
    cout << "--AUFGABE 5.2 - ANZAHL DER ZEICHEN--" << endl;
    cout << "Geben Sie einen String ein: ";
    string input;
    cin >> input;

    string::size_type output;
    output = input.size();

    cout << "Anzahl der Zeichen: " << output << endl;
}

string strDotToColon(string input){
    string output;
    for(std::string::size_type i = 0; i < input.size(); i++){
        if(input[i] == ','){
            input[i] = '.';
        }
    }

    return input;
}

void strDotToColonMenu(){
    cout << "--AUFGABE 5.1 - PUNKTE IN KOMMA--" << endl;
    cout << "Geben Sie einen String ein: ";
    string input;
    cin >> input;

    string output = strDotToColon(input);

    cout << "Umgewandelt: " << output << endl;
}

int startmenu(){
    int input = -1;

    while(input != 9){
        cout << "--AUFGABEN 5 - ZEICHENKETTEN--" << endl;
        cout << "Welche Augabe soll gestartet werden?" << endl;
        cout << "1 - Punkte in Komma umwandeln" << endl;
        cout << "2 - Anzahl der Zeichen eines String" << endl;
        cout << "=====================================" << endl;
        cout << "9 - Beenden" << endl;
        cin >> input;
        cout << endl;
        cout << endl;

        switch(input){
            case 1:
                strDotToColonMenu();
                break;
            case 2:
                strCountMenu();
                break;
        }

        cout << endl;
        cout << endl;
    }
    return 0;
}

int main(){
    return startmenu();
}
