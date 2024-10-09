#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int linearSearch(int arr[], int n, int target)
{
    for (int i = 0; i < n; ++i)
    {
        cout << "Checking element at index " << i << ": " << arr[i] << endl;
        if (arr[i] == target)
            return i;
    }
    return -1;
}
int binarySearch(int arr[], int n, int target)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        cout << "Checking element at index " << mid << ": " << arr[mid] << endl;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                printArray(arr, n);
            }
        }
    }
    cout<<"\nSorted Array:\n";
    printArray(arr, n);
}
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
        printArray(arr, n);
    }
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j)
    {
        if (arr[j] < pivot)
        {
            ++i;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
        printArray(arr, n);
    }
}
int main()
{
    char choice;
    do
    {
        cout << "1. Linear Search\n2. Binary Search\n3. Bubble Sort\n";
        cout << "4. Merge Sort\n5. Quick Sort\n6. Selection Sort\n";
        cout << "7. Insertion Sort\n";
        cout << "\n-- Select an Algorithm by entering its number: ";

        int algo_choice;
        cin >> algo_choice;

        cout << "\nEnter the number of elements: ";
        int n;
        cin >> n;

        int arr[100];

        cout << "Enter array elements separated by spaces:\n";
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }

        switch (algo_choice)
        {
            case 1:
            {
                cout << "\n-- Selected Algorithm: Linear Search --\n";
                cout << "Enter target value: ";
                int target;
                cin >> target;
                int index = linearSearch(arr, n, target);
                if (index != -1)
                    cout << "\nElement found at index " << index << endl;
                else
                    cout << "Element not found" << endl;
                break;
            }
            case 2:
            {
                cout << "\n-- Selected Algorithm: Binary Search --\n";
                cout << "Enter target value: ";
                int target;
                cin >> target;
                quickSort(arr, 0, n - 1);
                int index = binarySearch(arr, n, target);
                if (index != -1)
                    cout << "Element found at index " << index << endl;
                else
                    cout << "Element not found" << endl;
                break;
            }
            case 3:
                cout << "\n-- Selected Algorithm: Bubble Sort --\n";
                bubbleSort(arr, n);
                break;
            case 4:
                cout << "\n-- Selected Algorithm: Merge Sort --\n";
                mergeSort(arr, 0, n - 1);
                printArray(arr, n);
                break;
            case 5:
                cout << "\n-- Selected Algorithm: Quick Sort --\n";
                quickSort(arr, 0, n - 1);
                printArray(arr, n);
                break;
            case 6:
                cout << "\n-- Selected Algorithm: Selection Sort --\n";
                selectionSort(arr, n);
                break;
            case 7:
                cout << "\n-- Selected Algorithm: Insertion Sort --\n";
                insertionSort(arr, n);
                break;
            default:
                cout << "Invalid choice" << endl;
        }

        cout << "\nWould you like to solve another problem? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Program ended.\n";
    return 0;
}
