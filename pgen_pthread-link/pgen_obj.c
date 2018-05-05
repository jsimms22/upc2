/* --- UPCR system headers --- */ 
#include "upcr.h" 
#include "whirl2c.h"
#include "upcr_proxy.h"
/*******************************************************
 * C file translated from WHIRL Sat May  5 15:09:29 2018
 *******************************************************/

/* UPC Runtime specification expected: 3.6 */
#define UPCR_WANT_MAJOR 3
#define UPCR_WANT_MINOR 6
/* UPC translator version: release 2.26.0, built on Aug 31 2017 at 17:02:50, host aphid linux-x86_64/64, gcc v4.2.4 (Ubuntu 4.2.4-1ubuntu4) */
/* Included code from the initialization script */
#include</pylon5/cc3uv3p/bbrock/public/opt/include/upcr_config.h>
#include</pylon5/cc3uv3p/bbrock/public/opt/include/gasnet_portable_platform.h>
#include "upcr_geninclude/stdio.h"
#include "upcr_geninclude/string.h"
#include "upcr_geninclude/stdlib.h"
#include</usr/include/sys/time.h>
#include "upcr_geninclude/math.h"
#include "upcr_geninclude/time.h"
#include</pylon5/cc3uv3p/bbrock/public/opt/include/upcr_preinclude/upc_types.h>
#include "upcr_geninclude/stddef.h"
#include</pylon5/cc3uv3p/bbrock/public/opt/include/upcr_preinclude/upc_bits.h>
#include "upcr_geninclude/stdlib.h"
#include "upcr_geninclude/inttypes.h"
#include</pylon5/cc3uv3p/jsimms22/upc2/packingDNAseq.h>
#include "upcr_geninclude/stdio.h"
#include "upcr_geninclude/stdlib.h"
#include "upcr_geninclude/math.h"
#include "upcr_geninclude/string.h"
#include "upcr_geninclude/stdio.h"
#include "upcr_geninclude/stdlib.h"
#include "upcr_geninclude/sys/stat.h"
#include "upcr_geninclude/math.h"
#include "upcr_geninclude/string.h"
#line 1 "pgen.w2c.h"
/* Include builtin types and operators */

#ifndef UPCR_TRANS_EXTRA_INCL
#define UPCR_TRANS_EXTRA_INCL
extern int upcrt_gcd (int _a, int _b);
extern int _upcrt_forall_start(int _start_thread, int _step, int _lo, int _scale);
#define upcrt_forall_start(start_thread, step, lo, scale)  \
       _upcrt_forall_start(start_thread, step, lo, scale)
