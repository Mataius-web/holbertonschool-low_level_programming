#include <stdlib.h>
#include <string.h>
#include "store.h"

/**
 * store_init - initialize a store
 * @st: pointer to store
 */

void store_init(store_t *st)
{
	if (st)
		st->head = NULL;
}

/**
 * node_create - create a new node for a session
 * @s: pointer to session
 *
 * Return: pointer to new node or NULL on failure
 */

static node_t *node_create(session_t *s)
{
	node_t *n;

	if (!s)
		return (NULL);

	n = malloc(sizeof(*n));
	if (!n)
		return (NULL);

	n->sess = s;
	n->next = NULL;

	return (n);
}

/**
 * store_add - add a session to the store
 * @st: pointer to store
 * @s: pointer to session
 *
 * Return: 1 on success, 0 on failure
 */

int store_add(store_t *st, session_t *s)
{
	node_t *n, *cur;

	if (!st || !s || !s->id)
		return (0);

	cur = st->head;
	while (cur)
	{
		if (cur->sess && cur->sess->id &&
			strcmp(cur->sess->id, s->id) == 0)
			return (0);
		cur = cur->next;
	}

	n = node_create(s);
	if (!n)
		return (0);

	n->next = st->head;
	st->head = n;

	return (1);
}

/**
 * store_get - retrieve a session by id
 * @st: pointer to store
 * @id: session id
 *
 * Return: pointer to session, or NULL if not found
 */

session_t *store_get(store_t *st, const char *id)
{
	node_t *cur;

	if (!st || !id)
		return (NULL);

	cur = st->head;
	while (cur)
	{
		if (cur->sess && cur->sess->id &&
			strcmp(cur->sess->id, id) == 0)
			return (cur->sess);
		cur = cur->next;
	}

	return (NULL);
}

/**
 * store_delete - delete a session by id
 * @st: pointer to store
 * @id: session id
 * @out: optional pointer to store deleted session
 *
 * Return: 1 on success, 0 if not found
 */

int store_delete(store_t *st, const char *id, session_t **out)
{
	node_t *cur, *prev;

	if (!st || !id)
		return (0);

	prev = NULL;
	cur = st->head;

	while (cur)
	{
		if (cur->sess && cur->sess->id &&
			strcmp(cur->sess->id, id) == 0)
		{
			if (prev)
				prev->next = cur->next;
			else
				st->head = cur->next;

			if (out)
				*out = cur->sess;
			else
				session_destroy(cur->sess);

			free(cur);
			return (1);
		}
		prev = cur;
		cur = cur->next;
	}

	return (0);
}

/**
 * store_destroy - free all sessions and nodes in the store
 * @st: pointer to store
 */

void store_destroy(store_t *st)
{
	node_t *cur, *next;

	if (!st)
		return;

	cur = st->head;
	while (cur)
	{
		next = cur->next;

		if (cur->sess)
			session_destroy(cur->sess);

		free(cur);
		cur = next;
	}

	st->head = NULL;
}
