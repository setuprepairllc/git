//logic destroyer's code
// KianV c++ terroriser
#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()

// Base class
class Animal {
public:
    virtual void speak() const {
        std::cout << "Some generic animal sound" << std::endl;
    }
    virtual ~Animal() = default;
};

// Derived class Dog
class Dog : public Animal {
public:
    void speak() const override {
        std::cout << "Woof!" << std::endl;
    }
    void fetch() const {
        std::cout << "Dog is fetching!" << std::endl;
    }
};

// Derived class Cat
class Cat : public Animal {
public:
    void speak() const override {
        std::cout << "Meow!" << std::endl;
    }
    void scratch() const {
        std::cout << "Cat is scratching!" << std::endl;
    }
};

// Function to demonstrate polymorphism
void makeAnimalSpeak(const Animal& animal) {
    animal.speak();
}

int main() {
    // Encapsulation: Using private members
    std::vector<std::unique_ptr<Animal>> animals;

    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Creating multiple objects in a loop with random selection
    for (int i = 0; i < 1000; ++i) {
        if (std::rand() % 2 == 0) {
            animals.push_back(std::make_unique<Dog>());
        } else {
            animals.push_back(std::make_unique<Cat>());
        }
    }

    // Polymorphism: Different behaviors through base class pointers
    for (const auto& animal : animals) {
        makeAnimalSpeak(*animal);
    }

    // Accessing derived class specific functions
    for (size_t i = 0; i < animals.size(); ++i) {
        Dog* dog = dynamic_cast<Dog*>(animals[i].get());
        if (dog) {
            dog->fetch();
        }

        Cat* cat = dynamic_cast<Cat*>(animals[i].get());
        if (cat) {
            cat->scratch();
        }
    }

    return 0;
}