int32_t UPCR_TLD_DEFINE_TENTATIVE(upcrt_forall_control, 4, 4);
#define upcr_forall_control upcrt_forall_control
#ifndef UPCR_EXIT_FUNCTION
#define UPCR_EXIT_FUNCTION() ((void)0)
#endif
#if UPCR_RUNTIME_SPEC_MAJOR > 3 || (UPCR_RUNTIME_SPEC_MAJOR == 3 && UPCR_RUNTIME_SPEC_MINOR >= 8)
  #define UPCRT_STARTUP_SHALLOC(sptr, blockbytes, numblocks, mult_by_threads, elemsz, typestr) \
      { &(sptr), (blockbytes), (numblocks), (mult_by_threads), (elemsz), #sptr, (typestr) }
#else
  #define UPCRT_STARTUP_SHALLOC(sptr, blockbytes, numblocks, mult_by_threads, elemsz, typestr) \
      { &(sptr), (blockbytes), (numblocks), (mult_by_threads) }
#endif
#define UPCRT_STARTUP_PSHALLOC UPCRT_STARTUP_SHALLOC

/**** Autonb optimization ********/

extern void _upcrt_memput_nb(upcr_shared_ptr_t _dst, const void *_src, size_t _n);
#define upcrt_memput_nb(dst, src, n) \
       (upcri_srcpos(), _upcrt_memput_nb(dst, src, n))

#endif


/* Types */
struct shared_hash_table_t {
    long size;
    upcr_pshared_ptr_t table;
  };
  struct shared_bucket_t {
    upcr_pshared_ptr_t head;
  };
  struct kmer_t {
      char kmer[5LL];
      char l_ext;
      char r_ext;
      struct kmer_t * next;
    };
    struct memory_heap_t {
    struct kmer_t * heap;
    long posInHeap;
  };
  struct bucket_t {
    struct kmer_t * head;
  };
  struct hash_table_t {
  long size;
  struct bucket_t * table;
};
struct shared_memory_heap_t {
    upcr_pshared_ptr_t heap;
    long posInHeap;
  };
  struct start_kmer_t {
    struct kmer_t * kmerPtr;
    struct start_kmer_t * next;
  };
  /* File-level vars and routines */
static _IEEE64 gettime(void);

extern long getNumKmersInUFX(const char *);

extern upcr_pshared_ptr_t create_shared_memory_heap(int, int, long);

extern upcr_pshared_ptr_t create_shared_hash_table(int, int, long);

extern struct hash_table_t * create_hash_table(long, struct memory_heap_t *);

extern long hashseq(long, char *, int);

extern long hashkmer(long, char *);

extern upcr_pshared_ptr_t lookup_kmer_shared_local(struct shared_hash_table_t *, const unsigned char *);

extern upcr_pshared_ptr_t lookup_kmer_shared_remote(upcr_pshared_ptr_t, const unsigned char *);

extern struct kmer_t * lookup_kmer(struct hash_table_t *, const unsigned char *);

extern int add_kmer_shared(struct shared_hash_table_t *, struct shared_memory_heap_t *, const unsigned char *, char, char);

extern int add_kmer(struct hash_table_t *, struct memory_heap_t *, const unsigned char *, char, char);

extern void addKmerToStartList(struct memory_heap_t *, struct start_kmer_t **);

extern int dealloc_heap(struct memory_heap_t *);

extern int dealloc_hashtable(struct hash_table_t *);

extern int user_main(int, char **);


#define UPCR_SHARED_SIZE_ 8
#define UPCR_PSHARED_SIZE_ 8

void UPCRI_ALLOC_pgen_6953898206118(void) { 
UPCR_BEGIN_FUNCTION();

UPCR_SET_SRCPOS("_pgen_6953898206118_ALLOC",0);
}

void UPCRI_INIT_pgen_6953898206118(void) { 
UPCR_BEGIN_FUNCTION();
UPCR_SET_SRCPOS("_pgen_6953898206118_INIT",0);
}

#line 28 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
static _IEEE64 gettime()
#line 28 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
{
#line 28 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
  UPCR_BEGIN_FUNCTION();
  register _INT32 _bupc_comma;
  struct timeval tv;
  int _bupc__spilleq0;
  
#line 30 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
  _bupc_comma = gettimeofday(&tv, (struct timezone *) 0ULL);
#line 30 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
  _bupc__spilleq0 = _bupc_comma;
#line 30 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
  if(_bupc__spilleq0 != 0)
#line 30 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
  {
#line 31 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
    perror("gettimeofday");
#line 32 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
    abort();
  }
#line 34 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
  UPCR_EXIT_FUNCTION();
#line 34 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
  return(_IEEE64)((tv).tv_sec) + ((_IEEE64)((tv).tv_usec) / 1e+06);
} /* gettime */


#line 105 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
extern long getNumKmersInUFX(
  const char * filename)
#line 105 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
{
#line 105 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
  UPCR_BEGIN_FUNCTION();
  register _UINT64 _bupc_comma;
  register _INT32 _bupc_comma0;
  register _INT32 _bupc_comma1;
  struct _IO_FILE * f;
  char firstLine[24LL];
  unsigned long _bupc__spilleq1;
  int fd;
  struct stat buf;
  int _bupc__spilleq2;
  long totalSize;
  long numKmers;
  struct _IO_FILE * _bupc_call0;
  
#line 106 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
  _bupc_call0 = fopen(filename, "r");
#line 106 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
  f = _bupc_call0;
#line 107 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
  if((_UINT64)(f) == 0ULL)
#line 107 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
  {
#line 108 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
    fprintf(stderr, "Could not open %s for reading!\n", filename);
#line 109 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
    UPCR_EXIT_FUNCTION();
#line 109 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
    return -1LL;
  }
#line 112 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
  (firstLine)[23] = 0;
#line 113 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
  _bupc_comma = fread(firstLine, (unsigned long) 1ULL, (unsigned long) 23ULL, f);
#line 113 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
  _bupc__spilleq1 = _bupc_comma;
#line 113 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
  if(_bupc__spilleq1 != 23ULL)
#line 113 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
  {
#line 114 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
    fprintf(stderr, "Could not read %d bytes!\n", (int) 23);
#line 115 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
    UPCR_EXIT_FUNCTION();
#line 115 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
    return -2LL;
  }
#line 118 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
  if((_INT32)((firstLine)[23]) != 0)
#line 118 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
  {
#line 119 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
    fprintf(stderr, "UFX text file is an unexpected line length for kmer length %d\n", (int) 19);
#line 120 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
    UPCR_EXIT_FUNCTION();
#line 120 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
    return -3LL;
  }
#line 122 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
  if((_INT32)(((_INT32)((firstLine)[19]) != 32)) && (_INT32)(((_INT32)((firstLine)[19]) != 9)))
#line 122 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
  {
#line 123 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
    fprintf(stderr, "Unexpected format for firstLine \'%s\'\n", firstLine);
#line 124 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
    UPCR_EXIT_FUNCTION();
#line 124 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
    return -4LL;
  }
#line 128 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
  _bupc_comma0 = fileno(f);
#line 128 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
  fd = _bupc_comma0;
#line 129 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
  _bupc_comma1 = fstat(fd, &buf);
#line 129 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
  _bupc__spilleq2 = _bupc_comma1;
#line 129 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
  if(_bupc__spilleq2 != 0)
#line 129 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
  {
#line 130 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
    fprintf(stderr, "Could not stat %s\n", filename);
#line 131 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
    UPCR_EXIT_FUNCTION();
#line 131 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
    return -5LL;
  }
#line 133 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
  totalSize = (buf).st_size;
#line 134 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
  if((totalSize % 23LL) != 0LL)
#line 134 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
  {
#line 135 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
    fprintf(stderr, "UFX file is not a multiple of %d bytes for kmer length %d\n", (int) 23, (int) 19);
#line 136 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
    UPCR_EXIT_FUNCTION();
#line 136 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
    return -6LL;
  }
#line 138 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
  fclose(f);
#line 139 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
  numKmers = totalSize / 23LL;
#line 140 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
  printf("Detected %lld kmers in text UFX file: %s\n", numKmers, filename);
#line 141 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
  UPCR_EXIT_FUNCTION();
#line 141 "/pylon5/cc3uv3p/jsimms22/upc2/contig_generation_shared.h"
  return numKmers;
} /* getNumKmersInUFX */


#line 12 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
extern upcr_pshared_ptr_t create_shared_memory_heap(
  int nthread,
  int thread_id,
  long nEntries)
#line 12 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
{
#line 12 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_BEGIN_FUNCTION();
  long n_buckets;
  upcr_pshared_ptr_t result;
  upcr_shared_ptr_t _bupc_call1;
  upcr_shared_ptr_t _bupc_call2;
  upcr_pshared_ptr_t _bupc_Mstopcvt3;
  upcr_pshared_ptr_t _bupc_Mstopcvt4;
  upcr_pshared_ptr_t _bupc_Mptra5;
  upcr_pshared_ptr_t _bupc_Mptra6;
  upcr_pshared_ptr_t _bupc_spillld7;
  _INT32 _bupc_Mptreq8;
  upcr_pshared_ptr_t _bupc_Mptra9;
  
#line 13 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  n_buckets = nEntries;
#line 17 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc_call1 = upc_all_alloc((unsigned long)(_UINT64)(nthread), (unsigned long) 16ULL);
#line 17 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc_Mstopcvt3 = UPCR_SHARED_TO_PSHARED(_bupc_call1);
#line 17 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  result = _bupc_Mstopcvt3;
#line 18 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc_call2 = upc_alloc((unsigned long)((_UINT64)(nEntries) * 16ULL));
#line 18 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc_Mptra5 = UPCR_ADD_PSHARED1(result, 16ULL, thread_id);
#line 18 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc_Mstopcvt4 = UPCR_SHARED_TO_PSHARED(_bupc_call2);
#line 18 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_PUT_PSHARED_VAL(_bupc_Mptra5, 0, _bupc_Mstopcvt4, 8);
#line 20 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc_Mptra6 = UPCR_ADD_PSHARED1(result, 16ULL, thread_id);
#line 20 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_GET_PSHARED(&_bupc_spillld7, _bupc_Mptra6, 0, 8);
#line 20 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc_Mptreq8 = UPCR_ISNULL_PSHARED(_bupc_spillld7);
#line 20 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  if(_bupc_Mptreq8)
#line 20 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  {
#line 21 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
    fprintf(stderr, "ERROR: Could not allocate memory for the heap!\n");
#line 22 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
    upcri_do_exit((int) 1);
  }
#line 24 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc_Mptra9 = UPCR_ADD_PSHARED1(result, 16ULL, thread_id);
#line 24 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_PUT_PSHARED_VAL(_bupc_Mptra9, 8, 0LL, 8);
#line 25 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_EXIT_FUNCTION();
#line 25 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  return result;
} /* create_shared_memory_heap */


#line 28 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
extern upcr_pshared_ptr_t create_shared_hash_table(
  int nthread,
  int thread_id,
  long nEntries)
#line 28 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
{
#line 28 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_BEGIN_FUNCTION();
  long n_buckets;
  upcr_pshared_ptr_t result;
  upcr_shared_ptr_t _bupc_call10;
  upcr_shared_ptr_t _bupc_call11;
  upcr_pshared_ptr_t _bupc_Mstopcvt12;
  upcr_pshared_ptr_t _bupc_Mptra13;
  upcr_pshared_ptr_t _bupc_Mstopcvt14;
  upcr_pshared_ptr_t _bupc_Mptra15;
  upcr_pshared_ptr_t _bupc_Mptra16;
  struct shared_hash_table_t * _bupc_Mcvtptr17;
  struct shared_bucket_t * _bupc_Mcvtptr18;
  upcr_pshared_ptr_t _bupc_Mptra19;
  struct shared_hash_table_t * _bupc_Mcvtptr20;
  _INT32 _bupc_Mptreq21;
  
#line 31 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  n_buckets = nEntries;
#line 33 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc_call10 = upc_all_alloc((unsigned long)(_UINT64)(nthread), (unsigned long) 16ULL);
#line 33 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc_Mstopcvt12 = UPCR_SHARED_TO_PSHARED(_bupc_call10);
#line 33 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  result = _bupc_Mstopcvt12;
#line 34 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc_Mptra13 = UPCR_ADD_PSHARED1(result, 16ULL, thread_id);
#line 34 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_PUT_PSHARED_VAL(_bupc_Mptra13, 0, n_buckets, 8);
#line 35 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc_call11 = upc_alloc((unsigned long)((_UINT64)(n_buckets) * 8ULL));
#line 35 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc_Mptra15 = UPCR_ADD_PSHARED1(result, 16ULL, thread_id);
#line 35 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc_Mstopcvt14 = UPCR_SHARED_TO_PSHARED(_bupc_call11);
#line 35 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_PUT_PSHARED_VAL(_bupc_Mptra15, 8, _bupc_Mstopcvt14, 8);
#line 36 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc_Mptra16 = UPCR_ADD_PSHARED1(result, 16ULL, thread_id);
#line 36 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc_Mcvtptr17 = (struct shared_hash_table_t *) UPCR_PSHARED_TO_LOCAL(_bupc_Mptra16);
#line 36 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc_Mcvtptr18 = (struct shared_bucket_t *) UPCR_PSHARED_TO_LOCAL((_bupc_Mcvtptr17) -> table);
#line 36 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  memset(_bupc_Mcvtptr18, (int) 0, (unsigned long)((_UINT64)(n_buckets) * 8ULL));
#line 38 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc_Mptra19 = UPCR_ADD_PSHARED1(result, 16ULL, thread_id);
#line 38 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc_Mcvtptr20 = (struct shared_hash_table_t *) UPCR_PSHARED_TO_LOCAL(_bupc_Mptra19);
#line 38 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc_Mptreq21 = UPCR_ISNULL_PSHARED((_bupc_Mcvtptr20) -> table);
#line 38 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  if(_bupc_Mptreq21)
#line 38 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  {
#line 39 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
    fprintf(stderr, "ERROR: Could not allocate memory for the hash table: %lld buckets of %llu bytes\n", n_buckets, 8ULL);
#line 40 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
    upcri_do_exit((int) 1);
  }
