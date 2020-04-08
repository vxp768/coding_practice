/*
 * allocate memory aligned with given alignment
 * 
 */
void *aligned_malloc(size_t bytes, size_t alignment) {
void *p1 ,*p2;

//p1 returned by malloc will be maximum off by alignment bytes.
p1 = (void *) malloc(bytes + alignment + sizeof(size_t));

if(p1==NULL)
    return NULL;

/* advance p1 by align+sizeof(ptr) */
size_t addr= (size_t)p1 + alignment + sizeof(size_t);

/* subtract remainder ... its guaranteed that there is enough headroom as 
 * that much more memory was allocated */
p2=(void *)(addr - (addr%alignment));

/* Store orignal pointer in header */
*((size_t *)p2-1)=(size_t)p1;

return p2;
}

void aligned_free(void *p )
{
/* fetch original pointer from header and free it */
free((void *)(*((size_t *) p-1)));
}

// If align is power of 2
#define align_up(num, align) \
    (((num) + ((align) - 1)) & ~((align) - 1))