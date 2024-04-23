// Heap Data Structure

// Heap data structure is a complete binary tree that satisfies the heap property, where any given node is
// ->   always greater than its child node/s and the key of the root node is the largest among all other nodes. This property is also called max heap property.
// ->   always smaller than the child node/s and the key of the root node is the smallest among all other nodes. This property is also called min heap property.
// It is visualized using binary trees but implemented using arrays.

// Heap operations-
// Insert: Adds a new element to the heap while maintaining the heap property.
// Extract Max/Min: Removes the maximum or minimum element from the heap and returns it.
// Heapify: Converts an arbitrary binary tree into a heap.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Heap
{
public:
    vector<int> arr;
    int capacity;
    int size;
    Heap(int capacity)
    {
        arr.resize(capacity);
        size = 0;
    }
    void insert(int val)
    {
        if (size == capacity)
        {
            cout << "Heap Overflow!!!!"
                 << "\n";
            return;
        }
        size++;
        int index = size;
        arr[index] = val;
        while (index > 1)
        {
            int parentIndex = index / 2;
            if (arr[index] > arr[parentIndex])
            {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }
    void printHeap()
    {
        for (int i = 1; i < size + 1; i++)
        {
            cout << arr[i] << " ";
        }
    }
    int deleteFromHeap()
    {
        int answer = arr[1];
        arr[1] = arr[size];
        size--;
        int index = 1;
        while (index < size)
        {
            int leftIndex = 2 * index;
            int rightIndex = 2 * index + 1;
            int largestIndex = index;
            if (leftIndex <= size && arr[largestIndex] < arr[leftIndex])
            {
                largestIndex = leftIndex;
            }
            if (rightIndex <= size && arr[largestIndex] < arr[rightIndex])
            {
                largestIndex = rightIndex;
            }
            if (rightIndex == largestIndex)
            {
                break;
            }
            else
            {
                swap(arr[index], arr[largestIndex]);
                index = largestIndex;
            }
        }
        return answer;
    }
};
void heapify(vector<int> &arr, int n, int index)
{
    int leftIndex = 2 * index;
    int rightIndex = 2 * index + 1;
    int largestIndex = index;
    if (leftIndex <= n && arr[leftIndex] > arr[largestIndex])
    {
        largestIndex = leftIndex;
    }
    if (rightIndex <= n && arr[rightIndex] > arr[largestIndex])
    {
        largestIndex = rightIndex;
    }
    if (largestIndex != index)
    {
        swap(arr[index], arr[largestIndex]);
        index = largestIndex;
        heapify(arr, n, index);
    }
}
void buildHeap(vector<int> &arr, int n)
{
    for (int index = n / 2; index > 0; index--)
    {
        heapify(arr, n, index);
    }
}
void heapSort(vector<int> &arr, int n)
{
    while (n != 1)
    {
        swap(arr[1], arr[n]);
        n--;
        heapify(arr, n, 1);
    }
}

int main()
{
    // Heap h(20);
    // h.insert(10);
    // h.insert(20);
    // h.insert(5);
    // h.insert(11);
    // h.insert(6);
    // int ans=h.deleteFromHeap();
    // cout<<ans<<"\n";
    // h.printHeap();
    vector<int> arr = {-1, 5, 10, 20, 15, 12, 25};
    buildHeap(arr, 6);
    for (int i = 1; i <= 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    heapSort(arr, 6);
    for (int i = 1; i <= 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}