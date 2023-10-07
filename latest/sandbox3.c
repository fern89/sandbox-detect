#include <windows.h>
#include <stdio.h>
#include <math.h>
#define THRESHOLD 5.0
#define ITERATIONS 1000000
int notdone, c;
DWORD WINAPI fp(void* data) {
    while(notdone){
        for(int i=0;i<10;i++) asm(".byte 0xd9\n\t.byte 0xf9"); //FYL2XP1
        c++;
    }
    return 0;
}

int main(){
    notdone=1;
    c=0;
    HANDLE thread = CreateThread(NULL, 0, fp, NULL, 0, NULL);
    for(int i=0;i<ITERATIONS;i++) asm("push %eax\n\tpush %ebx\n\tpush %ecx\n\tpush %edx\n\txor %eax, %eax\n\t.byte 0x0f\n\t.byte 0xa2\n\tpop %edx\n\tpop %ecx\n\tpop %ebx\n\tpop %eax"); //CPUID
    notdone=0;
    WaitForSingleObject(thread, INFINITE);
    c*=10;
    double ration = ((double)c)/((double)ITERATIONS);
    printf("c=%d, ratio=%f\n", c, ration);
    if(ration > THRESHOLD) printf("SANDBOX DETECTED!!!\n");
    double fscore = ((tanh(ration-THRESHOLD)+1)/2)*100;
    printf("%f%% confident sandbox\n", fscore);
    return 0;
}
