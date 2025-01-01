#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int __init _init(void) {
    printk(KERN_INFO "First module!\n");
    return 0;
}

static void __exit _exit(void) {
    printk(KERN_INFO "bye!\n");
}

module_init(_init);
module_exit(_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mina");
MODULE_DESCRIPTION("Simple kernel module");
MODULE_VERSION("1.0");
