#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/slab.h>

struct birthday 
{	
	int month;
	int day;
	int year;
    char *name;
    struct list_head list;
};

/**
 * The following defines and initializes a list_head object named birthday_list
 */
static LIST_HEAD(birthday_list);

int simple_init(void)
{
   
    /* Create a linked list containing five struct birthday elements*/
    
    /* NOTE:THE NAME OF FIRST STRUCT BIRTHDAY SHOULD BE YOUR OWN NAME
     
    ///////////Add your codes here......
     
     
    
    /* Traverse the linked list  */
    
    //Add codes here......
    
    return 0;
}

void simple_exit(void) {
    
    /* Remove the elements from the linked list and return the free memory back to the kernel */
    
    //////////Add your codes here....
    
}

module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Kernel Data Structures");
MODULE_AUTHOR("SGG");

