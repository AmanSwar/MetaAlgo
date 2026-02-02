#include "linked_list.h"
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
  m_CurrentNode->next = node;
  m_CurrentNode = node;
   
}


template<typename Dtype>
void SingleLinkedList<Dtype>::_Init(std::initializer_list<Dtype>& initArray){

  for(const auto& element : initArray){
    Append(element);
  }
}