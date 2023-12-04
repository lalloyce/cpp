#include <iostream>
using namespace std;

int main() {
    double height, weight, bmi;

    cout<< "Enter your height in meters"; //Asking the user for their height in meters.
    cin>> height; //binding the user input to the height variable.

    cout<< "Enter your weight in kilograms"; //Asking the user for their weight in kilograms.
    cin>> weight; //binding the user input to the weight variable.
    
    bmi = weight / (height * height); //calculating the BMI by diving the weight in KGs by the square of the height.

    cout<< "Your BMI is: " <<bmi << endl; //Print the BMI to the Console

    //Print a message indicating whether the User is Underweight, Healthy, Overweight, Obese
    if(bmi < 18.5) {
        cout<< "You are Underweight." <<endl;
    } else if (bmi >= 18.5 && bmi <25){
        cout<< "You are Healthy." <<endl;
    } else if (bmi > 25 && bmi <=30){
        cout<< "You are Overweight." <<endl;
    } else {
        cout<< "You are Obese." <<endl;
    }

    return 0;
    
}