#include <alloca.h>
#define MAX 4096

int next_data();

int n;
int alloca_linked_list()
{
  typedef struct lln {
    int data;
    struct lln* next;
  } Node;
  if (n > MAX)
    return 0;

  Node* hd = 0;
  for (int i = 0; i < n; ++i) {
    Node* tmp = alloca(sizeof(Node));
    tmp->data = next_data();
    tmp->next = hd; hd = tmp;
  }
  Node* tmp = hd;
  int ret = 0;
  while (tmp != 0) {
    ret += tmp->data;
    tmp = tmp->next;
  }
  return ret;
}
