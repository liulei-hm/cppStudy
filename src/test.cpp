//
// Created by liulei on 2023/3/4.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void badman()
{
    printf("I am the bad man\n");
    return;
}
int func(char *str)
{
    int variable_a;
    char buffer[12];
    printf("address:%p\n",buffer);
    strcpy(buffer, str);
    return 1;
}
int main(int argc, char **argv)
{
    char *buf = "hello\n";
    if(argc > 1){
        buf = argv[1];
    }
    func(buf);
    printf("Returned Properly\n");
    return 1;
}
