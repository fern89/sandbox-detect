#include <windows.h>
#include <stdio.h>
#define THRESHOLD 4.8
#define MAX_SAND 60 // 40/100 is minimum score
int main(){
    LARGE_INTEGER start;
    LARGE_INTEGER end;
    int phys=0;
    int sand=0;
    double sum=0;
    for(int j=0;j<100;j++){
        QueryPerformanceCounter(&start);
        for(int i=0;i<100;i++) asm("FYL2XP1");
        QueryPerformanceCounter(&end);
        double fy = end.QuadPart - start.QuadPart;
        
        QueryPerformanceCounter(&start);
        for(int i=0;i<100;i++) asm("push eax\n\tpush ebx\n\tpush ecx\n\tpush edx\n\txor eax, eax\n\tCPUID\n\tpop edx\n\tpop ecx\n\tpop ebx\n\tpop eax");
        QueryPerformanceCounter(&end);
        double cpu = end.QuadPart - start.QuadPart;
        double ration=cpu/fy;
        if(ration > THRESHOLD) sand++;
        else phys++;
        sum+=ration;
        Sleep(10);
    }
    sum/=100;
    printf("Avg. score: %f\n", sum);
    printf("%d%% likely to be physical\n", phys);
    if(sand>MAX_SAND) printf("SANDBOX DETECTED!!!\n");
    else printf("Clean\n");
}
