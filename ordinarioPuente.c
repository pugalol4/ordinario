#include <18F4620.h>
#include <stdio.h>
#include <stdlib.h>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=4000000)
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8,stream=PORT1)

int a=0;
int contadorGlobal1=1, cont=0;
int contadorGlobal2=1;
int contadorGlobal3=1;
char caracter[22];
char cadena2[22],cadena3[22],cadena4[22],cadena5[22];
int bandera2=0;
int bandera1=0;
int calculo=0;
int i=0;
int j=1;
int inicio=0;
int16 contadorms=0;
int contadorval=0;

#INT_TIMER0
void TIMER0(){
   contadorGlobal1*=2;
   if(cont%3==0)
   contadorGlobal2*=2;
   if(cont%5==0)
   contadorGlobal3*=2;
   
   cont++;
   if(cont==15)
      cont=1;
   set_timer0(3036);
}





void main(void) {
  
  setup_oscillator(OSC_4MHZ);
   setup_timer_0(RTCC_INTERNAL | RTCC_DIV_8  );
   enable_interrupts(INT_TIMER0 );
   enable_interrupts(GLOBAL);

  set_timer0(15536);

   while (1) { 
   if(kbhit()){
         
        caracter[i]=getch();
        
        if(caracter[i]>=48 && caracter[i]<=57 || caracter[i] == 59){
            printf("%c",caracter[i]);
        bandera1=1;
        i++;
        if(caracter[i-1]==59)
            contadorval++;
        if(caracter[i]==60){
            bandera2=1;
            }
        else
        {
            bandera2=0;
        }
    }else if(contadorval=3)
    {
      if(caracter[i]>=65 && caracter[i]<=90 || caracter[i]>=97 && caracter[i]<=122 || caracter[i]==60 || caracter[i]==62 || caracter[i]==13 || caracter[i]==59){
            printf("%c",caracter[i]);
            bandera1=1;
            i++;
         }
    }
    else 
      bandera1=0;
   }
   
   if(bandera2=1)
   {
      do{
         cadena2[j]=j;
         j++;
      }while(caracter[j]!=59);
      do{
         cadena3[j];
         j++;
      }while(caracter[j]!=59);
      do{
         cadena4[j];
         j++;
      }while(caracter[j]!=59);
      do{
         cadena5[j];
         j++;
      }while(caracter[j]!=59);
   }
   
   
   
   
   output_a(contadorglobal1);
   if(contadorglobal1==256)
      contadorglobal1=1;
   output_b(contadorglobal2);
   if(contadorglobal2==256)
      contadorglobal2=1;
   output_d(contadorglobal3);
   if(contadorglobal3==256)
      contadorglobal3=1;
   
   
  /* contadoranillob=contadoranillob>>1;
                     if(contadoranillob==0)
                        { contadoranillob=0x80;}
                     output_d(contadoranillob);
                     //-----------------------------------//
                     if((contadoranillob&0x20)==0x20)  //& funciona para apuntar a un bit en especifico ignorando a los demas
                     {
                        output_b(contadoranillob);
                     }
                     else
                        {output_b(0);}
                     //--------------------------//
                     delay_ms(100);
     */
   /*a=1;
   
   switch(a)
    {
      case 1 :case 8:
                     output_b(contadoranillob);
                     
                     if(contadoranillob==0x80)
                        { contadoranillob=1;}
                     else
                     contadoranillob=contadoranillob<<1;
                     delay_ms(100);
         break;
      case  2 : case 16:
                    
                     if(contadoranilloc==0)
                        { contadoranilloc=0x80;}
                     else
                     contadoranilloc=contadoranilloc>>1;
                     output_c(contadoranilloc);
                     delay_ms(100);
         break;
      case 4 : case 32:
                     
                     output_d(contadoranillod);
                     if(contadoranillod==0xc0)
                        { contadoranillod=3;}
                     else
                     contadoranillod=contadoranillod<<2;
                     
                     delay_ms(300);
         break;
    }
    
    
   /* if(input_a()==1)
    {
      contadoranillob=contadoranillob<<1;
                     if(contadoranillob==0x80)
                        { contadoranillob=1;}
                     output_d(contadoranillob);
                     delay_ms(100);
    }
  */  
   }
}
