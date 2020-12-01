#include <iostream>
#include <chrono>

using namespace std;

int* insertionSort(int numbers[], int arr_size){
    for(int i = 1; i < (arr_size-1); i++){
    int einzusortierender_wert = numbers[i];
        int j = i;
        while ((j > 0) && (numbers[j-1] > einzusortierender_wert)){
            numbers[j] = numbers[j - 1];
            j--;
        }
        numbers[j] = einzusortierender_wert;
    }
    return numbers;
}

int* selectionSort(int numbers[], int arr_size){
    int hoechsterIndex = arr_size - 1;
    int einfuegeIndex = 0;
    do{
        int minPosition = einfuegeIndex;
        for(int idx = einfuegeIndex + 1; idx <= hoechsterIndex; idx++){
          if(numbers[idx] < numbers[minPosition]){
            minPosition = idx;
          }
        }
        int save = numbers[minPosition];
        numbers[minPosition] = numbers[einfuegeIndex];
        numbers[einfuegeIndex] = save;
        einfuegeIndex = einfuegeIndex + 1;
    }
    while (einfuegeIndex < hoechsterIndex);
    return numbers;
}

int* bubbleSort(int numbers[], int arr_size){
    for(int n = arr_size; n>1; --n){
        for (int i = 0; i<n-1; ++i){
            if (numbers[i] > numbers[i+1]){
                int save = numbers[i];
                numbers[i] = numbers[i+1];
                numbers[i+1] = save;
            }
        }
    }
    return numbers;
}

void startMainMenu(){
    cout << "###Sort Times###" << endl;
    cout << endl;
    cout << "Wieviele Zahlen sollen sortiert werden (50.000 empfohlen)?" << endl;

    int arr_size;
    cin >> arr_size;

    srand(time(NULL));
    int bubble_numbers[arr_size];
    int selection_numbers[arr_size];
    int insertion_numbers[arr_size];
    for(int i = 0; i < arr_size; i++){
        int rand_number = rand() % 100000 + 1;
        bubble_numbers[i] = rand_number;
        selection_numbers[i] = rand_number;
        insertion_numbers[i] = rand_number;
    }

    cout << "Starte Bubble-Sort..." << endl;
    auto bubble_start = std::chrono::high_resolution_clock::now();
    int *bubble_sorted;
    bubble_sorted = bubbleSort(bubble_numbers, arr_size);
    auto bubble_finish = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> bubble_time = bubble_finish - bubble_start;
    cout << "Bubble-Sort Zeit: " << bubble_time.count() << "s" << endl;

    cout << "Starte Selection-Sort..." << endl;
    auto selection_start = std::chrono::high_resolution_clock::now();
    int *selection_sorted;
    selection_sorted = selectionSort(selection_numbers, arr_size);
    auto selection_finish = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> selection_time = selection_finish - selection_start;
    cout << "Selection-Sort Zeit: " << selection_time.count() << "s" << endl;

    cout << "Starte Insertion-Sort..." << endl;
    auto insertion_start = std::chrono::high_resolution_clock::now();
    int *insertion_sorted;
    insertion_sorted = insertionSort(insertion_numbers, arr_size);
    auto insertion_finish = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> insertion_time = insertion_finish - insertion_start;
    cout << "Insertion-Sort Zeit: " << insertion_time.count() << "s" << endl;
}

int main()
{
    startMainMenu();
    return 0;
}
