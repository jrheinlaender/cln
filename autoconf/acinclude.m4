# Is the gmp header file new enough? (should be implemented with an argument)
AC_DEFUN(CL_GMP_H_VERSION,
[AC_CACHE_CHECK([for recent enough gmp.h], cl_cv_new_gmp_h, [
  AC_TRY_CPP([#include <gmp.h>
#if !defined(__GNU_MP_VERSION) || (__GNU_MP_VERSION < 3)
 #error "ancient gmp.h"
#endif],
cl_cv_new_gmp_h="yes", cl_cv_new_gmp_h="no")
])])dnl

# Does libgmp provide some functionality introduced in version 3.0?
AC_DEFUN(CL_GMP_CHECK,
[AC_CACHE_CHECK([for working libgmp], cl_cv_new_libgmp, [
    SAVELIBS=$LIBS
    LIBS="$LIBS -lgmp"
    AC_TRY_LINK([#include <gmp.h>],[mpn_divexact_by3(0,0,0)],
cl_cv_new_libgmp="yes", cl_cv_new_libgmp="no"; LIBS=$SAVELIBS)
])])

# What is sizeof(mp_limb_t)?  (It has to match sizeof(uintD) later.)
AC_DEFUN(CL_GMP_SET_UINTD,
[AC_CACHE_CHECK([how large gmp demands uintD to be], cl_cv_gmp_set_uintd, [
    AC_TRY_RUN([#include <stdio.h>
#include <gmp.h>
int main() {
    FILE *f=fopen("conftestval", "w");
    if (!f) return(255);
    if (sizeof(mp_limb_t) > sizeof(long))
        fprintf(f, "long long");
    else if (sizeof(mp_limb_t) == sizeof(long))
        fprintf(f, "long");
    else if (sizeof(mp_limb_t) == sizeof(int))
        fprintf(f, "int");
    else return(sizeof(mp_limb_t));
#if defined(__GMP_BITS_PER_MP_LIMB)
    /* Is there a nail in a limb? */
    if (8*sizeof(mp_limb_t)!=__GMP_BITS_PER_MP_LIMB)
        return(254);
#endif
    return(0);
}], cl_cv_gmp_set_uintd=`cat conftestval`
    cl_gmp_demands="GMP_DEMANDS_UINTD_`echo ${cl_cv_gmp_set_uintd} | sed -e 'y/ gilnot/_GILNOT/'`",
    gmp_retval="$ac_status"
    if test x$gmp_retval = "x255"; then AC_MSG_ERROR([error opening output file.]); fi
    if test x$gmp_retval = "x254"; then AC_MSG_ERROR([nails in MP limbs are unsupported.]); fi
    AC_MSG_ERROR([Don't know which C-type has sizeof $gmp_retval.]),
    AC_MSG_ERROR([cross-compiling - cannot determine]))
])
AC_DEFINE_UNQUOTED($cl_gmp_demands)
])