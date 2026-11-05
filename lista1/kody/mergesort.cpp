#include <iostream>

using namespace std;

//zwykły mergesort
void merge(int*& tab, int*& help, int left, int middle, int right){
    int i = left;
    int j = middle + 1;
    int k = left;

    while (i <= middle && j <= right){
        if (tab[i] <= tab[j]){
            help[k] = tab[i];
            ++i;
        }
        else{
            help[k] = tab[j];
            ++j;
        }
        ++k;
    }
    while (i <= middle){
        help[k] = tab[i];
        ++i;
        ++k;
    }

    for (int l = left; l <= right; ++l){
        tab[l] = help[l];
    }
}

void mergesort_h(int*& tab, int*& help, int left, int right){
    if (left < right){
        int middle = (left + right) / 2;
        mergesort_h(tab, help, left, middle);
        mergesort_h(tab, help, middle + 1, right);
        merge(tab, help, left, middle, right);
    }
}

void mergesort(int*& tab, int size){
    int* help = new int[size];
    for (int i = 0; i < size; ++i){
        help[i] = tab[i];
    }
    mergesort_h(tab, help, 0, size - 1);
    delete [] help;
}

int main(){
    int n;
    cin >> n;
    int* tab = new int[n];
    for (int i = 0; i < n; ++i){
        cin >> tab[i];
    }

    mergesort(tab, n);

    for (int i = 0; i < n; ++i){
        cout << tab[i] << " ";
    }

    delete [] tab;
}