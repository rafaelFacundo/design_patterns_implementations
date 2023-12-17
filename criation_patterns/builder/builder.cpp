#include <iostream>
#include <stdlib.h>
using namespace std;

class Car {
    private:
        string engine;
        int numberOfTires;
        int numberOfDoors;
        string serialNumber;
    
    public:
        void setEngine(string engine) {this->engine = engine;};
        void setNumberOfTires(int numberOfTires) {this->numberOfTires = numberOfTires;}
        void setNumberOfDoors(int numberOfDoors) {this->numberOfDoors = numberOfDoors;}
        void setSerialNumber(string serialNumber) {this->serialNumber = serialNumber;}
};

class Builder {
    public:
        virtual void reset() = 0;
        virtual void setEngine() = 0;
        virtual void setNumberOfTires(int numberOfTires) = 0;
        virtual void setNumberOfDoors() = 0;
        virtual void setSerialNumber() = 0;
};

class suvCarBuilder : public Builder {
    private:
        Car suvCar;
    public:
        void reset() {
            this->suvCar = Car();
        }

        void setEngine() {
            this->suvCar.setEngine("SUV MOTOR ENGINE V8 TURBO");
        }

        void setNumberOfTires(int numberOfTires) {
            this->suvCar.setNumberOfTires(numberOfTires);
        }

        void setNumberOfDoors() {
            this->suvCar.setNumberOfDoors(2);
        }

        void setSerialNumber () {
            this->suvCar.setSerialNumber("ALKJslkjDaIJdaLDkjasdasodij");
        }
};



int main()
{

    return 0;
}