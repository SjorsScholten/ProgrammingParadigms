#include <iostream>
#include <vector>
#include <algorithm>

struct Animal {
    const char *name;
    int age;
    const char *noise;
};

const auto CreateCat = [](const char *name, const int age) {
    return Animal{name, age, "Nyan!"};
};

const auto CreateDog = [](const char *name, const int age) {
    return Animal{name, age, "Bark!"};
};

const auto AddAnimal = [](const std::vector<Animal> shelter, const Animal animal) {
    std::vector<Animal> newShelter;
    newShelter.reserve(shelter.size() + 1);
    newShelter.insert(newShelter.end(), shelter.begin(), shelter.end());
    newShelter.push_back(animal);
    return newShelter;
};

const auto RemoveAnimal = [](const std::vector<Animal> shelter, const char *name) {
    std::vector<Animal> newShelter;
    std::copy_if(shelter.begin(), shelter.end(), std::back_inserter(newShelter),
                 [name](const Animal animal) { return strcmp(animal.name, name); });
    return newShelter;
};

const auto MakeNoise = [](const Animal animal) {
    std::cout << animal.noise << '\n';
};

const auto PrintAnimal = [](const Animal animal) {
    std::cout << "{" << animal.name << ", " << animal.age << "yo}, ";
};

const auto PrintShelter = [](const std::vector<Animal> shelter) {
    std::cout << "Animals: ";
    std::for_each(shelter.begin(), shelter.end(), PrintAnimal);
    std::cout << std::endl;
};

int main() {
    std::vector<Animal> shelter;

    shelter = AddAnimal(shelter, CreateDog("Doggo", 4));
    PrintShelter(shelter);

    shelter = AddAnimal(shelter, CreateCat("Catto", 8));
    PrintShelter(shelter);

    std::for_each(shelter.begin(), shelter.end(), MakeNoise);

    shelter = RemoveAnimal(shelter, "Doggo");
    PrintShelter(shelter);

    return 0;
}
