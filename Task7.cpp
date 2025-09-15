#include <iostream>
using namespace std;

int* findAllIndices(const int arr[], int size, int key, int& outCount) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            count++;
        }
    }

    outCount = count;
    if (count == 0) return nullptr;

    int* indices = new int[count];
    int idx = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            indices[idx++] = i;
        }
    }
    return indices;
}

void testFindAllIndices() {
    int arr1[] = {1, 2, 3, 2, 4, 2};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int count1 = 0;
    int* res1 = findAllIndices(arr1, size1, 2, count1);
    cout << "Multiple occurrences: ";
    for (int i = 0; i < count1; i++) cout << res1[i] << " ";
    cout << "\n";
    delete[] res1;

    int arr2[] = {1, 3, 5, 7};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int count2 = 0;
    int* res2 = findAllIndices(arr2, size2, 2, count2);
    cout << "Key not present: ";
    if (res2 == nullptr) cout << "(none)";
    else {
        for (int i = 0; i < count2; i++) cout << res2[i] << " ";
        delete[] res2;
    }
    cout << "\n";

    int* res3 = findAllIndices(nullptr, 0, 1, count2);
    cout << "Empty array: ";
    if (res3 == nullptr) cout << "(none)";
    else {
        for (int i = 0; i < count2; i++) cout << res3[i] << " ";
        delete[] res3;
    }
    cout << "\n";
}

int main() {
    testFindAllIndices();
    return 0;
}
