#ifndef __RINGBUFFER_H__
#define __RINGBUFFER_H__

template<typename T, typename Tbig, unsigned int N>
class RingBuffer
{
  unsigned int position = 0;
  unsigned int fillLevel = 0;
  T buffer[N] = {0};
public:
  void insert(T val)
  {
    buffer[position++]=val;
    if(position>=N)
    {
      position = 0;
    }
    if(fillLevel<N)fillLevel++;
  }
  T get()
  {
    Tbig sum = 0;
    if(fillLevel==0)return 0;
    for(unsigned int i=0;i<fillLevel;++i)
    {
      sum+=buffer[i];
    }
    return((T)sum/fillLevel);
  }
  void clear()
  {
    position = 0;
    fillLevel = 0;
  }

};
#endif/*__RINGBUFFER_H__*/
