#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/kthread.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");

static struct task_structthread1;
static struct task_struct thread2;

static struct mutex mutex1;
static struct mutex mutex2;

static int thread_func1(voiddata)
{
    mutex_lock(&mutex1);
    printk(KERN_INFO "Thread 1 acquired mutex1\n");
    msleep(1000);  // Simulate some work
    mutex_lock(&mutex2);  // Try to acquire mutex2
    printk(KERN_INFO "Thread 1 acquired mutex2\n");
    mutex_unlock(&mutex2);
    mutex_unlock(&mutex1);

    return 0;
}

static int thread_func2(void *data)
{
    mutex_lock(&mutex2);
    printk(KERN_INFO "Thread 2 acquired mutex2\n");
    msleep(1000);  // Simulate some work
    mutex_lock(&mutex1);  // Try to acquire mutex1
    printk(KERN_INFO "Thread 2 acquired mutex1\n");
    mutex_unlock(&mutex1);
    mutex_unlock(&mutex2);

    return 0;
}

static int init deadlock_init(void)
{
    mutex_init(&mutex1);
    mutex_init(&mutex2);

    thread1 = kthread_run(thread_func1, NULL, "thread1");
    thread2 = kthread_run(thread_func2, NULL, "thread2");

    return 0;
}

static void exit deadlock_exit(void)
{
    kthread_stop(thread1);
    kthread_stop(thread2);
    mutex_destroy(&mutex1);
    mutex_destroy(&mutex2);
}

module_init(deadlock_init);
module_exit(deadlock_exit);
