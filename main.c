#include <iostm8s003k3.h>
//
// Delay loop
//
// Actual delay depends on clock settings
// and compiler optimization settings.
//
void delay(unsigned int n)
{
    while (n-- > 0);
}

int main( void )
{
    //
    // Data Direction Register
    //
    // 0: Input
    // 1: Output
    //
    PD_DDR_bit.DDR0 = 1;

    //
    // Control Register 1
    //
    // Input mode:
    //   0: Floating input
    //   1: Input with pull-up
    //
    // Output mode:
    //   0: Pseudo open drain
    //   1: Push-pull
    //
    PD_CR1_bit.C10 = 1;

    //
    // Control Register 2
    //
    // Input mode:
    //   0: External interrupt disabled
    //   1: External interrupt enabled
    //
    // Output mode:
    //   0: Output speed up to  2 MHz
    //   1: Output speed up to 10 MHz
    //
    PD_CR2_bit.C20 = 1;

    //
    // Output Data Register
    //
    // Output value
    //
    PD_ODR_bit.ODR0 = 0;

    //
    // Main loop
    //
    while (1)
    {
        PD_ODR_bit.ODR0 = !PD_ODR_bit.ODR0;
        delay(60000);
    }
}
