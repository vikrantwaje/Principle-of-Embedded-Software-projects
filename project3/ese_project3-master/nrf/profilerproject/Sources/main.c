/*
 * main implementation: use this 'C' sample to create your own application
 *
 */


#include <MKL25Z4.H> /* include peripheral declarations */
static volatile unsigned int DelayTimerTick = 0;

volatile unsigned int Ticker[4];
void InitSysTick()
{	SysTick->LOAD = 41940000/16-1; // Set the Reload to the interrupt at our desired frequency
	SysTick->CTRL = 3;

	//Important!  Since the Systick is part of the Cortex core and NOT a kinetis peripheral
	// its Interrupt line is not passed through NVIC.   You need to make sure that
	//the SysTickIRQ function is populated in the vector table.  See the kinetis_sysinit.c file
}

void SysTick_Handler()
{
	unsigned int i;

	if(DelayTimerTick<0xFFFFFFFF)
	{
		DelayTimerTick++;
	}

	for(i=0;i<4;i++)
	{
		if(Ticker[i]<0xFFFFFFFF)
			{
				Ticker[i]++;
			}
	}
}

void Delay_mS(unsigned int TicksIn_mS)
{
	DelayTimerTick = 0;

	while(DelayTimerTick<TicksIn_mS)
	{
	}
}




void TPM0_init(void)
{
	SIM->SOPT2 |= 0x01000000; /* use MCGFLLCLK as timer counter clock */
	SIM->SCGC6 |= 0x01000000; /* enable clock to TPM0 */
	TPM0->SC = 0; /* disable timer while configuring */
	TPM0->SC = 0x06; /* prescaler /64 */
	TPM0->MOD = 0x7FFE; /* max modulo value */
	TPM0->SC |= 0x80; /* clear TOF */
	TPM0->SC |= 0x40; /* enable timeout interrupt */
	TPM0->SC |= 0x08; /* enable timer */
}

void pin_init(void)
{
	SIM->SCGC5 |= 0x400; /* enable clock to Port B */
	PORTB->PCR[18] = 0x100; /* make PTB18 pin as GPIO */
	PORTB->PCR[19] = 0x100; /* make PTB19 pin as GPIO */
	PTB->PDDR |= 0xC0000; /* make PTB18, 19 as output pin */
	PTB->PDOR |= 0xC0000; /* turn off LEDs */
	SIM->SCGC5 |= 0x200; /* enable clock to Port A */
	/* configure PTA1 for interrupt */
	PORTA->PCR[1] |= 0x00100; /* make it GPIO */
	PORTA->PCR[1] |= 0x00003; /* enable pull-up */
	PTA->PDDR &= ~0x0002; /* make pin input */
	PORTA->PCR[1] &= ~0xF0000; /* clear interrupt selection */
	PORTA->PCR[1] |= 0xA0000; /* enable falling edge interrupt */
	// configure PTA2 for interrupt
	PORTA->PCR[2] |= 0x00100; /* make it GPIO */
	PORTA->PCR[2] |= 0x00003; /* enable pull-up */
	PTA->PDDR &= ~0x0004; /* make pin input */
	PORTA->PCR[2] &= ~0xF0000; /* clear interrupt selection */
	PORTA->PCR[2] |= 0xA0000; /* enable falling edge interrupt */
	NVIC->ISER[0] |= 0x40000000; /* enable INT30 (bit 30 of ISER[0]) */
}

void TPM0_IRQHandler(void)
{
	float end_value= SysTick->VAL;
	float difference=(SysTick->LOAD)-end_value;
	float elapsed_value=elapsed_value/48000000;
	PTB->PTOR = 0x40000; /* toggle red LED */
	TPM0->SC |= 0x80; /* clear TOF */
}


void PORTA_IRQHandler(void)
{
	int i;
	/* toggle green LED (PTB19) three times */
	for (i = 0; i < 3; i++) {
	PTB->PDOR &= ~0x80000; /* turn on green LED */
	delayMs(500);
	PTB->PDOR |= 0x80000; /* turn off green LED */
	delayMs(500);
	}
	PORTA->ISFR = 0x00000006; /* clear interrupt flag */
}

int main(void)
{   TPM0_init();
	NVIC -> ICPR[0]=0xFFFFFFFF; //clear pending interrupts
	InitSysTick(); // Systick is now interrupting once a mS!
	NVIC -> ISPR[0]=(1<<17);

	pin_init();
	float nStart = SysTick->VAL;
	PORTA->PCR[1] |= 0x00100; /* make it GPIO */
	PORTA->PCR[1] |= 0x00003; /* enable pull-up */
	GPIOA_PDDR |= (1<<0); // Set data direction to output
	GPIOA_PCOR|= (1<<0); // Set pin to zero
	PORTA->PCR[1] &= ~0xF0000; /* clear interrupt selection */
	PORTA->PCR[1] |= 0xC0000; /* enable falling edge interrupt */
	PORTA->PCR[1] = 0xC0083;
	float nStop = SysTick->VAL;
	float elapsed_value=elapsed_value/48000000;


}

void delayMs(int n) {
int i;
int j;
for(i = 0 ; i < n; i++)
for (j = 0; j < 7000; j++) {}
}
