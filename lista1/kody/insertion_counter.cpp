#include <iostream>

using namespace std;

int assignment = 0, comparison = 0;

//zwykły insertion sort
void insertionsort(int*& tab, int size){
    int val, j;
    ++assignment; // z for-a
    for (int i = 1; i < size; ++i){
        val = tab[i];
        j = i - 1;
        assignment += 2;

        comparison += 2; // z while-a
        while (j >= 0 && val < tab[j]){
            tab[j + 1] = tab[j];
            ++assignment;
            --j;
            ++assignment;

            comparison += 2;
        }
        tab[j + 1] = val;
        ++assignment;

        ++comparison;
        ++assignment; // z for-a
    }
}

//modyfikacja insertion sort
void insertionsort2(int*& tab, int size){
    int val1, val2, j;

    comparison += 2;
    if (size > 1 && tab[0] > tab[1]){
        swap(tab[0], tab[1]);
        assignment += 3;
    }

    assignment += 2;
    ++comparison;
    for (int i = 2; i < size; ++i){
        val1 = tab[i];
        ++assignment;
        ++comparison;
        if (i + 1 < size){
            val2 = tab[i + 1];
            ++assignment;

            ++comparison;
            if (val2 < val1){
                swap(val1, val2);
                assignment += 3;
            }
            j = i - 1;
            ++assignment;

            comparison += 2;
            while (j >= 0 && val2 < tab[j]){
                tab[j + 2] = tab[j];
                --j;
                assignment += 2;

                comparison += 2;
            }
            tab[j + 2] = val2;
            ++assignment;

            comparison += 2;
            while(j >= 0 && val1 < tab[j]){
                tab[j + 1] = tab[j];
                --j;
                assignment += 2;

                comparison += 2;
            }
            tab[j + 1] = val1;
            ++i;
            assignment += 2;
        }
        else{
            j = i - 1;
            ++assignment;

            comparison += 2;
            while (j >= 0 && val1 < tab[j]){
                tab[j + 1] = tab[j];
                --j;
                assignment += 2;

                comparison += 2;
            }
            tab[j + 1] = val1;
            ++assignment;
        }

        ++comparison;
        ++assignment;
    }
}

int main(){
    int n;
    cin >> n;
    int* tab = new int[n];
    for (int i = 0; i < n; ++i){
        cin >> tab[i];
    }

    insertionsort(tab, n);
    //insertionsort2(tab, n);

    for (int i = 0; i < n; ++i){
        cout << tab[i] << " ";
    }

    cout << endl;
    cout << comparison << " " << assignment;

    delete [] tab;
}