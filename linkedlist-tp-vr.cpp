// vr: exécutez ce code et trouvez ce qui ne va pas -

#include <iostream>
struct Cell
{
  int value;
  Cell *next;

  Cell(int v, Cell *n) : value(v), next(n)
  {
  }
};

struct LinkedList
{
  Cell *head;

  LinkedList() : head(nullptr) {}

  ~LinkedList()
  {
    Cell *actuel = head;
    while (actuel != nullptr)
    {
      Cell *next = actuel->next;
      delete actuel;
      actuel = next;
    }
  }

  void push_front(int v)
  {
    head = new Cell(v, head);
  }

  void print()
  {
    Cell *affiche = head;
    while (affiche != nullptr)
    {
      std::cout << affiche->value << " ";
      affiche = affiche->next;
    }
    std::cout << std::endl;
  }

  void remove(int v)
  {
    if (head == nullptr)
    {
      return;
    }
    else
    {
        while (head->value==v)
      {
          Cell *d = head;
          head = head->next;
          delete d;
        
      }
      Cell *actuelle = head->next;
      Cell *pre = head;
      while (actuelle != nullptr)
      {
        if (actuelle->value == v)
        {
          Cell *d = actuelle;
          pre->next = actuelle->next;
          actuelle = actuelle->next;
          delete d;
        }
        else
        {
          pre = actuelle;
          actuelle = actuelle->next;
        }
      }
    }
  }
};

int main()
{
  LinkedList list1;

  list1.push_front(45);
  list1.push_front(45);
  list1.push_front(12);
  list1.push_front(42);
  list1.push_front(33);
  list1.push_front(17);
  list1.push_front(17);
  list1.print();

  list1.remove(45);
  list1.print();
  list1.remove(17);
  list1.print();

  // LinkedList list;

  // list.push_front(45);
  // list.push_front(12);
  // list.push_front(42);
  // list.push_front(33);
  // list.push_front(17);

  // list.print(); // Affiche: 17 33 42 12 45
  //               // oui l'ordre est inversé car on ajoute en tête de liste...

  // list.remove(88); // Ne fait rien (et pas d'exception à générer)
  // list.remove(17); // Attention on supprime la tête de liste !!
  // list.remove(45); // Attention on supprime la queue de liste !!
  // list.remove(42); // Supprime un élément du milieu de liste
  // // que de cas à gérer... que de pointeurs à mettre à jour...

  // list.print();

  return 0;
}