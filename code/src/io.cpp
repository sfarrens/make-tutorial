#include "io.hpp"

void listhead (const std::string &file_name) {

  fitsfile *fptr; /* FITS file pointer, defined in fitsio.h */
  char card[FLEN_CARD]; /* Standard string lengths defined in fitsio.h */
  int status = 0; /* CFITSIO status value MUST be initialized to zero! */
  int single = 0, hdupos, nkeys, ii;

  if (!fits_open_file(&fptr, file_name.c_str(), READONLY, &status))
      {
        fits_get_hdu_num(fptr, &hdupos);  /* Get the current HDU position */

        /* List only a single header if a specific extension was given */
        if (hdupos != 1 || strchr(file_name.c_str(), '[')) single = 1;

        for (; !status; hdupos++)  /* Main loop through each extension */
        {
          fits_get_hdrspace(fptr, &nkeys, NULL, &status); /* get # of keywords */

          printf("Header listing for HDU #%d:\n", hdupos);

          for (ii = 1; ii <= nkeys; ii++) { /* Read and print each keywords */

             if (fits_read_record(fptr, ii, card, &status))break;
             printf("%s\n", card);
          }
          printf("END\n\n");  /* terminate listing with END */

          if (single) break;  /* quit if only listing a single header */

          fits_movrel_hdu(fptr, 1, NULL, &status);  /* try to move to next HDU */
        }

        if (status == END_OF_FILE)  status = 0; /* Reset after normal error */

        fits_close_file(fptr, &status);
      }
}
