/* Constructors and Destructor */

#include "Deque.h"
#include <iostream>
#include <cstring>
using namespace std;

Deque::Deque(){
  left_p = NULL;
  right_p = NULL;
  current_size = 0;
  cursor = NULL;
} // Constructs a new empty deque.
Deque::Deque( const Deque& dq ){
  if(dq.current_size == 0){
    left_p = NULL;
    right_p = NULL;
    current_size = 0;
    cursor = NULL;
    return;
  }
  node* temp = dq.left_p;
  node *newNode = new node(temp->data,NULL,NULL);
  left_p = newNode;
  node* curr = left_p;
  current_size = 1;
  temp = temp -> next;
  while(temp != NULL){

    node* newNode1 = new node(temp -> data, curr, NULL);
    curr -> next = newNode1;
    curr = newNode1;
    if(dq.cursor == temp){
      cursor = newNode1;
    }
    current_size = current_size + 1;
    temp = temp -> next;
  }
  right_p = curr;

}// Copy constructor.
Deque::~Deque(){
  node* temp = left_p;
  while(temp != NULL){
    node* temp2 = temp -> next;
    delete temp;
    temp = temp2;
  }

}// Destructor.

/* Insertion operators */
void Deque::push_left( int item ){
  if(current_size == 0){
    node * node1 = new node(item, NULL, NULL);
    left_p = node1;
    right_p = node1;
    current_size = current_size + 1;
    cursor = node1;
    return;
  }
  left_p -> prev = new node(item, NULL, left_p);
  left_p = left_p -> prev;

  current_size = current_size + 1;

} // Inserts <item> at left end.
void Deque::push_right( int item){
  if(current_size == 0){
    right_p = new node(item, NULL, NULL);
    left_p = right_p;
    current_size = current_size + 1;
    cursor = right_p;
    return;
  }
  right_p -> next = new node(item, right_p, NULL);
  right_p = right_p -> next;

  current_size = current_size + 1;

} // Inserts <item> at right end.

/* Removal operators */
int Deque::pop_left(){
  int tempval = left_p -> data;
  node *temp = left_p;
  if(cursor == left_p){
    cursor = cursor -> next;
  }
  if(current_size == 1){
    left_p = NULL;
    right_p = NULL;
    cursor = NULL;
    current_size = current_size -1;
    delete temp;
    return tempval;
  }
  left_p = left_p -> next;
  left_p -> prev = NULL;
  current_size = current_size -1;
  delete temp;
  return tempval;
}  // removes and returns item on left end.
    // Pre: Deque is not empty.
int Deque::pop_right(){
  int tempval = right_p -> data;
  node *temp = right_p;
  if(cursor == right_p){
    cursor = cursor -> prev;
  }
  if(current_size == 1){
    left_p = NULL;
    right_p = NULL;
    cursor = NULL;
    current_size = current_size -1;
    delete temp;
    return tempval;
  }
  right_p = right_p -> prev;
  right_p -> next = NULL;
  current_size = current_size -1;
  delete temp;
  return tempval;
}  // removes and returns item on right end.
    // Pre: Deque is not empty.

/* Size functions */
bool Deque::empty(){
  if(left_p == NULL && right_p == NULL){
    return 0;
  }
  return 1;
}  // Returns true iff the Deque contains no items.
int Deque::size(){
  return current_size;
}  // Returns the current number of items in the deque.

/* Cursor movement operators
*  These move the cursor one node to the left or right and then
*  return true if such a move is possible.  If the move is not
*  possible (i.e., the cursor is already at the extreme eeque' failed
make: *** [Deque] Error 1
nd
*  or the Deque is emty), no change occurs and false is returned.
*/
bool Deque::cursor_left(){
  if(cursor -> prev == NULL || current_size == 0){
    return false;
  }
  cursor = cursor -> prev;
  return true;
} // Move cursor left.
bool Deque::cursor_right(){
  if(cursor -> next == NULL || current_size == 0){
    return false;
  }
  cursor = cursor -> next;
  return true;
} // Move cursor right.

/* Accessor functions */
int Deque::peek_left(){
  if(current_size == 0){
    return 0;
  }

  return left_p-> data;
}  // Returns the left-most item without removing it.
    // Pre: Deque is not empty.
int Deque::peek_right(){
  if(current_size == 0){
    return 0;
  }
  return right_p -> data;
}  // Returns the right-most item without removing it.
    // Pre: Deque is not empty.
int Deque::get_cursor(){
  if(current_size == 0){
    return 0;
  }
  return cursor -> data;
} // Return value the cursor currently is at,
    // Pre: Deque is not empty.
void Deque::set_cursor(int i){
  cursor -> data = i;
  return;
}
    // Pre: Deque is not empty.

/* Utility functions */
void Deque::display(){
  node* curr = left_p;
  cout << "[";
  while(curr != NULL){
    cout << curr -> data << ";";
    curr = curr -> next;
  }
  cout << "]";
  if(current_size == 0){
    cout << " size=" << current_size << ", cursor=NULL." << endl;
    return;
  }
  cout << " size=" << current_size << ", cursor=" << cursor -> data << "." << endl;

} // prints a depiction of the deque contents to standard output.
void Deque::verbose_display(){
  node* curr = left_p;
  while(curr != NULL){
    cout << curr -> data << " " << curr << " ";
    curr = curr -> next;
  }
} //
