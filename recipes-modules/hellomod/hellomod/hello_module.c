/*
######################################################
#  ****************************************
#  Hello Module example                   \
#  Using Yocto                            /
#                                         \
#                                         /
#  Alejandro Enedino Hernandez Samaniego  \
#  alejandro.hernandez@linux.intel.com    /
#  alejandro.hernandez@intel.com          \
#  aehs29@ieee.org                        /
#  ****************************************
######################################################
*/

/* __init & __exit */
#include <linux/init.h>

#include <linux/module.h>
#include <linux/kernel.h>

/* For modinfo */
MODULE_AUTHOR("Alejandro Hernandez");
MODULE_DESCRIPTION("Example Linux Module");
MODULE_VERSION("1.0");

/* Necessary */
MODULE_LICENSE("GPL");

/* Specify a parameter and default value */
static char *name = "Yocto";

/* Char pointer, world readable */
module_param(name, charp, S_IRUGO);
MODULE_PARM_DESC(name, "dmesg parameter");

static int __init hello_init(void){
   printk(KERN_INFO "Yocto Module: Hello %s!\n", name);
   return 0;
}

static void __exit hello_exit(void){
   printk(KERN_INFO "Yocto Module: Buh Bye %s\n", name);
}

/* Declare module initialization and exit functions */
module_init(hello_init);
module_exit(hello_exit);
