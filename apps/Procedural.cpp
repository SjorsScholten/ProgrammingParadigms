#include <iostream>
#include <cassert>
#include <vector>

enum AnimalType {
    CAT, DOG
};

struct Animal {
    AnimalType type;
    const char *name;
    int age;
};

std::vector<Animal> c_AnimalShelter;

Animal *GetFirstAnimalWithName(const char *name);

void AddAnimal(AnimalType type, const char *name, int age);

void RemoveAnimal(const char *name);

void MakeNoise(const char *name);

void Print();

int main() {
    const char *doggo = "Doggo";
    const char *catto = "Catto";

    AddAnimal(DOG, doggo, 4);
    Print();

    AddAnimal(CAT, catto, 8);
    Print();

    MakeNoise(doggo);
    MakeNoise(catto);

    RemoveAnimal(doggo);
    Print();

    return 0;
}

Animal *GetFirstAnimalWithName(const char *name) {
    auto it = std::find_if(c_AnimalShelter.begin(), c_AnimalShelter.end(),
                           [name](const auto &a) { return strcmp(a.name, name); });
    assert(it != c_AnimalShelter.end());
    return &c_AnimalShelter[it - c_AnimalShelter.begin()];
}

void AddAnimal(AnimalType type, const char *name, int age) {
    c_AnimalShelter.push_back({type, name, age});
}

void RemoveAnimal(const char *name) {
    auto it = std::find_if(c_AnimalShelter.begin(), c_AnimalShelter.end(),
                           [name](const auto &a) { return strcmp(a.name, name); });
    if (it != c_AnimalShelter.end()) {
        c_AnimalShelter.erase(it);
    }
}

void MakeNoise(const char *name) {
    auto a = GetFirstAnimalWithName(name);
    switch (a->type) {
        case CAT:
            std::cout << "Nyan!\n";
            break;
        case DOG:
            std::cout << "Bark!\n";
            break;
    }
}

void Print(){
    std::cout << "Animals: ";
    for (auto &animal: c_AnimalShelter) {
        std::cout << "{" << animal.name << ", " << animal.age << "yo}, ";
    }
    std::cout << std::endl;
}