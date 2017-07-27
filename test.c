#include "expr_parser.h"

char value_str[128] = {'1','5','\0'};

int get_value(char *valname, char **value) {
	*value = value_str;
	return 0;
}

int main()
{
	expr_parser * parser = expr_parser_new();
	expr_parser_parse(parser, (char *)"[[a]]==$b.a[5]||\"hello_c\"<$d&&(e>=15.6)||!\'world_c\'");
	//expr_parser_parse(parser, (char*)"a > b && ! e");
	expr_parser_print_tree(parser);
	printf("\nend\n");
	if(0 != parser) {
		int result;
		if( expr_parser_execute(parser, &result, get_value) == 0) {
			
		
			printf("result = %d\n", result);
		}	
		expr_parser_delete(parser);
	}
	return 0;
}
