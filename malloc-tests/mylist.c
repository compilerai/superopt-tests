#include <stdint.h>
#include <stdlib.h>

#ifndef __TYPES_H
#define __TYPES_H
//#include <linux/types.h>

//#ifdef __PEEPGEN__
#define dprintk printf
#define kmalloc umalloc
#define kfree free
#undef ASSERT
#define ASSERT assert
#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
/* "Safe" macros for min() and max(). See [GCC-ext] 4.1 and 4.6. */
#define min(a,b)                                                      \
  ({typeof (a) _a = (a); typeof (b) _b = (b);                         \
    _a < _b ? _a : _b;                                                \
   })
#define max(a,b)                                                      \
  ({typeof (a) _a = (a); typeof(b) _b = (b);                          \
    _a > _b ? _a : _b;                                                \
   })


#define GFP_KERNEL 0
#define UINT_MAX 4294967295U

#define LONG_MAX 2147483647L
#define LONG_MIN (-LONG_MAX - 1)
#define ULONG_MAX 4294967295UL

#define LLONG_MAX 9223372036854775807LL
#define LLONG_MIN (-LLONG_MAX - 1)
#define ULLONG_MAX 18446744073709551615ULL

//#endif

/*typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;*/

typedef uint32_t target_ulong;
typedef uint32_t target_phys_addr_t;

/* Index of a disk sector within a disk.
   Good enough for disks up to 2 TB. */
//typedef uint32_t disk_sector_t;

#ifndef INT8_MAX
#define INT8_MAX 127
#define INT8_MIN (-INT8_MAX - 1)

#define INT16_MAX 32767
#define INT16_MIN (-INT16_MAX - 1)

#define INT32_MAX 2147483647
#define INT32_MIN (-INT32_MAX - 1)

#define INT64_MAX 9223372036854775807LL
#define INT64_MIN (-INT64_MAX - 1)

#define UINT8_MAX 255

#define UINT16_MAX 65535

#define UINT32_MAX 4294967295U

#define UINT64_MAX 18446744073709551615ULL

#define INTPTR_MIN INT32_MIN
#define INTPTR_MAX INT32_MAX

#define UINTPTR_MAX UINT32_MAX

#define INTMAX_MIN INT64_MIN
#define INTMAX_MAX INT64_MAX

#define UINTMAX_MAX UINT64_MAX

#define PTRDIFF_MIN INT32_MIN
#define PTRDIFF_MAX INT32_MAX

//#define SIZE_MAX UINT32_MAX

/**/
#endif

#define UNUSED __attribute__ ((unused))
#define NO_RETURN __attribute__ ((noreturn))
#define NO_INLINE __attribute__ ((noinline))
#define PRINTF_FORMAT(FMT, FIRST) __attribute__ ((format (dprintk, FMT, FIRST)))

#define PANIC(...) {dprintk(__VA_ARGS__);}


#endif



//#include "debug.h"
//#ifndef __PEEPGEN__
//#include <linux/module.h>	/* Needed by all modules */
//#include <linux/kernel.h>
//#include "hypercall.h"
//#endif

#ifndef __LIB_MYLIST_H
#define __LIB_MYLIST_H

/* Doubly linked list.

   This implementation of a doubly linked list does not require
   use of dynamically allocated memory.  Instead, each structure
   that is a potential list element must embed a struct list_elem
   member.  All of the list functions operate on these `struct
   list_elem's.  The list_entry macro allows conversion from a
   struct list_elem back to a structure object that contains it.

   For example, suppose there is a needed for a list of `struct
   foo'.  `struct foo' should contain a `struct list_elem'
   member, like so:

      struct foo
        {
          struct list_elem elem;
          int bar;
          ...other members...
        };

   Then a list of `struct foo' can be be declared and initialized
   like so:

      struct list foo_list;

      list_init (&foo_list);

   Iteration is a typical situation where it is necessary to
   convert from a struct list_elem back to its enclosing
   structure.  Here's an example using foo_list:

      struct list_elem *e;

      for (e = list_begin (&foo_list); e != list_end (&foo_list);
           e = list_next (e))
        {
          struct foo *f = list_entry (e, struct foo, elem);
          ...do something with f...
        }

   You can find real examples of list usage throughout the
   source; for example, malloc.c, palloc.c, and thread.c in the
   threads directory all use lists.

   The interface for this list is inspired by the list<> template
   in the C++ STL.  If you're familiar with list<>, you should
   find this easy to use.  However, it should be emphasized that
   these lists do *no* type checking and can't do much other
   correctness checking.  If you screw up, it will bite you.

   Glossary of list terms:

     - "front": The first element in a list.  Undefined in an
       empty list.  Returned by list_front().

     - "back": The last element in a list.  Undefined in an empty
       list.  Returned by list_back().

     - "tail": The element figuratively just after the last
       element of a list.  Well defined even in an empty list.
       Returned by list_end().  Used as the end sentinel for an
       iteration from front to back.

     - "beginning": In a non-empty list, the front.  In an empty
       list, the tail.  Returned by list_begin().  Used as the
       starting point for an iteration from front to back.

     - "head": The element figuratively just before the first
       element of a list.  Well defined even in an empty list.
       Returned by list_rend().  Used as the end sentinel for an
       iteration from back to front.

     - "reverse beginning": In a non-empty list, the back.  In an
       empty list, the head.  Returned by list_rbegin().  Used as
       the starting point for an iteration from back to front.

     - "interior element": An element that is not the head or
       tail, that is, a real list element.  An empty list does
       not have any interior elements.
*/

