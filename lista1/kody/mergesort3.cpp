#include <iostream>
#include <algorithm>

using namespace std;

//mergesort na 3 części
void merge3(int*& tab, int*& help, int left, int middle1, int middle2, int right){
    int i = left;
    int j = middle1 + 1;
    int k = middle2 + 1;
    int l = left;
    int minimum;

    while (i <= middle1 && j <= middle2 && k <= right){
        minimum = min({tab[i], tab[j], tab[k]});
        if (tab[i] == minimum){
            help[l] = tab[i];
            ++i;
        }
        else if (tab[j] == minimum){
            help[l] = tab[j];
            ++j;
        }
        else if (tab[k] == minimum){
            help[l] = tab[k];
            ++k;
        }
        ++l;
    }
    while (i <= middle1 && j <= middle2){
        minimum = min(tab[i], tab[j]);
        if (tab[i] == minimum){
            help[l] = tab[i];
            ++i;
        }
        else if (tab[j] == minimum){
            help[l] = tab[j];
            ++j;
        }
        ++l;
    }
    while (i <= middle1 && k <= right){
        minimum = min(tab[i], tab[k]);
        if (tab[i] == minimum){
            help[l] = tab[i];
            ++i;
        }
        else if (tab[k] == minimum){
            help[l] = tab[k];
            ++k;
        }
        ++l;
    }
    while (j <= middle2 && k <= right){
        minimum = min(tab[j], tab[k]);
        if (tab[j] == minimum){
            help[l] = tab[j];
            ++j;
        }
        else if (tab[k] == minimum){
            help[l] = tab[k];
            ++k;
        }
        ++l;
    }
    while (i <= middle1){
        help[l] = tab[i];
        ++i;
        ++l;
    }
    while (j <= middle2){
        help[l] = tab[j];
        ++j;
        ++l;
    }

    for (int m = left; m <= right; ++m){
        tab[m] = help[m];
    }
}

void mergesort3_h(int*& tab, int*& help, int left, int right){
    if (left < right){
        int middle1 = left + (right - left) / 3;
        int middle2 = middle1 + (right - left) / 3;
        mergesort3_h(tab, help, left, middle1);
        mergesort3_h(tab, help, middle1 + 1, middle2);
        mergesort3_h(tab, help, middle2 + 1, right);
        merge3(tab, help, left, middle1, middle2, right);
    }
}

void mergesort3(int*& tab, int size){
    int* help = new int[size];
    for (int i = 0; i < size; ++i){
        help[i] = tab[i];
    }
    mergesort3_h(tab, help, 0, size - 1);
    delete [] help;
}

int main(){
    int n;
    cin >> n;
    int* tab = new int[n];
    for (int i = 0; i < n; ++i){
        cin >> tab[i];
    }

    mergesort3(tab, n);

    for (int i = 0; i < n; ++i){
        cout << tab[i] << " ";
    }

    delete [] tab;
}