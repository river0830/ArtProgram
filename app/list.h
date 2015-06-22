#ifndef _LIST_H
#define _LIST_H

#ifdef __cplusplus
extern "C" {
#endif


#include <stdio.h>

//#define offsetof(type, item) ((int)(&((type*)0)->item))

#define container_of(ptr, type, member) \
        (type *)( (char *)ptr - offsetof(type,member) )


/*
 * Double linked lists with a single pointer list head.
 * Mostly useful for hash tables where the two pointer list head is
 * too wasteful.
 * You lose the ability to access the tail in O(1).
 */

struct slist_node;
struct slist_head
{
	struct slist_node *first;
};

struct slist_node 
{
	struct slist_node *next, **pprev;
};

#define SLIST_HEAD(name) struct slist_head name = {.first = NULL}

static __inline void INIT_SLIST_NODE(struct slist_node *h)
{
	h->next = NULL;
	h->pprev = NULL;
}

static __inline int slist_empty(const struct slist_head *h)
{
	return !h->first;
}

static __inline void _slist_del(struct slist_node *n)
{
	struct slist_node *next = n->next;
	struct slist_node **pprev = n->pprev;
	*pprev = next;
	if (next)
		next->pprev = pprev;
}

static __inline void slist_del(struct slist_node *n)
{
	_slist_del(n);
    n->next = NULL;
    n->pprev = NULL;
}

static __inline void slist_add_head(struct slist_node *n, struct slist_head *h)
{
	struct slist_node *first = h->first;
	n->next = first;
	if (first)
		first->pprev = &n->next;
	h->first = n;
	n->pprev = &h->first;
}

/* next must be != NULL */
static __inline void slist_add_before(struct slist_node *n,
					struct slist_node *next)
{
	n->pprev = next->pprev;
	n->next = next;
	next->pprev = &n->next;
	*(n->pprev) = n;
}

static __inline void slist_add_after(struct slist_node *n,
					struct slist_node *next)
{
	next->next = n->next;
	n->next = next;
	next->pprev = &n->next;

	if(next->next)
		next->next->pprev  = &next->next;
}

#define slist_entry(ptr, type, member) container_of(ptr,type,member)

#define slist_for_each(pos, head) \
	for (pos = (head)->first; pos; pos = pos->next)

#ifdef __cplusplus
}
#endif

#endif

