#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

// Biến đếm số lần so sánh
long long comp_count = 0;

void bubble_sort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            comp_count++; // Đếm số lần so sánh
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        
        if (swapped == false)
            break;
    }
}

void selection_sort(vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        
        for (int j = i + 1; j < n; j++) {
            comp_count++; // Đếm số lần so sánh
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
        }
    }
}

void insertion_sort(vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0) {
            comp_count++; // Đếm số lần so sánh
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            } else {
                break;
            }
        }
        
        arr[j + 1] = key;
    }
}

// Hàm hiển thị mảng
void print_array(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // Nhập kích thước mảng
    int n;
    cout << "Nhap kich thuoc mang: ";
    cin >> n;
    
    // Tạo mảng
    vector<int> arr(n);
    cout << "Nhap " << n << " phan tu: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Hiển thị mảng ban đầu
    cout << "Mang ban dau: ";
    print_array(arr);
    
    // Tạo bản sao của mảng
    vector<int> arr1 = arr;
    vector<int> arr2 = arr;
    vector<int> arr3 = arr;
    
    // Bubble Sort
    comp_count = 0; // Reset biến đếm
    auto start = chrono::high_resolution_clock::now();
    bubble_sort(arr1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> bubble_time = end - start;
    
    cout << "\nBubble Sort:" << endl;
    cout << "Mang sau khi sap xep: ";
    print_array(arr1);
    cout << "Thoi gian chay: " << bubble_time.count() << " ms" << endl;
    cout << "So lan so sanh: " << comp_count << endl;
    
    // Selection Sort
    comp_count = 0; // Reset biến đếm
    start = chrono::high_resolution_clock::now();
    selection_sort(arr2);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> selection_time = end - start;
    
    cout << "\nSelection Sort:" << endl;
    cout << "Mang sau khi sap xep: ";
    print_array(arr2);
    cout << "Thoi gian chay: " << selection_time.count() << " ms" << endl;
    cout << "So lan so sanh: " << comp_count << endl;
    
    // Insertion Sort
    comp_count = 0; // Reset biến đếm
    start = chrono::high_resolution_clock::now();
    insertion_sort(arr3);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> insertion_time = end - start;
    
    cout << "\nInsertion Sort:" << endl;
    cout << "Mang sau khi sap xep: ";
    print_array(arr3);
    cout << "Thoi gian chay: " << insertion_time.count() << " ms" << endl;
    cout << "So lan so sanh: " << comp_count << endl;
    
    return 0;
}
