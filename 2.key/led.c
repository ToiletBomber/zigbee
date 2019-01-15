
//PxDIR Ĭ�� 0x00 ����ģʽ
//PxSEL Ĭ�� 0x00 ͨ��io
//PxINP Ĭ�� 0x00 ����

#include <ioCC2530.h>
#define uint unsigned int 
#define uchar unsigned char 

#define LED1 P0_1    //����P0_1��ΪLED1���ƶ�
#define LED2 P0_4    //����P0_4��ΪLED2���ƶ�
#define KEY1 P1_1       
#define KEY2 P2_0
#define KEY3 P0_5

/**************************************************
 �� �� ��  : IO_Init
 ��������  : LED_IO��ʼ������
 �������  : NONE  
 �������  : NONE
 �� �� ֵ  : NONE
***************************************************/
void IO_Init(void)
{
    P0DIR |= 0xdf;       //P1�˿ڶ���Ϊ���   1Ϊ���
    LED1 = 1;            //Ϩ��
    LED2 = 1;            
}


/**************************************************
 �� �� ��  : Delayms
 ��������  : ������ʱ
 �������  : xms����ʱʱ�䣬�� i=xms ����ʱi����
 �������  : none
 �� �� ֵ  : none
***************************************************/
void Delayms(uint xms)
{
    uint i,j;
    for(i=xms;i>0;i--)
      for(j=587;j>0;j--);
}
//p1_1 s3
//p2_0 s4
//p0_5 s5
uchar keyscan()
{
  if(KEY3 == 0)
  {
    Delayms(2);
    if(KEY3 == 0)
    {
      while(!KEY3);
      return 1;
    }
  }
  return 0;
}

/**************************************************
 �� �� ��  : main
 ��������  : LED����(ͨ��IO�����ʹ��)
 �������  : NONE  
 �������  : NONE 
 �� �� ֵ  : NONE
***************************************************/
void main ( void )
{
  IO_Init ();       //���ó�ʼ������
    
  while ( 1 )
  {
    if(keyscan() == 1)
    {
      LED1 = ~LED1;
      LED2 = ~LED2;
    }   
  }
  
}



/*********************************************END OF FILE**********************/
