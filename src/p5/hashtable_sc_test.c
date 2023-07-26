#include "contact.h"
#include "hashtable.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 11

int main() {
  Hashtable ht = hashtable_create(
      INITIAL_CAPACITY, (CopyFunction) contact_copy,
      (CompareFunction) contact_compare,
      (DestroyFunction) contact_destroy, (HashFunction) contact_hash);

  Contact *contact_list[6];
  contact_list[0] = contact_create("Pepe Argento", "3412695452", 61);
  contact_list[1] = contact_create("Moni Argento", "3412684759", 60);
  contact_list[2] = contact_create("Coqui Argento", "3415694286", 32);
  contact_list[3] = contact_create("Paola Argento", "3416259862", 29);
  contact_list[4] = contact_create("Maria Elena Fuseneco", "3416874594", 59);
  contact_list[5] = contact_create("Dardo Fuseneco", "3416894526", 64);

  printf("Insertion:\n");
  for (int i = 0; i < 6; ++i) {
    printf("Inserting contact: ");
    contact_print(contact_list[i]);
    printf(" in cell %d.\n",
           contact_hash(contact_list[i]) % hashtable_capacity(ht));
    
    int nElems = hashtable_nelems(ht);
    hashtable_insert(ht, contact_list[i]);

    if (hashtable_nelems(ht) == nElems)
      printf("\tFailure: Colision.\n");
    else
      printf("\tSuccess.\n");
  }

  printf("\nSearch:\n");
  for (int i = 0; i < 6; ++i) {
    printf("Searching contact: ");
    contact_print(contact_list[i]);
    puts("");

    Contact *ret = hashtable_search(ht, contact_list[i]);

    if (ret != NULL)
      printf("\tFound.\n");
    else
      printf("\tNot Found.\n");
  }

  printf("\nDelete:\n");
  for (int i = 5; i > 2; --i) {
    printf("Deleting contact: ");
    contact_print(contact_list[i]);
    puts("");
    hashtable_delete(ht, contact_list[i]);
  }

  printf("\nSearch:\n");
  for (int i = 0; i < 6; ++i) {
    printf("Searching contact: ");
    contact_print(contact_list[i]);
    puts("");

    Contact *ret = hashtable_search(ht, contact_list[i]);

    if (ret != NULL)
      printf("\tFound.\n");
    else
      printf("\tNot Found.\n");
  }

  Contact *newContact = contact_create("Pepe Argento", "3410000000", 71);
  printf("\nOverwriting contact: ");
  contact_print(contact_list[0]);
  printf("\n\t for: ");
  contact_print(newContact);
  puts("");

  hashtable_insert(ht, newContact);

  Contact *ret = hashtable_search(
      ht, contact_list[0]);
  printf("New contact is: ");
  contact_print(ret);
  puts("");

  hashtable_destroy(ht);
  for (int i = 0; i < 6; ++i)
    contact_destroy(contact_list[i]);
  contact_destroy(newContact);

  return 0;
}