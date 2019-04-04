#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

template <class Elem>
struct Vector{
    Elem * data;
    int size;
    int capacity;

    Vector(int cap){
        this->size = 0;
        this->capacity = cap;
        this->data = new Elem[cap];
    }
    ~Vector(){
        delete [] this->data;
    }
    void push_back(Elem value){
        if(this->size == this->capacity)
            resize(this->capacity * 2);
        this->data[this->size] = value;
        this->size += 1;
    }

    void resize(int new_capacity){
        this->data = (Elem*) realloc(this->data, new_capacity * sizeof(int));
        this->capacity = new_capacity;
        if(new_capacity < this->size)
            this->size = new_capacity;
    }

    void pop_back(){
        if(this->size > 0)
            return;
        this->size -= 1;
    }

    void show(){
        printf("%02d/%02d[ ", this->size, this->capacity);
        for(int i = 0; i < this->size; i++){
            cout << this->data[i] << " ";
        }
        printf("]\n");
    }

    void insert(int index, int valor){
        if((index < 0) || (index > this->size)){
            return;
        }
        if(this->capacity == this->size){
            this->resize(this->capacity * 2);
        }

        for(int i = this->size; i >= index; i--){
            this->data[i + 1] = this->data[i]; 
        }
        this->data[index] = valor;
        this->size++;
    }
    void remove(int index){
        if((index < 0) || (index >= this->size)){
            return;
        }
        for(int i = index; i < this->size - 1; i++){
            this->data[i] = this->data[i+1];
            
        }
        this->size--;
    }

    void remove_all(int value){
        for(int a = 0; a < this->size; a++){
            if(this->data[a] == value){
                this->remove(a);
            }
        }
    }
};


int main(){
    Vector<string> nomes(3);
    nomes.push_back("oi");
    nomes.push_back("tim");


}

/* struct Pessoa{
    string nome;
    int idade;

    Pessoa cruzar(Pessoa other){
        Pessoa filho;
        filho.idade = 0;
        filho.name = this->name + other.name;
        return filho;
    }
};


Pessoa a("jose", 33);
Pessoa b("maria", 32);
Pessoa filho = b.cruzar(a) */
