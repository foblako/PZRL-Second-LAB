// объявления функций как для для каждой системы, так и общих
#pragma once


int get_first_index(char* num);
int get_sign(char* num);
int check_system_of_input(char* input);
int do_operation(int n1, int n2, char o);
int unary_operation(char* input);
int binary_operation(char* input);
int system_correct(char* number, int system);
int to_int(char* number, int system);
void show_result(int num, int system);
int choose_mode_of_calculator(char* input);


int if_bin(char* num);
int if_oct(char* num);
int if_hex(char* num);

int convert_from_bin_to_int(char* num);
int convert_from_oct_to_int(char* num);
int convert_from_hex_to_int(char* num);


char* convert_from_int_to_bin(int num);
char* convert_from_int_to_oct(int num);
char* convert_from_int_to_hex(int num);