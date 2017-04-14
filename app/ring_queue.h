#ifndef RING_QUEUE_H
#define RING_QUEUE_H
	 
#ifdef __cplusplus
	 extern "C" {
#endif

#define	RingQueueOK     0
#define RingQueueErr    1
#define	RingQueueFull   2 
#define	RingQueueEmpty  3	

typedef int RingQueue_Ret;

typedef struct _RingQueue RingQueue;
typedef struct _RingQueue* RingQueue_t;
struct _RingQueue
{	
	unsigned char data_size;    //���ݵ�Ԫ����
	unsigned char queue_size;   //���г���
	//unsigned short buf_len;     //buf_len = queue_size * data_size
	unsigned char *buf;

    unsigned int front;         //��ͷָ�� ��βָ��=(front+size)%MAX_ICSQUEUE
	unsigned int size;          //�������ݵ�Ԫ����
	
	RingQueue_Ret (*enqueue)(RingQueue_t queue, void *data); 
	RingQueue_Ret (*get_size)(RingQueue_t queue);
	void *        (*get_head)(RingQueue_t queue);
	void *        (*get_tail)(RingQueue_t queue);
	void *        (*get_index)(RingQueue_t queue, unsigned char index);
	
	void          (*remove_head)(RingQueue_t queue);
	void          (*remove_tail)(RingQueue_t queue);
};


#define RingQueue_Get_Size(queue)      ((queue).get_size(&(queue)))
#define RingQueue_EnQueue(queue, data) ((queue).enqueue(&(queue), data))
#define RingQueue_Get_Head(queue)      ((queue).get_head(&(queue)))
#define RingQueue_Get_Tail(queue)      ((queue).get_tail(&(queue)))
#define RingQueue_Get_Index(queue, id) ((queue).get_index(&(queue), id))
#define RingQueue_Remove_Head(queue)   ((queue).remove_head(&(queue)))
#define RingQueue_Remove_Tail(queue)   ((queue).remove_tail(&(queue)))

void RingQueue_Init(RingQueue_t queue);

#ifdef __cplusplus
}
#endif

#endif




