#include <iostream>

class Animal {
public:
    void eat() {
        std::cout << "The animal is eating." << std::endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        std::cout << "The dog is barking." << std::endl;
    }
};

class Cat : public Animal {
public:
    void meow() {
        std::cout << "The cat is meowing." << std::endl;
    }
};

int main() {
    Dog dog;
    Cat cat;

    dog.eat();  // Inherited from Animal
    dog.bark(); // Dog's own method

    cat.eat();  // Inherited from Animal
    cat.meow(); // Cat's own method

    return 0;
}
