#include "PmergeMe.hpp"

template <typename T>
void insertionSort(T& arr, int left, int right) {
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

template <typename T>
void merge(T& arr, int left, int mid, int right) {
    T tempArr(right - left + 1);

    std::merge(arr.begin() + left, arr.begin() + mid + 1,
               arr.begin() + mid + 1, arr.begin() + right + 1,
               tempArr.begin());
    for (size_t i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << " ";
    for (size_t i = 0; i < tempArr.size(); ++i) {
        arr[left + i] = tempArr[i];
    }
}

template <typename T>
void mergeInsertionSort(T& arr, int left, int right, int threshold) {
    if (left < right) {
        if (right - left + 1 <= threshold) {
            insertionSort(arr, left, right);
        } else {
            int mid = left + (right - left) / 2;
            mergeInsertionSort(arr, left, mid, threshold);
            mergeInsertionSort(arr, mid + 1, right, threshold);
            //merge(arr, left, mid, right);
        }
    }
}

int main(int argc, char *argv[])
{
    struct timespec ts;

	if (!isInteger(argv, argc) || argc < 2)
		return (std::cout << "Error: not a positive integer argument." << std::endl, 1);
	std::vector<int> vector;
	std::list<int> list;
    for (int i = 1; i < argc; ++i) {
        vector.push_back(std::atoi(argv[i]));
        list.push_back(std::atoi(argv[i]));
    }
    std::cout << "Array before sorting: ";
    for (std::vector<int>::size_type i = 0; i < vector.size(); ++i)
        std::cout << vector[i] << " ";
    std::cout << std::endl;
    clock_gettime(CLOCK_REALTIME, &ts);
    long double before = ts.tv_nsec;
    std::cout << "Current time in microseconds: \n" << ts.tv_nsec;
    mergeInsertionSort(vector, 0, vector.size() - 1, 2);
    mergeInsertionSort(list, 0, vector.size() - 1, 2);
    clock_gettime(CLOCK_REALTIME, &ts); 
    std::cout << "Current time in microseconds: \n" << ts.tv_nsec - before;
    std::cout << "array after sorting: ";
    for (std::vector<int>::size_type i = 0; i < vector.size(); ++i)
        std::cout << vector[i] << " ";
    std::cout << std::endl;

    return 0;
}
