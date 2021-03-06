#include <linux/capability.h>
#include <linux/hash.h>
#include <linux/kernel_stat.h>
#include <linux/percpu.h>
#include <linux/rcupdate.h>

// kernel/capability.c
bool capable(int cap)
{
	return false;
}

// kernel/locking/mutex.c

void
__mutex_init(struct mutex *lock, const char *name, struct lock_class_key *key)
{
	atomic_set(&lock->count, 1);
	spin_lock_init(&lock->wait_lock);
	INIT_LIST_HEAD(&lock->wait_list);
	// mutex_clear_owner(lock);
	// debug_mutex_init(lock, name, key);
}
EXPORT_SYMBOL(__mutex_init);

void mutex_lock(struct mutex *lock)
{
}

void mutex_unlock(struct mutex *lock)
{
}

// kernel/sched/core.c
void resched_cpu(int cpu)
{
}


DEFINE_PER_CPU(struct kernel_stat, kstat);
DEFINE_PER_CPU(struct kernel_cpustat, kernel_cpustat);

EXPORT_PER_CPU_SYMBOL(kstat);
EXPORT_PER_CPU_SYMBOL(kernel_cpustat);

#define WAIT_TABLE_BITS 8
#define WAIT_TABLE_SIZE (1 << WAIT_TABLE_BITS)
static wait_queue_head_t bit_wait_table[WAIT_TABLE_SIZE] __cacheline_aligned;

wait_queue_head_t *bit_waitqueue(void *word, int bit)
{
	const int shift = BITS_PER_LONG == 32 ? 5 : 6;
	unsigned long val = (unsigned long)word << shift | bit;

	return bit_wait_table + hash_long(val, WAIT_TABLE_BITS);
}
EXPORT_SYMBOL(bit_waitqueue);

// kernel/sched/wait.c

void wake_up_bit(void *word, int bit)
{
	printk("wake_up_bit\n");
}

// kernal/signal.c
long do_no_restart_syscall(struct restart_block *param)
{
	return -EINTR;
}

// kernel/time/timekeeping.c
ktime_t ktime_get_with_offset(enum tk_offsets offs)
{
	ktime_t kt = { 0 };
	return kt;
}

unsigned long get_seconds(void)
{
	// panic("get_seconds");
	return 1234567890;
}

void getnstimeofday64(struct timespec64 *ts)
{
	panic("getnstimeofday64");
}
