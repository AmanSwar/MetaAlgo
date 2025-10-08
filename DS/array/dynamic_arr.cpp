/*
To implement
- push_back(x)
- pop_back()
- insert(index , x)
- erase(index)
- print_array()
- get(index)


- size()
- capacity()
- resize(new_cap)

class 
- attributess
  - ptr 
  - current size
  - max capacity currentlyw
*/

#include <cassert>
#include <cstddef>
#include <stdatomic.h>
#include "../../types.h"
#include "../../common.h"

template <typename type>
class DynamicArr{
private:
  size_t CAP = 1;
  size_t CURRENT_SIZE = 0;

  type* internal_array;

  type* _reallocate(UINT32 size){
    type* ptr = new type[size];
    return ptr;
  }

public:
  DynamicArr(){
    this->internal_array = _reallocate(1);
  }
  DynamicArr(size_t size) : CURRENT_SIZE(size) {
    this->CAP = size;
    this->internal_array = _reallocate(size);
  }

  void insert(INT32 index , type value){
    
    ASSERT(index < this->CURRENT_SIZE , "Index out of range");

    this->CURRENT_SIZE += 1;

    if(this->CURRENT_SIZE >= this->CAP){
      this->CAP *= 2;
      this->internal_array = _reallocate(this->CAP);
      
    }

    type carry_over_value;
    type index_value = value;
    for(int idx = index ; idx < this->CURRENT_SIZE ; idx++){
      carry_over_value = this->internal_array[idx];
      this->internal_array[idx] = index_value;
      index_value = carry_over_value;
    }

  }

  void erase(INT32 index){
    ASSERT(index > 0, "Index should be possitive");
    ASSERT(index < this->CURRENT_SIZE, "Index greater than array size");

    type currIndexValue = index;
    type succesorValue = index + 1;

    while(currIndexValue < this->CURRENT_SIZE){
      this->internal_array[currIndexValue] = this->internal_array[succesorValue];
      currIndexValue += 1;
      succesorValue += 1;
    }   
    
    this->CURRENT_SIZE -=1;
  }

  void push_back(type value){
    this->CURRENT_SIZE += 1;

    if (this->CURRENT_SIZE >= this->CAP) {
      this->CAP *= 2;
      this->internal_array = _reallocate(this->CAP);
    }

    this->internal_array[this->CURRENT_SIZE-1] = value;
  }

  void pop_back(){
    ASSERT(this->CURRENT_SIZE < 0, "Array is already empty");

    this->internal_array[this->CURRENT_SIZE-1] = 0;

    this->CURRENT_SIZE -=1;
  }

  void print_array(){
    for(int idx = 0; idx < this->CURRENT_SIZE ; idx ++){
      std::cout << this->internal_array[idx] << " ";
    }
  }

  void get(INT32 index){
    ASSERT(index < this->CURRENT_SIZE, "Index out of range");
    return this->internal_array[index];
  }

  size_t size(){
    return this->CURRENT_SIZE;
  }

  size_t capacity(){
    return this->CAP;
  }

  
};