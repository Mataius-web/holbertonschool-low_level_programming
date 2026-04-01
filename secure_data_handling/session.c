#include <stdlib.h>
#include <string.h>
#include "session.h"

/**
 * session_create - create a new session safely
 * @id: session identifier (string)
 * @uid: user id
 * @data: pointer to data buffer
 * @data_len: length of data buffer
 *
 * Return: pointer to newly created session, or NULL on failure
 */

session_t *session_create(const char *id, unsigned int uid,
						  const unsigned char *data, size_t data_len)
{
	session_t *s;

	if (!id)
		return (NULL);

	s = malloc(sizeof(*s));
	if (!s)
		return (NULL);

	s->id = strdup(id);
	if (!s->id)
	{
		free(s);
		return (NULL);
	}

	s->uid = uid;

	if (data_len > 0)
	{
		s->data = malloc(data_len);
		if (!s->data)
		{
			free(s->id);
			free(s);
			return (NULL);
		}
		memcpy(s->data, data, data_len);
		s->data_len = data_len;
	}
	else
	{
		s->data = NULL;
		s->data_len = 0;
	}

	return (s);
}

/**
 * session_set_data - safely set or update session data
 * @s: pointer to session
 * @data: pointer to new data
 * @data_len: length of new data
 *
 * Return: 1 on success, 0 on failure
 */

int session_set_data(session_t *s, const unsigned char *data, size_t data_len)
{
	unsigned char *tmp;

	if (!s)
		return (0);

	if (data_len == 0)
	{
		free(s->data);
		s->data = NULL;
		s->data_len = 0;
		return (1);
	}

	tmp = realloc(s->data, data_len);
	if (!tmp)
		return (0);

	s->data = tmp;
	memcpy(s->data, data, data_len);
	s->data_len = data_len;

	return (1);
}

/**
 * session_destroy - safely free a session
 * @s: pointer to session
 */

void session_destroy(session_t *s)
{
	if (!s)
		return;

	free(s->id);
	free(s->data);
	free(s);
}
