#include <iostream>

using namespace std;

//zwykły insertion sort
void insertionsort(int*& tab, int size){
    int val, j;
    for (int i = 1; i < size; ++i){
        val = tab[i];
        j = i - 1;

        while (j >= 0 && val < tab[j]){
            tab[j + 1] = tab[j];
            --j;
        }
        tab[j + 1] = val;
    }
}

//modyfikacja insertion sort
void insertionsort2(int*& tab, int size){
    int val1, val2, j;
    if (size > 1 && tab[0] > tab[1]){
        swap(tab[0], tab[1]);
    }

    for (int i = 2; i < size; ++i){
        val1 = tab[i];
        if (i + 1 < size){
            val2 = tab[i + 1];
            if (val2 < val1){
                swap(val1, val2);
            }
            j = i - 1;

            while (j >= 0 && val2 < tab[j]){
                tab[j + 2] = tab[j];
                --j;
            }
            tab[j + 2] = val2;
            while(j >= 0 && val1 < tab[j]){
                tab[j + 1] = tab[j];
                --j;
            }
            tab[j + 1] = val1;
            ++i;
        }
        else{
            j = i - 1;
            while (j >= 0 && val1 < tab[j]){
                tab[j + 1] = tab[j];
                --j;
            }
            tab[j + 1] = val1;
        }
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

    delete [] tab;
}