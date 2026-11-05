#include <iostream>

using namespace std;

int comparison = 0, assignment = 0;

void bubblesort(int*& tab, int size){
    bool check = false;
    ++assignment;
    int repeat = 0;
    ++assignment;

    ++comparison;
    while (check == false){
        check = true;
        ++assignment;

        ++comparison;
        assignment += 2;
        for (int i = 0; i < size - 1 - repeat; ++i){
            ++comparison;
            if (tab[i] > tab[i + 1]){
                swap(tab[i], tab[i + 1]);
                assignment += 3;
                check = false;
                ++assignment;
            }

            ++comparison;
            ++assignment;
        }

        ++repeat;
        ++assignment;

        ++comparison;
    }
}

int main(){
    int n;
    cin >> n;
    int* tab = new int[n];
    for (int i = 0; i < n; ++i){
        cin >> tab[i];
    }

    bubblesort(tab, n);

    for (int i = 0; i < n; ++i){
        cout << tab[i] << " ";
    }

    cout << endl;
    cout << comparison << " " << assignment;

    delete [] tab;
}