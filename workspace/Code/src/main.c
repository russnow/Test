#include "main.h" 

uint16_t delay_count=0;
uint8_t Mode=0;
uint16_t Mode_count=0;
uint8_t Mode_new=0;

uint8_t Button_count=0;
uint8_t Button_state=0;
//---------------------------------------
//
//----------------------------------------
void SysTick_Handler(void)//1ms
{
	if (delay_count>0)
		{
			delay_count--;
		}

	if (Mode_count>0)
		{
			Mode_count--;
		}
	
	if (BUTTON_READ() ==1)
		{
			if (Button_count <5)
				{
					Button_count++;
				}
		
				else
					{
						if (Button_state ==0)
							{
								Button_state=1;
							//	GPIO_ToggleBits(GPIOB, GPIO_Pin_6);
								Mode=MODE_BLUE;
								Mode_new = 1;
								GREEN_OFF();
							}
						
					}
		}
		
		else 
		{
		if (Button_count>0)
			{
				Button_count--;
			}
			
		else 
			{
				Button_state=0;
			}
		}
}

//----------------------------------------
void delay_ms(uint16_t delay_temp)
{
delay_count = delay_temp;
while(delay_count) {}
}
//----------------------------------------
//
//----------------------------------------
int main(void)
{
LEDs_ini();
Button_ini();	
SysTick_Config(SystemCoreClock/1000); //1ms
Mode_count = DELAY;
Mode=MODE_BLUE;

	while(1)
		{
			/*	if (BUTTON_READ() ==1)
				{
				BLUE_ON();
				GREEN_ON();
				}
				else
				{
					BLUE_OFF();
					GREEN_OFF();
				}
					
			*/
					
						if (Mode == MODE_BLUE)
					{
							if (Mode_new ==1)
							{
								Mode_count = DELAY;
								BLUE_ON();
								Mode_new=0;
							}
						
							if (Mode_count == 0)
							{
								BLUE_OFF();
									if (Button_state==1)
										{
											Mode = MODE_GREEN;
										}
								
								Mode = MODE_GREEN;
								Mode_new =1;
							}
					}
					else if (Mode == MODE_GREEN)
					{	
							if (Mode_new ==1)
							{
								Mode_count = DELAY;
								GREEN_ON();
								Mode_new=0;
							}
								if (Mode_count == 0)
							{
								GREEN_OFF();
								Mode = MODE_BLUE;
								Mode_new =1;
							}
					}
		}
}