#include <linux/stddef.h>
#include <linux/types.h>

/* List element. */
struct mylist_elem {
  struct mylist_elem *prev;     /* Previous mylist element. */
  struct mylist_elem *next;     /* Next mylist element. */
};

/* List. */
struct mylist {
  struct mylist_elem head;      /* List head. */
  struct mylist_elem tail;      /* List tail. */
};

/* Converts pointer to mylist element MYLIST_ELEM into a pointer to
   the structure that MYLIST_ELEM is embedded inside.  Supply the
   name of the outer structure STRUCT and the member name MEMBER
   of the mylist element.  See the big comment at the top of the
   file for an example. */
#define mylist_entry(MYLIST_ELEM, STRUCT, MEMBER)           \
        ((STRUCT *) ((uint8_t *) &(MYLIST_ELEM)->next     \
                     - offsetof (STRUCT, MEMBER.next)))

/* List initialization.

   A mylist may be initialized by calling mylist_init():

       struct mylist my_mylist;
       mylist_init (&my_mylist);

   or with an initializer using MYLIST_INITIALIZER:

       struct mylist my_mylist = MYLIST_INITIALIZER (my_mylist); */
#define MYLIST_INITIALIZER(NAME) { { NULL, &(NAME).tail }, \
                                 { &(NAME).head, NULL } }


void mylist_init (struct mylist *);

/* List traversal. */
struct mylist_elem *mylist_begin (struct mylist *);
struct mylist_elem *mylist_next (struct mylist_elem *);
struct mylist_elem *mylist_end (struct mylist *);

struct mylist_elem *mylist_rbegin (struct mylist *);
struct mylist_elem *mylist_prev (struct mylist_elem *);
struct mylist_elem *mylist_rend (struct mylist *);

struct mylist_elem *mylist_head (struct mylist *);
struct mylist_elem *mylist_tail (struct mylist *);

/* List insertion. */
void mylist_insert (struct mylist_elem *, struct mylist_elem *);
void mylist_splice (struct mylist_elem *before,
                  struct mylist_elem *first, struct mylist_elem *last);
void mylist_push_front (struct mylist *, struct mylist_elem *);
void mylist_push_back (struct mylist *, struct mylist_elem *);

/* List removal. */
struct mylist_elem *mylist_remove (struct mylist_elem *);
struct mylist_elem *mylist_pop_front (struct mylist *);
struct mylist_elem *mylist_pop_back (struct mylist *);

/* List elements. */
struct mylist_elem *mylist_front (struct mylist *);
struct mylist_elem *mylist_back (struct mylist *);

/* List properties. */
size_t mylist_size (struct mylist *);
bool mylist_empty (struct mylist *);

/* Miscellaneous. */
//void mylist_reverse (struct mylist *);

/* Compares the value of two mylist elements A and B, given
   auxiliary data AUX.  Returns true if A is less than B, or
   false if A is greater than or equal to B. */
typedef bool mylist_less_func (const struct mylist_elem *a,
                             const struct mylist_elem *b,
                             void *aux);

/* Operations on mylists with ordered elements. */
void mylist_sort (struct mylist *,
                mylist_less_func *, void *aux);
void mylist_insert_ordered (struct mylist *, struct mylist_elem *,
                          mylist_less_func *, void *aux);
void mylist_unique (struct mylist *, struct mylist *duplicates,
                  mylist_less_func *, void *aux);

/* Max and min. */
struct mylist_elem *mylist_max (struct mylist *, mylist_less_func *, void *aux);
struct mylist_elem *mylist_min (struct mylist *, mylist_less_func *, void *aux);

