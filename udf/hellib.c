#include <string.h> 
#include "sqludf.h"

// volgende UDF neemt geen input en geeft "Hello, world!" terug

SQL_API_RC SQL_API_FN hello ( SQLUDF_VARCHAR* out,
                              SQLUDF_NULLIND* outnul,
                              SQLUDF_TRAIL_ARGS )
{
  strcpy(out,"Hello, world!");
}
