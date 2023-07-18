#include "contact.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Contact *contact_create(char *name, char *phone_number, unsigned int age) {
  Contact *newContact = malloc(sizeof(Contact));

  newContact->name = malloc(sizeof(char) * (strlen(name) + 1));
  strcpy(newContact->name, name);

  newContact->phone_number = malloc(sizeof(char) * (strlen(phone_number) + 1));
  strcpy(newContact->phone_number, phone_number);

  newContact->age = age;

  return newContact;
}

Contact *contact_copy(Contact *contact) {
  Contact *copy =
      contact_create(contact->name, contact->phone_number, contact->age);
  return copy;
}

int contact_compare(Contact *c1, Contact *c2) {
  return (strcmp(c1->name, c2->name));
}

void contact_destroy(Contact *contact) {
  free(contact->name);
  free(contact->phone_number);
  free(contact);
}

void contact_print(Contact *contact) {
  printf("%s, %s, %d.\n", contact->name, contact->phone_number, contact->age);
}
