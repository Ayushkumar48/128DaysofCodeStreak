#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Queue
{
private:
    int size;
    int f;
    int r;
    int *arr;

public:
    Queue()
    {
        f = -1;
        r = -1;
        arr = new int[10001];
        this->size = 10001;
    }
    Queue(int size)
    {
        this->size = size;
        f = -1;
        r = -1;
        arr = new int[size];
    }
    bool isFull(Queue *q)
    {
        if (q->r == this->size - 1)
        {
            return true;
        }
        return false;
    }
    bool isEmpty(Queue *q)
    {
        if (q->r == q->f)
        {
            return true;
        }
        return false;
    }
    void enqueue(Queue *q, int data)
    {
        if (isFull(q))
        {
            cout << "Stack Overflow!!!!";
            return;
        }
        q->r++;
        q->arr[q->r] = data;
        cout << "EnQueued Element: " << q->arr[q->r] << "\n";
    }
    int dequeue(Queue *q)
    {
        if (isEmpty(q))
        {
            cout << "Stack Underflow!!!!\n";
            return -1;
        }
        q->f++;
        cout << "DeQueued Element: " << q->arr[q->f] << "\n";
        return q->arr[q->f];
    }
    int front(Queue *q)
    {
        cout << "Front Element:" << arr[f + 1] << "\n";
        return arr[f + 1];
    }
    ~Queue()
    {
        delete[] arr;
    }
};

int main()
{
    Queue *q = new Queue();
    q->enqueue(q, 50);
    q->enqueue(q, 50);

    q->enqueue(q, 50);
    q->enqueue(q, 50);

    q->enqueue(q, 50);
    q->enqueue(q, 50);
    q->enqueue(q, 50);
    q->enqueue(q, 50);
    q->front(q);
    q->dequeue(q);
    q->dequeue(q);
    q->dequeue(q);
    delete q;
    return 0;
}