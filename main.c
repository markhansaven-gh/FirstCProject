#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
    char* name; 
} Person;

Person* createPerson() {
    Person* p = (Person*)malloc(sizeof(Person));
    if (p == NULL) {
        fprintf(stderr, "Failed to allocate Person\n");
        return NULL;
    }
    p->name = NULL;
    return p;
}

void setName(Person* p, const char* newName) {
    if (p == NULL) return;

    if (p->name != NULL) {
        free(p->name);
    }

    p->name = (char*)malloc(strlen(newName) + 1);
    if (p->name != NULL) {
        strcpy(p->name, newName);
    }
}

void freePerson(Person* p) {
    if (p == NULL) return;

    if (p->name != NULL) {
        free(p->name);
    }

    free(p);
}

int main() {
    Person* p = createPerson();

    setName(p, "Feehlix");
    printf("Hello, %s!\n", p->name);

    setName(p, "NewName");
    printf("Name changed to: %s\n", p->name);

    freePerson(p);

    return 0;
}