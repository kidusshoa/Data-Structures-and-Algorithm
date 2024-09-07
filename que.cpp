#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

void displayPoints(Point* points, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Point " << i + 1 << ": " << points[i].x << ", " << points[i].y << endl;
    }
}

int main() {
    const int size = 3;

    // arr of stru
    Point points[size];

    
    points[0] = { 1, 2 };
    points[1] = { 3, 4 };
    points[2] = { 5, 6 };

    // Pass arr to stru
    displayPoints(points, size);

    // p to arr stru
    Point* ptr = points;

    cout << "Accessing the array using the pointer:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Point " << i + 1 << ": " << ptr[i].x << ", " << ptr[i].y << endl;
    }

    return 0;
}