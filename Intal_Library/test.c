#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "intal.h"

int main(int argc, char const *argv[]) {
	char intal1[100] = "1234512345123451234512345";
	char intal2[100] = "543215432154321543215432154321";
	char *result1;
	char *result2;
	char *result_mod;
	char *result_mul;
	char **a = (char**) malloc(10 * sizeof(char*));
	for(int i = 0; i < 10; i++) {
		a[i] = (char*) malloc(1001 * sizeof(char));
	}
	
	strcpy(a[0], "1234512345123451234512345");
	strcpy(a[1], "543215432154321543215432154321");
	strcpy(a[2], "0");
	strcpy(a[3], "1234512345123451234512345");
	strcpy(a[4], "1234512345123451234512344");
	strcpy(a[5], "12");
	strcpy(a[6], "265252859812191058636308480000000");
	strcpy(a[7], "265252859812191058636308480000000");
	strcpy(a[8], "5432154321543215432154321");
	strcpy(a[9], "3");

	int i1;
	result1 = intal_multiply(a[8], a[9]);
	if(!result1) {
		printf("Test intal_multiply FAILED.\n");
	} else {               //679116296462964629646296462963
		if(0 == strcmp(result1, "16296462964629646296462963")) {
			printf("Test intal_multiply PASSED\n");
		} else {
			printf("%s\n",result1 );
			printf("Test intal_multiply FAILED.\n");
		}
		free(result1);
	}
	result1 = intal_add(intal1, intal2);
	// printf("%s\n",result1 );
	if(!result1) {
		printf("Test Add FAILED.\n");
	} else {
		if(0 == strcmp(result1, "543216666666666666666666666666")) {
			printf("Test Add PASSED\n");
		} else {
			printf("Test Add FAILED.\n");
		}
		free(result1);
	}
	char x[100] ="100";
	char y[100] = "98";
	result1 = intal_add(x, y);
	result_mul = intal_multiply(x, y);

	// printf("add : %s\n",result1 );
	if(!result1) {
		printf("Test Add FAILED.\n");
	} else {
		if(0 == strcmp(result1, "198")) {
			printf("Test Add PASSED\n");
		} else {
			printf("Test Add FAILED.\n");
		}
		free(result1);
		if(0 == strcmp(result_mul, "9800")) {
			printf("Test Multiply PASSED\n");
		} else {
			printf("Test Multiply FAILED.\n");
		}
		free(result_mul);
	}
	char x1[100] = "12345678";
	char x2[100] = "98";
	result1 = intal_add(x1, x2);
	result_mul = intal_multiply(x1, x2);

	// printf("add : %s\n",result1 );
	if(!result1) {
		printf("Test Add FAILED.\n");
	} else {
		if(0 == strcmp(result1, "12345776")) {
			printf("Test Add PASSED\n");
		} else {
			printf("Test Add FAILED.\n");
		}
		free(result1);
		if(0 == strcmp(result_mul, "1209876444")) {
			printf("Test Multiply PASSED\n");
		} else {
			printf("Expected Result : %s Your Result : %s\n","1209876444",result_mul);
			printf("Test Multiply FAILED.\n");
		}
	}
	char x3[100] = "123";
	char x4[100] = "999";
	result1 = intal_add(x3, x4);
	result_mul = intal_multiply(x3,x4);
	// printf("add : %s\n",result1 );
	if(!result1) {
		printf("Test Add FAILED.\n");
	} else {
		if(0 == strcmp(result1, "1122")) {
			printf("Test Add PASSED\n");
		} else {
			printf("Test Add FAILED.\n");
		}
		free(result1);
		if(0 == strcmp(result_mul, "122877")) {
			printf("Test Multiply PASSED\n");
		} else {
			printf("Expected Result : %s Your Result : %s\n","122877",result_mul);
			printf("Test Multiply FAILED.\n");
		}
		free(result_mul);

	}

	i1 = intal_compare(intal1, intal2);
	if(-1 == i1) {
		printf("Test Compare PASSED\n");
	} else {
		printf("Test Compare FAILED.\n");
	}
	
	result1 = intal_diff(intal2, intal1);
	if(!result1) {
		printf("Test Diff FAILED.\n");
	} else {
		//                       543214197641976679146791412345
		if(0 == strcmp(result1, "543214197641976419764197641976")) {
			printf("Test Diff PASSED\n");
		} else {
			printf("Test Diff FAILED.\n");
		}
		free(result1);
	}
	char ax[100] = "120";
	char bx[100] = "100";
	result1 = intal_diff(ax, bx);
	if(!result1) {
		printf("Test Diff FAILED.\n");
	} else {
		if(0 == strcmp(result1, "20")) {
			printf("Test Diff PASSED\n");
		} else {
			printf("Expected Result : %s Your Result : %s\n","20",result1);

			printf("Test Diff FAILED.\n");
		}
		free(result1);
	}
	char x5[100] = "100";
	char x6[100] = "98";
	result1 = intal_diff(x5, x6);
	result2 = intal_diff(x6, x5);

	if(!result1) {
		printf("Test Diff FAILED.\n");
	} else {
		if((0 == strcmp(result1, "2"))&&(0 == strcmp(result2, "2"))) {
			printf("Test Diff PASSED\n");
		} else {
			printf("Expected Result : %s Your Result : %s\n","2",result1);
			printf("Test Diff FAILED.\n");
		}
		free(result1);
	}
	char x7[100] = "1234567890";
	char x8[100] = "98765432";
	result1 = intal_diff(x7, x8);
	result2 = intal_diff(x8, x7);

	if(!result1) {
		printf("Test Diff FAILED.\n");
	} else {
		if(0 == strcmp(result1, "1135802458")&&(0 == strcmp(result2, "1135802458"))) {
			printf("Test Diff PASSED\n");
		} else {
			printf("Expected Result : %s Your Result : %s\n","1135802458",result1);
			printf("Test Diff FAILED.\n");
		}
		free(result1);
	}
	char alpha[100] = "123";
	char beta[100] = "60";
	result_mod = intal_mod(alpha, beta);
	printf("123 mod 60 is %s\n",result_mod );
	char x9[100] = "123445";
	char x10[100] = "567";
	// printf("%s\n",intal_add("7406700","864115") );
	result1 = intal_multiply(x9, x10);
	result2 = intal_multiply(x10, x9);
	// printf("%s %s\n",x9,x10);

	result_mod = intal_mod(x9, x10);
	if(!result1) {
		printf("Test intal_multiply FAILED.\n");
	} else {
		if(0 == strcmp(result1, "69993315")&&(0 == strcmp(result2, "69993315"))) {
			printf("Test intal_multiply PASSED\n");
		} else {
			printf("Expected Result : %s Your Result : %s\n","69993315",result1);
			printf("Test Multiply FAILED.\n");
		}
		if(0 == strcmp(result_mod, "406")){
			printf("Test Mod PASSED\n");
		} else {
			printf("Expected Result : %s Your Result : %s\n","406",result_mod);
			printf("Test Mod FAILED.\n");
		}
		free(result1);
	}
	char x11[100] = "100000";
	char x12[100] = "3";
	// printf("%s\n",intal_add("7406700","864115") );
	result1 = intal_diff(x11, x12);
	result2 = intal_mod(x11, x12);
	if(!result1) {
		printf("Test Diff FAILED.\n");
	} else {
		if(0 == strcmp(result1, "99997")) {
			printf("Test Diff PASSED\n");
		} else {
			printf("Expected Result : %s Your Result : %s\n","99997",result1);
			printf("Test Diff FAILED.\n");
		}
		if(0 == strcmp(result2, "1")){
			printf("Test Mod PASSED\n");
		} else {
			printf("Expected Result : %s Your Result : %s\n","1",result1);
			printf("Test Mod FAILED.\n");
		}
		free(result1);
		free(result2);
		free(result_mod);

	}
	// printf("%s %s\n",a[8],a[9]);
	result1 = intal_multiply(a[8], a[9]);
	if(!result1) {
		printf("Test intal_multiply FAILED.\n");
	} else {               //679116296462964629646296462963
		if(0 == strcmp(result1, "16296462964629646296462963")) {
			printf("Test intal_multiply PASSED\n");
		} else {
			printf("%s\n",result1 );
			printf("Test intal_multiply FAILED.\n");
		}
		free(result1);
	}
	//Fibonacci test
	// int fn ;
	// int fn_1 = 0;
	// int fn_2 = 1;
	// for(int i=0;i<=50;++i)
	// {
	// 	printf("n:%d %s\n",i,intal_fibonacci(i));
	// }
	// Factorial Test:
	result1 = intal_factorial(25);
	if(0 == strcmp(result1, "15511210043330985984000000")){
					printf("Test Factorial PASSED\n");
		} else {
			printf("Expected Result : %s Your Result : %s\n","15511210043330985984000000",result1);
			printf("Test Factorial FAILED.\n");
		}
		free(result1);

	int n = 10;
	char **b = (char**) malloc(n * sizeof(char*));
	for(int i = 0; i < n; i++) {
		b[i] = (char*) malloc(1001 * sizeof(char));
	}
	
	strcpy(b[0], "999999999999999999999998636308480000000");
	strcpy(b[1], "4454321");
	strcpy(b[2], "1");
	strcpy(b[3], "664124512345");
	strcpy(b[4], "1231132451234412323144124125415215141341");
	strcpy(b[5], "126644");
	strcpy(b[6], "264424566444567898636308480000000");
	strcpy(b[7], "9999999999999999999999986363084800000001241243252523642572457727274752752725472547272");
	strcpy(b[8], "1");
	strcpy(b[9], "3");

	intal_sort(b, n);
	printf("\nTest intal_sort PASSED only if the following sequence of %d intals are sorted in nondecreasing order.\n", n);
	for (int i = 0; i < n; i++) {
		printf("%s\n", b[i]);
	}
	printf("\n");
	int index1 = intal_binsearch(b, n, "1");
	if(0 == index1) {
		printf("Test intal_binsearch and probably intal_sort PASSED\n");
	} else {
		printf("Test intal_binsearch and probably intal_sort FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, 0);
	}
	index1 = intal_binsearch(a, n, "1644");
	if(-1 == index1) {
		printf("Test intal_binsearch and probably intal_sort PASSED\n");
	} else {
		printf("Test intal_binsearch and probably intal_sort FAILED.\nYour answer: %d\nExpected answer: %d\n", index1, 1);
	}
	char x13[1001] = "12345123451234512345123451231344523423";
	char x14[1001] = "1234";
	result_mod = intal_mod(x13,x14);
	if(!result_mod) {
		printf("Test intal_mod FAILED.\n");
	} else {
		if(0 == strcmp(result_mod, "665")) {
			printf("Test intal_mod PASSED\n");
		} else {
			printf("Test intal_mod FAILED.\nYour answer: %s\nExpected answer: %s\n", result_mod, "665");
		}
		free(result_mod);
	}
	result1 = intal_bincoeff(1001, 900);
	if(!result1) {
		printf("Test intal_bincoeff FAILED.\n");
	} else {
		if(0 == strcmp(result1, "632815469685459756108269402506577193619249144500467179287753495423226746254907453969008864615341560338749903294508709346489007975944773454890")) {
			printf("Test intal_bincoeff PASSED\n");
		} else {
			printf("Test intal_bincoeff FAILED.\nYour answer: %s\nExpected answer: %s\n", result1, "632815469685459756108269402506577193619249144500467179287753495423226746254907453969008864615341560338749903294508709346489007975944773454890");
		}
		free(result1);
	}
	char *result_gcd;
	result_gcd = intal_gcd(b[9],"13");
	if(0==strcmp(result_gcd,"1"))
	{
			printf("Test gcd PASSED\n");
		}
		 else {
			printf("Expected Result : %s Your Result : %s\n","1",result_gcd);
			printf("Test gcd FAILED.\n");
		}
	free(result_gcd);
	result1 = intal_multiply("1","1");
	printf("1*1 result : %s\n",result1 );
	for(int i = 0; i < n; i++) {
		free(a[i]);
	}
	free(a);
	for(int i = 0; i < n; i++) {
		free(b[i]);
	}
	free(b);
}