#line 43 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_EXIT_FUNCTION();
#line 43 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  return result;
} /* create_shared_hash_table */


#line 48 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
extern struct hash_table_t * create_hash_table(
  long nEntries,
  struct memory_heap_t * memory_heap)
#line 48 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
{
#line 48 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_BEGIN_FUNCTION();
  long n_buckets;
  struct hash_table_t * _bupc__casttmp3;
  struct hash_table_t * result;
  struct bucket_t * _bupc__casttmp4;
  struct kmer_t * _bupc__casttmp5;
  void * _bupc_call22;
  void * _bupc_call23;
  void * _bupc_call24;
  
#line 50 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  n_buckets = nEntries;
#line 52 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc_call22 = malloc((unsigned long) 16ULL);
#line 52 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc__casttmp3 = _bupc_call22;
#line 52 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  result = _bupc__casttmp3;
#line 53 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  (result) -> size = n_buckets;
#line 54 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc_call23 = calloc((unsigned long)(_UINT64)(n_buckets), (unsigned long) 8ULL);
#line 54 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc__casttmp4 = _bupc_call23;
#line 54 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  (result) -> table = _bupc__casttmp4;
#line 56 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  if((_UINT64)((result) -> table) == 0ULL)
#line 56 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  {
#line 57 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
    fprintf(stderr, "ERROR: Could not allocate memory for the hash table: %lld buckets of %llu bytes\n", n_buckets, 8ULL);
#line 58 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
    upcri_do_exit((int) 1);
  }
#line 61 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc_call24 = malloc((unsigned long)((_UINT64)(nEntries) * 16ULL));
#line 61 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc__casttmp5 = _bupc_call24;
#line 61 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  (memory_heap) -> heap = _bupc__casttmp5;
#line 62 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  if((_UINT64)((memory_heap) -> heap) == 0ULL)
#line 62 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  {
#line 63 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
    fprintf(stderr, "ERROR: Could not allocate memory for the heap!\n");
#line 64 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
    upcri_do_exit((int) 1);
  }
#line 66 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  (memory_heap) -> posInHeap = 0LL;
#line 68 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_EXIT_FUNCTION();
#line 68 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  return result;
} /* create_hash_table */


#line 73 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
extern long hashseq(
  long hashtable_size,
  char * seq,
  int size)
#line 73 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
{
#line 73 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_BEGIN_FUNCTION();
  unsigned long hashval;
  int i;
  
#line 75 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  hashval = 5381ULL;
#line 76 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  i = 0;
#line 76 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  while(i < size)
#line 76 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  {
#line 77 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
    hashval = hashval + ((_UINT64)((unsigned long) * (seq + i)) + _U8SHL(hashval, (_UINT64)(5)));
#line 78 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
    _1 :;
#line 78 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
    i = i + 1;
  }
#line 80 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_EXIT_FUNCTION();
#line 80 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  return(_INT64)(hashval % (_UINT64)(hashtable_size));
} /* hashseq */


#line 85 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
extern long hashkmer(
  long hashtable_size,
  char * seq)
#line 85 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
{
#line 85 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_BEGIN_FUNCTION();
  register _INT64 _bupc_comma;
  
#line 86 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc_comma = hashseq(hashtable_size, seq, (int) 5);
#line 86 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_EXIT_FUNCTION();
#line 86 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  return _bupc_comma;
} /* hashkmer */


#line 91 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
extern upcr_pshared_ptr_t lookup_kmer_shared_local(
  struct shared_hash_table_t * hashtable,
  const unsigned char * kmer)
#line 91 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
{
#line 91 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_BEGIN_FUNCTION();
  register _INT64 _bupc_comma;
  register _UINT64 _bupc_reg8;
  register _INT32 _bupc_comma0;
  char packedKmer[5LL];
  long hashval;
  upcr_pshared_ptr_t cur_table;
  upcr_pshared_ptr_t result;
  int _bupc__spilleq6;
  upcr_pshared_ptr_t _bupc_Mptra25;
  upcr_pshared_ptr_t _bupc_spillld26;
  char * _bupc_Mcvtptr27;
  upcr_pshared_ptr_t _bupc_spillld28;
  _INT32 _bupc_Mptreq29;
  
#line 93 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  packSequence(kmer, (unsigned char *) packedKmer, (int) 19);
#line 94 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc_comma = hashkmer((hashtable) -> size, packedKmer);
#line 94 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  hashval = _bupc_comma;
#line 96 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc_Mptra25 = UPCR_ADD_PSHAREDI((hashtable) -> table, 8ULL, hashval);
#line 96 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  cur_table = _bupc_Mptra25;
#line 98 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_GET_PSHARED(&_bupc_spillld26, cur_table, 0, 8);
#line 98 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  result = _bupc_spillld26;
#line 105 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc_reg8 = UPCR_ISNULL_PSHARED(result);
  _bupc_Mptreq29 = !(_INT32) _bupc_reg8;
#line 100 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  while(_bupc_Mptreq29)
#line 100 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  {
#line 101 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
    _bupc_Mcvtptr27 = (char *) UPCR_PSHARED_TO_LOCAL(result);
#line 101 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
    _bupc_comma0 = memcmp(packedKmer, _bupc_Mcvtptr27, (unsigned long) 5ULL);
#line 101 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
    _bupc__spilleq6 = _bupc_comma0;
#line 101 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
    if(_bupc__spilleq6 == 0)
#line 101 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
    {
#line 102 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
      UPCR_EXIT_FUNCTION();
#line 102 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
      return result;
    }
#line 104 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
    UPCR_GET_PSHARED(&_bupc_spillld28, result, 8, 8);
#line 104 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
    result = _bupc_spillld28;
#line 105 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
    _1 :;
#line 105 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
    _bupc_reg8 = UPCR_ISNULL_PSHARED(result);
    _bupc_Mptreq29 = !(_INT32) _bupc_reg8;
  }
#line 106 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_EXIT_FUNCTION();
#line 106 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  return upcr_null_pshared;
} /* lookup_kmer_shared_local */


#line 111 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
extern upcr_pshared_ptr_t lookup_kmer_shared_remote(
  upcr_pshared_ptr_t hashtable,
  const unsigned char * kmer)
