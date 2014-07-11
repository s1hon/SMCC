#SMCC
====
Step motor control with Cubieboard  
  
  
##使用方式

` git clone https://github.com/opjlmi/SMCC.git `  
將檔案下載至cubieboard  
執行 ` ./step-servo `即可。  
  
  
##使用接腳  
  
PD1、PD5、PD7、PD10接到步進馬達驅動模組的控制接腳A、B、C、D，  
gcc Vcc 可以直接接到CubieBoard板子上，  
不過建議Vcc另外拉出來接。  
  
  
##如何修改
  
如果需要改變速度，只需要修改 ./step-servo.c中的sp變數，即可控制速度。  
修改完之後需要重新Compiler  
  
` gcc ./step-servo.c -c `  
` gcc step-servo.o gpio_lib.o -o step-servo `
