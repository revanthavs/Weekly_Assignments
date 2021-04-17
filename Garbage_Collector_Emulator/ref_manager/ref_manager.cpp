/*
  Name: Atmakuri Venkata Sai Revanth
  ID: 1684293
  CMPUT 275, Winter 2021

  Exercise 3: Garbage Collector Emulator
*/
#include "ref_manager.h"
#include <cassert>

ReferenceManager::ReferenceManager() {
  numToDelete = 0;
  for (int i = 0; i < MAX_PTRS; i++) {
    pointers[i] = NULL;
  }
}

ReferenceManager::~ReferenceManager() {
  // To free any memory that is currently allocated
  for (int i = 0; i < pointers_size; i++){
    // To reassign the pointer that are allocated to some memory
    if (pointers[i] !=  NULL)
      reassignPointer(i, NULL);
  }
  garbageCollect();
}

void ReferenceManager::garbageCollect() {
  // To print all the element in the garbage collector
  for (int i = 0; i < garbage_i; i++){
    // Just to make sure NULL is not the a element in garbage collector
    if (garbage[i] != NULL)
      cout << garbage[i] << endl;
  }
  // To free the memory of elements that are added to garbage collector
  for (int i = 0; i < garbage_i; i++){
    // Just to make sure the element is not NULL
    if (garbage[i] != NULL){
      delete[] garbage[i];
      // Since the memory is no longer used reassineing it to NULL
      garbage[i] = NULL;
    }
  }
  // Since all the elements add were deleted reseting the index
  garbage_i = 0;
  return;
}

void ReferenceManager::reassignPointer(unsigned int ptrIndex, const char* newAddr) {
  bool Null_checker;
  // To prevent adding the NULL to the reference counter
  if (newAddr == NULL)
    Null_checker = true;
  else
    Null_checker = false;
  // Since NULL is not an element in refCount unordered_map
  if (pointers[ptrIndex] != NULL)
    refCount[pointers[ptrIndex]]--;

  if ((pointers[ptrIndex] != NULL) && (refCount[pointers[ptrIndex]]) == 0){
    // Since no pointer in pointers array reference the char pointer
    garbage[garbage_i] = pointers[ptrIndex];
    garbage_i++;
  }
  pointers[ptrIndex] = newAddr;
  // To update the refCount of the new pointer added to the pointers array
  if (refCount.find(newAddr) != refCount.end() && (!Null_checker))
    refCount[newAddr]++;
  else if (!Null_checker)
    refCount[newAddr] = 1;
  return;
}

void ReferenceManager::readString(unsigned int ptrIndex, unsigned int length) {
  // The space was allocated one char excess to accommodate the
  // stirng terminator at the end of the charater array
  char *string = new char[length+1];
  for (unsigned int i = 0; i < length; i++)
    cin >> string[i];
  string[length] = '\0';
  // To have the pointer at index reference the newly allocated string
  reassignPointer(ptrIndex, string);
  return;
}

const char* ReferenceManager::getPtr(unsigned int ptrIndex) {
  assert(ptrIndex < MAX_PTRS);
  return pointers[ptrIndex];
}
