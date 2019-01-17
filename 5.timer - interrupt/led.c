//
////PxDIR Ĭ�� 0x00 ����ģʽ
////PxSEL Ĭ�� 0x00 ͨ��io
////PxINP Ĭ�� 0x00 ����



#include <ioCC2530.h>

#define uint unsigned int 
#define uchar unsigned char

#define LED1 P0_1      

uint count = 0;
//��������
void Delayms(uint);     //��ʱ����
void InitLed(void);	//LED_IO��ʼ��
void InitT1 (void);


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


/**************************************************
 �� �� ��  : InitLed
 ��������  : LED_IO��ʼ��
 �������  : none
 �������  : none
 �� �� ֵ  : none
***************************************************/
void InitLed(void)
{
    P0DIR |= 0xff;       //P1�˿ڶ���Ϊ���
    LED1 = 1;            //LED1��Ϩ��
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
 �� �� ��  : InitKey
 ��������  : KEY_IO��ʼ��(�жϷ�ʽ����)
 �������  : none
 �������  : none
 �� �� ֵ  : none
***************************************************/
void InitKey(void)
{

    P2IEN |= 0x01;  //����P2_0Ϊ�жϷ�ʽ
    IEN2 |= 0x02;   //����P0���ж�
    PICTL |= 0x08;  //�½��ش��� 
    P0IFG = 0x00;   //���жϱ�־λ
    EA = 1;         //�����ж�
}


/**************************************************
 �� �� ��  : P0_ISR
 ��������  : �жϴ�������
 �������  : none
 �������  : none
 �� �� ֵ  : none
***************************************************/
#pragma vector = T3_VECTOR         //��ʽ��#pragma vector = �ж�����
__interrupt void T3_ISR(void)     //�������жϴ�������(��������������ȡ)
{ 
    if((++count)>244 )
    {
      LED1 = ~LED1;
      count = 0;
    }
}


/**************************************************
 �� �� ��  : main
 ��������  : KEY����(ͨ��IO�жϵ�ʹ��)
 �������  : NONE  
 �������  : NONE
 �� �� ֵ  : NONE
***************************************************/
void main(void) 
{
    InitLed();		//���ó�ʼ������
    InitT3();
    while(1)
    {
     ;
    }
    
}



/*********************************************END OF FILE**********************/



/*********************************************END OF FILE**********************/