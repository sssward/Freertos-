#include "task_init.h"

//队列
QueueHandle_t queue_1;
QueueHandle_t queue_2;

//队列集合
QueueSetHandle_t queueSet_1;

//事件组
EventGroupHandle_t eventGroup_1;

//二值信号量 & 计数信号量 & 互斥锁
SemaphoreHandle_t xBinary_1;      //二值
SemaphoreHandle_t xCounting_1;    //计数
SemaphoreHandle_t xMutex_1;       //互斥锁

//任务
TaskHandle_t task_1;
TaskHandle_t task_2;

void tskt_init(void)
{
    BaseType_t retval;

    //初始化队列
    queue_1 = xQueueCreate(10, sizeof(int32_t));
    _CHECK(queue_1);

    queue_2 = xQueueCreate(20, sizeof(int32_t));
    _CHECK(queue_2);

    //初始化队列集
    queueSet_1 = xQueueCreateSet(10 + 20);
	_CHECK(queueSet_1);
    retval = xQueueAddToSet(queue_1,queueSet_1);
    _CHECK(retval);
    retval = xQueueAddToSet(queue_2,queueSet_1);
    _CHECK(retval);

    //初始化事件组
    eventGroup_1 = xEventGroupCreate();
    _CHECK(eventGroup_1);

    //初始化二值信号量 & 计数信号量 & 互斥锁
    xBinary_1 = xSemaphoreCreateBinary();
    _CHECK(xBinary_1);
    xCounting_1 = xSemaphoreCreateCounting(3, 3);
    _CHECK(xCounting_1);
    xMutex_1 = xSemaphoreCreateMutex();
    _CHECK(xMutex_1);

    //初始化任务
    retval = xTaskCreate(task_task1, "task1", configMINIMAL_STACK_SIZE, NULL, 3, &task_1);
    _CHECK(retval);

    retval = xTaskCreate(task_task2, "task2", configMINIMAL_STACK_SIZE, NULL, 3, &task_2);
    _CHECK(retval);

    //开启调度器
    vTaskStartScheduler();
}
