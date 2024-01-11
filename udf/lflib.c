#include <stdio.h>
#include <string.h>
#include "sqludf.h"

typedef
  struct
  {
    FILE* file_ptr;
  }
  my_pad_type;

// deze table UDF neemt als input de naam van een file (volledig pad).
// deze file wordt ondersteld een textfile te zijn van rijen van
// telkens twee integers.
// de outputtabel bestaat dan uit deze rijen.

SQL_API_RC SQL_API_FN leesfile ( SQLUDF_VARCHAR* in,
                                 SQLUDF_INTEGER* out1,
                                 SQLUDF_INTEGER* out2,
                                 SQLUDF_NULLIND* innul,
                                 SQLUDF_NULLIND* out1nul,
                                 SQLUDF_NULLIND* out2nul,
                                 SQLUDF_TRAIL_ARGS_ALL )
{
  FILE *f;
  int i;

  my_pad_type* pad_ptr = (my_pad_type*) SQLUDF_SCRAT->data;

  switch (SQLUDF_CALLT) {
  case SQLUDF_TF_OPEN:
    f = fopen(in,"r");
    if (f) // fopen is gelukt, bewaar file pointer in scratchpad
      pad_ptr->file_ptr = f;
    else strcpy(SQLUDF_STATE,"38XXX");
    break;
  case SQLUDF_TF_FETCH:
    f = pad_ptr->file_ptr;
    i = fscanf(f,"%d %d",out1,out2);
    if (i != 2)
      // niet gelukt 2 integers te lezen
      strcpy(SQLUDF_STATE,"02000");
    break;
  case SQLUDF_TF_CLOSE:
    fclose(pad_ptr->file_ptr);
    break;
  }
}
