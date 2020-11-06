#ifndef _Steck_
#define _Steck_

#include <iostream>

using namespace std;

template <class T>
class TSteck
{
protected:
  int length;
  T* x;
  int ind;
public:
  TSteck(int size = 0);
  TSteck(TSteck<T>& _v);
  ~TSteck();

  TSteck<T>& operator =(TSteck<T>& _v);

  void Push(T d);
  T Get();

  template <class T1>
  friend ostream& operator<< (ostream& ostr, const TSteck<T1> &A);
  template <class T1>
  friend istream& operator >> (istream& istr, TSteck<T1> &A);

  int Length();
};

template <class T1>
ostream& operator<< (ostream& ostr, const TSteck<T1> &A) {
  for (int i = 0; i < A.ind; i++) {
    ostr << A.x[i] << endl;
  }
  return ostr;
}

template <class T1>
istream& operator >> (istream& istr, TSteck<T1> &A) {
  int count;
  istr >> count;
  for (int i = 0; i < count; i++) 
  {
    T1 d;
    istr >> d;
    A.Push(d);
  }
  return istr;
}

template<class T>
inline TSteck<T>::TSteck(int size)
{
  if (size > 0)
  {
    this->length = size;
    x = new T[length];
    for (int i = 0; i < length; i++)
      x[i] = 0;
    this->ind = 0;
  }
  else
    throw - 1;
}

template <class T>
TSteck<T>::TSteck(TSteck<T>& _v)
{
  length = _v.length;
  ind = _v.ind;
  x = new T [length];
  for (int i = 0; i < length;i = i + 1)
    x[i] = _v.x[i];
}
template <class T>
TSteck<T>::~TSteck()
{
  length = 0;
  if (x != 0)
    delete [] x;
  x = 0;
}

template <class T>
TSteck<T>& TSteck<T>::operator =(TSteck<T>& _v)
{
  if (this == &_v)
    return *this;

  length = _v.length;
  delete[] x;
  x = new T [length];
  for (int i = 0; i < length; i++)
    x[i] = _v.x[i];
  ind = _v.ind;
  return *this;
}

template<class T>
inline void TSteck<T>::Push(T d)
{
  if (ind >= length)
    throw - 1;

  x[ind] = d;
  ind++;
}

template<class T>
inline T TSteck<T>::Get()
{
  if (ind == 0)
    throw - 1;

  T d= x[ind - 1];
  ind--;
  return d;
}

template <class T>
int TSteck<T>::Length()
{
  return length;
}


#endif //_Steck_