/**
 * mylist_for_each_entry	-	iterate over mylist of given type
 * @pos:	the type * to use as a loop cursor.
 * @head:	the head for your mylist.
 * @member:	the name of the mylist_struct within the struct.
 */
#define mylist_for_each_entry(pos, head, member)				\
	for (pos = mylist_entry((head)->next, typeof(*pos), member);	\
	     prefetch(pos->member.next), &pos->member != (head); 	\
	     pos = mylist_entry(pos->member.next, typeof(*pos), member))

/**
 * mylist_for_each_entry_safe - iterate over mylist of given type safe against removal of mylist entry
 * @pos:	the type * to use as a loop cursor.
 * @n:		another type * to use as temporary storage
 * @head:	the head for your mylist.
 * @member:	the name of the mylist_struct within the struct.
 */
#define mylist_for_each_entry_safe(pos, n, head, member)			\
	for (pos = mylist_entry((head)->next, typeof(*pos), member),	\
		n = mylist_entry(pos->member.next, typeof(*pos), member);	\
	     &pos->member != (head); 					\
	     pos = n, n = mylist_entry(n->member.next, typeof(*n), member))

/**
 * mylist_for_each  - iterate over a mylist
 * @pos:  the &struct mylist_head to use as a loop cursor.
 * @head: the head for your mylist.
 */
#define mylist_for_each(pos, head) \
  for (pos = (head)->next; prefetch(pos->next), pos != (head); \
      pos = pos->next)



#define MYLIST_HEAD_INIT(name) { &(name), &(name) }

#define MYLIST_HEAD(name) \
    struct mylist_head name = MYLIST_HEAD_INIT(name)

static inline void INIT_MYLIST_HEAD(struct mylist_elem *mylist)
{
  mylist->next = mylist;
  mylist->prev = mylist;
}

/*
 * Insert a new entry between two known consecutive entries.
 *
 * This is only for internal mylist manipulation where we know
 * the prev/next entries already!
 */
static inline void __mylist_add(struct mylist_elem *new,
			      struct mylist_elem *prev,
			      struct mylist_elem *next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}

/**
 * mylist_add - add a new entry
 * @new: new entry to be added
 * @head: mylist head to add it after
 *
 * Insert a new entry after the specified head.
 * This is good for implementing stacks.
 */
static inline void mylist_add(struct mylist_elem *new, struct mylist_elem *head)
{
	__mylist_add(new, head, head->next);
}


/**
 * mylist_add_tail - add a new entry
 * @new: new entry to be added
 * @head: mylist head to add it before
 *
 * Insert a new entry before the specified head.
 * This is useful for implementing queues.
 */
static inline void mylist_add_tail(struct mylist_elem *new, struct mylist_elem *head)
{
	__mylist_add(new, head->prev, head);
}

/*
 * Delete a mylist entry by making the prev/next entries
 * point to each other.
 *
 * This is only for internal mylist manipulation where we know
 * the prev/next entries already!
 */
static inline void __mylist_del(struct mylist_elem * prev, struct mylist_elem * next)
{
	next->prev = prev;
	prev->next = next;
}

/********** include/linux/mylist.h **********/
/*
 *  These are non-NULL pointers that will result in page faults
 *  under normal circumstances, used to verify that nobody uses
 *  non-initialized mylist entries.
 */
#define MYLIST_POISON1  NULL //((void *) 0x00100100)
#define MYLIST_POISON2  NULL //((void *) 0x00200200)

/**
 * mylist_del - deletes entry from mylist.
 * @entry: the element to delete from the mylist.
 * Note: mylist_empty() on entry does not return true after this, the entry is
 * in an undefined state.
 */
static inline void mylist_del(struct mylist_elem *entry)
{
	__mylist_del(entry->prev, entry->next);
	entry->next = MYLIST_POISON1;
	entry->prev = MYLIST_POISON2;
}

/**
 * mylist_replace - replace old entry by new one
 * @old : the element to be replaced
 * @new : the new element to insert
 *
 * If @old was empty, it will be overwritten.
 */
static inline void mylist_replace(struct mylist_elem *old,
				struct mylist_elem *new)
{
	new->next = old->next;
	new->next->prev = new;
	new->prev = old->prev;
	new->prev->next = new;
}

static inline void mylist_replace_init(struct mylist_elem *old,
					struct mylist_elem *new)
{
	mylist_replace(old, new);
	INIT_MYLIST_HEAD(old);
}

/**
 * mylist_del_init - deletes entry from mylist and reinitialize it.
 * @entry: the element to delete from the mylist.
 */
