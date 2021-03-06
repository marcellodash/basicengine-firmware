#include <stdio.h>
#if defined(UNIFILE_USE_SDFAT) && defined(__cplusplus)
// messes with our macros, have to include it first
#include <SdFat.h>
#endif

#ifndef EOF
#define EOF (-1)
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef void DIR;

FILE *_fopen(const char *path, const char *mode);
int _fclose(FILE *stream);
size_t _fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
size_t _fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
int _fputs(const char *s, FILE *stream);
int _fseek(FILE *stream, int offset, int whence);
long _ftell(FILE *stream);
int _feof(FILE *stream);
int _getc(FILE *stream);
int _ungetc(int c, FILE *stream);
int _putc(int c, FILE *stream);
int _fflush(FILE *stream);
int _ferror(FILE *stream);
void _clearerr(FILE *stream);

struct dirent {
  unsigned char d_type;
  char d_name[64]; /* filename */
};

#define DT_DIR 4
#define DT_REG 8

DIR *_opendir(const char *name);
int _closedir(DIR *dir);
struct dirent *_readdir(DIR *dir);

int _remove(const char *pathname);
int _rename(const char *oldpath, const char *newpath);

int _chdir(const char *path);
char *_getcwd(char *buf, size_t size);

struct stat {
  mode_t st_mode;
  off_t st_size;
};

#define S_IFDIR 0040000
#define S_IFREG 0100000

int _stat(const char *pathname, struct stat *buf);

int _mkdir(const char *pathname, mode_t mode);
int _rmdir(const char *pathname);

#ifdef __cplusplus
}
#endif

#define fopen  _fopen
#define fclose _fclose
#define fread  _fread
#define fwrite _fwrite
#define fputs  _fputs
#define fseek  _fseek
#define ftell  _ftell
#define feof   _feof
#undef getc
#define getc   _getc
#define ungetc _ungetc
#undef putc
#define putc     _putc
#define fflush   _fflush
#define ferror   _ferror
#define clearerr _clearerr
