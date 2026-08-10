#include <stdio.h>
#include "api_bridge_lab.h"

void main () {

	printf("hello world\n");
	int test = legacy_parse_year("Shayne:2020");
	printf("\":\" year is %d\n",test);

	char s[20] ;
	legacy_make_slug("hello world",s);
	printf("%s\n",s);

	modern_make_slug("hello world",s,20);
	printf("%s\n",s);

}
