#include <stdlib.h>
#include "dog.h"

/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: pointer to new dog, or NULL if it fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;
	int i, len_name = 0, len_owner = 0;

	if (name == NULL || owner == NULL)
		return (NULL);

	/* calculate length of name */
	for (i = 0; name[i]; i++)
		len_name++;

	/* calculate length of owner */
	for (i = 0; owner[i]; i++)
		len_owner++;

	/* allocate memory for dog struct */
	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	/* allocate memory for name */
	dog->name = malloc(len_name + 1);
	if (dog->name == NULL)
	{
		free(dog);
		return (NULL);
	}

	/* allocate memory for owner */
	dog->owner = malloc(len_owner + 1);
	if (dog->owner == NULL)
	{
		free(dog->name);
		free(dog);
		return (NULL);
	}

	/* copy name */
	for (i = 0; i < len_name; i++)
		dog->name[i] = name[i];
	dog->name[len_name] = '\0';

	/* copy owner */
	for (i = 0; i < len_owner; i++)
		dog->owner[i] = owner[i];
	dog->owner[len_owner] = '\0';

	dog->age = age;

	return (dog);
}
