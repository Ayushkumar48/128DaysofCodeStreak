// More about Queues

/*
Types of Queues

There are different types of queues:

1.  Input Restricted Queue: This is a simple queue. In this type of queue, the input can be taken from only one end but deletion can be done from any of the     ends.
2.  Output Restricted Queue: This is also a simple queue. In this type of queue, the input can be taken from both ends but deletion can be done from only one end.
3.  Circular Queue: This is a special type of queue where the last position is connected back to the first position. Here also the operations are performed in FIFO order.
4.  Double-Ended Queue (Dequeue): Deque or Double Ended Queue is a generalized version of Queue data structure that allows insert and delete at both ends.
    In a double-ended queue the insertion and deletion operations, both can be performed from both ends. All operations's time complexity is O(1).
    Operations- push_front(x), push_back(x), pop_front(), pop_back(), front(), back(), empty(), size()
5.  Priority Queue: A priority queue is a special queue where the elements are accessed based on the priority assigned to them.
    It is a type of queue that arranges elements based on their priority values.
    Elements with higher priority values are typically retrieved before elements with lower priority values.
    Priority queue can be implemented using the following data structures:
    a)  Arrays
    b)  Linked list
    c)  Heap data structure - I haven't learnt it yet!!- will cover it later.
    d)  Binary search tree - I haven't learnt it yet!!- will cover it later.

    i)  Implement Priority Queue Using Array:

    Arrays              enqueue()   dequeue()   peek()/front()
    Time Complexity     O(1)        O(n)        O(n)

    ii) Implement Priority Queue Using Linked List:
    Linked List         enqueue()   dequeue()   peek()/front()
    Time Complexity     O(n)        O(1)        O(1)
*/
