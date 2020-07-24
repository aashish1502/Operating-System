
#include "types.h"
#include "gdt.h"

typedef void(*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;
extern "C" void callConstructors()
{
    for(constructor* i = &start_ctors ; i != &end_ctors ; i++)
    (*i)();
}

//pointer that points to the memory address of the display device
void printf(char* str){



    static uint16_t* VideoMemory = (uint16_t*)0xb8000;

    for(int i = 0 ; str[i]!='\0' ; ++i)
        VideoMemory[i] = (VideoMemory[i] & 0xFF00) | str[i];


}


extern "C" void kernelMain(void* multiboot_structure , uint32_t magicnumber){

    printf("This is an attemp to make an operating system -Aashish.");
    printf("This is an attemp to make an operating system -Aashish.");

    GlobalDescriptorTable gdt;

    while(1);

}

