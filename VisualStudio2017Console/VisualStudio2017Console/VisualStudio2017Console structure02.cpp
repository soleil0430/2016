#include <stdio.h>
#include <string.h>

struct People
{
    char name[20];
    int age;
};

void main()
{
    // int i; int: 타입 이름, i: 변수
    People i; // People 구조체 타입 이름, i: 변수
    People j;
    strcpy(i.name, "Jintaeks");
    i.age = 50;
    strcpy(j.name, "Cheon");
    j.age = 27;
    printf("%s, age=%i\r\n", i.name, i.age);
}