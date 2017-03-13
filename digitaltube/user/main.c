#include "public.h"
#include "systick.h"
#include "digital.h"


int main(){


	digital_init();
	while(1){
		   static_digital_display(); 
	}
}
