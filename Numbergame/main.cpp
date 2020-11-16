#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

int getScore(){
    string score;
    ifstream score_file("highscore.txt");
    if (score_file.is_open()){
        while (getline(score_file, score)){
            return atoi(score.c_str());
        }
    }
    else{
        return 0;
    }
    return atoi(score.c_str());
}

void setScore(int score){
      ofstream score_file("highscore.txt");
      score_file << score;
      score_file.close();
}

int checknumbers(int input, int number_1, int number_2, int number_3, bool number_1_guessed, bool number_2_guessed, bool number_3_guessed){
    if(input == number_1 && number_1_guessed == false){
        return 1;
    }
    else if(input == number_2 && number_2_guessed == false){
        return 2;
    }
    else if(input == number_3 && number_3_guessed == false){
        return 3;
    }
    else{
        return 0;
    }
}

void startGameRound(int round){
    int number_1 = rand() % round + 1;
    int number_2 = rand() % round + 1;
    int number_3 = rand() % round + 1;

    bool number_1_guessed = false;
    bool number_2_guessed = false;
    bool number_3_guessed = false;

    cout << endl;
    cout << endl;
    cout << "=================================" << endl;
    cout << "========== NUMBER GAME ==========" << endl;
    cout << "========== HIGHSCORE " << getScore() << " ==========" << endl;
    cout << "==========   ROUND " << round << "   ==========" << endl;
    cout << endl;
    cout << "Product is: " << number_1 * number_2 * number_3 << endl;
    cout << "Sum is: " << number_1 + number_2 + number_3 << endl;
    cout << "=================================" << endl;

    int input;
    int result;

    input = -1;
    cout << "Guess the first number: (0 to exit)" << endl;
    cin >> input;
    if(input == 0){
        return;
    }
    result = checknumbers(input, number_1, number_2, number_3, number_1_guessed, number_2_guessed, number_3_guessed);
    if(result == 0){
        cout << "Wrong number. Restart Level" << endl;
        startGameRound(round);
        return;
    }
    else if(result != 0){
        cout << "First number guessed" << endl;
        if(result == 1){
            number_1_guessed = true;
        }
        else if(result == 2){
            number_2_guessed = true;
        }
        else if(result == 3){
            number_3_guessed = true;
        }
    }

    input = -1;
    cout << "Guess the second number: (0 to exit)" << endl;
    cin >> input;
    if(input == 0){
        return;
    }
    result = checknumbers(input, number_1, number_2, number_3, number_1_guessed, number_2_guessed, number_3_guessed);
    if(result == 0){
        cout << "Wrong number. Restart Level" << endl;
        startGameRound(round);
        return;
    }
    else if(result != 0){
        cout << "Second number guessed" << endl;
        if(result == 1){
            number_1_guessed = true;
        }
        else if(result == 2){
            number_2_guessed = true;
        }
        else if(result == 3){
            number_3_guessed = true;
        }
    }

    input = -1;
    cout << "Guess the third number: (0 to exit)" << endl;
    cin >> input;
    if(input == 0){
        return;
    }
    result = checknumbers(input, number_1, number_2, number_3, number_1_guessed, number_2_guessed, number_3_guessed);
    if(result == 0){
        cout << "Wrong number. Restart Level" << endl;
        startGameRound(round);
        return;
    }
    else if(result != 0){
        cout << "Third number guessed" << endl;
        if(result == 1){
            number_1_guessed = true;
        }
        else if(result == 2){
            number_2_guessed = true;
        }
        else if(result == 3){
            number_3_guessed = true;
        }
    }

    if(round > getScore()){
        setScore(round);
    }
    cout << "Level passed! Next Level:" << endl;
    startGameRound(round + 1);
    return;
}

void showInstructions(){
    cout << endl;
    cout << endl;
    cout << "=================================" << endl;
    cout << "========== NUMBER GAME ==========" << endl;
    cout << "========== HIGHSCORE " << getScore() << " ==========" << endl;
    cout << "========== INSTRUCTIONS =========" << endl;
    cout << "Each Round u get a sum and a product of three numbers > 1." << endl;
    cout << "Guess the numbers to get to the next level" << endl;
    cout << "Wrong guess will restart the level with new numbers" << endl;
    return;
}

int startMainMenu(){
    int input = -1;

    while(input != 9){
        cout << endl;
        cout << endl;
        cout << "=================================" << endl;
        cout << "========== NUMBER GAME ==========" << endl;
        cout << "========== HIGHSCORE " << getScore() << " ==========" << endl;
        cout << "=================================" << endl;
        cout << "1: Start Game" << endl;
        cout << "2: How to play" << endl;
        cout << endl;
        cout << "9: End Game" << endl;
        cout << "=================================" << endl;

        cin >> input;
        switch (input){
            case 1:
                startGameRound(1);
                break;
            case 2:
                showInstructions();
                break;
            default:
                cout << "Unknown input" << endl;
                break;
        }
    }
}

int main(){
    return startMainMenu();
}
