// リンクエラーのためダミー関数を定義
// 以下の2つの関数は、ARM例外処理の一部とのことで、以下のURLを参考にダミーとした
// http://lists.linaro.org/pipermail/linaro-toolchain/2011-September/001675.html
extern "C"
void __aeabi_unwind_cpp_pr1(void){}
extern "C"
void __aeabi_unwind_cpp_pr0(void){}

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
