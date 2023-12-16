#include <iostream>

class MyCircularQueue 
{
    struct ListNode 
    {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
    };

    ListNode* first;
    ListNode* last;
    unsigned size;
    unsigned capacity;

public:

    MyCircularQueue(int k) {
        first = new ListNode();
        last = first;
        for (size_t i = 1; i < k; ++i)
        {
            last->next = new ListNode();
            last = last->next;
        }
        last->next = first;
        last = nullptr;

        capacity = k;
        size = 0;
    }

    bool enQueue(int value) {
        if (!last)
        {
            first->val = value;
            last = first;
        }
        else
        {
            if (last->next == first)
                return false;

            last=last->next;
            last->val = value;
        }

        ++size;
        if (size > capacity)
        {
            size = capacity;
            return false;
        }

        return true;
    }

    bool deQueue() {
        if (size == 0)
            return false;

        first = first->next;
        --size;
        if (size == 0)
            last = nullptr;
        return true;
    }

    int Front() {
        if (size == 0)
            return -1;
        return first->val;
    }

    int Rear() {
        if (size == 0)
            return -1;
        return last->val;
    }

    bool isEmpty() {
        return (size == 0);
    }

    bool isFull() {
        return (size == capacity);
    }

    ~MyCircularQueue()
    {
        for (size_t i = 0; i < size; ++i)
        {
            last = first->next;
            delete first;
            first = last;
        }
    }
};

int main()
{
    std::cout << "Hello World!\n";

    MyCircularQueue a (6);
    a.enQueue(6);
    a.Rear();
    a.Rear();
    a.deQueue();
    a.enQueue(5);
    a.Rear();
    a.deQueue();
    int num = a.Front();
    a.deQueue();
    a.deQueue();
    a.deQueue();
}