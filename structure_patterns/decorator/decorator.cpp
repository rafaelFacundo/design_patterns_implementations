#include <iostream>
#include <stdlib.h>
using namespace std;

class Component {
    public:
        virtual string componentOperation() const = 0;
};

class concreteComponent : public Component {
    public:
        string componentOperation() const override
        {
            return "this is the component operation";
        };
};

class Decorator : public Component {
    protected:
        Component* wrappedComponent;
    public:
        Decorator(Component* componentToWrapp) : wrappedComponent(componentToWrapp) {}; 
        
        //delegate the operation to the wrapped component
        string componentOperation() const override
        {
            return this->wrappedComponent->componentOperation();
        }

};

class ConcreteDecoratorA : public Decorator {
    public:
        ConcreteDecoratorA(Component* componentToWrapp) : Decorator(componentToWrapp) {};
        
        string componentOperation() const override
        {
            return "Concrete A ( " + Decorator::componentOperation() + " )"; 
        }
};


class ConcreteDecoratorB : public Decorator {
    public:
        ConcreteDecoratorB(Component* componentToWrapp) : Decorator(componentToWrapp) {};
        
        string componentOperation() const override
        {
            return "Concrete B ( " + Decorator::componentOperation() + " )"; 
        }
};

int main() {
    return 0;
}
