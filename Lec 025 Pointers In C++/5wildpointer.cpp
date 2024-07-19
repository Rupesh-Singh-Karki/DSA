//A pointer behaves like a wild pointer when declared but not initialized. So, they point to any random memory location.
int *ptr; //wild pointer

int * p; /* wild pointer */
int a = 10;
p = & a; /* p is not a wild pointer now*/
*p = 12; /* This is fine. Value of a is changed */