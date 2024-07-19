const int MAX_VALUE = 100;
const double PI = 3.14159;

class MyClass {
public:
    int getValue() const; // Const member function
};

int MyClass::getValue() const {
    // This function does not modify any member variables
    return value;
}
