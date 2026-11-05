#include <iostream>

using namespace std;

void bubblesort(int*& tab, int size){
    bool check = false;
    int repeat = 0;
    while (check == false){
        check = true;
        for (int i = 0; i < size - 1 - repeat; ++i){
            if (tab[i] > tab[i + 1]){
                swap(tab[i], tab[i + 1]);
                check = false;
            }
        }
        ++repeat;
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

    delete [] tab;
}