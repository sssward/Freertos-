#ifndef _TASK_INIT_H
#define _TASK_INIT_H

#include "task_app.h"

#define _CHECK(val) do{if(!(val)){while(1);}}while(0)

void task_init(void);

#endif