static inline void mylist_del_init(struct mylist_elem *entry)
{
	__mylist_del(entry->prev, entry->next);
	INIT_MYLIST_HEAD(entry);
}

/**
 * mylist_move - delete from one mylist and add as another's head
 * @mylist: the entry to move
 * @head: the head that will precede our entry
 */
static inline void mylist_move(struct mylist_elem *mylist, struct mylist_elem *head)
{
	__mylist_del(mylist->prev, mylist->next);
	mylist_add(mylist, head);
}

/**
 * mylist_move_tail - delete from one mylist and add as another's tail
 * @mylist: the entry to move
 * @head: the head that will follow our entry
 */
static inline void mylist_move_tail(struct mylist_elem *mylist,
				  struct mylist_elem *head)
{
	__mylist_del(mylist->prev, mylist->next);
	mylist_add_tail(mylist, head);
}

/**
 * mylist_is_last - tests whether @mylist is the last entry in mylist @head
 * @mylist: the entry to test
 * @head: the head of the mylist
 */
static inline int mylist_is_last(const struct mylist_elem *mylist,
				const struct mylist_elem *head)
{
	return mylist->next == head;
}

/**
 * mylist_empty - tests whether a mylist is empty
 * @head: the mylist to test.
 */
static inline int mylist_head_empty(const struct mylist_elem *head)
{
	return head->next == head;
}

/**
 * mylist_empty_careful - tests whether a mylist is empty and not being modified
 * @head: the mylist to test
 *
 * Description:
 * tests whether a mylist is empty _and_ checks that no other CPU might be
 * in the process of modifying either member (next or prev)
 *
 * NOTE: using mylist_empty_careful() without synchronization
 * can only be safe if the only activity that can happen
 * to the mylist entry is mylist_del_init(). Eg. it cannot be used
 * if another CPU could re-mylist_add() it.
 */
static inline int mylist_empty_careful(const struct mylist_elem *head)
{
	struct mylist_elem *next = head->next;
	return (next == head) && (next == head->prev);
}

/**
 * mylist_is_singular - tests whether a mylist has just one entry.
 * @head: the mylist to test.
 */
static inline int mylist_is_singular(const struct mylist_elem *head)
{
	return !mylist_head_empty(head) && (head->next == head->prev);
}

static inline void __mylist_cut_position(struct mylist_elem *mylist,
		struct mylist_elem *head, struct mylist_elem *entry)
{
	struct mylist_elem *new_first = entry->next;
	mylist->next = head->next;
	mylist->next->prev = mylist;
	mylist->prev = entry;
	entry->next = mylist;
	head->next = new_first;
	new_first->prev = head;
}

/**
 * mylist_cut_position - cut a mylist into two
 * @mylist: a new mylist to add all removed entries
 * @head: a mylist with entries
 * @entry: an entry within head, could be the head itself
 *	and if so we won't cut the mylist
 *
 * This helper moves the initial part of @head, up to and
 * including @entry, from @head to @mylist. You should
 * pass on @entry an element you know is on @head. @mylist
 * should be an empty mylist or a mylist you do not care about
 * losing its data.
 *
 */
static inline void mylist_cut_position(struct mylist_elem *mylist,
		struct mylist_elem *head, struct mylist_elem *entry)
{
	if (mylist_head_empty(head))
		return;
	if (mylist_is_singular(head) &&
		(head->next != entry && head != entry))
		return;
	if (entry == head)
		INIT_MYLIST_HEAD(mylist);
	else
		__mylist_cut_position(mylist, head, entry);
}

static inline void __mylist_head_splice(const struct mylist_elem *mylist,
				 struct mylist_elem *prev,
				 struct mylist_elem *next)
{
	struct mylist_elem *first = mylist->next;
	struct mylist_elem *last = mylist->prev;

	first->prev = prev;
	prev->next = first;

	last->next = next;
	next->prev = last;
}

#if 0
/**
 * mylist_head_splice - join two mylists, this is designed for stacks
 * @mylist: the new mylist to add.
 * @head: the place to add it in the first mylist.
 */
static inline void mylist_head_splice(const struct mylist_elem *mylist,
				struct mylist_elem *head)
{
	if (!mylist_head_empty(mylist))
		__mylist_head_splice(mylist, head, head->next);
}

/**
 * mylist_splice_tail - join two mylists, each mylist being a queue
 * @mylist: the new mylist to add.
 * @head: the place to add it in the first mylist.
 */
static inline void mylist_splice_tail(struct mylist_elem *mylist,
				struct mylist_elem *head)
{
	if (!mylist_head_empty(mylist))
		__mylist_splice(mylist, head->prev, head);
}

