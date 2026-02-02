#include "linked_list.h"
#include <cstddef>
#include <initializer_list>


template<typename Dtype>
SingleLinkedList<Dtype>::SingleLinkedList(std::initializer_list<Dtype>& initArray){
  m_CurrentNode = m_HeadNode;

  _Init(initArray);
}

template<typename Dtype>
void SingleLinkedList<Dtype>::Append(Dtype value){
  SingleLLNode<Dtype>* node = new SingleLinkedList<Dtype>; //alloc in heap
  node->value = value;
  node->next = nullptr;
  m_CurrentNode->next = node;
  m_CurrentNode = node;
   
}


template<typename Dtype>
void SingleLinkedList<Dtype>::_Init(std::initializer_list<Dtype>& initArray){

  for(const auto& element : initArray){
    Append(element);
  }
}

template<typename Dtype>
void SingleLinkedList<Dtype>::Delete(){
  
  SingleLLNode<Dtype>* to_delete_ptr;
  SingleLLNode<Dtype> neighbour_ptr;

  to_delete_ptr = m_HeadNode.next;
  neighbour_ptr = to_delete_ptr->next;

  while(neighbour_ptr != nullptr){
    delete to_delete_ptr;
    to_delete_ptr = neighbour_ptr;
    neighbour_ptr = to_delete_ptr->next;
  }
  // after this loop to_delete_ptr will be at the last node
  // so delete the last node
  delete to_delete_ptr;

}



