#include <alloca.h>
#define MAX 4096

int MYmynext_data();

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
    //DBG(__LINE__); // fcall with arg in loop with alloca() will not get correlated because a loc will not be created for arg slot, thus missing the arg slot and llvm arg correlation
                     // loc creation will fail because of avail-exprs analysis' incompleteness due to shallow-deep problem
    Node* tmp = alloca(sizeof(Node));
    tmp->data = MYmynext_data();
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