/**
 * mylist_splice_init - join two mylists and reinitialise the emptied mylist.
 * @mylist: the new mylist to add.
 * @head: the place to add it in the first mylist.
 *
 * The mylist at @mylist is reinitialised
 */
static inline void mylist_splice_init(struct mylist_elem *mylist,
				    struct mylist_elem *head)
{
	if (!mylist_head_empty(mylist)) {
		__mylist_splice(mylist, head, head->next);
		INIT_MYLIST_HEAD(mylist);
	}
}

/**
 * mylist_splice_tail_init - join two mylists and reinitialise the emptied mylist
 * @mylist: the new mylist to add.
 * @head: the place to add it in the first mylist.
 *
 * Each of the mylists is a queue.
 * The mylist at @mylist is reinitialised
 */
static inline void mylist_splice_tail_init(struct mylist_elem *mylist,
					 struct mylist_elem *head)
{
	if (!mylist_head_empty(mylist)) {
		__mylist_splice(mylist, head->prev, head);
		INIT_MYLIST_HEAD(mylist);
	}
}
#endif

#endif /* lib/list.h */


/* Our doubly linked mylists have two header elements: the "head"
   just before the first element and the "tail" just after the
   last element.  The `prev' link of the front header is null, as
   is the `next' link of the back header.  Their other two links
   point toward each other via the interior elements of the mylist.

   An empty mylist looks like this:

                      +------+     +------+
                  <---| head |<--->| tail |--->
                      +------+     +------+

   A mylist with two elements in it looks like this:

        +------+     +-------+     +-------+     +------+
    <---| head |<--->|   1   |<--->|   2   |<--->| tail |<--->
        +------+     +-------+     +-------+     +------+

   The symmetry of this arrangement eliminates lots of special
   cases in mylist processing.  For example, take a look at
   mylist_remove(): it takes only two pointer assignments and no
   conditionals.  That's a lot simpler than the code would be
   without header elements.

   (Because only one of the pointers in each header element is used,
   we could in fact combine them into a single header element
   without sacrificing this simplicity.  But using two separate
   elements allows us to do a little bit of checking on some
   operations, which can be valuable.) */

static bool is_sorted (struct mylist_elem *a, struct mylist_elem *b,
                       mylist_less_func *less, void *aux) UNUSED;

/* Returns true if ELEM is a head, false otherwise. */
static inline bool
is_head (struct mylist_elem *elem)
{
  return elem != NULL && elem->prev == NULL && elem->next != NULL;
}

/* Returns true if ELEM is an interior element,
   false otherwise. */
static inline bool
is_interior (struct mylist_elem *elem)
{
  return elem != NULL && elem->prev != NULL && elem->next != NULL;
}

/* Returns true if ELEM is a tail, false otherwise. */
static inline bool
is_tail (struct mylist_elem *elem)
{
  return elem != NULL && elem->prev != NULL && elem->next == NULL;
}

/* Initializes MYLIST as an empty mylist. */
void
mylist_init (struct mylist *mylist)
{
  ASSERT (mylist != NULL);
  mylist->head.prev = NULL;
  mylist->head.next = &mylist->tail;
  mylist->tail.prev = &mylist->head;
  mylist->tail.next = NULL;
}

/* Returns the beginning of MYLIST.  */
struct mylist_elem *
mylist_begin (struct mylist *mylist)
{
  ASSERT (mylist != NULL);
  return mylist->head.next;
}

/* Returns the element after ELEM in its mylist.  If ELEM is the
   last element in its mylist, returns the mylist tail.  Results are
   undefined if ELEM is itself a mylist tail. */
struct mylist_elem *
mylist_next (struct mylist_elem *elem)
{
  ASSERT (is_head (elem) || is_interior (elem));
  return elem->next;
}

/* Returns MYLIST's tail.

   mylist_end() is often used in iterating through a mylist from
   front to back.  See the big comment at the top of mylist.h for
   an example. */
struct mylist_elem *
mylist_end (struct mylist *mylist)
{
  ASSERT (mylist != NULL);
  return &mylist->tail;
}

/* Returns the MYLIST's reverse beginning, for iterating through
   MYLIST in reverse order, from back to front. */
struct mylist_elem *
mylist_rbegin (struct mylist *mylist) 
{
  ASSERT (mylist != NULL);
  return mylist->tail.prev;
}

/* Returns the element before ELEM in its mylist.  If ELEM is the
   first element in its mylist, returns the mylist head.  Results are
   undefined if ELEM is itself a mylist head. */
