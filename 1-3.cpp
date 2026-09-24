#include <iostream>
#include <iomanip>
using namespace std;

#define SIZE 4

struct data_t {
    void* values[SIZE];
    int types[SIZE];
};

void print_data(data_t* p) {
    cout << "a = " << *(long*)p->values[0] << endl;
    cout << "b = " << *(int*)p->values[1] << endl;
    cout << "c = " << *(short*)p->values[2] << endl;
    cout << "d = " << *(float*)p->values[3] << endl;
}

int main() {
    long a = 100;
    int b = 15;
    short c = 4;
    float d = 2.0f;

    data_t data = {{&a, &b, &c, &d}, {3, 1, 0, 4}};

    print_data(&data);

    float implicit_result = ((a - b) / c) * d;

    double explicit_result =
        (static_cast<double>(a) - b) / c * d;

    cout << fixed << setprecision(3);
    cout << "Implicit: " << implicit_result << endl;
    cout << "Explicit: " << explicit_result << endl;

    return 0;
}
