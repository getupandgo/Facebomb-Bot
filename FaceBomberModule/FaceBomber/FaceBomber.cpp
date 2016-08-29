#include "FaceBomber.h"

FaceBomber::FaceBomber() {
    std::cout << "Constructing FaceBomber" << std::endl;
}

void FaceBomber::sayHello() {
    std::cout << "Hello!" << std::endl;

    cv::Mat image;
    image = cv::imread("./FaceBomberModule/FaceBomber/hide-the-pain-harold.jpg", CV_LOAD_IMAGE_COLOR);

    if(!image.data) {
      std::cout << ( "No image data \n" ) << std::endl;
    }

    cv::namedWindow("Display Image", CV_WINDOW_AUTOSIZE);
    cv::imshow("Display Image", image);
}

void FaceBomber::sayBye() {
    std::cout << "Bye!" << std::endl;
}

FaceBomber::~FaceBomber() {
    std::cout << "Destructing FaceBomber" << std::endl;
}