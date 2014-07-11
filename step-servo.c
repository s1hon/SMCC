#include <stdlib.h>
#include <stdio.h>

#include "gpio_lib.h"
#define PD0    SUNXI_GPD(0)
#define PD1    SUNXI_GPD(1)
#define PD2    SUNXI_GPD(2)
#define PD3    SUNXI_GPD(3)
#define PD4    SUNXI_GPD(4)
#define PD5    SUNXI_GPD(5)
#define PD6    SUNXI_GPD(6)
#define PD7    SUNXI_GPD(7)
#define PD8    SUNXI_GPD(8)
#define PD9    SUNXI_GPD(9)
#define PD10    SUNXI_GPD(10)
#define PD11    SUNXI_GPD(11)
#define PD12    SUNXI_GPD(12)
#define PD13    SUNXI_GPD(13)
#define PD14    SUNXI_GPD(14)
#define PD15    SUNXI_GPD(15)
#define PD16    SUNXI_GPD(16)
#define PD17    SUNXI_GPD(17)
#define PD18    SUNXI_GPD(18)
#define PD19    SUNXI_GPD(19)
#define PD20    SUNXI_GPD(20)
#define PD21    SUNXI_GPD(21)
#define PD22    SUNXI_GPD(22)
#define PD23    SUNXI_GPD(23)
#define PD24    SUNXI_GPD(24)
#define PD25    SUNXI_GPD(25)
#define PD26    SUNXI_GPD(26)
#define PD27    SUNXI_GPD(27)

#define MISO    SUNXI_GPE(3)
#define MOSI    SUNXI_GPE(2)
#define SCK     SUNXI_GPE(1)
#define CS      SUNXI_GPE(0)

int main()
{
    if(SETUP_OK!=sunxi_gpio_init()){
        printf("Failed to initialize GPIO\n");
        return -1;
    }

    if(SETUP_OK!=sunxi_gpio_set_cfgpin(PD1,OUTPUT)){
        printf("Failed to config GPIO1 pin\n");
        return -1;
    }
    if(SETUP_OK!=sunxi_gpio_set_cfgpin(PD5,OUTPUT)){
        printf("Failed to config GPIO5 pin\n");
        return -1;
    }
    if(SETUP_OK!=sunxi_gpio_set_cfgpin(PD7,OUTPUT)){
        printf("Failed to config GPIO7 pin\n");
        return -1;
    }
    if(SETUP_OK!=sunxi_gpio_set_cfgpin(PD10,OUTPUT)){
        printf("Failed to config GPIO10 pin\n");
        return -1;
    }

    //clean port
    printf("Clean port now....\n");
    sunxi_gpio_output(PD1,LOW);
    sunxi_gpio_output(PD5,LOW);
    sunxi_gpio_output(PD7,LOW);
    sunxi_gpio_output(PD10,LOW);
    int sp=5000;
    int i;

    printf("Sleep 2 sec to start...\n");
    sleep(2);

    for(i=0;i<=1000;i++){
    	 if(i%10==0) printf("Loop %d\n",i);   
	 if(sunxi_gpio_output(PD1,HIGH)){
            printf("Failed to set GPIO pin value\n");
            return -1;
        }
        usleep(sp);
        if(sunxi_gpio_output(PD1,LOW)){
            printf("Failed to set GPIO pin value\n");
            return -1;
        }
        

	if(sunxi_gpio_output(PD5,HIGH)){
            printf("Failed to set GPIO pin value\n");
            return -1;
        }
        usleep(sp);
        if(sunxi_gpio_output(PD5,LOW)){
            printf("Failed to set GPIO pin value\n");
            return -1;
        }

        if(sunxi_gpio_output(PD7,HIGH)){
            printf("Failed to set GPIO pin value\n");
            return -1;
        }

        usleep(sp);
        if(sunxi_gpio_output(PD7,LOW)){
            printf("Failed to set GPIO pin value\n");
            return -1;
        }

        if(sunxi_gpio_output(PD10,HIGH)){
            printf("Failed to set GPIO pin value\n");
            return -1;
        }

        usleep(sp);
        if(sunxi_gpio_output(PD10,LOW)){
            printf("Failed to set GPIO pin value\n");
            return -1;
        }

    }

    sunxi_gpio_cleanup();

    return 0;
    
}
