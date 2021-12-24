#include <iostream>
template <class T>
void ChangeSize(T*& a, const int oldSize, const int newSize) {
  if (newSize < 1) throw "Error";
  T* temp = new T[newSize];
  int number = std::min(oldSize, newSize);
  std::copy(a, a + number, temp);
  delete[] a;
  a = temp;
}
template <class T>
class Stack {
  friend std::ostream& operator<<(std::ostream& os, const Stack& s);
  friend std::istream& operator>>(std::istream& is, Stack& s);

 public:
  Stack(int stackCapacity = 10);
  bool isEmpty() const;
  T& Top() const;
  void Push(const T& item);
  void Pop();

 private:
  T* stack;
  int top;
  int capacity;
};

template <class T>
Stack<T>::Stack(int stackCapacity) : capacity(stackCapacity) {
  if (capacity < 1) throw "Error";
  stack = new T[capacity];
  top = -1;
}

template <class T>
bool Stack<T>::isEmpty() const {
  return top == -1;
}

template <class T>
T& Stack<T>::Top() const {
  return top;
}

template <class T>
void Stack<T>::Push(const T& item) {
  if (capacity - 1 == top) {
    ChangeSize(stack, capacity, capacity * 2);
    capacity *= 2;
  }
  stack[++top] = item;
}

template <class T>
void Stack<T>::Pop() {
  if (isEmpty()) throw "Empty";
  stack[top--].~T();
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& s) {
  for (int i = 0; i < s.capacity; i++) os << s.stack[i] << " ";
  return os;
}

template <class T>
std::istream& operator>>(std::istream& is, Stack<T>& s) {
  T* temp = new T[100];
  is >> temp;
  int i = 0;
  while (temp[i] != '\0') {
    s.Push(temp[i]);
    i++;
  }
  return is;
}
int main(int argc, char const* argv[]) {
  Stack<int> s;
  s.Push(5);
  if (!s.isEmpty()) std::cout << "STACK";
  return 0;
}
