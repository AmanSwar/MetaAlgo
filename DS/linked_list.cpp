#include "linked_list.h"
#include <initializer_list>

#include <iostream>

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

  m_Size++;
   
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

  m_Size = 0;

}

template<typename Dtype>
void SingleLinkedList<Dtype>::Insert(Dtype value , UINT64 index){

  SingleLLNode<Dtype>* node = new SingleLLNode<Dtype>;
  node->value = value;
  node->next = nullptr;

  SingleLLNode<Dtype>* iter = m_HeadNode; // points to first element
  for(size_t i = 0 ; i < index-1 ; i++){
    iter = iter->next;
  }
  SingleLLNode<Dtype>* temp_ptr = iter->next;
  iter->next = node;
  node->next = temp_ptr;

  m_Size++;

}


template<typename Dtype>
void SingleLinkedList<Dtype>::Remove(UINT64 index){

  SingleLLNode<Dtype>* iter = m_HeadNode;
  for(size_t i = 0; i < index-1 ; i++){
    iter = iter->next;
  }

  SingleLLNode<Dtype> to_delete_ptr = iter->next;

  SingleLLNode<Dtype> temp_ptr = to_delete_ptr->next;

  delete to_delete_ptr;

  iter->next = temp_ptr;

  m_Size--;

}

template <typename Dtype>
SingleLLNode<Dtype>* SingleLinkedList<Dtype>::GetLast(){
  
  SingleLLNode<Dtype>* iter = m_HeadNode;

  for(size_t i = 0; i < m_Size ; i++){
    iter = iter->next;
  }
  return iter;
}

template <typename Dtype>
void SingleLinkedList<Dtype>::PrintList(){

  SingleLLNode<Dtype>* iter = m_HeadNode;

  for(size_t i = 0 ; i < m_Size ; i++){
    iter = iter->next;
    std::cout << iter->value << " ";
  }
  
}
