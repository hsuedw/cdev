#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/sched.h>
#include <linux/mm.h>
#include <asm/uaccess.h>

#define MAJOR_NUM ( 121 )
#define DRV_NAME  "cdev"

int cdev_open( struct inode *inode, struct file *filp )
{
    return 0;
}

int cdev_release( struct inode *inode, struct file *filp )
{
    return 0;
}

static struct file_operations cdev_fops = {
    open:    cdev_open,
    release: cdev_release,
};

int cdev_init( void )
{
    printk( KERN_INFO "%s: Hello Edward\n", DRV_NAME );

    if ( register_chrdev( MAJOR_NUM, DRV_NAME, &cdev_fops ))
    {
        printk( KERN_ALERT "%s: Cannot register cdev in kernel.\n", DRV_NAME );
    }

    return 0;
}

void cdev_exit( void )
{
    unregister_chrdev( MAJOR_NUM, DRV_NAME );

    printk( KERN_INFO "%s: Goodbye Edward\n", DRV_NAME );
}

module_init( cdev_init );
module_exit( cdev_exit );


MODULE_LICENSE( "GPL" );

