#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

//in this exemple the singleton class will be a "data base" that stores number
//from the input, so it make senses to be just one class.

class Singleton_numbersDataBase {
    private:
        static Singleton_numbersDataBase* singletonInstance;
        vector<int> data;
        Singleton_numbersDataBase() {};
    public:
        static Singleton_numbersDataBase* getInstance();
        
        void insertData(int numberToInsert)
        {
            data.push_back(numberToInsert);
        }

        static bool areThere_aInstance()
        {
            if (singletonInstance != nullptr) 
                return true;
            return false;        
        }
};

Singleton_numbersDataBase* Singleton_numbersDataBase::singletonInstance = nullptr;;

Singleton_numbersDataBase* Singleton_numbersDataBase::getInstance()
{   
    
    if (singletonInstance == nullptr)
    {
        singletonInstance = new Singleton_numbersDataBase();         
    }
    return singletonInstance; 
};

int main() {
    
    Singleton_numbersDataBase* singletInstan = Singleton_numbersDataBase::getInstance();
    
    cout << "Existe instância: " << Singleton_numbersDataBase::areThere_aInstance() << '\n';      
    
    singletInstan->insertData(1);

        

    return 0;

}
