#include "FaceBomber.h"

FaceBomber::FaceBomber() {
    std::cout << "Constructing FaceBomber" << std::endl;
}

void FaceBomber::sayHello() {
    std::cout << "Hello!" << std::endl;
}

void FaceBomber::sayBye() {
    std::cout << "Bye!" << std::endl;
}

FaceBomber::~FaceBomber() {
    std::cout << "Destructing FaceBomber" << std::endl;
}