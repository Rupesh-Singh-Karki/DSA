#include <iostream>

class MyClass {
private:
    int value1;
    int value2;
public:
    // Constructor with initialization list
    MyClass(int v1, int v2) : value1(v1), value2(v2) {
        // Constructor body
    }

    void printValues() {
        std::cout << "Value1: " << value1 << ", Value2: " << value2 << std::endl;
    }
};

int main() {
    MyClass obj(10, 20);
    obj.printValues();
    return 0;
}
