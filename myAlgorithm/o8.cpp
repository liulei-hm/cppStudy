#include <iostream>

class Animal {
public:
    virtual void makeSound() {
        std::cout << "This is an animal sound." << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() {
        std::cout << "Meow!" << std::endl;
    }

    void catchMouse() {
        std::cout << "I caught a mouse!" << std::endl;
    }
};

int main() {
    Animal* animalPtr = new Cat();
    Cat* catPtr = dynamic_cast<Cat*>(animalPtr);

    animalPtr->makeSound(); // This is an animal sound.
    catPtr->makeSound(); // Meow!

    // This line will not compile, because the catchMouse() method is not defined in the Animal class.
    // animalPtr->catchMouse();

    catPtr->catchMouse(); // I caught a mouse!

    delete animalPtr;
    return 0;
}