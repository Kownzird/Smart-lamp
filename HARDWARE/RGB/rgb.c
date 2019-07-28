#include "rgb.h"
#include "sys.h"
#include "string.h"

int RGB_Convert(u8 USART_DATA[200],int v)
{
	int i;
	int r=0;
	int g=0;
	int b=0;
	
	int len;
	int len_r;
	int len_g;
	int len_b;

	u16 RED_VALUE; 
	u16 GREEN_VALUE;
	u16 BLUE_VALUE; 
	 
	int temp1=0;
	int temp2=0;
	
	char USART_RX[200];
	char i_RED[4];
	char i_GREEN[4];
	char i_BLUE[4];
	
	for(i=0;i<200;i++)
	{
		USART_RX[i]=USART_DATA[i];
	}
	len=strlen(USART_RX);
	
	for(i=0;i<len;i++)
	{
		
		if(USART_RX[i]==')')temp1++;  //标记‘）’分组 
		
		while((temp1==3)&&(i<len))
		{
			i++;
			if(USART_RX[i]!=')')
			{
				if(USART_RX[i]=='.')  //标记‘.’分组 
				{
					temp2++;
				}
			

				if((temp2==0)&&(i<len)&&(r<3)&&(USART_RX[i]!='.'))
				{
					i_RED[r]=USART_RX[i];
					//printf("i_RED[%d]=%c\n",r,i_RED[r]);
					r++;
				}else if((temp2==1)&&(i<len)&&(g<3)&&(USART_RX[i]!='.'))
				{
					i_GREEN[g]=USART_RX[i];
					//printf("i_GREEN[%d]=%c\n",g,i_GREEN[g]);
					g++;
				}else if((temp2==2)&&(i<len)&&(b<3)&&(USART_RX[i]!='.'))
			 	{
			 		i_BLUE[b]=USART_RX[i];
					//printf("i_BLUE[%d]=%c\n",b,i_BLUE[b]);
					b++;
			 	}
			}
			else
			{
				temp1=4;	
			} 

		}		
	}
	
	
	i_RED[r]='\0';   //字符数组最后必须赋值一个结束符 '\0' 
	i_GREEN[g]='\0';
	i_BLUE[b]='\0';
	
	len_r=strlen(i_RED);   //获取三个数组的字符串长度 
	len_g=strlen(i_GREEN);
	len_b=strlen(i_BLUE);
	
	
	if(len_r==1)    //R值转换 
	{
		RED_VALUE=i_RED[0]-48;
	}
	else if(len_r==2)
	{
		RED_VALUE=((i_RED[0]-48)*10+(i_RED[1]-48));
	}
	else if(len_r==3)
	{
		RED_VALUE=((i_RED[0]-48)*100+(i_RED[1]-48)*10+(i_RED[2]-48));
	}
	
	if(len_g==1)    //G值转换 
	{
		GREEN_VALUE=i_GREEN[0]-48;
	}
	else if(len_g==2)
	{
		GREEN_VALUE=((i_GREEN[0]-48)*10+(i_GREEN[1]-48));
	}
	else if(len_g==3)
	{
		GREEN_VALUE=((i_GREEN[0]-48)*100+(i_GREEN[1]-48)*10+(i_GREEN[2]-48));
	}
	
	if(len_b==1)    //B值转换 
	{
		BLUE_VALUE=i_BLUE[0]-48;
	}
	else if(len_b==2)
	{
		BLUE_VALUE=((i_BLUE[0]-48)*10+(i_BLUE[1]-48));
	}
	else if(len_b==3)
	{
		BLUE_VALUE=((i_BLUE[0]-48)*100+(i_BLUE[1]-48)*10+(i_BLUE[2]-48));
	}
	
	
	//printf("\n\nRED_VALUE = %d\n",RED_VALUE);
	//printf("GREEN_VALUE = %d\n",GREEN_VALUE);
	//printf("BLUE_VALUE = %d\n\n",BLUE_VALUE);
	
	
	switch(v)
	{
		case 1:
			{
				return(RED_VALUE);
			}
		case 2:
			{
				return(GREEN_VALUE);
			}
		case 3:
			{
				return(BLUE_VALUE);
			}
		default:return 0;
		
	}
} 

