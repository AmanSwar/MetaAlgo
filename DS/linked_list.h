/*
Single linkedList and Double LinkedList

Methods to implement
- Append(value)
- Insert(value , index)
- Delete() -> remove the whole linkedList
- Remove(index) -> remove the node from the given position
- Find(index)

- GetLength
- GetFirst
- GetLast

- Reverse
- Sort
- Merge(list 2) -> merges list 2
- Copy(list 2)


*/
#pragma once


#include <initializer_list>
#include "../types.h"


template <typename Dtype>
struct SingleLLNode{
  Dtype value;
  SingleLLNode<Dtype>* next;
};

template <typename Dtype>
struct DoubleLLNode{
  Dtype value;
  DoubleLLNode<Dtype>* next;
  DoubleLLNode<Dtype>* prev;
};


template <typename Dtype>
class SingleLinkedList{

private:
  SingleLLNode<Dtype> m_HeadNode;
  SingleLLNode<Dtype>* m_CurrentNode; 
  size_t size;

public:

  // init LinkedList with given unintializer list
  SingleLinkedList(std::initializer_list<Dtype>& initArray);
  ~SingleLinkedList();

  void Append(Dtype value);
  void Insert(Dtype value , UINT32 index);
  void Delete(); // delete the entire linkedList
  void Remove(UINT32 index);
  UINT32 Find(Dtype value); // find the specified element and returns the index

  size_t GetLength(){ return size; }
  SingleLinkedList<Dtype>* GetFirst() { return HeadNode->next; }
  SingleLinkedList<Dtype>* GetLast();

  void Reverse();
  void Sort();
  void Merge(const SingleLinkedList<Dtype>& other);
  void Copy(const SingleLinkedList<Dtype>& other);

private:

  void _Init(std::initializer_list<Dtype>& initArray); // function to be called inside the constructor for init LinkedList from inititalizer list



};







