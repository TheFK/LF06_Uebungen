#include <iostream>

using namespace std;

int main()
{
    int number;
    cout << "//POSITIV ODER NEGATIV//" << endl;
    cout << "Zahl: ";
    cin >> number;

    if(number >= 0){
        cout << number << " ist eine positive Zahl!" << endl;
    }
    else{
        cout << number << " ist eine negative Zahl!" << endl;
    }

    return 0;
}
