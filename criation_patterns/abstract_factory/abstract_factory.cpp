#include <iostream>
#include <stdlib.h>
using namespace std;

class ProductA {
    public:
        virtual string typeOfProduct() = 0;
};

class ProductA_scrollBar_ubuntu : public ProductA  {
    public:
        string typeOfProduct() {
            return "scroll ubuntu";
        }
};

class ProductA_scrollBar_linuxMint : public ProductA  {
    public:
        string typeOfProduct() {
            return "scroll linuxMint";
        }
};

class ProductB {
    public:
        virtual string typeOfProduct() = 0;
};

class ProductB_cursor_ubuntu : public ProductB {
    public:
        string typeOfProduct () {
            return "cursor ubuntu";        
        }
};

class ProductB_cursor_linuxMint : public ProductB {
    public:
        string typeOfProduct () {
            return "cursor linuxMint";        
        }
};


class Factory {
    public:
        virtual ProductA* returnTypeA() = 0;
        virtual ProductB* returnTypeB() = 0;
};

class FactoryUbuntu : public Factory {
    public:
        ProductA* returnTypeA() {
            return new ProductA_scrollBar_ubuntu();      
        }
        ProductB* returnTypeB(){
            return new ProductB_cursor_ubuntu();
        };
};

class FactoryLinuxMint : public Factory {
    public:
        ProductA* returnTypeA() {
            return new ProductA_scrollBar_linuxMint();      
        }
        ProductB* returnTypeB(){
            return new ProductB_cursor_linuxMint();
        };
};


int main ()
{
    return 0;
}
