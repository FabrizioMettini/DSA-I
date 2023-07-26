#ifndef __CONTACT_H__
#define __CONTACT_H__

typedef struct {
  char *name;
  char *phone_number;
  unsigned int age;
} Contact;

Contact *contact_create();

Contact *contact_copy(Contact *contact);

int contact_compare(Contact *c1, Contact *c2);

void contact_destroy(Contact *contact);

unsigned contact_hash(Contact *contact);

void contact_print(Contact *contact);

#endif /* __CONTACT_H__ */