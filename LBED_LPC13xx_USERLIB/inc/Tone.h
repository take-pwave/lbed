#ifndef TONE_H
#define TONE_H

#include "lbed.h"


class Tone
{
public:
  /*!
  Arduinoのtone関数ライクなクラスをPwmOutを使って作成したクラス
  */
  Tone(PinName pin);

  /*!
  Destroys instance.
  */
  ~Tone() {
	  noTone();
  }

  /*!
  指定された周波数のトーンを出力する
  */
  void tone(unsigned int frequency);
  /*!
   指定された周波数のトーンをduration(ミリ秒)で指定された時間出力する
   */
  void tone(unsigned int frequency, unsigned long duration);
  /*!
   出力を停止する
   */
  void noTone();

private:
  PwmOut	_out;

};

#endif