#line 111 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
{
#line 111 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_BEGIN_FUNCTION();
  register _INT64 _bupc_comma;
  register _UINT64 _bupc_reg8;
  register _INT32 _bupc_comma0;
  char packedKmer[5LL];
  long hashval;
  upcr_pshared_ptr_t cur_table;
  upcr_pshared_ptr_t result;
  char curKmer[5LL];
  int _bupc__spilleq7;
  long _bupc_spillld30;
  upcr_pshared_ptr_t _bupc_spillld31;
  upcr_pshared_ptr_t _bupc_Mptra32;
  upcr_pshared_ptr_t _bupc_spillld33;
  upcr_shared_ptr_t _bupc_Mstopcvt34;
  upcr_pshared_ptr_t _bupc_spillld35;
  _INT32 _bupc_Mptreq36;
  
#line 113 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  packSequence(kmer, (unsigned char *) packedKmer, (int) 19);
#line 114 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_GET_PSHARED(&_bupc_spillld30, hashtable, 0, 8);
#line 114 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc_comma = hashkmer(_bupc_spillld30, packedKmer);
#line 114 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  hashval = _bupc_comma;
#line 116 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_GET_PSHARED(&_bupc_spillld31, hashtable, 8, 8);
#line 116 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc_Mptra32 = UPCR_ADD_PSHAREDI(_bupc_spillld31, 8ULL, hashval);
#line 116 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  cur_table = _bupc_Mptra32;
#line 118 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_GET_PSHARED(&_bupc_spillld33, cur_table, 0, 8);
#line 118 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  result = _bupc_spillld33;
#line 126 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc_reg8 = UPCR_ISNULL_PSHARED(result);
  _bupc_Mptreq36 = !(_INT32) _bupc_reg8;
#line 120 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  while(_bupc_Mptreq36)
#line 120 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  {
#line 121 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
    _bupc_Mstopcvt34 = UPCR_PSHARED_TO_SHARED(result);
#line 121 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
    upc_memget(curKmer, _bupc_Mstopcvt34, (unsigned long) 5ULL);
#line 122 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
    _bupc_comma0 = memcmp(packedKmer, curKmer, (unsigned long) 5ULL);
#line 122 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
    _bupc__spilleq7 = _bupc_comma0;
#line 122 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
    if(_bupc__spilleq7 == 0)
#line 122 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
    {
#line 123 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
      UPCR_EXIT_FUNCTION();
#line 123 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
      return result;
    }
#line 125 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
    UPCR_GET_PSHARED(&_bupc_spillld35, result, 8, 8);
#line 125 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
    result = _bupc_spillld35;
#line 126 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
    _1 :;
#line 126 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
    _bupc_reg8 = UPCR_ISNULL_PSHARED(result);
    _bupc_Mptreq36 = !(_INT32) _bupc_reg8;
  }
#line 127 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_EXIT_FUNCTION();
#line 127 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  return upcr_null_pshared;
} /* lookup_kmer_shared_remote */


#line 132 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
extern struct kmer_t * lookup_kmer(
  struct hash_table_t * hashtable,
  const unsigned char * kmer)
#line 132 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
{
#line 132 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_BEGIN_FUNCTION();
  register _INT64 _bupc_comma;
  register _INT32 _bupc_comma0;
  char packedKmer[5LL];
  long hashval;
  struct bucket_t cur_bucket;
  struct kmer_t * result;
  int _bupc__spilleq8;
  
#line 134 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  packSequence(kmer, (unsigned char *) packedKmer, (int) 19);
#line 135 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc_comma = hashkmer((hashtable) -> size, packedKmer);
#line 135 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  hashval = _bupc_comma;
#line 139 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  cur_bucket = *((hashtable) -> table + hashval);
#line 140 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  result = (cur_bucket).head;
#line 142 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  while((_UINT64)(result) != 0ULL)
#line 142 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  {
#line 143 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
    _bupc_comma0 = memcmp(packedKmer, result, (unsigned long) 5ULL);
#line 143 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
    _bupc__spilleq8 = _bupc_comma0;
#line 143 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
    if(_bupc__spilleq8 == 0)
#line 143 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
    {
#line 144 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
      UPCR_EXIT_FUNCTION();
#line 144 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
      return result;
    }
#line 146 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
    result = (result) -> next;
#line 147 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
    _1 :;
  }
#line 148 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_EXIT_FUNCTION();
#line 148 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  return(struct kmer_t *) 0ULL;
} /* lookup_kmer */


#line 153 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
extern int add_kmer_shared(
  struct shared_hash_table_t * hashtable,
  struct shared_memory_heap_t * memory_heap,
  const unsigned char * kmer,
  char left_ext,
  char right_ext)
#line 153 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
{
#line 153 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_BEGIN_FUNCTION();
  register _INT64 _bupc_comma;
  char packedKmer[5LL];
  long hashval;
  long pos;
  upcr_pshared_ptr_t cur_kmer;
  upcr_pshared_ptr_t cur_table;
  upcr_pshared_ptr_t _bupc_Mptra37;
  upcr_pshared_ptr_t _bupc_Mptra38;
  char * _bupc_Mcvtptr39;
  upcr_pshared_ptr_t _bupc_spillld40;
  
#line 156 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  packSequence(kmer, (unsigned char *) packedKmer, (int) 19);
#line 157 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc_comma = hashkmer((hashtable) -> size, packedKmer);
#line 157 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  hashval = _bupc_comma;
#line 158 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  pos = (memory_heap) -> posInHeap;
#line 159 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc_Mptra37 = UPCR_ADD_PSHAREDI((memory_heap) -> heap, 16ULL, pos);
#line 159 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  cur_kmer = _bupc_Mptra37;
#line 161 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc_Mptra38 = UPCR_ADD_PSHAREDI((hashtable) -> table, 8ULL, hashval);
#line 161 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  cur_table = _bupc_Mptra38;
#line 171 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc_Mcvtptr39 = (char *) UPCR_PSHARED_TO_LOCAL(cur_kmer);
#line 171 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  memcpy(_bupc_Mcvtptr39, (const void *)(packedKmer), (unsigned long) 5ULL);
#line 172 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_PUT_PSHARED_VAL(cur_kmer, 5, left_ext, 1);
#line 173 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_PUT_PSHARED_VAL(cur_kmer, 6, right_ext, 1);
#line 176 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_GET_PSHARED(&_bupc_spillld40, cur_table, 0, 8);
#line 176 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_PUT_PSHARED_VAL(cur_kmer, 8, _bupc_spillld40, 8);
#line 179 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_PUT_PSHARED_VAL(cur_table, 0, cur_kmer, 8);
#line 182 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  (memory_heap) -> posInHeap = (memory_heap) -> posInHeap + 1LL;
#line 183 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_EXIT_FUNCTION();
#line 183 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  return 0;
} /* add_kmer_shared */


#line 189 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
extern int add_kmer(
  struct hash_table_t * hashtable,
  struct memory_heap_t * memory_heap,
  const unsigned char * kmer,
  char left_ext,
  char right_ext)
#line 189 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
{
#line 189 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_BEGIN_FUNCTION();
  register _INT64 _bupc_comma;
  char packedKmer[5LL];
  long hashval;
  long pos;
  
#line 192 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  packSequence(kmer, (unsigned char *) packedKmer, (int) 19);
#line 193 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc_comma = hashkmer((hashtable) -> size, packedKmer);
#line 193 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  hashval = _bupc_comma;
#line 194 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  pos = (memory_heap) -> posInHeap;
#line 197 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  memcpy((memory_heap) -> heap + pos, (const void *)(packedKmer), (unsigned long) 5ULL);
#line 198 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  (((memory_heap) -> heap + pos)) -> l_ext = left_ext;
#line 199 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  (((memory_heap) -> heap + pos)) -> r_ext = right_ext;
#line 202 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  (((memory_heap) -> heap + pos)) -> next = (((hashtable) -> table + hashval)) -> head;
#line 204 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  (((hashtable) -> table + hashval)) -> head = (memory_heap) -> heap + pos;
#line 207 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  (memory_heap) -> posInHeap = (memory_heap) -> posInHeap + 1LL;
#line 209 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_EXIT_FUNCTION();
#line 209 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  return 0;
} /* add_kmer */


