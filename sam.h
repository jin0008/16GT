#ifndef BAM_SAM_H
#define BAM_SAM_H

#include "bam.h"




typedef struct
{
  int type;
  union
  {
    tamFile tamr;
    bamFile bam;
    FILE *tamw;
  } x;
  bam_header_t *header;
} samfile_t;

#ifdef __cplusplus
extern "C" {
#endif


samfile_t *samopen(const char *fn, const char *mode, const void *aux);


void samclose(samfile_t *fp);


int samread(samfile_t *fp, bam1_t *b);


int samwrite(samfile_t *fp, const bam1_t *b);


int sampileup(samfile_t *fp, int mask, bam_pileup_f func, void *data);

char *samfaipath(const char *fn_ref);

#ifdef __cplusplus
}
#endif

#endif
