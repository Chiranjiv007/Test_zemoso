#include <stdio.h>
#include <stdlib.h>

#include <ctype.h>
#include <stdio.h>
#include <sys/resource.h>
#include <sys/time.h>

#include "dictionary.h"

// Default dictionary
#define DICTIONARY "dictionaries/large"


int main(void)
{

	char source[MAX_LENGTH], destination[MAX_LENGTH];
	bool loaded = load(DICTIONARY);

	get_string("source: ",source);
	get_string("Destination: ",destination);

	// Exit if dictionary not loaded
    if (!loaded)
    {
        printf("Could not load %s.\n", DICTIONARY);
        return 1;
    }

    travel(source,destination);

	
	
	return 0;
}

void get_string(const char call_for_var[MAX_LENGTH],int &input[MAX_LENGTH])
{
    
    printf("%s\n", call_for_var);
    fgets(input, MAX_LENGTH, stdin);
    input[strlen(input)-1]='\0';

    return;
}

void travel()
{
	if(strlen(source) != strlen(destination))
	{
		printf("Not possible\n");
		return;
	}

	int checkpoint[strlen(source)] = {-1};
	
	while(source != destination)
	{
		for(int i = 0; i < strlen(source); i++)
		{
			for(int j = 0; j < strlen(source); j++)
			{
				if(j != checkpoint[i])
				{
					char *temp;
					temp = source;


					if(source[j] == destination[j])
					{
						continue;
					}
					source[j] = destination[j];
					

					if(check(source))
					{
						check_point[i] = j;
						break;
					}
					else
					{
						source = temp;
					}
				}
			}
		}
	}
}