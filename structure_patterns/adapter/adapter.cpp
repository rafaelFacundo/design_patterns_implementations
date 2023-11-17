#include <iostream>
#include <stdlib.h>
using namespace std;


class Target {
    public:
        virtual string espectedBehavior(string stringToFormat) const {
            return "++ " + stringToFormat + " ++";
        }
    
};


class Adaptee {
    public:
        string AdapteeBehavior(string stringToFormat) const {
            return "== " + stringToFormat + " ==";        
        }
};

class Adapter : public Target {
    private:
        Adaptee* adaptee;
    public:
        Adapter(Adaptee* objectToAdapt) : adaptee(objectToAdapt) {}
        string espectedBehavior(string stringToFormat) const override
        {
            string adapteeReturn = this->adaptee->AdapteeBehavior(stringToFormat);
                        
            int i = 3;
            string newStringToReturn = "";
            while(adapteeReturn[i] != '=')
            {
                newStringToReturn +=  adapteeReturn[i];
                ++i;
            }
            return "++ " + newStringToReturn + "++";
        }
};

int main() {
    Adaptee* newAdaptee = new Adaptee();
    Adapter* newAdapter = new Adapter(newAdaptee);
    
    cout << "The result of adapter method is: \n";
    cout << newAdapter->espectedBehavior("Peace and love") << '\n';   

    return 0;
}
