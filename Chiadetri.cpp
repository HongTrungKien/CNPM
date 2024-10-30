// Chiadetri.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*#include <iostream>
using namespace std;

// Hàm trộn hai dãy con đã sắp xếp
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Số phần tử trong dãy con trái
    int n2 = right - mid;    // Số phần tử trong dãy con phải

    // Tạo mảng tạm để chứa hai dãy con
    // Sử dụng cấp phát động
    int* L = new int[n1];  // Mảng tạm cho dãy con trái
    int* R = new int[n2];  // Mảng tạm cho dãy con phải

    // Copy dữ liệu vào mảng tạm L[] và R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Trộn hai mảng tạm vào mảng gốc
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Sao chép các phần tử còn lại của L[] nếu có
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Sao chép các phần tử còn lại của R[] nếu có
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Giải phóng bộ nhớ đã cấp phát cho L và R
    delete[] L;
    delete[] R;
}

// Hàm Merge Sort phiên bản lặp
void mergeSort(int arr[], int n) {
    // Kích thước dãy con ban đầu là 1
    for (int curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size) {
        // Chọn điểm bắt đầu của dãy con trái
        for (int left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            // Tìm điểm giữa và điểm kết thúc của dãy con phải
            int mid = min(left_start + curr_size - 1, n - 1);
            int right_end = min(left_start + 2 * curr_size - 1, n - 1);

            // Trộn hai dãy con đã sắp xếp
            merge(arr, left_start, mid, right_end);
        }
    }
}

// Hàm in mảng
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = { 11, 10, 19, 6, 20, 25, 90, 8, 7, 21, 1, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Day ban dau: ";
    printArray(arr, n);

    // Thực hiện sắp xếp
    mergeSort(arr, n);

    cout << "Day sau khi sap xep: ";
    printArray(arr, n);

    return 0;
}*/
#include <iostream>
using namespace std;

void QuickSort(int a[], int left, int right)
{
    int i, j, x, t;
    x = a[(left + right) / 2]; i = left; j = right;
    do {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j) {
            t = a[i]; a[i] = a[j]; a[j] = t;
            i++; j--;
        }
    } while (i < j);
    if (left < j) QuickSort(a, left, j);
    if (i < right) QuickSort(a, i, right);
}

/*
// Hàm in mảng
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = { 15, 10, 9, 5, 20, 90, 8, 6, 21, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Day ban dau: ";
    printArray(arr, n);

    // Thực hiện sắp xếp với pivot là phần tử giữa
    QuickSort(arr, 0, n - 1);

    cout << "Day sau khi sap xep: ";
    printArray(arr, n);

    return 0;
}
*/
/*
#include <iostream>
#include <algorithm>
using namespace std;

int findMin(int A[], int left, int right) {
    // Trường hợp cơ sở: nếu mảng chỉ có 1 phần tử
    if (left == right)
        return A[left];

    // Chia mảng thành 2 nửa
    int mid = (left + right) / 2;

    // Đệ quy tìm giá trị nhỏ nhất ở 2 nửa
    int minLeft = findMin(A, left, mid);
    int minRight = findMin(A, mid + 1, right);

    // Kết hợp kết quả
    return min(minLeft, minRight);
}

int main() {
    int A[] = { 3, 5, 1, 9, 2, 8, 6 };
    int n = sizeof(A) / sizeof(A[0]);

    int result = findMin(A, 0, n - 1);
    cout << "Gia tri nho nhat trong mang la: " << result << endl;

    return 0;
}
*/
#include <iostream>  
#include <cstdlib>   
#include <ctime>     
using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int num) {
    if (num < 2) return false; // Số nhỏ hơn 2 không phải là nguyên tố
    for (int i = 2; i * i <= num; i++) { // Kiểm tra từ 2 đến căn bậc hai của num
        if (num % i == 0)
            return false; // Nếu chia hết, num không phải là nguyên tố
    }
    return true; // Nếu không chia hết cho bất kỳ số nào, num là nguyên tố
}

// Hàm tìm vị trí của số dương đầu tiên bằng chiến lược chia để trị
int findFirstPositive(int A[], int left, int right) {
    if (left > right)
        return -1; // Nếu phạm vi không hợp lệ, trả về -1 (không tìm thấy)

    if (left == right) { // Trường hợp cơ sở: chỉ có một phần tử
        return (A[left] > 0) ? left : -1; // Nếu phần tử đó dương, trả về chỉ số; ngược lại trả về -1
    }

    int mid = left + (right - left) / 2; // Tìm chỉ số giữa để chia mảng thành hai nửa

    // Tìm số dương trong nửa trái trước
    int leftPos = findFirstPositive(A, left, mid);
    if (leftPos != -1)
        return leftPos; // Nếu tìm thấy trong nửa trái, trả về vị trí đó

    // Nếu không tìm thấy ở nửa trái, tìm ở nửa phải
    return findFirstPositive(A, mid + 1, right);
}

// Hàm tìm vị trí của số nguyên tố cuối cùng bằng chiến lược chia để trị
int findLastPrime(int A[], int left, int right) {
    if (left > right)
        return -1; // Nếu phạm vi không hợp lệ, trả về -1 (không tìm thấy)

    if (left == right) { // Trường hợp cơ sở: chỉ có một phần tử
        return isPrime(A[left]) ? left : -1; // Nếu phần tử đó là nguyên tố, trả về chỉ số; ngược lại trả về -1
    }

    int mid = left + (right - left) / 2; // Tìm chỉ số giữa để chia mảng thành hai nửa

    // Tìm số nguyên tố trong nửa phải trước
    int rightPos = findLastPrime(A, mid + 1, right);
    if (rightPos != -1)
        return rightPos; // Nếu tìm thấy trong nửa phải, trả về vị trí đó

    // Nếu không tìm thấy ở nửa phải, tìm ở nửa trái
    return findLastPrime(A, left, mid);
}

int main() {
    srand(time(0)); // Khởi tạo seed cho trình tạo số ngẫu nhiên dựa trên thời gian hiện tại

    
    int N;
    cout << "Nhap so phan tu N: ";
    cin >> N;

    if (N <= 0) { // Kiểm tra N phải là số dương
        cout << "So phan tu N phai duong." << endl;
        return 0; 
    }

    // Cấp phát bộ nhớ động cho mảng A với N phần tử
    int* A = new int[N];
    cout << "Day so ngau nhien la: ";
    for (int i = 0; i < N; i++) {
        A[i] = rand() % 101 - 50;  // Sinh số ngẫu nhiên từ -50 đến 50
        cout << A[i] << " "; // In ra từng phần tử của mảng
    }
    cout << endl;

    // Tìm vị trí của số dương đầu tiên trong mảng
    int firstPositivePos = findFirstPositive(A, 0, N - 1);
    if (firstPositivePos != -1)
        cout << "Vi tri so duong dau tien: " << firstPositivePos << ", Gia tri: " << A[firstPositivePos] << endl;
    else
        cout << "Khong co so duong trong day." << endl;

    // Tìm vị trí của số nguyên tố cuối cùng trong mảng
    int lastPrimePos = findLastPrime(A, 0, N - 1);
    if (lastPrimePos != -1)
        cout << "Vi tri so nguyen to cuoi cung: " << lastPrimePos << ", Gia tri: " << A[lastPrimePos] << endl;
    else
        cout << "Khong co so nguyen to trong day." << endl;
    delete[] A;
    return 0; 
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
