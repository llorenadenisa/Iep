#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

static int __init helloTest_start(void)
{
        printk(KERN_INFO "Hello this is a test\n");
        return 0;
}

static void __exit helloTest_end(void)
{
        printk(KERN_INFO "Bye, test succeeded\n");
}

module_init(h_init);
module_exit(h_exit);