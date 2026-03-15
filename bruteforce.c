#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdint.h>

#define MAX_LENGTH 8
#define CHARSET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"

const char *g_charset = CHARSET;
size_t charset_size;
uint64_t attempts = 0;


int is_valid_target(const char *target)
{
    int i;

    for (i = 0; target[i] != '\0'; i++)
    {
        if (strchr(g_charset, target[i]) == NULL)
        {
            return 0;
        }
    }

    return 1;
}


int increment(char *guess, int length)
{
    int i = length - 1;

    while (i >= 0)
    {
        char *pos = strchr(g_charset, guess[i]);

        if (pos == NULL)
        {
            return 0;
        }

        size_t idx = (size_t)(pos - g_charset);

        if (idx + 1 < charset_size)
        {
            guess[i] = g_charset[idx + 1];
            return 1;
        }

        guess[i] = g_charset[0];
        i--;
    }

    return 0;
}


int brute_force_length(const char *target, int length, char *found)
{
    char guess[MAX_LENGTH + 1];
    int i;

    for (i = 0; i < length; i++)
    {
        guess[i] = g_charset[0];
    }
    guess[length] = '\0';

    do
    {
        attempts++;

        if (strcmp(guess, target) == 0)
        {
            strcpy(found, guess);
            return 1;
        }

    } while (increment(guess, length));

    return 0;
}


int main(void)
{
    char target[MAX_LENGTH + 1];
    char found[MAX_LENGTH + 1] = {0};
    int max_length;
    int len;
    clock_t start;
    clock_t end;
    double elapsed;

    charset_size = strlen(g_charset);

    printf("Brute Force Password Simulator (C)\n");
    printf("----------------------------------\n");
    printf("Allowed charset: %s\n", g_charset);
    printf("Maximum supported length: %d\n\n", MAX_LENGTH);

    printf("Target password: ");
    if (scanf("%8s", target) != 1)
    {
        fprintf(stderr, "Input error.\n");
        return 1;
    }

    if (!is_valid_target(target))
    {
        fprintf(stderr, "Target contains characters not present in the charset.\n");
        return 1;
    }

    printf("Max length to try: ");
    if (scanf("%d", &max_length) != 1 || max_length < 1 || max_length > MAX_LENGTH)
    {
        fprintf(stderr, "Invalid length.\n");
        return 1;
    }

    if ((int)strlen(target) > max_length)
    {
        fprintf(stderr, "Max length is smaller than target length.\n");
        return 1;
    }

    start = clock();

    for (len = 1; len <= max_length; len++)
    {
        if (brute_force_length(target, len, found))
        {
            end = clock();
            elapsed = (double)(end - start) / CLOCKS_PER_SEC;

            printf("\nPassword found:   %s\n", found);
            printf("Length matched:   %d\n", len);
            printf("Attempts:         %llu\n", (unsigned long long)attempts);
            printf("Elapsed time:     %.6f seconds\n", elapsed);

            return 0;
        }
    }

    end = clock();
    elapsed = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nPassword not found.\n");
    printf("Attempts:         %llu\n", (unsigned long long)attempts);
    printf("Elapsed time:     %.6f seconds\n", elapsed);

    return 0;
}
