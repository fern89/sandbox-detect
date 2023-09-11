# Sandbox detector
Code for [this](https://lemond69.github.io/2023/09/11/post.html) blog post

Compiled with `i686-w64-mingw32-gcc sandbox.c -s -O3 -masm=intel`

Results, where THRESHOLD=4.8, and 100%=physical machine, 0%=sandbox:
-   Wine on i7-1165G7: 100%
-   Windows 7 on KVM: 0%
-   Triage Windows 7: 0-3%
-   any.run Windows 7: 0-2%
-   Triage Windows 10 1703: 7-21%
-   Triage Windows 10 2004: 0-5%
-   Native Windows 10 on Pentium Gold 4425Y: 64-100%
-   Native Windows 10 on AMD Ryzen 9 PRO 7940HS: 100%
