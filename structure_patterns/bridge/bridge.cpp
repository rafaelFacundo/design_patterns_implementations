#include <iostream>
#include <stdlib.h>
using namespace std;

class Implementation {
    public:
        virtual string OperationImplementation() = 0;
};

class ConcreteImplementatioA : public Impementation {
    public:
        string OperationImplementatio() {
            return "type A implementatio";
        }
};


class ConcreteImplementatioB : public Impementation {
    public:
        string OperationImplementatio() {
            return "type B implementatio";
        }
}

class Abstraction {
    protected: 
        implementation* implementation;
    public:
         Abstraction(Implementation* implementation) : implementation_(implementation) {}
        virtual string Operation() {
            return "this is a abstraction: " << this->implementation
        }
    
}

class Extended : public Abstraction {
    public:
        Extended(implemenToSee* imp): Abstraction(implementation);
}

int main() {
    return 0;
}
