// sjabloon voor een external table function geschreven in C
// (geval voor twee inputs, en outputs van twee componenten;
// meer of minder inputs of componenten is analoog)

#include <string.h> // voor strcpy
#include "sqludf.h"

typedef
  struct
  {
    // opsomming van de objecten die we in de scratchpad willen bewaren
  }
  my_pad_type;

// opgelet: indien my_pad_type meer dan 100 bytes vergt,
// waarde van SQLUDF_SCRATCHPAD_LEN verhogen in sqludf.h
// en scratchpad-lengte declareren in CREATE FUNCTION

SQL_API_RC SQL_API_FN funnaam ( SQLUDF_type* in1,
                                SQLUDF_type* in2,
                                SQLUDF_type* out1,
                                SQLUDF_type* out2,
                                SQLUDF_NULLIND* in1nul,
                                SQLUDF_NULLIND* in2nul,
                                SQLUDF_NULLIND* out1nul,
                                SQLUDF_NULLIND* out2nul,
                                SQLUDF_TRAIL_ARGS_ALL )
{
  // de scratchpad is een data-array van bytes.
  // we gebruiken hem echter als een record van type my_pad_type.
  // dit is eigenlijk niet safe, maar het werkt normaal wel.
  my_pad_type* pad_ptr = (my_pad_type*) SQLUDF_SCRAT->data;

  switch (SQLUDF_CALLT) {
  case SQLUDF_TF_OPEN:
    // analyseer de in-parameters
    // initialiseer de scratchpad
    if (er is iets mis)
      strcpy(SQLUDF_STATE,"38XXX"); // vertelt DB2 dat iets mis is
    break;
  case SQLUDF_TF_FETCH:
    // bereken componenten van het volgende output-tupel, en plaats
    // ze in de locaties verwezen door de out-parameters
    // (gebruik strcpy voor strings!)
    if (geen tupels meer)
      strcpy(SQLUDF_STATE,"02000"); // vertelt DB2 dat het gedaan is
    break;
  case SQLUDF_TF_CLOSE:
    // kuis op
    break;
  }
}
