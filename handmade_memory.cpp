/*
// // // // // // // // // // // // // // // // // // // // // // // // //  

 Notice: (C) Copyright 2024 by Kat Mwenesongole. All Rights Reserved.

// // // // // // // // // // // // // // // // // // // // // // // // // 
*/
#pragma once

//
// STANDARD ALLOCATOR IMPLEMENTATION
//
struct memory_entry
{
    memory_entry* next;
    
    void* base;
    u32   size; // @ does not include the structure.
    b32   used;
};

struct memory_struct
{
    void* base;
    void*  end;
    u32   size;
    u32   used;
};

// // INTERNAL.

internal memory_entry* memory_find_vacant      (memory_struct* Memory, u32 size)
{
    memory_entry* entry = (memory_entry*)Memory->base;
    while(entry)
    {
	// @ is this vacant?
	if(!entry->used)
	{
	    // @ is there enough space?
	    if(entry->size >= size)
	    {
		return(entry); // @ here is some data.
	    }
	}
	entry = entry->next;
    }
    return(0);
}
internal memory_entry* memory_find_entry       (memory_struct* Memory, void* base)
{
    memory_entry* entry = (memory_entry*)Memory->base;
    while(entry)
    {
	if(entry->base == base) { return(entry); } // @ are the pointers the same?
	entry = entry->next;
    }
    return(0);
}
internal memory_entry* memory_find_entry_before(memory_struct* Memory, void* base)
{
    memory_entry* entry = (memory_entry*)Memory->base;
    while(entry)
    {
	if(entry->next)
	{
	    if(entry->next->base == base)
	    {
		return(entry);
	    }
	}
	entry = entry->next;
    }
    return(0);
}

// // EXTERNAL.

internal void* MEM_GET_SPACE(memory_struct* Memory, u32 size)
{
    // @ are there any vacant slots?
    memory_entry* entry = memory_find_vacant(Memory, size);
    
    if(entry)
    {
	// @ does it fit perfectly?
	if(entry->size != size)
	{
	    // @ create a new entry for the remainder.
	    
	    u32 sub_size = entry->size - size;

	    memory_entry* sub_entry = (memory_entry*)((u8*)entry->base + size);
	    sub_entry->size = sub_size - sizeof(memory_entry);
	    sub_entry->base = (u8*)sub_entry + sizeof(memory_entry);
	    sub_entry->next = entry->next;
	    sub_entry->used = 0;

	    // @ update entry
	    entry->size = size;
	    entry->next = sub_entry;
	}
	
	entry->used = true;
	
	return(entry->base); // @ here is some data
    }
    else
    {
	// @ increase the used and create new entry

	if((Memory->used + size + sizeof(memory_entry)) <= Memory->size) // @ is there enough space
	{
	    entry = (memory_entry*)((u8*)Memory->base + Memory->used);

	    entry->size = size;
	    entry->base = (u8*)entry + sizeof(memory_entry);
	    entry->next = 0;
	    entry->used = true;

	    Memory->used += size + sizeof(memory_entry);

	    if((memory_entry*)Memory->end != entry)
	    {
		((memory_entry*)Memory->end)->next = entry;
		Memory->end = entry;
	    }

	    return(entry->base);
	}
	ASSERT(0);
    }
    
    return(0);
}
internal void  MEM_FREE_SPACE(memory_struct* Memory, void* base)
{
    memory_entry* entry = memory_find_entry(Memory, base);
    ASSERT(entry)

    mem_clear(entry->base, entry->size); // @ clear data.

    memory_entry* next   = entry->next;
    memory_entry* before = memory_find_entry_before(Memory, entry->base);

    if(next && !next->used)   // @ is there an entry ahead of us? and is it used?
    {
	// @ consolidate
	entry->size += sizeof(memory_entry) + next->size;
	entry->next = next->next;
	entry->used = false;

	mem_clear(entry->base, entry->size);
    }
    if(before && !before->used) // @ is there an entry before us? and is it used?
    {
	before->next = entry->next;
	before->size += sizeof(memory_entry) + entry->size;

	mem_clear(before->base, before->size); // @ clear data.

	entry = before;
    }

    if(!entry->next)
    {
	// @ we can get rid of ourselves. we are at the top of the stack.
	Memory->used -= entry->size + sizeof(memory_entry);

	mem_clear(entry, sizeof(memory_entry)); // @ clear structure.
    }
    
}


