#include "latin_representation.h"
/** malloc() */
#include <stdlib.h>

node *create_morse_node_no_arg() {
  node *cell = (node *)malloc(sizeof(node));
  cell -> dot = NULL;
  cell -> dash = NULL;
  cell -> value = (char)0;                    // 0 instead of NULL to prevent casting from integer to char
  return cell;
}
node *create_morse_node(char val) {
  node *cell = (node *)malloc(sizeof(node));
  cell -> dot = NULL;
  cell -> dash = NULL;
  cell -> value = val;
  return cell;
}

node *create_morse_tree() {
  node *tree = create_morse_node_no_arg();
  tree -> dot = create_morse_node('E');
  tree -> dot -> dot = create_morse_node('I');
  tree -> dot -> dot -> dot = create_morse_node('S');
  tree -> dot -> dot -> dot -> dot = create_morse_node('H');
  tree -> dot -> dot -> dot -> dot -> dot = create_morse_node('5');
  tree -> dot -> dot -> dot -> dot -> dash = create_morse_node('4');
  tree -> dot -> dot -> dot -> dash = create_morse_node('V');
  tree -> dot -> dot -> dot -> dash -> dash = create_morse_node('3');
  tree -> dot -> dot -> dash = create_morse_node('U');
  tree -> dot -> dot -> dash -> dot = create_morse_node('F');
  tree -> dot -> dot -> dash -> dash = create_morse_node('_');
  tree -> dot -> dot -> dash -> dash -> dash = create_morse_node('2');
  tree -> dot -> dash = create_morse_node('A');
  tree -> dot -> dash -> dot = create_morse_node('R');
  tree -> dot -> dash -> dot -> dot = create_morse_node('L');
  tree -> dot -> dash -> dash = create_morse_node('W');
  tree -> dot -> dash -> dash -> dot = create_morse_node('P');
  tree -> dot -> dash -> dash -> dash = create_morse_node('J');
  tree -> dot -> dash -> dash -> dash -> dash = create_morse_node('1');
  tree -> dash = create_morse_node('T');
  tree -> dash -> dash = create_morse_node('M');
  tree -> dash -> dash -> dash = create_morse_node('O');
  tree -> dash -> dash -> dash -> dash = create_morse_node('-');
  tree -> dash -> dash -> dash -> dash -> dash = create_morse_node('0');
  tree -> dash -> dash -> dash -> dash -> dot = create_morse_node('9');
  tree -> dash -> dash -> dash -> dot = create_morse_node('.');
  tree -> dash -> dash -> dash -> dot -> dot = create_morse_node('8');
  tree -> dash -> dash -> dot = create_morse_node('G');
  tree -> dash -> dash -> dot -> dash = create_morse_node('Q');
  tree -> dash -> dash -> dot -> dot = create_morse_node('Z');
  tree -> dash -> dash -> dot -> dot -> dot = create_morse_node('7');
  tree -> dash -> dot = create_morse_node('N');
  tree -> dash -> dot -> dash = create_morse_node('K');
  tree -> dash -> dot -> dash -> dash = create_morse_node('Y');
  tree -> dash -> dot -> dash -> dot = create_morse_node('C');
  tree -> dash -> dot -> dot = create_morse_node('D');
  tree -> dash -> dot -> dot -> dash = create_morse_node('X');
  tree -> dash -> dot -> dot -> dot = create_morse_node('B');
  tree -> dash -> dot -> dot -> dot -> dot = create_morse_node('6');

  return tree;
}
