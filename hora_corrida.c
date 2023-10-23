#include<stdio.h>
#include<math.h>


int main() {
	int voltas, placas;
	
	scanf("%d%d", &voltas, &placas);
	
	float placasTotal = voltas * placas;
	
	float placasPassada;
	
	
	float decimal = round(placasTotal * 0.1);
		
	if(decimal != placasTotal * 0.1)
		printf("%0.f ", ceil(placasTotal * 0.1));
	else
		printf("%.0f ", decimal);


	decimal = round(placasTotal * 0.2);
		
	if(decimal != placasTotal * 0.2)
		printf("%0.f ", ceil(placasTotal * 0.2));
	else
		printf("%.0f ", decimal);



	decimal = round(placasTotal * 0.3);
		
	if(decimal != placasTotal * 0.3)
		printf("%0.f ", ceil(placasTotal * 0.3));
	else
		printf("%.0f ", decimal);


	decimal = round(placasTotal * 0.4);
		
	if(decimal != placasTotal * 0.4)
		printf("%0.f ", ceil(placasTotal * 0.4));
	else
		printf("%.0f ", decimal);



	decimal = round(placasTotal * 0.5);
		
	if(decimal != placasTotal * 0.5)
		printf("%0.f ", ceil(placasTotal * 0.5));
	else
		printf("%.0f ", decimal);



	decimal = round(placasTotal * 0.6);
		
	if(decimal != placasTotal * 0.6)
		printf("%0.f ", ceil(placasTotal * 0.6));
	else
		printf("%.0f ", decimal);



	decimal = round(placasTotal * 0.7);
		
	if(decimal != placasTotal * 0.7)
		printf("%0.f ", ceil(placasTotal * 0.7));
	else
		printf("%.0f ", decimal);



	decimal = round(placasTotal * 0.8);
		
	if(decimal != placasTotal * 0.8)
		printf("%0.f ", ceil(placasTotal * 0.8));
	else
		printf("%.0f ", decimal);


	decimal = round(placasTotal * 0.9);
		
	if(decimal != placasTotal * 0.9)
		printf("%0.f\n", ceil(placasTotal * 0.9));
	else
		printf("%.0f\n", decimal);


	return 0;
}
