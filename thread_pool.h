#ifndef THREAD_POOL_GUARD
#define THREAD_POOL_GUARD

#define TRUE 1
#define FALSE 0

ThreadPool* CreateThreadPool();
void DestroyThreadPool(ThreadPool* pool);
void EnqueueJob(ThreadPool* pool, Job* job);
void ExecuteJobs(ThreadPool* pool);
int IsThreadPoolActive(ThreadPool* pool);
int GetNumberOfRemainingJobs(ThreadPool* pool);

#endif
