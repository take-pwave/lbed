// リンクエラーのためダミー関数を定義
// 以下の2つの関数は、ARM例外処理の一部とのことで、以下のURLを参考にダミーとした
// http://lists.linaro.org/pipermail/linaro-toolchain/2011-September/001675.html
extern "C"
void __aeabi_unwind_cpp_pr1(void){}
extern "C"
void __aeabi_unwind_cpp_pr0(void){}
// ねむいさんのsyscalls_if.hからよばれるので、ここでダミーを定義
extern "C"
void putch(int x){}
extern "C"
int getch(){ return -1; }
// __libc_init_arrayから呼ばれる_initは、起動時に呼ばれる関数とあるので、これもダミーを定義
extern "C"
void _init(void){}

#ifdef DEBUG
void
__error__(char *pcFilename, unsigned long ulLine)
{
//
// Something horrible happened! You need to look
// at file "pcFilename" at line "ulLine" to see
// what error is being reported.
//
while(1)
{
}
}
#endif
