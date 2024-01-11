#include "sqludf.h"

// volgende UDF neemt twee integers als input en telt ze op

SQL_API_RC SQL_API_FN telop ( SQLUDF_INTEGER* in1,
                              SQLUDF_INTEGER* in2,
                              SQLUDF_INTEGER* out,
                              SQLUDF_NULLIND* in1nul,
                              SQLUDF_NULLIND* in2nul,
                              SQLUDF_NULLIND* outnul,
                              SQLUDF_TRAIL_ARGS )
{
  *out = *in1 + *in2;
}
