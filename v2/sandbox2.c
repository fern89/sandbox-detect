#include <windows.h>
#include <stdio.h>
#define THRESHOLD 4.8
#define MAX_SAND 30 // 70/100 is minimum score
int main(){
    LARGE_INTEGER start;
    LARGE_INTEGER end;
    int phys, sand, outl;
    double fp, sum, cpid;
    for(int k=0;k<5;k++){
        phys=0;
        sand=0;
        fp=0;
        cpid=0;
        sum=0;
        outl=0;
        for(int j=0;j<100;j++){
            QueryPerformanceCounter(&start);
            for(int i=0;i<200;i++) asm("FYL2XP1");
            QueryPerformanceCounter(&end);
            double fy = end.QuadPart - start.QuadPart;
            fp+=fy;
            QueryPerformanceCounter(&start);
            for(int i=0;i<200;i++) asm("push eax\n\tpush ebx\n\tpush ecx\n\tpush edx\n\txor eax, eax\n\tCPUID\n\tpop edx\n\tpop ecx\n\tpop ebx\n\tpop eax");
            QueryPerformanceCounter(&end);
            double cpu = end.QuadPart - start.QuadPart;
            cpid+=cpu;
            double ration=cpu/fy;
            if(ration > THRESHOLD){
                if(ration > 2*(sum/(j+1))){
                    //outliers
                    Sleep(10);
                    j--;
                    outl++;
                    continue;
                }
            }
            if(ration > THRESHOLD) sand++;
            else phys++;
            sum+=ration;
            Sleep(5);
        }
        if(outl <= 10){
            break;
        }
    }
    cpid/=100;
    fp/=100;
    sum/=100;
    char buff[1000]={0};
    sprintf(buff, "cmd.exe /c \"echo FP: %f, CPUID: %f, outliers: %d\"", fp, cpid, outl);
    system(buff);
    memset(buff, 0, 1000);
    sprintf(buff, "cmd.exe /c \"echo Avg. score: %f\"", sum);
    system(buff);
    memset(buff, 0, 1000);
    sprintf(buff, "cmd.exe /c \"echo %d%% likely to be physical\"", phys);
    system(buff);
    memset(buff, 0, 1000);
    if(sand>MAX_SAND)
        system("cmd.exe /c \"echo SANDBOX DETECTED!!!\"");
}
