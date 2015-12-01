#include <stdio.h>
#include <stdlib.h>

#ifdef __linux__
#define UL 0x6a /* ┘ */
#define UR 0x6d /* └ */
#define UH 0x76 /* ┴ */
#define DR 0x6c /* ┌ */
#define DL 0x6b /* ┐ */
#define DH 0x77 /* ┬ */
#define VR 0x74 /* ├ */
#define VL 0x75 /* ┤ */
#define VH 0x6e /* ┼ */
#define HH 0x71 /* ─ */
#define VV 0x78 /* │ */
#define PRINTGRAF_ON printf("\e(0")
#define PRINTGRAF_OFF printf("\e(B")

#elif _WIN32 || _WIN64
#define UL 0xd9 /* ┘ */
#define UR 0xc0 /* └ */
#define UH 0xc1 /* ┴ */
#define DR 0xda /* ┌ */
#define DL 0xbf /* ┐ */
#define DH 0xc2 /* ┬ */
#define VR 0xc3 /* ├ */
#define VL 0xb4 /* ┤ */
#define VH 0xc5 /* ┼ */
#define HH 0xc4 /* ─ */
#define VV 0xb3 /* │ */
#define PRINTGRAF_ON ;
#define PRINTGRAF_OFF ;

#else
#error "este programa nao e compativel com o sistema"
#endif

int main(void)
{
    PRINTGRAF_ON;
    printf("%c\n\n%c\n\n%c\n\n%c\n\n%c\n\n%c\n\n%c\n\n%c\n\n%c\n\n%c\n\n%c\n\n",UL,UR,DR,DL,HH,VV,DH,UH,VR,VL,VH);
    PRINTGRAF_OFF;
    return EXIT_SUCCESS;
}

