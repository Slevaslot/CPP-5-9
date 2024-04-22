#include "PmergeMe.hpp"

// Fonction pour trier une sous-liste avec insertion sort
void insertionSort(std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}

// Fusionne deux sous-listes triées en une seule liste triée en utilisant std::merge
void merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> tempArr(right - left + 1);

    std::merge(arr.begin() + left, arr.begin() + mid + 1,
               arr.begin() + mid + 1, arr.begin() + right + 1,
               tempArr.begin());

    // Copie les éléments fusionnés dans le vecteur d'origine
    for (size_t i = 0; i < tempArr.size(); ++i) {
        arr[left + i] = tempArr[i];
    }
}

// Algorithme de tri merge-insert utilisant std::merge
void mergeInsertionSort(std::vector<int>& arr, int left, int right, int threshold) {
    if (left < right) {
        if (right - left + 1 <= threshold) {
            insertionSort(arr, left, right);
        } else {
            int mid = left + (right - left) / 2;
            mergeInsertionSort(arr, left, mid, threshold);
            mergeInsertionSort(arr, mid + 1, right, threshold);
            merge(arr, left, mid, right);
        }
    }
}

int main(int argc, char *argv[])
{
	if (!isInteger(argv, argc) || argc < 2)
		return (std::cout << "Error: not a positive integer argument." << std::endl, 1);
	std::vector<int> arr;
    // Remplissage du vecteur avec les valeurs fournies via les arguments de la ligne de commande
    for (int i = 1; i < argc; ++i) {
        arr.push_back(std::atoi(argv[i]));
    }

    std::cout << "Array before sorting: ";
    for (std::vector<int>::size_type i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    mergeInsertionSort(arr, 0, arr.size() - 1, 2); // Utilisation d'insertion sort pour les sous-listes de taille <= 5

    std::cout << "Array after sorting: ";
    for (std::vector<int>::size_type i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}
