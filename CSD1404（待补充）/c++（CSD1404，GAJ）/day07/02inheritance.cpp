#include <iostream>
using namespace std;
class Animal{

};
class Dog:protected  Animal{

};
int main(){
		Dog   b;
    Animal   a=b;
}

