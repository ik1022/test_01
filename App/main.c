
int *pfmod = (int *)0x30000500UL;
int *pfout = (int *)0x30000518UL;

void main()
{
    volatile int i = 0;

    *((int *)0x40001A00) = 0x5A690000 | (37 << 10) | (26 << 4);
    *((int *)0x40001820) = 0x20;

    *pfmod = 0x4000;

    i = 0;
    while (1)
    {
        i++;
        if (i >= 0xffff)
        {
            i       = 0;
            *pfout ^= 0x80;
        }
    }
}

void SystemInit(void) {}

void SysTick_Handler(void) {}
