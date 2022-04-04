#include <iostream>
#include <vector>
#include <algorithm>

class Animal {
public:
    Animal(const char *name, int age) : m_Name{name}, m_Age{age} {}

    const char *GetName() const { return m_Name; }

    int GetAge() const { return m_Age; }

    virtual void MakeNoise() = 0;

protected:
    const char *m_Name;
    int m_Age;
};

class Dog : public Animal {
public:
    Dog(const char *name, int age) : Animal(name, age) {
        std::cout << "Created dog: " << m_Name << ", " << m_Age << "yo\n";
    }

    void MakeNoise() override { std::cout << "Bark!\n"; }
};

class Cat : public Animal {
public:
    Cat(const char *name, int age) : Animal(name, age) {
        std::cout << "Created cat: " << m_Name << ", " << m_Age << "yo\n";
    }

    void MakeNoise() override { std::cout << "Nyan!\n"; }
};

class AnimalShelter {
public:
    void AddAnimal(Animal *animal) {
        m_Animals.push_back(animal);
    }

    void RemoveAnimal(Animal *animal) {
        auto it = std::find(m_Animals.begin(), m_Animals.end(), animal);
        if (it != m_Animals.end()) {
            m_Animals.erase(it);
        }
    }

    void Print() {
        std::cout << "Animals: ";
        for (Animal *animal: m_Animals) {
            std::cout << "{" << animal->GetName() << ", " << animal->GetAge() << "yo}, ";
        }
        std::cout << std::endl;
    }

private:
    std::vector<Animal *> m_Animals;
};

int main() {
    AnimalShelter animalShelter;

    Dog doggo{"Doggo", 4};
    Cat catto{"Catto", 8};

    doggo.MakeNoise();
    catto.MakeNoise();

    animalShelter.AddAnimal(&doggo);
    animalShelter.Print();

    animalShelter.AddAnimal(&catto);
    animalShelter.Print();

    animalShelter.RemoveAnimal(&doggo);
    animalShelter.Print();

    return 0;
}

