/* Copyright 2013 goodyoga all rights reserved. */

#include <stdio.h>    /* printf */
#include <stdlib.h>   /* atoi,exit   */
#include <string.h>   /* strlen  */
#include <unistd.h>   /* getopt */

void usage(void);
char *prog;
int check(unsigned long long int cur);

#define BUFF_SIZE   128

int check(unsigned long long int cur)
{
    char buff[BUFF_SIZE], buff2[BUFF_SIZE];
    size_t len;
    unsigned int i;

    snprintf(buff, BUFF_SIZE, "%llu", cur);
    len = strlen(buff);
    for ( i = 0 ; i < len ; i++ )
        buff2[i] = buff[len - i - 1];

    return (0 == strncmp(buff, buff2, len));
}

int main(int argc, char **argv)
{
    unsigned long long int max;
    unsigned long long int cur, i, j;
    int opt, all = 0;
    char *p;
    
    prog = argv[0];
    max = 20;

    while ( -1 != (opt = getopt(argc, argv, "ahn:")) )
    {
        if('h' == opt)
	{
            usage();
            exit(EXIT_SUCCESS);
	}
        else if ('n' == opt)
        {
            max = strtoull(optarg, &p, 0);
        }
        else if ('a' == opt)
        {
            all = 1;
        }
    }
    
    printf("getting Smallest multiple in %llu ...\n", max);

    for ( cur = 1, i = 2 ; i <= max ; i++)
    {
        if (all) printf("check  : %llu can be multiple of %llu?\n", cur, i);
        if (0 == ( cur % i )) 
        {
            if (all) printf("current: %llu covers %llu\n", cur, i);
            continue;
        }

        for ( j = 2 ; j <= i ; j++)
        {
            if (0 == ( (cur*j) % i )) 
            {
                unsigned long long int upd;
                upd = cur *j;
                if (all) printf("update : %llu -> %llu, i:%llu, j:%llu\n", cur, upd, i, j);
                cur = upd;
                break;
            }
        }
    }
    
    printf("answer: %llu\n", cur);
    return EXIT_SUCCESS;
}



void usage(void)
{
    printf("    http://projecteuler.net/problem=5\n");
    printf("    [Problem 5] Smallest multiple\n");
    printf("    2520 is the smallest number that can be divided \n"
           "    by each of the numbers from 1 to 10 without any remainder.\n\n"
           "    What is the smallest positive number that is evenly divisible \n"
           "    by all of the numbers from 1 to 20?\n\n");
    printf("    -h: show this help\n"
           "    -n <number>: solve this with max <number>\n");
    return;
}


