AC_INIT([fibonacci], [1.0], [adri@adridoesthings.com])
AC_CONFIG_SRCDIR([main.c])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_PROG_CC
AC_HEADER_STDC
AC_TYPE_SIZE_T
AC_CHECK_LIB([gmp],[mpz_init mpz_set_ui mpz_sgn mpz_sub_ui mpz_get_str mpz_set_str]) 
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
