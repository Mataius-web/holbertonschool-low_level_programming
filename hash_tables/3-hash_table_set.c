#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * update_node_value - update the value of an existing node
 * @node: node to update
 * @value: new value
 *
 * Return: 1 on success, 0 on failure
 */

int update_node_value(hash_node_t *node, const char *value)
{
	char *value_copy;

	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);

	free(node->value);
	node->value = value_copy;
	return (1);
}

/**
 * create_node - create a new hash node
 * @key: key of the node
 * @value: value of the node
 *
 * Return: pointer to new node, or NULL on failure
 */

hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *node;

	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
		return (NULL);

	node->key = strdup(key);
	if (node->key == NULL)
	{
		free(node);
		return (NULL);
	}

	node->value = strdup(value);
	if (node->value == NULL)
	{
		free(node->key);
		free(node);
		return (NULL);
	}

	node->next = NULL;
	return (node);
}

/**
 * hash_table_set - adds or updates a key/value in a hash table
 * @ht: pointer to the hash table
 * @key: key to add (cannot be empty)
 * @value: value associated with the key (duplicated)
 *
 * Return: 1 on success, 0 on failure
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *current, *node;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	current = ht->array[index];

	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
			return (update_node_value(current, value));
		current = current->next;
	}

	node = create_node(key, value);
	if (node == NULL)
		return (0);

	node->next = ht->array[index];
	ht->array[index] = node;

	return (1);
}
