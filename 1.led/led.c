
//PxDIR 默认 0x00 输入模式
//PxSEL 默认 0x00 通用io
//PxINP 默认 0x00 上拉

#include <ioCC2530.h>
#define uint unsigned int 
#define uchar unsigned char 

#define LED1 P0_1    //定义P0_1口为LED1控制端
#define LED2 P0_4    //定义P0_4口为LED2控制端


/**************************************************
 函 数 名  : IO_Init
 功能描述  : LED_IO初始化函数
 输入参数  : NONE  
 输出参数  : NONE
 返 回 值  : NONE
***************************************************/
void IO_Init(void)
{
    P0DIR |= 0xff;       //P1端口定义为输出   1为输出
    LED1 = 0;            //点亮LED1
    LED2 = 0;            //点亮LED2
}


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
 函 数 名  : main
 功能描述  : LED测试(通用IO的输出使用)
 输入参数  : NONE  
 输出参数  : NONE 
 返 回 值  : NONE
***************************************************/
void main ( void )
{
  IO_Init ();       //调用初始化程序
  Delayms ( 2000 );   //延时2s
    
  while ( 1 )
  {
    LED1 = ~ LED1;
    LED2 = ~ LED2;

    Delayms ( 500 );   //延时0.5s
        
  }
  
}



/*********************************************END OF FILE**********************/
