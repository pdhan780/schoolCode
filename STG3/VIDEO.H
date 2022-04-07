#ifndef VIDEO_H
#define VIDEO_H

#include "types.h"






/*replace the Physbase call*/
UINT16* get_video_base();


/*replace the setscreen call*/
void set_video_base(UINT16* base);





#endif
