#include <iostream>
using namespace std;

struct Node
{
    int valor;
    Node*next;
    Node(int v, Node *n = nullptr) {
      valor = v;
      next = n;
    }
};

template <class T>
struct par{
 bool operator()(Node*a){
  return a->valor <10;
}
};

template<class T>
struct lista_enlazada
{

void Add(int  v);
bool find(int  v, Node*&pos);
bool del(int v);
void split(Node*&H1,Node*&H2, T ES_PAR);
void print();
Node *head = nullptr;
T pp;
int A[8];
};

template <class T> 
void lista_enlazada<T>::Add(int v) {
  Node *pos;
  if (!find(v, pos)) {
    if (pos) {
      pos->next = new Node(v, pos->next);
    } else {
      head = new Node(v, head);
    }
  }
}

template <class T> 
bool lista_enlazada<T>::del(int v) {
  Node *pos, *tmp;
  if (find(v, pos)) {
    if (!pos) {
      tmp = head;
      head = head->next;
    } else {
      tmp = pos->next;
      pos->next = pos->next->next;
    }
    delete tmp;
  }
}
template <class T> 
bool lista_enlazada<T>::find(int v, Node *&pos) {
  bool res = false;
  pos = nullptr;
  for (Node*p = head; p && p->valor < v; pos = p, p = p->next) {
    if (p->valor == v) {
      res = true;
      break;
    }
  }

  return res;
}
template <class T> 
void lista_enlazada<T>::print() {
  if (head == nullptr) {
    cout << "Lista vacia" << endl;
  } else {
    cout << "head ->";
    for (Node*p = head; p; p = p->next) {
      cout << p->valor << "->";
    }
    cout << "NULL" << endl;
  }
}



template <class T>
void lista_enlazada<T>::split(Node*&H1, Node*&H2, T es_par) {
    Node* p1 = H1;
    Node* prev = nullptr;
    Node* nextNode = nullptr;

    while (p1) {
        if (es_par(p1)) {
            
            prev = p1;
            p1 = p1->next;
        } else {
            
            nextNode = p1->next;

            if (prev) {
                prev->next = nextNode;
            } else {
                H1 = nextNode;
            }


            if (H2) {
                Node* lastNode = H2;
                while (lastNode->next) {
                    lastNode = lastNode->next;
                }
                lastNode->next = p1;
                p1->next = nullptr;
            } else {
                H2 = p1;
                H2->next = nullptr;
            }

            p1 = nextNode;
        }
    }
}
int main() {
  lista_enlazada<par<int>> list1;
  lista_enlazada<par<int>> list2;

  int A[8]={1,7,9,8,12,23,34,90};
  
  for (int i = 0; i <8; ++i)
  {
      list1.Add(A[i]);
  }

  
  list1.print();

  list1.split(list1.head, list2.head, par<int>());

  cout << "h1:";
  list1.print();

  cout << "h2";
  list2.print();

  return 0;
    } 