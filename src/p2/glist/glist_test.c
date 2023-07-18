#include "contact.h"
#include "glist.h"

#include <stdio.h>
#include <stdlib.h>

int contact_over60(Contact *contact) {
  return contact->age > 60;
}

int main() {

  GList list = glist_create();
  Contact *contacts[6];
  contacts[0] = contact_create("Pepe Argento", "3412695452", 61);
  contacts[1] = contact_create("Moni Argento", "3412684759", 60);
  contacts[2] = contact_create("Coqui Argento", "3415694286", 32);
  contacts[3] = contact_create("Paola Argento", "3416259862", 29);
  contacts[4] = contact_create("Maria Elena Fuseneco", "3416874594", 59);
  contacts[5] = contact_create("Dardo Fuseneco", "3416894526", 64);

  for (int i = 0; i < 6; ++i) {
    list =
        glist_add_first(list, contacts[i], (CopyFunction) contact_copy);
    contact_destroy(contacts[i]);
  }

  printf("Contact List:\n");
  glist_traverse(list, (VisitFunction) contact_print);

  printf("Contacts over 60 years old:\n");
  GList list2 = glist_filter(list, (CopyFunction) contact_copy, (Predicate) contact_over60);
  glist_traverse(list2, (VisitFunction) contact_print);

  glist_destroy(list, (DestroyFunction) contact_destroy);
  glist_destroy(list2, (DestroyFunction) contact_destroy);

  return 0;
}