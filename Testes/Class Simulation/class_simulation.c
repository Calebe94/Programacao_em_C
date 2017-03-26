#include<stdio.h>
#include<stdlib.h>
/*
 *does not Work!
 * struct animal{
     void (*talk)(struct animal *this);
};
 
 
struct cat{
     struct animal;
};
 
struct dog{
    struct animal;
};
 
void dogtalk(struct animal *this){
    printf("Bark, bark!\n");
}
 
void cattalk(struct animal *this){
     printf("Meow, meow\n");
}
 
void dog_construct(struct dog *this){
     //this->talk = dogtalk;
    this->animal=dogtalk;
}
 
void cat_construct(struct cat *this){
     //this->talk = cattalk;
    this->animal=cattalk;
}
 
int main(){
     struct cat c;
     struct dog d;
 
     cat_construct(&c);
     dog_contstruct(&d);
 
     d.talk((struct animal *)&d);
     c.talk((struct animal *)&c);
}*/
struct class {
    int a;
    int (*method)(struct class* this, int b, int c);
};

int code(struct class* this, int b, int c) {
    return this->a*b+c;
}

struct class constructor(int a) {
    struct class result = {a, code};
    return result;
}

#define call(obj, method, ...) ((obj).method(&(obj), __VA_ARGS__))

#include <stdio.h>
int main() {
    struct class obj = constructor(10);
    int result = call(obj, method, 2, 3);
    printf("%d\n", result);
    return 0;
}