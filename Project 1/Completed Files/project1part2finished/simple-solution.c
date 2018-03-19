#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/slab.h>

struct birthday 
{	
	char *name;
	int month;
	int day;
	int year;
	struct list_head list;
};

/**
 * The following defines and initializes a list_head object named birthday_list
 */
static LIST_HEAD(birthday_list);

int simple_init(void)
{
   
	printk(KERN_INFO "Loading Module\n");
	/* Create a linked list containing five struct birthday elements*/
    
	/* NOTE:THE NAME OF FIRST STRUCT BIRTHDAY SHOULD BE YOUR OWN NAME */

	struct birthday *person1;
	struct birthday *person2;
	struct birthday *person3;
	struct birthday *person4;
	struct birthday *person5;
	
	//first element
	person1=kmalloc(sizeof(*person1),GFP_KERNEL);
	person1->name="Jimmy Tran";
	person1->month=1;
	person1->day=2;
	person1->year=1000;
	INIT_LIST_HEAD(&person1->list);   
	
	//second element
	person2=kmalloc(sizeof(*person2),GFP_KERNEL);
	person2->name="John";
	person2->month=3;
	person2->day=4;
	person2->year=1001;
	INIT_LIST_HEAD(&person2->list);   
	
	//third element
	person3=kmalloc(sizeof(*person3),GFP_KERNEL);
	person3->name="Jack";
	person3->month=5;
	person3->day=6;
	person3->year=1002;
	INIT_LIST_HEAD(&person3->list);   
	
	//fourth element
	person4=kmalloc(sizeof(*person4),GFP_KERNEL);
	person4->name="Jill";
	person4->month=7;
	person4->day=8;
	person4->year=1003;
	INIT_LIST_HEAD(&person4->list);   

	//fifth element
	person5=kmalloc(sizeof(*person5),GFP_KERNEL);
	person5->name="Joe";
	person5->month=9;
	person5->day=10;
	person5->year=1004;
	INIT_LIST_HEAD(&person5->list);   

	//build linked list
	list_add_tail(&person1->list,&birthday_list);
	list_add_tail(&person2->list,&birthday_list);
	list_add_tail(&person3->list,&birthday_list);
    	list_add_tail(&person4->list,&birthday_list);
    	list_add_tail(&person5->list,&birthday_list);

	/* Traverse the linked list  */
	
	struct birthday *ptr;
	list_for_each_entry(ptr,&birthday_list,list){
		/* on each iteration ptr points */
		/* to the next birthday struct */
		printk(KERN_INFO "Name: %s Birthday: Month %d Day %d Year %d\n",ptr->name,ptr->month,ptr->day,ptr->year);	
	}

	return 0;
}

void simple_exit(void) {

	/* Remove the elements from the linked list and return the free memory back to the kernel */
	printk(KERN_INFO "Removing Module\n");
	struct birthday *ptr,*next;
	list_for_each_entry_safe(ptr, next, &birthday_list,list){
		/* on each iteration ptr points */
		/* to the next birthday struct */
		printk(KERN_INFO "Name: %s Birthday: Month %d Day %d Year %d\n",ptr->name,ptr->month,ptr->day,ptr->year);
		list_del(&ptr->list);
		kfree(ptr);
	}

}

module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Kernel Data Structures");
MODULE_AUTHOR("SGG");

