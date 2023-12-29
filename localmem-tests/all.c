#include <alloca.h>

int next_data();

int n;
int all()
{
  typedef struct lln {
    int data;
    struct lln* next;
  } Node;
  if (n > 4096)
    return 0;
  Node* hd = 0;
  for (int i = 0; i < n; ++i) {
    Node* t = alloca(sizeof(Node));
    t->data = next_data();
    t->next = hd; hd = t;
  }
  Node* t = hd;
  int ret = 0;
  while (t != 0) {
    ret += t->data;
    t = t->next;
  }
  return ret;
}
