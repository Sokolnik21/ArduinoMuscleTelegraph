#ifndef MORSE_TO_LATIN_REPRESENTATION
#define MORSE_TO_LATIN_REPRESENTATION

typedef struct node node;
struct node {
  node *dot;
  node *dash;
  int value;
};

node *CURR_NODE;
node *MORSE;

node *create_morse_tree();

#endif