#line 215 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
extern void addKmerToStartList(
  struct memory_heap_t * memory_heap,
  struct start_kmer_t ** startKmersList)
#line 215 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
{
#line 215 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_BEGIN_FUNCTION();
  long prevPosInHeap;
  struct kmer_t * ptrToKmer;
  struct start_kmer_t * _bupc__casttmp9;
  struct start_kmer_t * new_entry;
  void * _bupc_call41;
  
#line 219 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  prevPosInHeap = (memory_heap) -> posInHeap + -1LL;
#line 220 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  ptrToKmer = (memory_heap) -> heap + prevPosInHeap;
#line 221 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc_call41 = malloc((unsigned long) 16ULL);
#line 221 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  _bupc__casttmp9 = _bupc_call41;
#line 221 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  new_entry = _bupc__casttmp9;
#line 222 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  (new_entry) -> next = *startKmersList;
#line 223 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  (new_entry) -> kmerPtr = ptrToKmer;
#line 224 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  * startKmersList = new_entry;
  UPCR_EXIT_FUNCTION();
  return;
} /* addKmerToStartList */


#line 229 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
extern int dealloc_heap(
  struct memory_heap_t * memory_heap)
#line 229 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
{
#line 229 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_BEGIN_FUNCTION();
  
#line 230 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  free((memory_heap) -> heap);
#line 231 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_EXIT_FUNCTION();
#line 231 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  return 0;
} /* dealloc_heap */


#line 235 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
extern int dealloc_hashtable(
  struct hash_table_t * hashtable)
#line 235 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
{
#line 235 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_BEGIN_FUNCTION();
  
#line 236 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  free((hashtable) -> table);
#line 237 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  UPCR_EXIT_FUNCTION();
#line 237 "/pylon5/cc3uv3p/jsimms22/upc2/kmer_hash_shared.h"
  return 0;
} /* dealloc_hashtable */


#line 14 "pgen.upc"
extern int user_main(
  int argc,
  char ** argv)