struct mylist_elem *
mylist_prev (struct mylist_elem *elem)
{
  ASSERT (is_interior (elem) || is_tail (elem));
  return elem->prev;
}

/* Returns MYLIST's head.

   mylist_rend() is often used in iterating through a mylist in
   reverse order, from back to front.  Here's typical usage,
   following the example from the top of mylist.h:

      for (e = mylist_rbegin (&foo_mylist); e != mylist_rend (&foo_mylist);
           e = mylist_prev (e))
        {
          struct foo *f = mylist_entry (e, struct foo, elem);
          ...do something with f...
        }
*/
struct mylist_elem *
mylist_rend (struct mylist *mylist) 
{
  ASSERT (mylist != NULL);
  return &mylist->head;
}

/* Return's MYLIST's head.

   mylist_head() can be used for an alternate style of iterating
   through a mylist, e.g.:

      e = mylist_head (&mylist);
      while ((e = mylist_next (e)) != mylist_end (&mylist)) 
        {
          ...
        }
*/
struct mylist_elem *
mylist_head (struct mylist *mylist) 
{
  ASSERT (mylist != NULL);
  return &mylist->head;
}

/* Return's MYLIST's tail. */
struct mylist_elem *
mylist_tail (struct mylist *mylist) 
{
  ASSERT (mylist != NULL);
  return &mylist->tail;
}

/* Inserts ELEM just before BEFORE, which may be either an
   interior element or a tail.  The latter case is equivalent to
   mylist_push_back(). */
void
mylist_insert (struct mylist_elem *before, struct mylist_elem *elem)
{
  ASSERT (is_interior (before) || is_tail (before));
  ASSERT (elem != NULL);

  elem->prev = before->prev;
  elem->next = before;
  before->prev->next = elem;
  before->prev = elem;
}

/* Removes elements FIRST though LAST (exclusive) from their
   current mylist, then inserts them just before BEFORE, which may
   be either an interior element or a tail. */
void
mylist_splice (struct mylist_elem *before,
             struct mylist_elem *first, struct mylist_elem *last)
{
  ASSERT (is_interior (before) || is_tail (before));
  if (first == last)
    return;
  last = mylist_prev (last);

  ASSERT (is_interior (first));
  ASSERT (is_interior (last));

  /* Cleanly remove FIRST...LAST from its current mylist. */
  first->prev->next = last->next;
  last->next->prev = first->prev;

  /* Splice FIRST...LAST into new mylist. */
  first->prev = before->prev;
  last->next = before;
  before->prev->next = first;
  before->prev = last;
}

/* Inserts ELEM at the beginning of MYLIST, so that it becomes the
   front in MYLIST. */
void
mylist_push_front (struct mylist *mylist, struct mylist_elem *elem)
{
  mylist_insert (mylist_begin (mylist), elem);
}

/* Inserts ELEM at the end of MYLIST, so that it becomes the
   back in MYLIST. */
void
mylist_push_back (struct mylist *mylist, struct mylist_elem *elem)
{
  mylist_insert (mylist_end (mylist), elem);
}

/* Removes ELEM from its mylist and returns the element that
   followed it.  Undefined behavior if ELEM is not in a mylist.

   It's not safe to treat ELEM as an element in a mylist after
   removing it.  In particular, using mylist_next() or mylist_prev()
   on ELEM after removal yields undefined behavior.  This means
   that a naive loop to remove the elements in a mylist will fail:

   ** DON'T DO THIS **
   for (e = mylist_begin (&mylist); e != mylist_end (&mylist); e = mylist_next (e))
     {
       ...do something with e...
       mylist_remove (e);
     }
   ** DON'T DO THIS **

   Here is one correct way to iterate and remove elements from a
   mylist:

   for (e = mylist_begin (&mylist); e != mylist_end (&mylist); e = mylist_remove (e))
     {
       ...do something with e...
     }

   If you need to free() elements of the mylist then you need to be
   more conservative.  Here's an alternate strategy that works
   even in that case:

   while (!mylist_empty (&mylist))
     {
       struct mylist_elem *e = mylist_pop_front (&mylist);
       ...do something with e...
     }
*/
struct mylist_elem *
mylist_remove (struct mylist_elem *elem)
{
  ASSERT (is_interior (elem));
  elem->prev->next = elem->next;
  elem->next->prev = elem->prev;
  return elem->next;
}

/* Removes the front element from MYLIST and returns it.
   Undefined behavior if MYLIST is empty before removal. */
