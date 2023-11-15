#include <stdlib.h>
#include <iostream>
#include <cstdlib>
using namespace std;


//definition of class Product 
class Product_ANIMAL {
    public:
        virtual string talk() = 0;
};


//definition of the class concrete product, in this case, our animals
class ConcreteProduct_DOG : public Product_ANIMAL {
    public:
        string talk()
        {
            return "au au";        
        }
};

class ConcreteProduct_CAT : public Product_ANIMAL {
    public:
        string talk()
        {
            return "miauu";
        }
};

//definition of the class Creator in wich we define our method 
class Creator_FACTORY {
    public:
        virtual Product_ANIMAL* returnInstance() = 0; 
};

class randomAnimalFactory : public Creator_FACTORY {
    public:
        Product_ANIMAL* returnInstance()
        {
            int randomNumber = rand();
            if (randomNumber % 2 == 0) {
                return new ConcreteProduct_DOG();         
            }
            return new ConcreteProduct_CAT();
        }
};

int main ()
{
    randomAnimalFactory* animalFactory = new randomAnimalFactory();

    Product_ANIMAL* aleatoryAnimal = animalFactory->returnInstance();

    cout << "O som do animal retornado é: " << aleatoryAnimal->talk() << "\n";
    
    return 0;
}


