/* Copyright 2013 goodyoga all rights reserved. */

#include <stdio.h>    /* printf */
#include <stdlib.h>   /* atoi,exit   */
#include <string.h>   /* strlen  */
#include <unistd.h>   /* getopt */

/**
 * @file main_005.c
 * @addtogroup EULER_005  Euler_005_smallest_multiple
 * @{
 */

/**
 * @brief main of smallest multiple
 * 
 * @param argc
 * @param argv -h shows help\n-n=&lt;number&gt; sets number.-a show all debug printf().
 * @return always SUCCESS
 * 
 * @startuml{euler_005_smallest_multiple.png}
 * 
 * participant defaults
 * 
 * defaults->defaults: all = 0
 * defaults->defaults: max = 20
 * 
 * opt h option
 *     note over defaults: show help.
 * else n option
 *     note over defaults: max = argv
 * else a option
 *     note over defaults: all = 1
 * end opt
 * 
 * k->k:
 * @enduml
 */
int main(int argc, char **argv);


/**
 * @brief shows usage
 */
void usage(void);

/**
 * @}
 */




/***********************************
 * Implementation
 ***********************************/



int main(int argc, char **argv)
{
    unsigned long long int max;
    unsigned long long int cur, i, j;
    int opt, all = 0;
    char *p;
    
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


