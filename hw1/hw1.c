#include<stdio.h>
#include "hw1.h"


void printStudent(Student s){
    char* p = (char*) &s;
    int len = sizeof(s);
    int i = 0;
    for(i = 0; i<len; i++){
        printf("%02x  ",*(p+i));
    }
    printf("\nId: %d", s.identifier);
    printf("\nGrade: %c", s.grade);
    printf("\nName: %s\n", s.name);
}

int strlength(char* s){
    int len = 0;
    if(s == 0) return 0;
    while(*s != '\0'){
        s++;
        len++;
    }
    return len;
}

void renameStudent(Student s, char* newName){
    printf("renaming to: %s\n", newName);
    int len = strlength(newName);
    len = len >= 29 ? 29 : len;
    int i = 0;
    for(i = 0; i<len; ++i){
        s.name[i] = newName[i];
    }
    s.name[i] = '\0';
    printStudent(s);
}

void copy(Student* src, Student* dest){
    char* s = (char* ) src;
    char* d = (char* ) dest;
    int len = sizeof(*src);
    int i = 0;
    for(i = 0; i<len; ++i){
        d[i] = s[i];
    }
}

void swap(Student* s, int  i, int j){
    Student temp;
    copy(s+i, &temp);
    copy(s+j, s+i);
    copy(&temp, s+j);
    //Student temp = s[i];
    //s[i] = s[j];
    //s[j] = temp;
}

void sortStudents(Student* s, int count){
    if(s==0 || count <= 0) return ;
    int i = 0, j = 0;
    for(i=0; i<count; ++i){
        char mingrade = s[i].grade;
        int minindex = i;
        for(j = i; j<count; j++){
            if(s[j].grade < mingrade){
                mingrade = s[j].grade;
                minindex = j;
            }
        }
        swap(s, i, minindex);
    }
    for(i=0; i<count; ++i){
        printStudent(s[i]);
    }
}

int main(){
    Student s = { 1, 'A', "Dennis Ritchie" };
    printStudent(s);
    renameStudent(s, "Hu Li");
    renameStudent(s, "Balakrishnan Radhakrishnan");
    Student p[3] = { {1, 'B',"T. Merrifield"}, {2, 'C', "J. Erikksson"}, {3, 'A', "D. Rittchie"} };
    printStudent(p[2]);
    sortStudents(p, 3);
    return 0;
}
