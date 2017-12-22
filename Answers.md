1. I'd say that the answer is *(a)*.  If the different processes are allocated memory then it shouldn't be able 
   to collide with other processes.  Also, since the processes are ordered, I'd assume that the allocation would 
   allocate the memory blocks in a orderly way, the easiest being starting from 0 and moving up by block of a
   certain size.
   
2. **Possible States:**
   a. **New:**
      A successfully created process that has yet to be accepted or delayed by the scheduler and queued and given 
      a "ready" state.
      
   b. **Ready:**
      This is the state where most processes that are just waiting to have their share of time to run instruc-
      -tions. At it's simplest, it's a single queue or non-blocking processes. A normal ready state could 
      involved being put in any one of several queues in some sort of priority order determined by the system.
      It might even involve moving down to a lower priority on a set of circumstances, likely to be how long 
      it takes to finish the process.
      
   c. **Running:**
      This state is where a process would have an alloted time, a quantum, to run as many instructions as it 
      could in the processor.  If it is a multi-processor system then it might be assigned to one of several 
      processors to run concurrently besides other processes in other processors.
      In this state, it's possible, depending on the system, to have several states associated with it. It 
      could be at a user level state or kernal level. A kernal level state is for a reserved set of processes 
      that can then access the kernal, all memory and instructions that a user processes in it's own 
      memory space wouldn't normally have access to.
      
   d. **Blocked:**
      When a processes is blocked, it's because it has to access some resource outside of it's processes that 
      it couldn't carry on without. It could be an IO port, or some system device that it needs exclusive 
      access to. It would request a blocked state change and be moved to some sort of blocking queue that the 
      scheduler would check before it runs down the different queues of non-blocking or ready processes. It has 
      it's own alloted quantum in the blocking queue as well and once it's done it would be moved back to a 
      ready state.
      
   e. **Terminated:**
      A terminated process is a process that, for one reason or another, has finished it's running tasks or has 
      been killed or exited in some way.  It's not gone, though, because it has a final state or result that 
      it waits for the process that initialized it to read before it's removed from the queue finally. If this 
      does not happen then it sits as a zombie process, stil holding it's memory and being checked on even 
      though there is nothing for it to do.
      
3.    Issues with running code completely.  Will come back if I have time.
      ******

4.   I would imagine that printf, being a tool designed to do a limited and specific set of functions and then 
     pass that output onto the write call, would optimize the information that it sends to write rather than 
     having write do any guessing to process it.