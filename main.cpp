#include <iostream>

using namespace std;

class Cat{
    string name;
    int age;
public:
    Cat(){
        name = "NoName";
        age = 0;
    }

    Cat(string nName, int nAge){
        this->name = nName;
        this->age = nAge;
    }

    void whoIsTheCat(){
        cout << "The cat is: " << name << " Age : " << age << endl;
    }
// new operator overloading
// return type -> pointer
// size_t -> data type defined you already know -> this size variable
// contains the number of whites that we want to allocate
void* operator new(size_t s){
        //Create a void pointer!!
        void *pointer;
        pointer = malloc(s);
        cout << "The size of the allocating memory is: " << s << endl;
        //If the memory is not allocated -> throw
        if(pointer == NULL){
            bad_alloc ba; // bad_alloc -> class
            throw ba;
        } else{
            return pointer;
        }
     }
    //delete operator overloading
    //return type -> void
    void operator delete(void *pointer){
     cout << "Overloaded pointer deleted." << endl;
        free(pointer);
    }


};

int main() {

    Cat jumiao("Miao", 21);
    jumiao.whoIsTheCat();
    //allocate memory
    try{Cat *sanhua;
        sanhua =  new Cat("GaosanMao", 33);
        sanhua->whoIsTheCat();
        delete(sanhua);
        return 0;
     } catch (bad_alloc &b){
       cout <<  b.what() << endl;

    }

}