#line 14 "pgen.upc"
{
#line 14 "pgen.upc"
  UPCR_BEGIN_FUNCTION();
  register _IEEE64 _bupc_comma;
  register _INT64 _bupc_comma0;
  register _INT32 _bupc_comma1;
  register _UINT64 _bupc_comma2;
  register _IEEE64 _bupc_comma3;
  register _IEEE64 _bupc_comma4;
  register _IEEE64 _bupc_comma5;
  register _IEEE64 _bupc_comma6;
  register _IEEE64 _bupc_comma7;
  register _INT64 _bupc_comma8;
  register _IEEE64 _bupc_comma9;
  register _IEEE64 _bupc_comma10;
  register _INT64 _bupc_comma11;
  register _INT64 _bupc_comma12;
  register _IEEE64 _bupc_comma13;
  _IEEE64 inputTime;
  _IEEE64 constrTime;
  _IEEE64 traversalTime;
  long n_total_kmers;
  long n_kmers_to_process_ideal;
  long start_kmer;
  long end_kmer;
  long n_kmers_to_process;
  long char_start_position;
  long chars_to_read;
  unsigned char * buffer;
  unsigned char * _bupc__casttmp10;
  unsigned char * buffer_cpy;
  unsigned char * _bupc__casttmp11;
  struct _IO_FILE * input_file;
  int _bupc__spilleq12;
  unsigned long _bupc__spilleq13;
  long * start_kmer_offsets;
  long * _bupc__casttmp14;
  long n_start_kmers;
  upcr_pshared_ptr_t hashtable_global;
  upcr_pshared_ptr_t memory_heap_global;
  struct shared_hash_table_t * private_hashtable;
  struct shared_memory_heap_t * private_memory_heap;
  int nints;
  upcr_pshared_ptr_t process_kmer_list_offsets_global;
  long * process_kmer_list_offsets;
  long max_kmers_to_transfer_to_single_process;
  long nchars;
  upcr_pshared_ptr_t kmers_to_transfer_global;
  char * kmers_to_transfer;
  int i;
  int process_owner;
  long _bupc_spillpost15;
  int _bupc_w2c_i0;
  long n_kmers_char_to_transfer_to_self;
  int j;
  char output_file_name[15LL];
  struct _IO_FILE * output_file;
  char contig_seq[100000LL];
  int _bupc_w2c_i1;
  long kmer_string_offset;
  long kmer_track;
  int process_owner_seed;
  upcr_pshared_ptr_t cur_kmer;
  char right_ext;
  int _bupc_w2c_process_owner0;
  void * _bupc_call42;
  void * _bupc_call43;
  struct _IO_FILE * _bupc_call44;
  void * _bupc_call45;
  upcr_pshared_ptr_t _bupc_call46;
  upcr_pshared_ptr_t _bupc_call47;
  upcr_shared_ptr_t _bupc_call48;
  upcr_shared_ptr_t _bupc_call49;
  struct _IO_FILE * _bupc_call50;
  upcr_pshared_ptr_t _bupc_call51;
  upcr_pshared_ptr_t _bupc_call52;
  upcr_pshared_ptr_t _bupc_call53;
  upcr_pshared_ptr_t _bupc_call54;
  upcr_pshared_ptr_t _bupc_Mptra55;
  struct shared_hash_table_t * _bupc_Mcvtptr56;
  upcr_pshared_ptr_t _bupc_Mptra57;
  struct shared_memory_heap_t * _bupc_Mcvtptr58;
  upcr_pshared_ptr_t _bupc_Mstopcvt59;
  upcr_pshared_ptr_t _bupc_Mptra60;
  long * _bupc_Mcvtptr61;
  upcr_pshared_ptr_t _bupc_Mstopcvt62;
  upcr_pshared_ptr_t _bupc_Mptra63;
  char * _bupc_Mcvtptr64;
  upcr_pshared_ptr_t _bupc_Mptra65;
  upcr_pshared_ptr_t _bupc_Mptra66;
  long _bupc_spillld67;
  upcr_pshared_ptr_t _bupc_Mptra68;
  upcr_pshared_ptr_t _bupc_Mptra69;
  upcr_shared_ptr_t _bupc_Mstopcvt70;
  upcr_shared_ptr_t _bupc_Mstopcvt71;
  upcr_shared_ptr_t _bupc_Mstopcvt72;
  upcr_pshared_ptr_t _bupc_Mptra73;
  char _bupc_spillld74;
  upcr_pshared_ptr_t _bupc_Mptra75;
  char _bupc_spillld76;
  
#line 17 "pgen.upc"
  inputTime = 0.0;
#line 17 "pgen.upc"
  constrTime = 0.0;
#line 17 "pgen.upc"
  traversalTime = 0.0;
#line 20 "pgen.upc"
  upcr_barrier(346153894, 1);
#line 21 "pgen.upc"
  _bupc_comma = gettime();
#line 21 "pgen.upc"
  inputTime = inputTime - _bupc_comma;
#line 24 "pgen.upc"
  _bupc_comma0 = getNumKmersInUFX((const char *) * (argv + 1LL));
#line 24 "pgen.upc"
  n_total_kmers = _bupc_comma0;
#line 25 "pgen.upc"
  n_kmers_to_process_ideal = (n_total_kmers / (_INT64)(((int) upcr_threads () ))) + 1LL;
#line 26 "pgen.upc"
  start_kmer = (_INT64)(((int) upcr_mythread () )) * n_kmers_to_process_ideal;
#line 27 "pgen.upc"
  end_kmer = (_INT64)((((int) upcr_mythread () ) + 1)) * n_kmers_to_process_ideal;
#line 28 "pgen.upc"
  if(((int) upcr_mythread () ) == (((int) upcr_threads () ) + -1))
#line 28 "pgen.upc"
  {
#line 28 "pgen.upc"
    end_kmer = n_total_kmers;
  }
#line 29 "pgen.upc"
  n_kmers_to_process = end_kmer - start_kmer;
#line 30 "pgen.upc"
  char_start_position = start_kmer * 23LL;
#line 31 "pgen.upc"
  chars_to_read = n_kmers_to_process * 23LL;
#line 32 "pgen.upc"
  _bupc_call42 = malloc((unsigned long)(_UINT64)(chars_to_read));
#line 32 "pgen.upc"
  _bupc__casttmp10 = _bupc_call42;
#line 32 "pgen.upc"
  buffer = _bupc__casttmp10;
#line 33 "pgen.upc"
  _bupc_call43 = malloc((unsigned long)(_UINT64)((n_kmers_to_process_ideal * 23LL)));
#line 33 "pgen.upc"
  _bupc__casttmp11 = _bupc_call43;
#line 33 "pgen.upc"
  buffer_cpy = _bupc__casttmp11;
#line 35 "pgen.upc"
  printf("Process %d: Reading and creating graph for K-mers %lld - %lld\n", ((int) upcr_mythread () ), start_kmer, end_kmer);
#line 38 "pgen.upc"
  _bupc_call44 = fopen((const char *) * (argv + 1LL), "r");
#line 38 "pgen.upc"
  input_file = _bupc_call44;
#line 39 "pgen.upc"
  _bupc_comma1 = fseek(input_file, char_start_position, (int) 0);
#line 39 "pgen.upc"
  _bupc__spilleq12 = _bupc_comma1;
#line 39 "pgen.upc"
  if(_bupc__spilleq12 != 0)
#line 39 "pgen.upc"
  {
#line 40 "pgen.upc"
    printf("Error Seeking...");
#line 41 "pgen.upc"
    upcri_do_exit((int) 0);
  }
#line 43 "pgen.upc"
  _bupc_comma2 = fread(buffer, (unsigned long) 1ULL, (unsigned long)(_UINT64)(chars_to_read), input_file);
#line 43 "pgen.upc"
  _bupc__spilleq13 = _bupc_comma2;
#line 43 "pgen.upc"
  if(_bupc__spilleq13 != (_UINT64)(chars_to_read))
#line 43 "pgen.upc"
  {
#line 44 "pgen.upc"
    printf("Error reading...");
#line 45 "pgen.upc"
    upcri_do_exit((int) 0);
  }
#line 47 "pgen.upc"
  fclose(input_file);
#line 49 "pgen.upc"
  upcr_barrier(346153895, 1);
#line 50 "pgen.upc"
  _bupc_comma3 = gettime();
#line 50 "pgen.upc"
  inputTime = inputTime + _bupc_comma3;
#line 53 "pgen.upc"
  _bupc_comma4 = gettime();
#line 53 "pgen.upc"
  constrTime = constrTime - _bupc_comma4;
#line 56 "pgen.upc"
  _bupc_call45 = malloc((unsigned long)((_UINT64)(n_kmers_to_process) * 8ULL));
#line 56 "pgen.upc"
  _bupc__casttmp14 = _bupc_call45;
#line 56 "pgen.upc"
  start_kmer_offsets = _bupc__casttmp14;
#line 57 "pgen.upc"
  n_start_kmers = 0LL;
#line 61 "pgen.upc"
  _bupc_comma5 = fmin((_IEEE64)((_IEEE32)((((int) upcr_threads () ) + 1)) * 0.5F), 3.0);
#line 61 "pgen.upc"
  _bupc_call46 = create_shared_hash_table(((int) upcr_threads () ), ((int) upcr_mythread () ), (long) _I8F8TRUNC((_IEEE64)(n_kmers_to_process_ideal) * _bupc_comma5));
#line 61 "pgen.upc"
  hashtable_global = _bupc_call46;
#line 62 "pgen.upc"
  _bupc_comma6 = fmin((_IEEE64)((_IEEE32)((((int) upcr_threads () ) + 1)) * 0.5F), 3.0);
#line 62 "pgen.upc"
  _bupc_call47 = create_shared_memory_heap(((int) upcr_threads () ), ((int) upcr_mythread () ), (long) _I8F8TRUNC((_IEEE64)(n_kmers_to_process_ideal) * _bupc_comma6));
#line 62 "pgen.upc"
  memory_heap_global = _bupc_call47;
#line 63 "pgen.upc"
  _bupc_Mptra55 = UPCR_ADD_PSHARED1(hashtable_global, 16ULL, ((int) upcr_mythread () ));
#line 63 "pgen.upc"
  _bupc_Mcvtptr56 = (struct shared_hash_table_t *) UPCR_PSHARED_TO_LOCAL(_bupc_Mptra55);
#line 63 "pgen.upc"
  private_hashtable = _bupc_Mcvtptr56;
#line 64 "pgen.upc"
  _bupc_Mptra57 = UPCR_ADD_PSHARED1(memory_heap_global, 16ULL, ((int) upcr_mythread () ));
#line 64 "pgen.upc"
  _bupc_Mcvtptr58 = (struct shared_memory_heap_t *) UPCR_PSHARED_TO_LOCAL(_bupc_Mptra57);
#line 64 "pgen.upc"
  private_memory_heap = _bupc_Mcvtptr58;
#line 67 "pgen.upc"
  nints = ((int) upcr_threads () );
#line 68 "pgen.upc"
  _bupc_call48 = upc_all_alloc((unsigned long)(_UINT64)(((int) upcr_threads () )), (unsigned long)((_UINT64)(nints) * 8ULL));
#line 68 "pgen.upc"
  _bupc_Mstopcvt59 = UPCR_SHARED_TO_PSHARED(_bupc_call48);
#line 68 "pgen.upc"
  process_kmer_list_offsets_global = _bupc_Mstopcvt59;
#line 69 "pgen.upc"
  _bupc_Mptra60 = UPCR_ADD_PSHARED1(process_kmer_list_offsets_global, 8ULL, ((int) upcr_mythread () ));
#line 69 "pgen.upc"
  _bupc_Mcvtptr61 = (long *) UPCR_PSHARED_TO_LOCAL(_bupc_Mptra60);
#line 69 "pgen.upc"
  process_kmer_list_offsets = _bupc_Mcvtptr61;
#line 70 "pgen.upc"
  memset(process_kmer_list_offsets, (int) 0, (unsigned long)((_UINT64)(((int) upcr_threads () )) * 8ULL));
#line 73 "pgen.upc"
  _bupc_comma7 = fmin((_IEEE64)((_IEEE32)((((int) upcr_threads () ) + 1)) * 0.5F), 3.0);
#line 73 "pgen.upc"
  max_kmers_to_transfer_to_single_process = _I8F8TRUNC((_IEEE64)((n_kmers_to_process_ideal / (_INT64)(((int) upcr_threads () )))) * _bupc_comma7);
#line 74 "pgen.upc"
  nchars = (max_kmers_to_transfer_to_single_process * (_INT64)(((int) upcr_threads () ))) * 23LL;
#line 75 "pgen.upc"
  _bupc_call49 = upc_all_alloc((unsigned long)(_UINT64)(((int) upcr_threads () )), (unsigned long)(_UINT64)(nchars));
#line 75 "pgen.upc"
  _bupc_Mstopcvt62 = UPCR_SHARED_TO_PSHARED(_bupc_call49);
#line 75 "pgen.upc"
  kmers_to_transfer_global = _bupc_Mstopcvt62;
#line 76 "pgen.upc"
  _bupc_Mptra63 = UPCR_ADD_PSHARED1(kmers_to_transfer_global, 1ULL, ((int) upcr_mythread () ));
#line 76 "pgen.upc"
  _bupc_Mcvtptr64 = (char *) UPCR_PSHARED_TO_LOCAL(_bupc_Mptra63);
#line 76 "pgen.upc"
  kmers_to_transfer = _bupc_Mcvtptr64;
#line 79 "pgen.upc"
  i = 0;
#line 79 "pgen.upc"
  while((_INT64)(i) < (n_kmers_to_process * 23LL))
#line 79 "pgen.upc"
  {
#line 80 "pgen.upc"
    _bupc_comma8 = hashkmer((long) ((int) upcr_threads () ), (char *)(buffer + i));
#line 80 "pgen.upc"
    process_owner = _bupc_comma8;
#line 82 "pgen.upc"
    if(process_owner == ((int) upcr_mythread () ))
#line 82 "pgen.upc"
    {
#line 83 "pgen.upc"
      add_kmer_shared(private_hashtable, private_memory_heap, buffer + i, (char)(char) * ((buffer + (i + 19)) + 1LL), (char)(char) * ((buffer + (i + 19)) + 2LL));
    }
    else
#line 83 "pgen.upc"
    {
#line 89 "pgen.upc"
      memcpy(kmers_to_transfer + (*(process_kmer_list_offsets + process_owner) + ((process_owner * max_kmers_to_transfer_to_single_process) * 23LL)), (const void *)(buffer + i), (unsigned long) 23ULL);
#line 90 "pgen.upc"
      * (process_kmer_list_offsets + process_owner) = *(process_kmer_list_offsets + process_owner) + 23LL;
    }
#line 94 "pgen.upc"
    if((_UINT32)(*((buffer + (i + 19)) + 1LL)) == 70U)
#line 94 "pgen.upc"
    {
#line 95 "pgen.upc"
      _bupc_spillpost15 = n_start_kmers;
#line 95 "pgen.upc"
      n_start_kmers = _bupc_spillpost15 + 1LL;
#line 95 "pgen.upc"
      * (start_kmer_offsets + _bupc_spillpost15) = i;
    }
#line 97 "pgen.upc"
    _1 :;
#line 97 "pgen.upc"
    i = i + 23;
  }
#line 100 "pgen.upc"
  upcr_barrier(346153896, 1);
#line 103 "pgen.upc"
  _bupc_w2c_i0 = 0;
#line 103 "pgen.upc"
  while(_bupc_w2c_i0 < ((int) upcr_threads () ))
#line 103 "pgen.upc"
  {
#line 104 "pgen.upc"
    if(_bupc_w2c_i0 != ((int) upcr_mythread () ))
#line 104 "pgen.upc"
    {
#line 105 "pgen.upc"
      _bupc_Mptra65 = UPCR_ADD_PSHARED1(process_kmer_list_offsets_global, 8ULL, _bupc_w2c_i0);
#line 105 "pgen.upc"
      _bupc_Mptra66 = UPCR_ADD_PSHAREDI(_bupc_Mptra65, 8ULL, ((int) upcr_mythread () ));
#line 105 "pgen.upc"
      UPCR_GET_PSHARED(&_bupc_spillld67, _bupc_Mptra66, 0, 8);
#line 105 "pgen.upc"
      n_kmers_char_to_transfer_to_self = _bupc_spillld67;
#line 108 "pgen.upc"
      _bupc_Mptra68 = UPCR_ADD_PSHARED1(kmers_to_transfer_global, 1ULL, _bupc_w2c_i0);
#line 108 "pgen.upc"
      _bupc_Mptra69 = UPCR_ADD_PSHAREDI(_bupc_Mptra68, 1ULL, ((_INT64)(((int) upcr_mythread () )) * max_kmers_to_transfer_to_single_process) * 23LL);
#line 108 "pgen.upc"
      _bupc_Mstopcvt70 = UPCR_PSHARED_TO_SHARED(_bupc_Mptra69);
#line 108 "pgen.upc"
      upc_memget(buffer_cpy, _bupc_Mstopcvt70, (unsigned long)(_UINT64)(n_kmers_char_to_transfer_to_self));
#line 110 "pgen.upc"
      j = 0;
#line 110 "pgen.upc"
      while((_INT64)(j) < n_kmers_char_to_transfer_to_self)
#line 110 "pgen.upc"
      {
#line 111 "pgen.upc"
        add_kmer_shared(private_hashtable, private_memory_heap, buffer_cpy + j, (char)(char) * ((buffer_cpy + (j + 19)) + 1LL), (char)(char) * ((buffer_cpy + (j + 19)) + 2LL));
#line 112 "pgen.upc"
        _3 :;
#line 112 "pgen.upc"
        j = j + 23;
      }
    }
#line 114 "pgen.upc"
    _2 :;
#line 114 "pgen.upc"
    _bupc_w2c_i0 = _bupc_w2c_i0 + 1;
  }
#line 116 "pgen.upc"
  upcr_barrier(346153897, 1);
#line 119 "pgen.upc"
  _bupc_Mstopcvt71 = UPCR_PSHARED_TO_SHARED(kmers_to_transfer_global);
#line 119 "pgen.upc"
  upc_all_free(_bupc_Mstopcvt71);
#line 120 "pgen.upc"
  _bupc_Mstopcvt72 = UPCR_PSHARED_TO_SHARED(process_kmer_list_offsets_global);
#line 120 "pgen.upc"
  upc_all_free(_bupc_Mstopcvt72);
#line 122 "pgen.upc"
  _bupc_comma9 = gettime();
#line 122 "pgen.upc"
  constrTime = constrTime + _bupc_comma9;
#line 125 "pgen.upc"
  _bupc_comma10 = gettime();
#line 125 "pgen.upc"
  traversalTime = traversalTime - _bupc_comma10;
#line 128 "pgen.upc"
  memset(output_file_name, (int) 0, (unsigned long) 15ULL);
#line 129 "pgen.upc"
  sprintf(output_file_name, "pgen_%d.out", ((int) upcr_mythread () ));
#line 130 "pgen.upc"
  _bupc_call50 = fopen(output_file_name, "w");
#line 130 "pgen.upc"
  output_file = _bupc_call50;
#line 133 "pgen.upc"
  memset(contig_seq, (int) 0, (unsigned long) 100000ULL);
#line 136 "pgen.upc"
  _bupc_w2c_i1 = 0;
#line 136 "pgen.upc"
  while((_INT64)(_bupc_w2c_i1) < n_start_kmers)
#line 136 "pgen.upc"
  {
#line 140 "pgen.upc"
    kmer_string_offset = *(start_kmer_offsets + _bupc_w2c_i1);
#line 140 "pgen.upc"
    kmer_track = 0LL;
#line 141 "pgen.upc"
    memcpy(contig_seq, (const void *)(buffer + kmer_string_offset), (unsigned long) 19ULL);
#line 144 "pgen.upc"
    _bupc_comma11 = hashkmer((long) ((int) upcr_threads () ), (char *)(buffer + kmer_string_offset));
#line 144 "pgen.upc"
    process_owner_seed = _bupc_comma11;
#line 146 "pgen.upc"
    if(process_owner_seed == ((int) upcr_mythread () ))
#line 146 "pgen.upc"
    {
#line 147 "pgen.upc"
      _bupc_call51 = lookup_kmer_shared_local(private_hashtable, buffer + kmer_string_offset);
#line 147 "pgen.upc"
      cur_kmer = _bupc_call51;
    }
    else
#line 147 "pgen.upc"
    {
#line 149 "pgen.upc"
      _bupc_Mptra73 = UPCR_ADD_PSHARED1(hashtable_global, 16ULL, process_owner_seed);
#line 149 "pgen.upc"
      _bupc_call52 = lookup_kmer_shared_remote(_bupc_Mptra73, buffer + kmer_string_offset);
#line 149 "pgen.upc"
      cur_kmer = _bupc_call52;
    }
#line 150 "pgen.upc"
    UPCR_GET_PSHARED(&_bupc_spillld74, cur_kmer, 6, 1);
#line 150 "pgen.upc"
    right_ext = _bupc_spillld74;
#line 153 "pgen.upc"
    while((_INT32)(right_ext) != 70)
#line 153 "pgen.upc"
    {
#line 154 "pgen.upc"
      kmer_track = kmer_track + 1LL;
#line 155 "pgen.upc"
      (contig_seq)[kmer_track + 18LL] = right_ext;
#line 156 "pgen.upc"
      _bupc_comma12 = hashkmer((long) ((int) upcr_threads () ), (char *)(contig_seq) + kmer_track);
#line 156 "pgen.upc"
      _bupc_w2c_process_owner0 = _bupc_comma12;
#line 157 "pgen.upc"
      if(_bupc_w2c_process_owner0 == ((int) upcr_mythread () ))
#line 157 "pgen.upc"
      {
#line 158 "pgen.upc"
        _bupc_call53 = lookup_kmer_shared_local(private_hashtable, (const unsigned char *)((char *)(contig_seq) + kmer_track));
#line 158 "pgen.upc"
        cur_kmer = _bupc_call53;
      }
      else
#line 158 "pgen.upc"
      {
#line 160 "pgen.upc"
        _bupc_Mptra75 = UPCR_ADD_PSHARED1(hashtable_global, 16ULL, _bupc_w2c_process_owner0);
#line 160 "pgen.upc"
        _bupc_call54 = lookup_kmer_shared_remote(_bupc_Mptra75, (const unsigned char *)((char *)(contig_seq) + kmer_track));
#line 160 "pgen.upc"
        cur_kmer = _bupc_call54;
      }
#line 162 "pgen.upc"
      UPCR_GET_PSHARED(&_bupc_spillld76, cur_kmer, 6, 1);
#line 162 "pgen.upc"
      right_ext = _bupc_spillld76;
    }
#line 166 "pgen.upc"
    fprintf(output_file, "%s\n", contig_seq);
#line 169 "pgen.upc"
    memset(contig_seq, (int) 0, (unsigned long) 100000ULL);
#line 170 "pgen.upc"
    _4 :;
#line 170 "pgen.upc"
    _bupc_w2c_i1 = _bupc_w2c_i1 + 1;
  }
#line 172 "pgen.upc"
  fclose(output_file);
#line 174 "pgen.upc"
  upcr_barrier(346153898, 1);
#line 175 "pgen.upc"
  _bupc_comma13 = gettime();
#line 175 "pgen.upc"
  traversalTime = traversalTime + _bupc_comma13;
#line 179 "pgen.upc"
  if(((int) upcr_mythread () ) == 0)
#line 179 "pgen.upc"
  {
#line 180 "pgen.upc"
    printf("%s: Input set: %s\n", *argv, *(argv + 1LL));
#line 181 "pgen.upc"
    printf("Number of UPC threads: %d\n", ((int) upcr_threads () ));
#line 182 "pgen.upc"
    printf("Input reading time: %f seconds\n", inputTime);
#line 183 "pgen.upc"
    printf("Graph construction time: %f seconds\n", constrTime);
#line 184 "pgen.upc"
    printf("Graph traversal time: %f seconds\n", traversalTime);
  }
#line 186 "pgen.upc"
  UPCR_EXIT_FUNCTION();
#line 186 "pgen.upc"
  return 0;
} /* user_main */

