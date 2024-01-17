# Sandbox detector

Can be compiled with `i686-w64-mingw32-gcc sandbox.c -s -O3`

Raw ratios, lower is more likely physical machine:
-   Wine on i7-1165G7 (all cores enabled): 0.26
-   Wine on i7-1165G7 (all cores except 1 parked): 0.24
-   Native Windows 10 on Pentium Gold 4425Y: 4.19
-   Native Windows 10 on Intel i5-5200U: 0.35
-   Windows 7 on KVM (1 core): 9.07
-   Windows 7 on KVM (8 cores): 9.89
-   Triage Windows 7: 6.59
-   any.run Windows 7: 48.79
-   Triage Windows 10 1703: 6.09
-   Triage Windows 10 2004: 7.23
-   VirusTotal Microsoft Sysinternals: 30.91
-   VirusTotal Jujubox: 157.27
-   VirusTotal Zenbox: 6.13
