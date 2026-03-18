#include "dog.h"
#include <stdlib.h>

/**
 * str_copy - copies a string into a new allocation
 * @str: the string to copy
 *
 * Return: pointer to the new string, or NULL on failure
 */
static char *str_copy(char *str)
{
	char *copy;
	int len;

	if (str == NULL)
		return (NULL);
	for (len = 0; str[len]; len++)
		;
	copy = malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	for (len = 0; str[len]; len++)
		copy[len] = str[len];
	copy[len] = '\0';
	return (copy);
}

/**
 * new_dog - creates a new dog
 * @name: the dog's name
 * @age: the dog's age
 * @owner: the dog's owner
 *
 * Return: pointer to the new dog, or NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;

	dog = malloc(sizeof(dog_t));
	if (!dog)
		return (NULL);
	dog->name = str_copy(name);
	if (!dog->name)
	{
		free(dog);
		return (NULL);
	}
	dog->owner = str_copy(owner);
	if (!dog->owner)
	{
		free(dog->name);
		free(dog);
		return (NULL);
	}
	dog->age = age;
	return (dog);
}