#line 1 "_SYSTEM"
/**************************************************************************/
/* upcc-generated strings for configuration consistency checks            */

GASNETT_IDENT(UPCRI_IdentString_pgen_o_1525558169_GASNetConfig_gen, 
 "$GASNetConfig: (/tmp/upcc--27123-1525558169/pgen.trans.c) RELEASE=1.30.0,SPEC=1.8,CONDUIT=OFI(OFI-0.5/OFI-0.5),THREADMODEL=PAR,SEGMENT=FAST,PTR=64bit,noalign,pshm,nodebug,notrace,nostats,nodebugmalloc,nosrclines,timers_native,membars_native,atomics_native,atomic32_native,atomic64_native $");
GASNETT_IDENT(UPCRI_IdentString_pgen_o_1525558169_UPCRConfig_gen,
 "$UPCRConfig: (/tmp/upcc--27123-1525558169/pgen.trans.c) VERSION=2.26.0,PLATFORMENV=shared-distributed,SHMEM=pthreads/pshm,SHAREDPTRREP=packed/p20:t10:a34,TRANS=berkeleyupc,nodebug,nogasp,notv,dynamicthreads $");
GASNETT_IDENT(UPCRI_IdentString_pgen_o_1525558169_translatetime, 
 "$UPCTranslateTime: (pgen.o) Sat May  5 15:09:29 2018 $");
