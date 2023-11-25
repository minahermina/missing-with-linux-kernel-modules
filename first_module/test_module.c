#include <linux/hash.h>
#include <linux/jiffies.h>
#include <linux/gcd.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <asm/uaccess.h>
#include <asm/param.h>

int _init(void) {
    // printk(KERN_INFO "First module!\n");
    // printk(KERN_INFO "%lu\n", jiffies); // number of timer interrupts that have occurred since the system was booted
    // printk(KERN_INFO "%lu\n", HZ); // tick rate 
    return 0;
}

void _exit(void) {
    printk(KERN_INFO "%lu\n", gcd(3300, 24));
}

module_init(_init);
module_exit(_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mina");
MODULE_DESCRIPTION("Simple kernel module");
MODULE_VERSION("1.0");

