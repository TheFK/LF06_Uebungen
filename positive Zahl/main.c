#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    cout << "positive Zahl?" << endl;
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