struct mylist_elem *
mylist_pop_front (struct mylist *mylist)
{
  struct mylist_elem *front = mylist_front (mylist);
	if (!front) PANIC("%s", "");
  mylist_remove (front);
  return front;
}

/* Removes the back element from MYLIST and returns it.
   Undefined behavior if MYLIST is empty before removal. */
struct mylist_elem *
mylist_pop_back (struct mylist *mylist)
{
  struct mylist_elem *back = mylist_back (mylist);
  mylist_remove (back);
  return back;
}

/* Returns the front element in MYLIST.
   Undefined behavior if MYLIST is empty. */
struct mylist_elem *
mylist_front (struct mylist *mylist)
{
  ASSERT (!mylist_empty (mylist));
  return mylist->head.next;
}

/* Returns the back element in MYLIST.
   Undefined behavior if MYLIST is empty. */
struct mylist_elem *
mylist_back (struct mylist *mylist)
{
  ASSERT (!mylist_empty (mylist));
  return mylist->tail.prev;
}

/* Returns the number of elements in MYLIST.
   Runs in O(n) in the number of elements. */
size_t
mylist_size (struct mylist *mylist)
{
  struct mylist_elem *e;
  size_t cnt = 0;

  for (e = mylist_begin (mylist); e != mylist_end (mylist); e = mylist_next (e))
    cnt++;
  return cnt;
}

/* Returns true if MYLIST is empty, false otherwise. */
bool
mylist_empty (struct mylist *mylist)
{
  return mylist_begin (mylist) == mylist_end (mylist);
}

#if 0
/* Swaps the `struct mylist_elem *'s that A and B point to. */
static void
myswap (struct mylist_elem **a, struct mylist_elem **b) 
{
  struct mylist_elem *t = *a;
  *a = *b;
  *b = t;
}

/* Reverses the order of MYLIST. */
void
mylist_reverse (struct mylist *mylist)
{
  if (!mylist_empty (mylist)) 
    {
      struct mylist_elem *e;

      for (e = mylist_begin (mylist); e != mylist_end (mylist); e = e->prev)
        myswap (&e->prev, &e->next);
      myswap (&mylist->head.next, &mylist->tail.prev);
      myswap (&mylist->head.next->prev, &mylist->tail.prev->next);
    }
}
#endif

/* Returns true only if the mylist elements A through B (exclusive)
   are in order according to LESS given auxiliary data AUX. */
static bool
is_sorted (struct mylist_elem *a, struct mylist_elem *b,
           mylist_less_func *less, void *aux)
{
  if (a != b)
    while ((a = mylist_next (a)) != b) 
      if (less (a, mylist_prev (a), aux))
        return false;
  return true;
}

/* Finds a run, starting at A and ending not after B, of mylist
   elements that are in nondecreasing order according to LESS
   given auxiliary data AUX.  Returns the (exclusive) end of the
   run.
   A through B (exclusive) must form a non-empty range. */
static struct mylist_elem *
find_end_of_run (struct mylist_elem *a, struct mylist_elem *b,
                 mylist_less_func *less, void *aux)
{
  ASSERT (a != NULL);
  ASSERT (b != NULL);
  ASSERT (less != NULL);
  ASSERT (a != b);
  
  do 
    {
      a = mylist_next (a);
    }
  while (a != b && !less (a, mylist_prev (a), aux));
  return a;
}

/* Merges A0 through A1B0 (exclusive) with A1B0 through B1
   (exclusive) to form a combined range also ending at B1
   (exclusive).  Both input ranges must be nonempty and sorted in
   nondecreasing order according to LESS given auxiliary data
   AUX.  The output range will be sorted the same way. */
static void
inplace_merge (struct mylist_elem *a0, struct mylist_elem *a1b0,
               struct mylist_elem *b1,
               mylist_less_func *less, void *aux)
{
  ASSERT (a0 != NULL);
  ASSERT (a1b0 != NULL);
  ASSERT (b1 != NULL);
  ASSERT (less != NULL);
  ASSERT (is_sorted (a0, a1b0, less, aux));
  ASSERT (is_sorted (a1b0, b1, less, aux));

  while (a0 != a1b0 && a1b0 != b1)
    if (!less (a1b0, a0, aux)) 
      a0 = mylist_next (a0);
    else 
      {
        a1b0 = mylist_next (a1b0);
        mylist_splice (a0, mylist_prev (a1b0), a1b0);
      }
}

/* Sorts MYLIST according to LESS given auxiliary data AUX, using a
   natural iterative merge sort that runs in O(n lg n) time and
   O(1) space in the number of elements in MYLIST. */
