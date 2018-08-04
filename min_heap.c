#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Node{
  int data;
  struct Node* left;
  struct Node* right;
} Node;

Node* root = NULL;
int heap_size = 0;

void swap(Node* a, Node* b){
  int temp = a->data;
  a->data = b->data;
  b->data = temp;
}

int calc_height(int num_nodes){ // calculates the height of a given node
  return log(num_nodes)/log(2);
}

char* dec_to_bin(int x){ // converts decimal to binary (10 bits)
  static char bits[MAX_SIZE] = "0000000000";
  int counter = MAX_SIZE-1;
  while(x != 0){
    if(x%2 == 1){
      bits[counter] = (char)49;
    }else{
      bits[counter] = (char)48;
    }
    counter--;
    x /= 2;
  }
  return bits;
}

Node* create_node(int data){
  Node* temp = (Node*)malloc(sizeof(Node));
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}

Node* get_node(int number){ // returns pointer to specified node
  char* bin_val = dec_to_bin(number);
  struct Node* trav = root;
  int counter = MAX_SIZE - calc_height(number);
  while(counter < MAX_SIZE){
    if(bin_val[counter] == '0'){
      trav = trav->left;
    }else{
      trav = trav->right;
    }
    counter++;
  }
  return trav;
}

void insert(int data){
  Node* temp = create_node(data);
  if(root == NULL){
    root = temp;
  }else{
    int new_heap_size = heap_size + 1;
    char* bin_val = dec_to_bin(new_heap_size);
    struct Node* trav = root;
    int counter = MAX_SIZE - calc_height(new_heap_size);
    while(counter < MAX_SIZE - 1){
      if(bin_val[counter] == '0'){
        trav = trav->left;
      }else{
        trav = trav->right;
      }
      counter++;
    }
    if(bin_val[counter] == '0'){
      trav->left = temp;
    }else{
      trav->right = temp;
    }
  }
  heap_size++;
  int current = heap_size;
  int parent = heap_size/2;
  while(parent > 0 && get_node(parent)->data > get_node(current)->data){
    swap(get_node(parent), get_node(current));
    current = parent;
    parent = current/2;
  }
}

void traverse(){ // level order traversal
  for(int i = 1; i <= heap_size; i++){
    printf("%d ", get_node(i)->data);
  }
}

void heapify(int current)
{
  int min = current;
  int left = 2*current;
  int right = 2*current + 1;
  if(left < heap_size && get_node(current)->data > get_node(left)->data){
    min = left;
  }
  if(right < heap_size && get_node(min)->data > get_node(right)->data){
    min = right;
  }
  if(min != current){
    swap(get_node(min), get_node(current));
    heapify(min);
  }
}

int extract_min(){
  int min = root->data;
  swap(root, get_node(heap_size));
  free(get_node(heap_size));
  heap_size--;
  heapify(1);
  return min;
}

int is_empty(){
  if(root == NULL){
    return 1;
  }else{
    return 0;
  }
}

int main(){
  printf("%d\n", is_empty());
  insert(5);
  insert(6);
  insert(7);
  insert(19);
  insert(20);
  insert(33);
  insert(44);
  insert(2);
  insert(15);
  traverse();
  printf("\n%d\n", extract_min());
  traverse();
  printf("\n%d\n", is_empty());
  insert(100);
  insert(3);
  insert(4);
  traverse();
  return 0;
}
