#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define READSIZE 20
#define MAXN 10

// a.
struct Contact {
  char *name;
  char *phoneNumber;
  unsigned int age;
};

// d.
struct ContactList {
  struct Contact contacts[MAXN];
  unsigned int size;
};

char *getnewline();

struct Contact createContact();

void updateAge(struct Contact *contact);

void addContact(struct ContactList *contactList);

void editAge(struct ContactList *contactList);

void showContact(struct Contact contact);

void showContactList(struct ContactList contactList);

double mean(struct ContactList *contactList);

int main() {
  struct ContactList contactList;
  addContact(&contactList);
  addContact(&contactList);
  showContactList(contactList);

  printf("Editing contact age...\n");
  editAge(&contactList);
  showContactList(contactList);

  printf("age mean: %.2lf years old\n", mean(&contactList));
  return 0;
}

char *getnewline() {
  char buffer[READSIZE + 1], *linea = NULL, *ptr = NULL;
  size_t largoTotal = 0, largoActual;
  int seguir = 1;
  while (seguir) {
    fgets(buffer, READSIZE + 1, stdin);
    ptr = strchr(buffer, '\n');
    if (ptr != NULL) {
      *ptr = '\0';
      seguir = 0;
    }
    largoActual = strlen(buffer);
    linea = realloc(linea, sizeof(char) * (largoTotal + largoActual + 1));
    strcpy(linea + largoTotal, buffer);
    largoTotal += largoActual;
  }
  return linea;
}

// b.
struct Contact createContact() {
  printf("Enter name: ");
  char *name = getnewline();

  printf("Enter phone number: ");
  char *phoneNumber = getnewline();

  printf("Enter age: ");
  char *temp = getnewline();;
  unsigned int age = atoi(temp);

  return (struct Contact) { name, phoneNumber, age };
}

// c. 
void updateAge(struct Contact *contact) {
  printf("Enter age: ");
  char *temp = getnewline();;
  unsigned int newAge = atoi(temp);
  contact->age = newAge;
}

// e.
void addContact(struct ContactList *contactList) {
  if (contactList->size == MAXN) {
    printf("Sorry. Your contact list is full\n");
  } else {
    struct Contact newContact = createContact();
    contactList->contacts[contactList->size] = newContact;
    contactList->size++;
  }
}

// f.
void editAge(struct ContactList *contactList) {
  printf("Enter name: ");
  char *name = getnewline();

  unsigned int i = 0;
  int found = 0;

  while (i < contactList->size && !found) {
    if (strcmp(contactList->contacts[i].name, name) == 0) {
      found = 1;
      updateAge(&contactList->contacts[i]);
    } else {
      i++;
    }
  }

  if (!found) {
    printf("Contact not found\n");
  }
}

// g.
void showContact(struct Contact contact) {
  printf("Name: %s\nPhone number: %s\nAge: %u\n", contact.name,
         contact.phoneNumber, contact.age);
}

void showContactList(struct ContactList contactList) {
  if (contactList.size == 0) {
    printf("Contact list is empty\n");
  }

  printf("Contact list: \n");
  for (unsigned int i = 0; i < contactList.size; i++) {
    showContact(contactList.contacts[i]);
  }
}

// h.
double mean(struct ContactList *contactList) {
  if (contactList->size == 0) {
    return 0;
  }

  double sum = 0.0;

  for (unsigned int i = 0; i < contactList->size; i++) {
    sum += contactList->contacts->age;
  }

  return sum / contactList->size;
}
