#include <iostream>

using namespace std;

float calcEdgeLength(float height){
    return height*12;
}

float calcSurface(float height){
    return height*height*6;
}

float calcVolume(float height){
    return height * height * height;
}

int startMainMenu(){
    int input = -1;

    while(input != 9){
        cout << "======================================" << endl;
        cout << "=========== Würfelrechner ============" << endl;
        cout << "= (Volumen, Oberfläche, Kantenlänge) =" << endl;
        cout << "Was möchten Sie tun?" << endl;
        cout << "1: Volumen berechnen" << endl;
        cout << "2: Oberfläche berechnen" << endl;
        cout << "3: Länge aller Kanten berechnen" << endl;
        cout << endl;
        cout << "9: Programm beenden" << endl;
        cout << "======================================" << endl;

        cin >> input;

        float height = 0;
        if(input == 1 || input == 2 || input == 3){
            cout << "Geben Sie die Höhe des Würfels ein (cm): ";
            cin >> height;
        }

        switch (input){
            case 1:
                cout << "Das Volumen des Würfel beträgt: " << calcVolume(height) << "cm^3" << endl;
                cout << endl;
                break;
            case 2:
                cout << "Die Oberfläche des Würfel beträgt: " << calcSurface(height) << "cm^2" << endl;
                cout << endl;
                break;
            case 3:
                cout << "Die Länge aller Kanten des Würfel beträgt: " << calcEdgeLength(height) << "cm" << endl;
                cout << endl;
                break;
            case 9:
                cout << "Programm wird beendet" << endl;
                break;
            default:
                cout << "Ungültige Eingabe!" << endl;
                break;
        }

        cout << endl;
    }
}

int main(){
    return startMainMenu();
}
