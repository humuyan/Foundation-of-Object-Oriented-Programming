1. 如果直接修改全局的counts可能会有多个线程同时争相修改数据，导致修改不成功；如果使用互斥锁则每次修改都需要加锁、解锁，效率不如先保存到local_counts最后一次性加锁、修改、解锁
2. 如果不加锁可能会有多个线程争相修改counts，导致修改不成功
