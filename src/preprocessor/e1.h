// a.
#define YES 1

// b.
#define NO 0

// c.
#line 3000

// d.
#if defined(TRUE)
  #undef TRUE
  #define TRUE 1
#endif

// e.
#ifdef TRUE
  #undef TRUE
  #define TRUE 1
#endif

// f.
#if TRUE != 0
  #define FALSE 0
#else
  #define FALSE 1
#endif

// g.
#define SQUARE_VOLUMEN(s) (s) * (s) * (s)