void
mylist_sort (struct mylist *mylist, mylist_less_func *less, void *aux)
{
  size_t output_run_cnt;        /* Number of runs output in current pass. */

  ASSERT (mylist != NULL);
  ASSERT (less != NULL);

  /* Pass over the mylist repeatedly, merging adjacent runs of
     nondecreasing elements, until only one run is left. */
  do
    {
      struct mylist_elem *a0;     /* Start of first run. */
      struct mylist_elem *a1b0;   /* End of first run, start of second. */
      struct mylist_elem *b1;     /* End of second run. */

      output_run_cnt = 0;
      for (a0 = mylist_begin (mylist); a0 != mylist_end (mylist); a0 = b1)
        {
          /* Each iteration produces one output run. */
          output_run_cnt++;

          /* Locate two adjacent runs of nondecreasing elements
             A0...A1B0 and A1B0...B1. */
          a1b0 = find_end_of_run (a0, mylist_end (mylist), less, aux);
          if (a1b0 == mylist_end (mylist))
            break;
          b1 = find_end_of_run (a1b0, mylist_end (mylist), less, aux);

          /* Merge the runs. */
          inplace_merge (a0, a1b0, b1, less, aux);
        }
    }
  while (output_run_cnt > 1);

  ASSERT (is_sorted (mylist_begin (mylist), mylist_end (mylist), less, aux));
}

/* Inserts ELEM in the proper position in MYLIST, which must be
   sorted according to LESS given auxiliary data AUX.
   Runs in O(n) average case in the number of elements in MYLIST. */
void
mylist_insert_ordered (struct mylist *mylist, struct mylist_elem *elem,
                     mylist_less_func *less, void *aux)
{
  struct mylist_elem *e;

  ASSERT (mylist != NULL);
  ASSERT (elem != NULL);
  ASSERT (less != NULL);

  for (e = mylist_begin (mylist); e != mylist_end (mylist); e = mylist_next (e))
    if (less (elem, e, aux))
      break;
  return mylist_insert (e, elem);
}

/* Iterates through MYLIST and removes all but the first in each
   set of adjacent elements that are equal according to LESS
   given auxiliary data AUX.  If DUPLICATES is non-null, then the
   elements from MYLIST are appended to DUPLICATES. */
void
mylist_unique (struct mylist *mylist, struct mylist *duplicates,
             mylist_less_func *less, void *aux)
{
  struct mylist_elem *elem, *next;

  ASSERT (mylist != NULL);
  ASSERT (less != NULL);
  if (mylist_empty (mylist))
    return;

  elem = mylist_begin (mylist);
  while ((next = mylist_next (elem)) != mylist_end (mylist))
    if (!less (elem, next, aux) && !less (next, elem, aux)) 
      {
        mylist_remove (next);
        if (duplicates != NULL)
          mylist_push_back (duplicates, next);
      }
    else
      elem = next;
}

/* Returns the element in MYLIST with the largest value according
   to LESS given auxiliary data AUX.  If there is more than one
   maximum, returns the one that appears earlier in the mylist.  If
   the mylist is empty, returns its tail. */
struct mylist_elem *
mylist_max (struct mylist *mylist, mylist_less_func *less, void *aux)
{
  struct mylist_elem *max = mylist_begin (mylist);
  if (max != mylist_end (mylist)) 
    {
      struct mylist_elem *e;
      
      for (e = mylist_next (max); e != mylist_end (mylist); e = mylist_next (e))
        if (less (max, e, aux))
          max = e; 
    }
  return max;
}

/* Returns the element in MYLIST with the smallest value according
   to LESS given auxiliary data AUX.  If there is more than one
   minimum, returns the one that appears earlier in the mylist.  If
   the mylist is empty, returns its tail. */
struct mylist_elem *
mylist_min (struct mylist *mylist, mylist_less_func *less, void *aux)
{
  struct mylist_elem *min = mylist_begin (mylist);
  if (min != mylist_end (mylist)) 
    {
      struct mylist_elem *e;
      
      for (e = mylist_next (min); e != mylist_end (mylist); e = mylist_next (e))
        if (less (e, min, aux))
          min = e; 
    }
  return min;
}

struct node {
  int data;
  struct mylist_elem mylist_elem;
};

struct mylist ls;
struct mylist pmem_ls;

int
main(void)
{
  mylist_init(&ls);
  int i;
  for (i = 0; i < 10; i++) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    mylist_push_front(&ls, &n->mylist_elem);
  }
  mylist_init(&pmem_ls);
  for (i = 0; i < 10; i++) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    mylist_push_front(&pmem_ls, &n->mylist_elem);
  }

}
