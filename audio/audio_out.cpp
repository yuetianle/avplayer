#include "ins.h"
#include "wave_render.h"
#include "dsound_render.h"
#include "audio_out.h"


#ifdef  __cplusplus
extern "C" {
#endif

EXPORT_API int wave_init_audio(void** ctx, uint32_t channels,
	uint32_t bits_per_sample, uint32_t sample_rate, int format)
{
   wave_render* wave = new wave_render;
   *ctx = wave;
   return wave->init_audio((void*)wave, channels, bits_per_sample, sample_rate, format) ? 0 : -1;
}

EXPORT_API int wave_play_audio(void* ctx, uint8_t* data, uint32_t size)
{
   wave_render* wave = (wave_render*)ctx;
   return wave->play_audio(data, size);
}

EXPORT_API void wave_audio_control(void* ctx, double vol)
{
   wave_render* wave = (wave_render*)ctx;
	control_vol_t ctrl_vol = { vol, vol };
   wave->audio_control(CONTROL_SET_VOLUME, &ctrl_vol);
}

EXPORT_API void wave_destory_audio(void* ctx)
{
   wave_render* wave = (wave_render*)ctx;
   if (wave)
   {
      wave->destory_audio();
      delete wave;
   }
}


EXPORT_API int dsound_init_audio(void** ctx, void* user_data,
	uint32_t channels, uint32_t bits_per_sample, uint32_t sample_rate, int format)
{
   dsound_render* dsound = new dsound_render;
   *ctx = dsound;
   return dsound->init_audio((void*)dsound, channels, bits_per_sample, sample_rate, format) ? 0 : -1;
}

EXPORT_API int dsound_play_audio(void* ctx, uint8_t* data, uint32_t size)
{
   dsound_render* dsound = (dsound_render*)ctx;
   return dsound->play_audio(data, size);
}

EXPORT_API void dsound_audio_control(void* ctx, double vol)
{
   dsound_render* dsound = (dsound_render*)ctx;
	control_vol_t ctrl_vol = { vol, vol };
	dsound->audio_control(CONTROL_SET_VOLUME, &ctrl_vol);
}

EXPORT_API void dsound_destory_audio(void* ctx)
{
   dsound_render* dsound = (dsound_render*)ctx;
   if (dsound)
   {
      dsound->destory_audio();
      delete dsound;
   }
}

#ifdef  __cplusplus
}
#endif

