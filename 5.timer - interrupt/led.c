//
////PxDIR 默认 0x00 输入模式
////PxSEL 默认 0x00 通用io
////PxINP 默认 0x00 上拉



#include <ioCC2530.h>

#define uint unsigned int 
#define uchar unsigned char

#define LED1 P0_1      

uint count = 0;
//函数声明
void Delayms(uint);     //延时函数
void InitLed(void);	//LED_IO初始化
void InitT1 (void);


/**************************************************
 函 数 名  : Delayms
 功能描述  : 毫秒延时
 输入参数  : xms：延时时间，如 i=xms 即延时i毫秒
 输出参数  : none
 返 回 值  : none
***************************************************/
void Delayms(uint xms) 
{
    uint i,j;
    for(i=xms;i>0;i--)
      for(j=587;j>0;j--);
}


/**************************************************
 函 数 名  : InitLed
 功能描述  : LED_IO初始化
 输入参数  : none
 输出参数  : none
 返 回 值  : none
***************************************************/
void InitLed(void)
{
    P0DIR |= 0xff;       //P1端口定义为输出
    LED1 = 1;            //LED1灯熄灭
}

void InitT3(void)
{
   T3CTL |= 0xE0;
   T3CTL |= 0X08;
   T3CTL &= ~0X03;
   T3IE = 1;
   EA = 1;
   T3CTL |= 0X10;
}

/**************************************************
 函 数 名  : InitKey
 功能描述  : KEY_IO初始化(中断方式配置)
 输入参数  : none
 输出参数  : none
 返 回 值  : none
***************************************************/
void InitKey(void)
{

    P2IEN |= 0x01;  //设置P2_0为中断方式
    IEN2 |= 0x02;   //允许P0口中断
    PICTL |= 0x08;  //下降沿触发 
    P0IFG = 0x00;   //清中断标志位
    EA = 1;         //开总中断
}


/**************************************************
 函 数 名  : P0_ISR
 功能描述  : 中断处理函数
 输入参数  : none
 输出参数  : none
 返 回 值  : none
***************************************************/
#pragma vector = T3_VECTOR         //格式：#pragma vector = 中断向量
__interrupt void T3_ISR(void)     //接着是中断处理程序(函数名可以任意取)
{ 
    if((++count)>244 )
    {
      LED1 = ~LED1;
      count = 0;
    }
}


/**************************************************
 函 数 名  : main
 功能描述  : KEY测试(通用IO中断的使用)
 输入参数  : NONE  
 输出参数  : NONE
 返 回 值  : NONE
***************************************************/
void main(void) 
{
    InitLed();		//调用初始化函数
    InitT3();
    while(1)
    {
     ;
    }
    
}



/*********************************************END OF FILE**********************/



/*********************************************END OF FILE**********************/
