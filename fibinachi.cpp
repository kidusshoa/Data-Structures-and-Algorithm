#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

class FibonacciGenerator {
public:
    class Iterator {
    public:
        using iterator_category = std::input_iterator_tag;
        using value_type = int;
        using difference_type = int;
        using pointer = int*;
        using reference = int&;

        Iterator() : a(0), b(1) {}

        reference operator*() { return a; }
        pointer operator->() { return &a; }

        Iterator& operator++() {
            int next = a + b;
            a = b;
            b = next;
            return *this;
        }

        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const Iterator& other) const {
            return a == other.a;
        }

        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }

    private:
        int a;
        int b;
    };

    Iterator begin() { return Iterator(); }
    Iterator end() { return Iterator(); }
};

int main() {
    FibonacciGenerator fibonacci;

    // Usage with range-based for loop
    for (int fib : fibonacci) {
        if (fib > 100)
            break;
        cout << fib << " ";
    }

    return 0;
}