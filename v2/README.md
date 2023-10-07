# Sandbox detector V2
Code for [this](https://lemond69.github.io/2023/09/24/post.html) post

Compiled with `i686-w64-mingw32-gcc sandbox.c -s -O3 -masm=intel`

Results, where THRESHOLD=4.8, and 100%=physical machine, 0%=sandbox:
-   Triage Windows 7: 5%
-   Triage Windows 10 1703: 9%
-   Triage Windows 10 2004: 17%
-   VirusTotal Zenbox: 38%
-   Native Windows 10 on Pentium Gold 4425Y: 83%
-   Native Windows 10 on Intel i5-5200U: 100%
