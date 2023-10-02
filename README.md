# Sandbox detector
Code for [this (part 1)](https://lemond69.github.io/2023/09/11/post.html), [this (part 2)](https://lemond69.github.io/2023/09/24/post.html), and [this (part 3)](https://lemond69.github.io/2023/10/02/post.html) blog post

For sandbox3.c:

Can be compiled with `i686-w64-mingw32-gcc sandbox3.c -s -O3` OR `tcc sandbox3.c`

Results:
-   Wine on i7-1165G7 (all cores enabled): 0.26
-   Wine on i7-1165G7 (all cores except 1 parked): 0.24
-   Native Windows 10 on Pentium Gold 4425Y: 4.19
-   Windows 7 on KVM (1 core): 9.07
-   Windows 7 on KVM (8 cores): 9.89
-   Triage Windows 7: 6.59
-   any.run Windows 7: 48.79
-   Triage Windows 10 1703: 6.09
-   Triage Windows 10 2004: 7.23
-   VirusTotal Microsoft Sysinternals: 30.91
-   VirusTotal Jujubox: 157.27
-   VirusTotal Zenbox: 6.13

Below are all compiled with `i686-w64-mingw32-gcc sandbox.c -s -O3 -masm=intel`

For sandbox2.c:

Results, where THRESHOLD=4.8, and 100%=physical machine, 0%=sandbox:
-   Triage Windows 7: 5%
-   Triage Windows 10 1703: 9%
-   Triage Windows 10 2004: 17%
-   VirusTotal Zenbox: 38%
-   Native Windows 10 on Pentium Gold 4425Y: 83%
-   Native Windows 10 on Intel i5-5200U: 100%

For sandbox.c:

Results, where THRESHOLD=4.8, and 100%=physical machine, 0%=sandbox:
-   Wine on i7-1165G7: 100%
-   Windows 7 on KVM: 0%
-   Triage Windows 7: 0-3%
-   any.run Windows 7: 0-2%
-   Triage Windows 10 1703: 7-21%
-   Triage Windows 10 2004: 0-5%
-   VirusTotal CAPE Sandbox: 0%
-   VirusTotal Microsoft Sysinternals: 1%
-   VirusTotal Jujubox: 0%
-   VirusTotal Zenbox: 91%
-   Native Windows 10 on Pentium Gold 4425Y: 64-100%
-   Native Windows 10 on AMD Ryzen 9 PRO 7940HS: 100%

~Note the false negative on VirusTotal Zenbox, this code is not 100% foolproof. THRESHOLD should be adjusted based on circumstance, THRESHOLD=3.5 is sufficient to block out Zenbox false negative, but may trigger false positive on the Pentium and other older CPUs under heavy load.~ See sandbox2.c
