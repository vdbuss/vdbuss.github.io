// sjabloon voor een external UDF geschreven in C
// (geval voor twee inputs: meer of minder inputs is analoog)

#include <string.h> // voor strcpy
#include "sqludf.h"

SQL_API_RC SQL_API_FN funnaam ( SQLUDF_type* in1,
                                SQLUDF_type* in2,
                                SQLUDF_type* out,
                                SQLUDF_NULLIND* in1nul,
                                SQLUDF_NULLIND* in2nul,
                                SQLUDF_NULLIND* outnul,
                                SQLUDF_TRAIL_ARGS )
{
  // bereken de output en plaats hem in de locatie
  // verwezen door de out-parameter
  // (gebruik strcpy voor strings!)
  if (er is iets mis)
    strcpy(SQLUDF_STATE,"38XXX"); // vertelt DB2 dat iets mis is
}
