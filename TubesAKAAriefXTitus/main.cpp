#include <iostream>
#include <string>
using namespace std;

struct University {
    string name;
    float score;
};

void iterativeInsertionSort(University arr[], int n) {
    for (int i = 1; i < n; i++) {
        University key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j].score < key.score) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void recursiveInsertionSort(University arr[], int n, int i = 1) {
    if (i >= n) {
        return;
    }

    University key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j].score < key.score) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;

    recursiveInsertionSort(arr, n, i + 1);
}

void printUniversities(University arr[], int size) {
    cout << "University Name\t\tOverall Score\n";
    cout << "----------------------------------------\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i].name << "\t\t" << arr[i].score << endl;
    }
}

int main() {
    int n;

    cout << "Enter the number of universities: ";
    cin >> n;

    University* universities = new University[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter name of university " << (i + 1) << ": ";
        cin >> universities[i].name;
        cout << "Enter overall score of university " << (i + 1) << ": ";
        cin >> universities[i].score;
    }

    int sortChoice;
    cout << "\nChoose sorting method:\n1. Iterative\n2. Recursive\nChoice: ";
    cin >> sortChoice;

    if (sortChoice == 1) {
        iterativeInsertionSort(universities, n);
    } else if (sortChoice == 2) {
        recursiveInsertionSort(universities, n);
    } else {
        cout << "Invalid sorting method choice!" << endl;
        delete[] universities;
        return 1;
    }

    cout << "\nSorted University Data (Descending Order):\n";
    printUniversities(universities, n);

    delete[] universities;
    return 0;
}
