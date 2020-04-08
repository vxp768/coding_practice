https://courses.engr.illinois.edu/cs241/sp2014/mp/mp2/html/

/*
 * A bad malloc Memory allocation might seem a bit magical. 
 * But you might be surprised to find out how easy it is to write a memory allocator which 
 * actually works in some primitive way. Let's do it now. First, malloc():

void *malloc(size_t size)
{
  return sbrk(size);
}
 * How does that work? Malloc gets a request for size bytes of memory. 
 * It then calls sbrk(size). This is a system call that asks the operating system to 
 * increase the heap by size bytes. sbrk() returns a pointer to this new memory, and away we go. Now, how about free?

void free(void *ptr)
{
}
 * That's right! It's empty. In a very limited way, this is a "correct" implementation. 
 * You could write programs that use this malloc and free. 

*/
typedef struct _mem_dictionary
{
  void *addr;
  size_t size;
} mem_dictionary;

mem_dictionary *dictionary = NULL;
int dictionary_ct = 0;

void *malloc(size_t size)
{
  void *return_ptr = sbrk(size);
 
  if (dictionary == NULL)
    dictionary = sbrk(1024 * sizeof(mem_dictionary)); /* Note the use of sbrk() and not malloc(), since malloc() would create an infinite loop of calling malloc(). */
  dictionary[dictionary_ct].addr = return_ptr;
  dictionary[dictionary_ct].size = size;
  dictionary_ct++;
 
  return return_ptr;
}

void *realloc(void *ptr, size_t size)
{
  if (!size) { free(ptr); return NULL; }
 
  void *return_ptr = malloc(size);
 
  if (!ptr)
    return return_ptr;
 
  size_t old_size = 0;
  int i;
  for (i = 0; i < dictionary_ct; i++)
    if (dictionary[i].addr == ptr)
      old_size = dictionary[i].size;
 
  memcpy(return_ptr, ptr, old_size);
  free(ptr);
 
  return return_ptr;
}