GASNETT_IDENT(UPCRI_IdentString_pgen_o_1525558169_GASNetConfig_obj, 
 "$GASNetConfig: (pgen.o) " GASNET_CONFIG_STRING " $");
GASNETT_IDENT(UPCRI_IdentString_pgen_o_1525558169_UPCRConfig_obj,
 "$UPCRConfig: (pgen.o) " UPCR_CONFIG_STRING UPCRI_THREADCONFIG_STR " $");
GASNETT_IDENT(UPCRI_IdentString_pgen_o_1525558169_translator, 
 "$UPCTranslator: (pgen.o) /usr/local/upc/2.26.0/translator/install/targ (aphid) $");
GASNETT_IDENT(UPCRI_IdentString_pgen_o_1525558169_upcver, 
 "$UPCVersion: (pgen.o) 2.26.0 $");
GASNETT_IDENT(UPCRI_IdentString_pgen_o_1525558169_compileline, 
 "$UPCCompileLine: (pgen.o) /usr/local/upc/2.26.0/runtime/inst/bin/upcc.pl --at-remote-http -translator=/usr/local/upc/2.26.0/translator/install/targ --arch-size=64 --network=ofi --pthreads 2 --lines --trans --sizes-file=upcc-sizes pgen.i $");
GASNETT_IDENT(UPCRI_IdentString_pgen_o_1525558169_compiletime, 
 "$UPCCompileTime: (pgen.o) " __DATE__ " " __TIME__ " $");
#ifndef UPCRI_CC /* ensure backward compatilibity for http netcompile */
#define UPCRI_CC <unknown>
#endif
GASNETT_IDENT(UPCRI_IdentString_pgen_o_1525558169_backendcompiler, 
 "$UPCRBackendCompiler: (pgen.o) " _STRINGIFY(UPCRI_CC) " $");

#ifdef GASNETT_CONFIGURE_MISMATCH
  GASNETT_IDENT(UPCRI_IdentString_pgen_o_1525558169_configuremismatch, 
   "$UPCRConfigureMismatch: (pgen.o) 1 $");
  GASNETT_IDENT(UPCRI_IdentString_pgen_o_1525558169_configuredcompiler, 
   "$UPCRConfigureCompiler: (pgen.o) " GASNETT_PLATFORM_COMPILER_IDSTR " $");
  GASNETT_IDENT(UPCRI_IdentString_pgen_o_1525558169_buildcompiler, 
   "$UPCRBuildCompiler: (pgen.o) " PLATFORM_COMPILER_IDSTR " $");
#endif

/**************************************************************************/
GASNETT_IDENT(UPCRI_IdentString_pgen_o_1525558169_transver_2,
 "$UPCTranslatorVersion: (pgen.o) 2.26.0, built on Aug 31 2017 at 17:02:50, host aphid linux-x86_64/64, gcc v4.2.4 (Ubuntu 4.2.4-1ubuntu4) $");
GASNETT_IDENT(UPCRI_IdentString_INIT_pgen_6953898206118,"$UPCRInitFn: (pgen.trans.c) UPCRI_INIT_pgen_6953898206118 $");
GASNETT_IDENT(UPCRI_IdentString_ALLOC_pgen_6953898206118,"$UPCRAllocFn: (pgen.trans.c) UPCRI_ALLOC_pgen_6953898206118 $");
