#include <string.h>
#include "ring_queue.h"

typedef int rt_base_t;

static rt_base_t rt_hw_interrupt_disable(void)
{
    return 0;
}
static void rt_hw_interrupt_enable(rt_base_t l)
{

}

static RingQueue_Ret Queue_Enqueue(RingQueue_t queue, void *data)
{
	rt_base_t level;

	if(NULL == queue || data == NULL) return -RingQueueErr;
	
	level = rt_hw_interrupt_disable();
	
	if (queue->size >= queue->queue_size) 
	{
        rt_hw_interrupt_enable(level);
		//debug(Debug_Warning, "Warning:RingQueue full!\r\n");
        //cout << "ring queue full" << endl;
		return -RingQueueFull;
	}

	queue->size++;
	memcpy(queue->buf + ((queue->front + queue->size) % queue->queue_size) * queue->data_size, 
	    data, queue->data_size);	

	rt_hw_interrupt_enable(level);

	return RingQueueOK;
}

static void Queue_Remove_Head(RingQueue_t queue)
{
	rt_base_t level;

	if(NULL == queue) return;

	level = rt_hw_interrupt_disable();
	
	if (queue->size == 0) 
	{
		rt_hw_interrupt_enable(level);
		return;
	}

    queue->front = (queue->front + 1) % queue->queue_size;
    memset(queue->buf + queue->front * queue->data_size, 0, queue->data_size);
	if(queue->size > 0)
	{
		queue->size--;
	}
	rt_hw_interrupt_enable(level);
}

static void Queue_Remove_Tail(RingQueue_t queue)
{
	rt_base_t level;

	if(NULL == queue) return;

	level = rt_hw_interrupt_disable();
	
	if (queue->size == 0)
	{
		rt_hw_interrupt_enable(level);
		return;
	}

	memset(queue->buf + ((queue->front+queue->size)%queue->queue_size) * queue->data_size, 
	    0, queue->data_size);
	if(queue->size > 0)
	{
		queue->size--;
	}
    rt_hw_interrupt_enable(level);

}

static void *Queue_Get_Head(RingQueue_t queue)
{
	rt_base_t level;
	unsigned char *p = NULL;
	
	if(NULL == queue) return NULL;

	level = rt_hw_interrupt_disable();
	
	if (queue->size == 0) 
	{
        rt_hw_interrupt_enable(level);
        return NULL;
	}

	p = queue->buf + ((queue->front+1)%queue->queue_size) * queue->data_size;
	
	rt_hw_interrupt_enable(level);

	return (p);
}

static void *Queue_Get_Tail(RingQueue_t queue)
{
	rt_base_t level;
	unsigned char *p = NULL;
	
	if(NULL == queue) return NULL;

	level = rt_hw_interrupt_disable();
	
	if (queue->size == 0) 
	{
        rt_hw_interrupt_enable(level);
        return NULL;
	}

	p = queue->buf + ((queue->front+queue->size)%queue->queue_size) * queue->data_size;
	
	rt_hw_interrupt_enable(level);

	return (p);
}


//获取队列长度
RingQueue_Ret Queue_Get_Size(RingQueue_t queue)
{
	rt_base_t level;
	int n = 0;

    if(queue)
    {
    	level = rt_hw_interrupt_disable();
    	n = queue->size;
    	rt_hw_interrupt_enable(level);
    }
    
	return n;    //((queue->rear-queue->front+queue->queue_size) % queue->queue_size);
}

static void *Queue_Get_Index(RingQueue_t queue, unsigned char index)
{
	rt_base_t level;
	unsigned char *pData = NULL;

	if(queue)
	{
    	level = rt_hw_interrupt_disable();

    	if(index < 1) 
    	{
    		rt_hw_interrupt_enable(level);
    		return NULL;
    	}

    	if(index <= queue->size)
    	{
    		pData = queue->buf + ((queue->front+index)%queue->queue_size) * queue->data_size;
    	}

    	rt_hw_interrupt_enable(level);
    }
    
	return pData;
}

void RingQueue_Init(RingQueue_t queue)
{
	if(queue) 
	{
	    queue->front = queue->size = 0;
	    
		queue->enqueue       = Queue_Enqueue;
		queue->get_size      = Queue_Get_Size;
		queue->get_head      = Queue_Get_Head;
		queue->get_tail      = Queue_Get_Tail;
		queue->get_index     = Queue_Get_Index;
		queue->remove_head   = Queue_Remove_Head;
		queue->remove_tail   = Queue_Remove_Tail;
	}
}

