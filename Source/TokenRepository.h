#include <iostream>
using namespace std;

#pragma once
class TokenRepository
{
public:


	//reserved tokens
	int T_while		  = 100;
	int T_for		  = 101;
	int T_int		  = 102;
	int T_double      = 103;
	int T_float		  = 104;
	int T_bool		  = 105;
	int T_void		  = 106;
	int T_class		  = 107;
	int T_return	  = 108;
	int T_main	      = 109;
	int T_then        = 110;
	int T_char        = 111;


	int T_identifier	 = 1;	
	int T_intConstant    = 2;
	int T_less		     = 3;
	int T_right_param    = 4;
	int T_left_param	 = 5;
	int T_open_brace	 = 6;
	int T_close_brace	 = 7;
	int T_assign	     = 12;
	int T_plus			 = 13;
	int T_semicolon		 = 14;
	int T_plus_assign	 = 15;
	int T_plus_plus		 = 16;
	int T_open_paran	 = 17;
	int T_close_paran	 = 18;
	int T_equal			 = 19;
	int T_equal_equal	 = 20;
	int T_smaller		 = 21;
	int T_larger	     = 22;
	int T_multiplication = 23;
	int T_division		 = 24;
	int T_minus			 = 25;
	int T_minus_minus    = 26;
	int T_open_bracket   = 27;
	int T_close_bracket  = 28;
	int T_doubleConstant = 29;
	int T_powerConstant	 = 30;


};

